
import java.util.*;

public class Driver
{
    static Scanner console = new Scanner(System.in);

    public static void main(String[] args)
    {
        UnorderedLinkedList<Integer> intList
                          = new UnorderedLinkedList<Integer>();

        Integer num;

        System.out.println("Enter integers ending with -999.");

        num = console.nextInt();

        while (num != -999)
        {
            intList.insertLast(num);
            num = console.nextInt();
        }

        System.out.println();

        System.out.println("intList: ");
        intList.print();
        System.out.println();
        System.out.println("Length of intList: " + intList.length());

        System.out.print("Enter the number to be deleted: ");
        num = console.nextInt();
        System.out.println();

            //deleteNode
        intList.deleteAll(num);

        System.out.println("After deleting all occurences of " + num + " intList: ");
        intList.print();
        System.out.println();

        System.out.println("Length of intList: " + intList.length());

        intList.deleteSmallest();

        System.out.println("After deleting the smallest element, intList:");

        intList.print();
        System.out.println();

        System.out.println("Length of intList: " + intList.length());
    }
}