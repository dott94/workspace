import java.util.InputMismatchException;
import java.util.Scanner;

public class PowerMethod {

	static Scanner console = new Scanner(System.in);

	public static void main(String[] args) {
		boolean goodInput = false;
		while (!goodInput) {

			try {
				System.out.println("Please, enter base and exponent");
				double x = getDouble();
				int y = getInt();
				if(x == 0 && y < 1){
					throw new BaseZeroExponentNonpositiveNumberException();	
				}
				goodInput = true;
				double answer = power(x, y);
				System.out.println(x + "^" + y + "=" + answer);
			} catch (InputMismatchException e) {
				System.out.println(e);
			}catch(BaseZeroExponentNonpositiveNumberException e){
				System.out.println(e);
			}
		}
	}

	public static double power(double x, int y) {
		if (x == 0) {
			return 0;
		}
		if (y == 0) {
			return 1;
		}
		if (y == 1) {
			return x;
		}
		if (y > 1) {
			return x * power(x, (y - 1));
		}
		return 1 / (power(x, -y));
	}

	public static int getInt() throws InputMismatchException {

		try {
			return console.nextInt();
		} catch (InputMismatchException e) {
			console.nextLine(); // clears the input
			System.out.println("Exception inside getInt " + e.toString());
			throw new InputMismatchException();
		}
	}

	public static double getDouble() throws InputMismatchException {

		try {
			return console.nextDouble();
		} catch (InputMismatchException e) {
			console.nextLine();
			System.out.println("Exception inside getDouble " + e.toString());
			throw new InputMismatchException();
		}
	}

}
