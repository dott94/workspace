
public class UtcWatch  implements Watch

{
	private int utcHour;
	private int utcMinute;
	private int utcSecond;

    public UtcWatch()
    {	   
	  	utcHour   = 0;
	  	utcMinute = 0;
	  	utcSecond = 0;		  
    }
    
    public UtcWatch(int hour, int minute, int second)
    {
	  	utcHour   = hour%24;
	  	utcMinute = minute%60;
	  	utcSecond = second%60;
    }
    
    public UtcWatch(Watch w1)
    {
	  	utcHour   = w1.getUtcHour()%24;
	  	utcMinute = w1.getUtcMinute()%60;
	  	utcSecond = w1.getUtcSecond()%60;
    }
    public  int  getHour ()
    {
    	return utcHour;  	  
    } 
    
	public int  getMinute() 
	{
		return utcMinute;
	}
	
	public int getSecond() 
	{
		return utcSecond;
	}
	
	public  void setHour (int hour )
	{
		setUtcHour( hour );
	}
	public  void setMinute   (int minute)
	{
		 setUtcMinute(minute);
	}
	public  void setSecond   (int second)
	{
		setUtcSecond(second);
	}
	public int  getUtcHour  () 
	{
		return utcHour;
	}
	public int  getUtcMinute()
	{
		return utcMinute;
	}
	public  int  getUtcSecond()
	{
		return utcSecond;
	}
	
	public void setUtcHour  (int hour  )
	{
        utcHour = hour%24;
	}
	
	public void setUtcMinute   (int minute)
    {
	    utcMinute = minute%60;
	}

	public void setUtcSecond   (int second)
	{
        utcSecond = second%60;
	}

	public  String toString()
	{
    	return "UTC time h:m:s "+utcHour+":"+utcMinute+":"+utcSecond;
	}

}
