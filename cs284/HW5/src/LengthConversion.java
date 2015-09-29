import java.io.*;
import java.util.*;

public class LengthConversion extends Exception
{   
	
	static Scanner console = new Scanner (System.in); 
	
	public static double getNumber() throws InputMismatchException
	{
//		return console.nextDouble();
		
		try {
			return console.nextDouble();
		}
		catch (InputMismatchException  e)
		{
			System.out.println("Exception inside getNumber"+e.toString());
			throw new InputMismatchException();
		}
	}
	
	public static double getPositiveNumber() throws InputMismatchException, NegativeNumberException
	{
		double num = getNumber();
		if (num < 0.0) throw new NegativeNumberException();
		return num;
	}
	
	public static void main(String[] args)
	{
		double feet,inches,centimeters;

		while (true)
		{	
			System.out.println("Please, enter the length in feet and inches ");
			try
			{
				feet   =  getPositiveNumber();
				inches =  getPositiveNumber();
			}
			catch (Exception e)
			{
				System.out.println("Exception: "+e.toString());
				console.nextLine();
				continue;
			}
			break;
		}
		
		centimeters = (feet * 12.0 + inches) * 2.54;
		System.out.println(feet + " feet " + inches + " inches = " + centimeters + " centimeters");
	}			
}
