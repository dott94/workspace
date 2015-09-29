//Fall2013

import java.util.*;

public class TestFraction 
{   
	
	static Scanner console = new Scanner (System.in); 
	public static void main(String[] args)
	{
	{
		Fraction fr1 = new Fraction (1,5);
		Fraction fr2 = new Fraction (3,5);
		Fraction res = new Fraction ();
		res          =    Fraction.add  (fr1, fr2);
		System.out.println(fr1+" + "+fr2+" = "+res);   
		// test subtract, multiply, divide, lessThan methods
				
	}
	{
		Fraction fr1 = new Fraction (1,5);
		Fraction fr2 = new Fraction (3,5);
		Fraction res = new Fraction ();
		res          =    Fraction.subtract  (fr1, fr2);
		System.out.println(fr1+" - "+fr2+" = "+res);   
				
	}
	{
		Fraction fr1 = new Fraction (1,5);
		Fraction fr2 = new Fraction (3,5);
		Fraction res = new Fraction ();
		res          =    Fraction.multiply  (fr1, fr2);
		System.out.println(fr1+" * "+fr2+" = "+res);   
				
	}
	{
		Fraction fr1 = new Fraction (1,5);
		Fraction fr2 = new Fraction (3,5);
		Fraction res = new Fraction ();
		res          =    Fraction.divide  (fr1, fr2);
		System.out.println(fr1+" / "+fr2+" = "+res);   
				
	}
	{
		Fraction fr1 = new Fraction (4,5);
		Fraction fr2 = new Fraction (1,5);
		Fraction res = new Fraction ();
		res			 =     Fraction.lessThan  (fr1, fr2);
		System.out.println(res+" is less than");   
				
	}
}
}
