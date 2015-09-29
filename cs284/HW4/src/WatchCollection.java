
public class WatchCollection
{   

	private Watch watches[];	// an array of references to Watch objects
	                            // watches[i] == null if there is no watch in position i
	private int num;            // size of the array
	
	private void init(int numberOfWatches) {
		watches = new Watch[numberOfWatches];
		for (int i=0;i<numberOfWatches;++i)
		{
			watches[i] = null;
		}
		num = numberOfWatches;
	}
	public WatchCollection(int numberOfWatches)
	{   
		init(numberOfWatches);
	}
	public WatchCollection (Watch  w1)
	{
		init(1);
		add(w1);			
	}
	
	// TODO Define WatchCollection (Watch w1, Watch w2) constructor
	public WatchCollection (Watch w1, Watch w2){
		init(2);
		add(w1);
		add(w2);
	}
	// TODO Define WatchCollection (Watch w1, Watch w2, Watch w3) constructor
	public WatchCollection (Watch w1, Watch w2, Watch w3){
		init(3);
		add(w1);
		add(w2);
		add(w3);
	}
	public void add    ( Watch w )
	{
		for(int i=0;i<num;++i)
		{
			if (watches[i]==null)
			{
				watches[i]=w;
				return;
			}
		}
	}
	public void remove ( Watch w )
	{
		// TODO Write a code that removes Watch w if it is in the array
		for(int i = 0; i < watches.length; i++){
			if (watches[i] != null && watches[i].equals(w)){
				watches[i] = null;
			}
		}
	}

    public int size()
    {
    	// TODO Write a code that returns actual number of watches, skip all null array elements
    	int count = 0;
    	for(int i = 0; i < watches.length; i++){
    		if (watches[i] != null){
				count = count + 1;
			}
    	}
    	return count;

    }
    
    public Watch at( int index)
    {
    	// TODO Write a code that returns a watch with the specified index (skip all null array elements)
    	// TODO Throw an exception if the index is < 0 or >= actual number of watches
    	// For example, if the array contains w1 w2 null w3 w4
    	// index 0 -> w1
    	// index 1 -> w2
    	// index 2 -> w3
    	// index 3 -> w4
    	// index 4 -> an exception
    	if (index < 0 || index >= watches.length){
    		throw new IndexOutOfBoundsException(); 
    	}
    	int j = -1;
    	for(int i = 0; i < watches.length; i++){
    		if (watches[i] != null){
    			j = j + 1;	
    			if(j== index){
    				return watches[i];
    			}
    		}
    	}
    	throw new IndexOutOfBoundsException();
    }
    
	public String toString()
	{
		String str="{\n";
		
	    int index=0;
		for(int i=0;i<num;++i)
		{
			if (watches[i]!=null)
			{
				str+=" " +index++ + ": " +watches[i] + "\n";
			}
		}
		str+=" }";
		return str;		 
	 }
}
