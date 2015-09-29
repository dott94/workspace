import java.util.*;

public class ZeroDenominatorException extends Exception
{
	private static final long serialVersionUID = 1L;

	public ZeroDenominatorException()
	{
		super("denominator cannot be zero");
	}
}
