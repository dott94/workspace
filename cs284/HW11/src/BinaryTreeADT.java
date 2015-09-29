
public interface BinaryTreeADT<T> extends Cloneable
{
    public Object clone();
       //Returns a clone of this binary tree.
       //This method clones only the references stored in
       //the nodes of the binary tree. The objects that
       //binary tree nodes point to are not cloned.

    public boolean isEmpty();
       //Method to determine whether the binary tree is empty.
       //Postcondition: Returns true if the binary tree is
       //               empty; otherwise, returns false.

    public void inorderTraversal();
       //Method to do an inorder traversal of the binary tree.
       //Postcondition: The nodes of the binary tree are
       //               output in the inorder sequence.

    public void preorderTraversal();
       //Method to do a preorder traversal of the binary tree.
       //Postcondition: The nodes of the binary tree are
       //               output in the preorder sequence.

    public void postorderTraversal();
       //Method to do a postorder traversal of the binary tree.
       //Postcondition: The nodes of the binary tree are
       //               output in the postorder sequence.

    public int treeHeight();
       //Method to determine the height of the binary tree.
       //Postcondition: The height of the binary tree is
       //               returned.

    public int treeNodeCount();
       //Method to determine the number of nodes in the
       //binary tree.
       //Postcondition: The number of nodes in the binary
       //               tree is returned.

    public int treeLeavesCount();
       //Method to determine the number of leaves in the
       //binary tree.
       //Postcondition: The number of leaves in the binary
       //               tree is returned.

    public void destroyTree();
       //Method to destroy the binary tree.
       //Postcondition: root = null

    public boolean search(T searchItem);
       //Method to determine whether searchItem is in the
       //binary search tree.
       //Postcondition: Returns true if searchItem is found
       //               in the binary search tree;
       //               otherwise, returns false.

    public void insert(T insertItem);
       //Method to insert insertItem in the binary search tree.
       //Postcondition: If no node in the binary search tree
       //               has the same info as insertItem, a node
       //               with the info insertItem is created and
       //               inserted in the binary search tree.

    public void deleteNode(T deleteItem);
       //Method to delete deleteItem from the binary search tree
       //Postcondition: If a node with the same info as
       //               deleteItem is found, it is deleted from
       //               the binary search tree.

    public int singleParent();
}