import java.util.*;

public class NegativeNumberException extends Exception
{
	private static final long serialVersionUID = 1L;

	public NegativeNumberException()
	{
		super("Number cannot be negative number");
	}
}
