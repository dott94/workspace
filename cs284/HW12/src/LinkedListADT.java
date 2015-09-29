import java.lang.*;

public interface LinkedListADT<T> extends Cloneable
{
	public Object clone();
	//Returns a copy of objects data in store.
	//This method clones only the references stored in
	//each node of the list. The objects that the 
	//list nodes point to are not cloned.
	
	public boolean isEmptyList();
	//Method to determine whether the list is empty.
	//Postcondition: Returns true if the list is empty;
	//                       false otherwise.
	
	public void initializeList();
	//Method to initialize the list to an empty state.
	//Postcondition: The list is initialized to an empty state.
	
	public void print();
	//Method to output the data contained in each node.
	
	public int length();
	//Method to return the number of nodes in the list.
	//Postcondition: The number of nodes in the list is returned.
	
	public T front();
	//Method to return a reference of the object containing 
	//the data of the first node of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: The reference of the object that 
	//               contains the info of the first node
	//               is returned.
	
	public T back();
	//Method to return a reference of object containing
	//the data of the last node of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: The reference of the object that 
	//               contains the info of the last node
	//               is returned.
	
	public boolean search (T searchItem);
	//Method to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is found
	//               in the list; false otherwise.
	
	public void insertFirst(T newItem);
	//Method to insert newItem in the list.
	//Postcondition: newItem is inserted at the 
	//               beginning of the list.
	
	public void insertLast (T newItem);
	//Method to insert newItem at the end of the list.
	//Postcondition: newItem is inserted at the end
	//               of the list
	
	public void deleteNode(T deleteItem);
	//Method to delete deleteItem from the list.
	//Postcondition: If found, the node containing 
	//               deleteItem is deleted from the list.
	
}
