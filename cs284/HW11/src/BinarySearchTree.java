
public class BinarySearchTree<T> extends BinaryTree<T>
{
       //Default constructor
       //Postcondition: root = null;
    public BinarySearchTree()
    {
        super();
    }

       //Method to determine whether searchItem is in the
       //binary search tree.
       //Postcondition: Returns true if searchItem is found
       //               in the binary search tree;
       //               otherwise, returns false.
    public boolean search(T searchItem)
    {
        BinaryTreeNode<T> current;
        boolean found = false;

        if (root == null)
            System.out.println("Cannot search an empty tree.");
        else
        {
            current = root;

            while (current != null && !found)
            {
                Comparable<T> temp =
                         (Comparable<T>) current.info;

                if (temp.compareTo(searchItem) == 0)
                    found = true;
                else if (temp.compareTo(searchItem) > 0)
                    current = current.lLink;
                else
                    current = current.rLink;
            }//end while
        }//end else

        return found;
    }//end search

       //Method to insert insertItem in the binary search tree.
       //Postcondition: If no node in the binary search tree has
       //               the same info as insertItem, a node with
       //               the info insertItem is created and inserted
       //               in the binary search tree.
    public void insert(T insertItem)
    {
        BinaryTreeNode<T> current;    //reference variable to
                                      //traverse the tree
        BinaryTreeNode<T> trailCurrent = null; //reference variable
                                               //behind current
        BinaryTreeNode<T> newNode;       //reference variable to
                                         //create the node

        newNode = new BinaryTreeNode<T>(insertItem, null, null);

        if (root == null)
            root = newNode;
        else
        {
            current = root;

            while (current != null)
            {
                trailCurrent = current;

                Comparable<T> temp1 =
                              (Comparable<T>) current.info;

                if (temp1.compareTo(insertItem) == 0)
                {
                    System.err.print("The insert item is "
                                   + "already in the tree -- "
                                   + "duplicates are not "
                                   + "allowed.");
                    return;
                }
                else if (temp1.compareTo(insertItem) > 0)
                    current = current.lLink;
                else
                    current = current.rLink;
            }//end while

            Comparable<T> temp2 =
                       (Comparable<T>) trailCurrent.info;

            if (temp2.compareTo(insertItem) > 0)
                trailCurrent.lLink = newNode;
            else
                trailCurrent.rLink = newNode;
        }
    }//end insert

       //Method to delete deleteItem from the binary search tree
       //Postcondition: If a node with the same info as
       //               deleteItem is found, it is deleted from
       //               the binary search tree.
    public void deleteNode(T deleteItem)
    {
        BinaryTreeNode<T> current;  //reference variable to
                                  //traverse the tree
        BinaryTreeNode<T> trailCurrent; //reference variable
                                      //behind current
        boolean found = false;

        if (root == null)
            System.err.println("Cannot delete from an "
                             + "empty tree.");
        else
        {
            current = root;
            trailCurrent = root;

            while (current != null && !found)
            {
                if (current.info.equals(deleteItem))
                    found = true;
                else
                {
                    trailCurrent = current;

                    Comparable<T> temp =
                              (Comparable<T>) current.info;

                    if (temp.compareTo(deleteItem) > 0)
                        current = current.lLink;
                    else
                        current = current.rLink;
                }
            }//end while

            if (current == null)
                System.out.println("The delete item is not in "
                                 + "the tree.");
            else if (found)
            {
                if (current == root)
                    root = deleteFromTree(root);
                else
                {
                    Comparable<T> temp =
                             (Comparable<T>) trailCurrent.info;

                    if (temp.compareTo(deleteItem) > 0)
                        trailCurrent.lLink =
                              deleteFromTree(trailCurrent.lLink);
                    else
                        trailCurrent.rLink =
                              deleteFromTree(trailCurrent.rLink);
                }
            }//end else-if
        }
    }//end deleteNode

       //Method to delete the node, to which p points, from
       //the binary search tree.
       //Postcondition: The node to which p points is deleted
       //               from the binary search tree. The
       //               reference of the root node of the binary
       //               search tree after deletion is returned.
    private BinaryTreeNode deleteFromTree(BinaryTreeNode<T> p)
    {
        BinaryTreeNode<T> current;   //reference variable to
                                     //traverse the tree
        BinaryTreeNode<T> trailCurrent;   //reference variable
                                        //behind current
        if (p == null)
            System.err.println("Error: The node to be deleted "
                             + "is null.");
        else if (p.lLink == null && p.rLink == null)
             p = null;
        else if (p.lLink == null)
             p = p.rLink;
        else if (p.rLink == null)
             p = p.lLink;
        else
        {
            current = p.lLink;
            trailCurrent = null;

            while (current.rLink != null)
            {
                trailCurrent = current;
                current = current.rLink;
            }//end while

            p.info = current.info;

            if (trailCurrent == null) //current did not move;
                                      //current == p.lLink;
                                      //adjust p
               p.lLink = current.lLink;
            else
                trailCurrent.rLink = current.lLink;
        }//end else

        return p;
    }//end deleteFromTree
}