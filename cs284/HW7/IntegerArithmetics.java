
public class IntegerArithmetics implements Arithmetics<Integer> {

	protected Integer value;
	
	public Integer zero() 
	{
		
		return new Integer(0);
	}
	 
	public Integer add( Integer a, Integer b ) 
	{
		
		return new Integer(a.intValue()+b.intValue());
	}
	
	public Integer subtract (Integer a, Integer b)
	{
		return new Integer(a.intValue()-b.intValue());
	}
    
	public Integer multiply (Integer a, Integer b)
	{
		return new Integer(a.intValue()*b.intValue());
	}
	
	public Integer parseString( String str )
	{
		return Integer.parseInt(str);
	}
	
	public String toString( Integer a )
	{
		return a.toString();
	}
}
