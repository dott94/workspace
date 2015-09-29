public class GeekWatch extends ZoneWatch

{
	// TODO Define GeekWatch(int azone) constructor
	public GeekWatch(int azone){
		super(azone);
	}
	
	
	// TODO Define GeekWatch(Watch w) constructor
	public GeekWatch(Watch w){
		super(w);
	}
	// TODO Define GeekWatch(Watch w, int azone) constructor
	public GeekWatch(Watch w, int azone){
		super(w, azone);
	}
	// TODO Define GeekWatch(int hour, int minute, int second) constructor
	public GeekWatch(int hour, int minute, int second){
		super(hour, minute, second);
	}
	// TODO Define GeekWatch(int hour, int minute, int second, int azone) constructor
	public GeekWatch(int hour, int minute, int second, int azone){
		super(hour, minute, second, azone);
	}
	 
	
	private int daySeconds(int hour, int minute, int seconds)
	{
		return seconds + minute * 60 + hour * 60 * 60;
	}
	
	public int angleHourMinuteHands() 
	{
		double angleHour = .5 * ((daySeconds(getHour(), getMinute(), getSecond()) / 60) % (60 * 12));
		double angleMinute = 6 * getMinute();
		// Assume that hour and minutes hands move a little every seconds
		// It takes 12 hours for hour hand to go around, so the hour hand traverses 360 degrees in 12 hours
		// It takes 60 minutes for minute hand to go around, so the minute hand traverses 360 degrees in 60 minutes
		
		return (int) Math.abs(angleHour - angleMinute);
	}
	
	public String toString()
	{
		return super.toString() + " angle between minute hand and hour hand " 
	           + angleHourMinuteHands() + " degrees";
	}
}
