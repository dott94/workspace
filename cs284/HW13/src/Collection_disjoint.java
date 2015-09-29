import java.util.Collections;
import java.util.Vector;


public class Collection_disjoint {

	public static void main(String[] args) {
		Vector<Integer> list1 = new Vector<Integer> ();
		list1.add(2);
		list1.add(4);
		list1.add(6);
		list1.add(8);
		System.out.println(list1);
		Vector<Integer> list2 = new Vector<Integer> ();
		list2.add(1);
		list2.add(2);
		list2.add(3);
		list2.add(5);
		list2.add(7);
		System.out.println(list2);
		Vector<Integer> list3 = new Vector<Integer> ();
		list3.add(1);
		list3.add(5);
		list3.add(9);
		System.out.println(list3);
		System.out.println(Collections.disjoint(list1, list2));
		System.out.println(Collections.disjoint(list2, list3)); 
		System.out.println(Collections.disjoint(list1, list3));
		
	}

}
