//Fall2013
public class Fraction {
	
	private int a;
	private int b;
	public Fraction()
	{
		a = 0;
		b = 1;
	}
	public Fraction (int a, int b) throws ZeroDenominatorException
	{
		setNumerator(a);
		setDenominator(b);
	}
	public int getNumerator()
	{
		return a;
	}
	public int getDenominator()
	{
		return b;
	}
	public void setNumerator(int a)
	{
		this.a=a;
	}
	
	public void setDenominator(int b) throws ZeroDenominatorException
	{
		if(b !=0){
			this.b=b;
		}
		else{
			throw new ZeroDenominatorException();
		}
	}
	public String toString ()
	{   
		if(b==1||a==0) return a+"";
		return a+"/"+b;
	
	}
	
	private static int gcd(int n1, int n2)
	{
		//ToDo   implement Euclide algorithm 
		while (n2 != 0) {
			int a = n1/n2;
			int b = n1 - a*n2;
			n1 = n2;
			n2 = b;
		}

		return (n1);   //return gcd(n1,n2)
	}
	public void lowestTerms()
	{   
		if ( a != 0 )
		{
			int g = gcd(a,b);
			a = a/g;
			b = b/g;
		}
	}
	public static Fraction add(Fraction first, Fraction second) throws ZeroDenominatorException
	{
		Fraction result = new Fraction();
		result.setNumerator          ( first.a*second.b + first.b*second.a );
	        result.setDenominator        ( first.b*second.b                    );
	        result.lowestTerms();
		return result;
	}
	//ToDo methods subtract, multiply, divide
	public static Fraction subtract(Fraction first, Fraction second) throws ZeroDenominatorException
	{
		Fraction result = new Fraction();
		result.setNumerator          ( first.a*second.b - first.b*second.a );
	        result.setDenominator        ( first.b*second.b                    );
	        result.lowestTerms();
		return result;
	}
	public static Fraction multiply(Fraction first, Fraction second) throws ZeroDenominatorException
	{
		Fraction result = new Fraction();
		result.setNumerator          ( first.a*second.a );
	        result.setDenominator        ( first.b*second.b                    );
	        result.lowestTerms();
		return result;
	}
	public static Fraction divide(Fraction first, Fraction second) throws ZeroDenominatorException
	{
		Fraction result = new Fraction();
		result.setNumerator          ( first.a*second.b );
	        result.setDenominator        ( first.b*second.a                    );
	        result.lowestTerms();
		return result;
	}
	public static boolean lessThan(Fraction first, Fraction second)
	{
		//ToDo
		if (first.a*second.b <
				first.b*second.a) {
			return true;
		}
		else {
			return false; 
		}
                
                
	}
}

