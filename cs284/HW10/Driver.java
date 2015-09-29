/*
 *11/08/2013 Kamilla demo Interface, Generic Methods
 *Sample output1:
 * 
 Enter 2 integers to compare 
1 1
Output: 1
Enter 2 strings to compare 
we we
Output: 1

Sample output2:

Enter 2 integers to compare 
1 2
Output: -1
Enter 2 strings to compare 
we re
Output: -1

 */
import java.util.Arrays;
import java.util.Scanner;


public class Driver {
	
	static Scanner console = new Scanner(System.in);
	
	public static void main(String[] args) {
		
	  SearchSortAlgorithm<Integer> n = new SearchSortAlgorithm<Integer>(); 
	  Integer[] a = {1, 2, 3, 4, 5, 6, 7};
	  System.out.println("test array " + Arrays.toString(a));
	  System.out.println("sequential search searching for number 2 found at index " + n.seqSearch(a, a.length, 2));
	  System.out.println("sequential Recursive search searching for number 2 found at index " + n.seqSearchRec(a, a.length, 2));
	  System.out.println("Binary search searching for number 2 found at index " + n.binarySearch(a, a.length, 2));
	  System.out.println("Binary Recursive search searching for number 2 found at index " + n.binarySearchRec(a, a.length, 2));

	  SearchSortAlgorithm<String> s = new SearchSortAlgorithm<String>(); 
	  String[] b = {"a", "b", "c" , "d", "e"};
	  System.out.println("test array " + Arrays.toString(b));
	  System.out.println("sequential search searching for string e found at index " + s.seqSearch(b, b.length, "e"));
	  System.out.println("sequential Recursive search searching for string e found at index " + s.seqSearchRec(b, b.length, "e"));
	  System.out.println("Binary search searching for string e found at index " + s.binarySearch(b, b.length, "e"));
	  System.out.println("Binary Recursive search searching for string e found at index " + s.binarySearchRec(b, b.length, "e"));
	  
	}

}
