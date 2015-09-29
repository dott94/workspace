
public interface SearchSortADT <T>{
	public int seqSearch(T[] list, int length, T searchItem);
	public int binarySearch(T[] list, int length, T searchItem);
	public int seqSearchRec(T[] list, int length, T searchItem);
	public int binarySearchRec(T[] list, int length, T searchItem);
}
