
// TODO Write class DoubleArithmetics implementing Arithemtics<Double> interface.
public class DoubleArithmetics implements Arithmetics<Double> {

	public Double zero() {
		// TODO Auto-generated method stub
		
		return 0.0;
	}

	public Double add(Double a, Double b) {
		// TODO Auto-generated method stub
		return a + b;
	}

	public Double subtract(Double a, Double b) {
		// TODO Auto-generated method stub
		return a - b;
	}

	public Double multiply(Double a, Double b) {
		// TODO Auto-generated method stub
		return a * b;
	}

	public Double parseString(String str) {
		// TODO Auto-generated method stub
		return Double.valueOf(str);
	}

	public String toString(Double a) {
		// TODO Auto-generated method stub
		return a.toString();
	}
}