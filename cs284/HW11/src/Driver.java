//Data: 65 78 34 22 40 89 50 75 80 100 90 97 45 120 105 -999

import java.util.*;

public class Driver
{
    static Scanner console = new Scanner(System.in);

    public static void main(String[] args)
    {
        BinarySearchTree<Integer> treeRoot =
                                new BinarySearchTree<Integer>();

        Integer num;

        System.out.println("Enter integers ending with -999");

        num = console.nextInt();

        while (num != -999)
        {
            treeRoot.insert(num);
            num = console.nextInt();
        }

        System.out.print("treeRoot nodes in inorder: ");
        treeRoot.inorderTraversal();
        
        System.out.println(); 
        System.out.print("Number of Nodes: " + treeRoot.treeNodeCount());
       
        System.out.println();
        System.out.print("Number of Leaves: "
                + treeRoot.treeLeavesCount());
        
         System.out.println();
        System.out.println("Tree Height: "
                          + treeRoot.treeHeight());
      
        System.out.println("Number of single Parents: "
                          + treeRoot.singleParent());
    }
}