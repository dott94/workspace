
public class Driver 
{
	public static void adjust( Watch w1, Watch w2)
	{
		final int averageHour   = (w1.getUtcHour()  + w2.getUtcHour())/2;
		// TODO Calculate average minutes and seconds
		final int averageMinute   = (w1.getUtcMinute()  + w2.getUtcMinute())/2;
		final int averageSecond   = (w1.getUtcSecond()  + w2.getUtcSecond())/2;
		w1.setUtcHour   (averageHour  );
	    // TODO Set w1 UTC minutes and seconds to the average
		w1.setUtcMinute   (averageMinute  );
		w1.setUtcSecond   (averageSecond  );
	    // TODO Set w2 UTC hours, minutes, and seconds to the average
		w2.setUtcHour   (averageHour  );
		w2.setUtcMinute   (averageMinute  );
		w2.setUtcSecond   (averageSecond  );
	}
	
	public static void sync  ( Watch w1, Watch w2)
	{
		System.out.println ( "w1 " + w1 );
		// TODO Print w1 watch before the adjustment
		System.out.println("Watch w1 before the adjustment");
		System.out.println(w1);
		adjust (w1,w2);
		
		// TODO Print w1 and w2 watches after the adjustment
		System.out.println("Watch w1 after the adjustment");
		System.out.println(w1);
		System.out.println("Watch w2 after the adjustment");
		System.out.println(w2);
	}
	
	public static void main(String args[])
	{
		ZoneWatch w1 = new ZoneWatch (15, 0, 15,-3);
		ZoneWatch w2 = new ZoneWatch (3 ,59, 0,  1);
		
		sync(w1,w2);

		GeekWatch w3 = new GeekWatch(17,30,0,5);
		System.out.println ( w3);

		WatchCollection wc = new WatchCollection(w1,w2,w3);
		
		System.out.println("[\n "+ wc + " \n] ");
		System.out.println( "[ size = " + wc.size() + " ] ");
	
		wc.remove(w1);
		wc.remove(w2);
		wc.add(w1);

		System.out.println();
		System.out.println("[\n "+ wc + " \n] ");
		System.out.println( "[ size = " + wc.size() + " ] ");

		// TODO Define GeekWatch w4 in EST (Eastern Time) zone
		GeekWatch w4 = new GeekWatch(- 5); 
		// TODO Define GeekWatch w5 in CST (Central Time) zone
		GeekWatch w5 = new GeekWatch(- 6);
		// TODO Define GeekWatch w6 in PST (Pacific Time) zone
		GeekWatch w6 = new GeekWatch(- 7);
		// TODO Set some time so w4 UTC time is the same as w5 UTC time + 2 hours and
		GeekWatch someTime = new GeekWatch(w5, 2);
		//      also the same as w6 UTC time + 3 hours 
		// TODO Create a collection consisting of w4, w1, w5, w2, w6, w3
		WatchCollection watches = new WatchCollection(6);
		watches.add(w4);
		watches.add(w1);
		watches.add(w5);
		watches.add(w2);
		watches.add(w6);
		watches.add(w3);
		// TODO Delete w1, w2, and w3 from the collection
		watches.remove(w1);
		watches.remove(w2);
		watches.remove(w3);
		// TODO Print the collection using toString()
		System.out.println(watches);
		// TODO Write a loop that prints each watch in the collection using size() and at()
		for(int i = 0; i < watches.size(); i++){
			System.out.println(watches.at(i));
		}
		// TODO Write loops that synchronize each pair of watches inside the collection
		for(int i = 0; i < watches.size(); i++){
			for(int j = 0; j < watches.size(); j++){
				sync(watches.at(i), watches.at(j));
			}
		}
		// TODO Print the collection after the synchronization using toString()
		System.out.println(watches);
	}

	
	
}
