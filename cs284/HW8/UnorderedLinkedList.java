public class UnorderedLinkedList<T> extends LinkedListClass<T> {
	// Default constructor
	public UnorderedLinkedList() {
		super();
	}

	// Method to determine whether searchItem is in
	// the list.
	// Postcondition: Returns true if searchItem is found
	// in the list; false otherwise.
	public boolean search(T searchItem) {
		LinkedListNode<T> current; // variable to traverse
									// the list
		boolean found;

		current = first; // set current to point to the first
							// node in the list

		found = false; // set found to false

		while (current != null && !found)
			// search the list
			if (current.info.equals(searchItem)) // item is found
				found = true;
			else
				current = current.link; // make current point to
										// the next node
		return found;
	}

	// Method to insert newItem in the list.
	// Postcondition: first points to the new list
	// and newItem is inserted at the
	// beginning of the list. Also,
	// last points to the last node and
	// count is incremented by 1.
	public void insertFirst(T newItem) {
		LinkedListNode<T> newNode; // variable to create the
									// new node

		newNode = new LinkedListNode<T>(newItem, first); // create and
		// insert newNode before
		// first

		first = newNode; // make first point to the
							// actual first node

		if (last == null) // if the list was empty, newNode is
							// also the last node in the list
			last = newNode;

		count++; // increment count
	}

	// Method to insert newItem at the end of the list.
	// Postcondition: first points to the new list and
	// newItem is inserted at the end
	// of the list. Also, last points to
	// the last node and
	// count is incremented by 1.
	public void insertLast(T newItem) {
		LinkedListNode newNode; // variable to create the
								// new node

		newNode = new LinkedListNode(newItem, null); // create newNode

		if (first == null) // if the list is empty, newNode is
							// both the first and last node
		{
			first = newNode;
			last = newNode;
		} else // if the list is not empty, insert
				// newNode after last
		{
			last.link = newNode; // insert newNode after last
			last = newNode; // set last to point to the
							// actual last node
		}

		count++;
	}// end insertLast

	// Method to delete deleteItem from the list.
	// Postcondition: If found, the node containing
	// deleteItem is deleted from the
	// list. Also, first points to the first
	// node, last points to the last
	// node of the updated list, and count
	// is decremented by 1.
	public void deleteNode(T deleteItem) {
		LinkedListNode<T> current; // variable to traverse
									// the list
		LinkedListNode<T> trailCurrent; // variable just
										// before current
		boolean found;

		if (first == null) // Case 1; the list is empty
			System.err.println("Cannot delete from an empty " + "list.");
		else {
			if (first.info.equals(deleteItem)) // Case 2
			{
				first = first.link;

				if (first == null) // the list had only one node
					last = null;
				count--;
			} else // search the list for the given info
			{
				found = false;
				trailCurrent = first; // set trailCurrent to
										// point to the first node
				current = first.link; // set current to point to
										// the second node

				while (current != null && !found) {
					if (current.info.equals(deleteItem))
						found = true;
					else {
						trailCurrent = current;
						current = current.link;
					}
				}// end while

				if (found) // Case 3; if found, delete the node
				{
					count--;
					trailCurrent.link = current.link;

					if (last == current) // node to be deleted
											// was the last node
						last = trailCurrent; // update the value
												// of last
				} else
					System.out.println("Item to be deleted is "
							+ "not in the list.");
			}// end else
		}// end else
	}// end deleteNode

	public void deleteAll(T deleteItem) {
		// TODO
		LinkedListNode<T> current; // variable to traverse
		// the list
		LinkedListNode<T> trailCurrent; // variable just
		// before current

		if (first == null) // Case 1; the list is empty
			System.err.println("Cannot delete from an empty " + "list.");
		else {
			if (first.info.equals(deleteItem)) // Case 2
			{
				first = first.link;

				if (first == null) // the list had only one node
					last = null;
				count--;
			}
			trailCurrent = first; // set trailCurrent to
			// point to the first node
			current = first.link; // set current to point to
			// the second node

			while (current != null) {
				if (current.info.equals(deleteItem)) {
					count--;
					trailCurrent.link = current.link;

					if (last == current) // node to be deleted
						// was the last node
						last = trailCurrent; // update the value
												// of last
				}
				trailCurrent = current;
				current = current.link;
			}// end while

		}// end else
	}// end else

	@SuppressWarnings("unchecked")
	public void deleteSmallest() {
		// TODO
		if (length() == 0)
			return;
		if (!(front() instanceof Comparable))
			return;
		T minElement = front();
		LinkedListNode<T> current = first.link; // set current to point to
		// the second node

		while (current != null) {
			if (((Comparable<T>) current.info).compareTo(minElement) == -1){
				minElement = current.info;
			}
			current = current.link;
		}// end while
		deleteNode(minElement);
	}
}
