
public class ZoneWatch extends UtcWatch
{

	private int zone;
	
	public ZoneWatch()
	{
		super();
		zone = 0;
	}
	
	// Define constructor ZoneWatch(int azone)
	public ZoneWatch(int azone){
		super();
		zone = azone;
	}
	// Define constructor ZoneWatch(Watch w, int azone)
	public ZoneWatch(Watch w, int azone){
		super(w);
		zone = azone;
	}
	// Define constructor ZoneWatch(Watch w)
	public ZoneWatch(Watch w){
		super(w);
		zone = 0;
	}
	// Define constructor ZoneWatch(int hour, int minute, int second)
	public ZoneWatch(int hour, int minute, int second){
		super(hour, minute, second);
		zone = 0;
	}
	// Define constructor ZoneWatch(int hour, int minute, int second, int azone)
	public ZoneWatch(int hour, int minute, int second, int azone){
		super(hour, minute, second);
		zone = azone;
	}
	public int  getHour() 
	{
	    return (super.getHour()+zone)%24;
		
	}
	
	public  void setHour(int hour)
	{
		super.setHour((hour-zone)%24);	
	}
	
	public String toString()
	{
		return super.toString() + " Current hour: " + getHour() + " zone " + zone;
	}
}
