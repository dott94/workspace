public class BaseZeroExponentNonpositiveNumberException extends Exception
{
	private static final long serialVersionUID = 1L;

	public BaseZeroExponentNonpositiveNumberException()
	{
		super("base is zero and exponent is nonpositive number");
	}
}
