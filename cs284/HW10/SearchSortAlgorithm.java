public class SearchSortAlgorithm<T> implements SearchSortADT<T> {

	public int seqSearch(T[] list, int length, T searchItem) {
		int loc;
		boolean found = false;
		for (loc = 0; loc < length; loc++) {
			if (list[loc].equals(searchItem)) {
				found = true;
				break;
			}
		}
		if (found)
			return loc;
		else
			return -1;
	}

	public int binarySearch(T[] list, int length, T searchItem) {
		int first = 0;
		int last = length - 1;
		int mid = -1;
		boolean found = false;

		while (first <= last && !found) {
			mid = (first + last) / 2;
			Comparable<T> compElem = (Comparable<T>) list[mid];

			if (compElem.compareTo(searchItem) == 0)
				found = true;
			else if (compElem.compareTo(searchItem) > 0)
				last = mid - 1;
			else
				first = mid + 1;
		}
		if (found)
			return mid;
		else
			return -1;

	}

	public int seqSearchRec(T[] list, int length, T searchItem) {
		return seqSearchRecPriv(list, 0, searchItem);
	}

	private int seqSearchRecPriv(T[] list, int index, T searchItem) {
		if (index >= list.length) {
			return -1;
		}
		if (list[index].equals(searchItem)) {
			return index;
		} else {
			return seqSearchRecPriv(list, index + 1, searchItem);

		}
	}

	public int binarySearchRec(T[] list, int length, T searchItem) {
		return binarySearchRecPriv(list, length, searchItem, 0, length - 1);
	}

	private int binarySearchRecPriv(T[] list, int length, T searchItem,
			int first, int last) {
		int mid = -1;

		if (first <= last) {
			mid = (first + last) / 2;
			Comparable<T> compElem = (Comparable<T>) list[mid];

			if (compElem.compareTo(searchItem) == 0)
				return mid;
			else if (compElem.compareTo(searchItem) > 0)
				last = mid - 1;
			else
				first = mid + 1;
			return binarySearchRecPriv(list, length, searchItem, first, last);
		} else
			return -1;
	}

}
