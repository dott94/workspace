import java.io.*;
import java.util.*;

public class TestFraction {

	static Scanner console = new Scanner(System.in);

	public static int getNumber() throws InputMismatchException {

		try {
			return console.nextInt();
		} catch (InputMismatchException e) {
			System.out.println("Exception inside getNumber" + e.toString());
			console.nextLine();
			throw new InputMismatchException();
		}
	}

	private static Fraction getFraction(String text)
			throws ZeroDenominatorException {
		while (true) {

			// prompt to enter a numerator and a denominator
			System.out.println("Enter a numerator and a denominator for "
					+ text);
			// input the numerator and the denominator using getNumber()
			try {
				int numerator = getNumber();
				int denominator = getNumber();
				return new Fraction(numerator, denominator);
			} catch (InputMismatchException e) {
				System.out
						.println("Please enter a valid numerator and denominator");
			}

			// return new Fraction if OK
			// otherwise print an error message
		}
	}

	public static void main(String[] args) {
		Fraction fr1 = null;
		Fraction fr2 = null;
		while (fr1 == null) {
			try {
				fr1 = getFraction("1st");
			} catch (ZeroDenominatorException e) {
				System.out.println(e);
			}
		}
		while (fr2 == null) {
			try {
				fr2 = getFraction("2nd");
			} catch (ZeroDenominatorException e) {
				System.out.println(e);
			}
		}
		try {
			Fraction res = Fraction.add(fr1, fr2);
			System.out.println(fr1 + " + " + fr2 + " = " + res);
		} catch (ZeroDenominatorException e) {
			System.out.println(e);
		}
		// test subtract, multiply, divide, lessThan methods
		try {
			Fraction res2 = Fraction.subtract(fr1, fr2);
			System.out.println(fr1 + " - " + fr2 + "=  " + res2);
		} catch (ZeroDenominatorException e) {
			System.out.println(e);
		}
		try {
			Fraction res3 = Fraction.multiply(fr1, fr2);
			System.out.println(fr1 + " * " + fr2 + "=  " + res3);
		} catch (ZeroDenominatorException e) {
			System.out.println(e);
		}
		try {
			Fraction res4 = Fraction.divide(fr1, fr2);
			System.out.println(fr1 + " / " + fr2 + "=  " + res4);
		} catch (ZeroDenominatorException e) {
			System.out.println(e);
		}
		boolean res5 = Fraction.lessThan(fr1, fr2);
		if (res5 == true) {
			System.out.println(fr1 + " is less than " + fr2);
		} else {
			System.out.println(fr1 + " is not less than " + fr2);
		}
		// each test has to print a description, a result,
		// and, possibly, a error message if the calculation fails

	}

}
