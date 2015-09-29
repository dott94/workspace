public class QueueOverflowException extends QueueException
{
	public QueueOverflowException()
	{
		super("Queue Overflows");
	}
	public QueueOverflowException(String msg)
	{super(msg);}
}
