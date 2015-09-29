
public interface QueueADT<T>
{
	public void initializeQueue();
	//Method to initialize the queue to an empty state.
	//Postcondition: The queue is intitializes
	
	public boolean isEmptyQueue();
	public boolean isFullQueue();
	public T front() throws QueueUnderflowException;
	public T back() throws QueueUnderflowException;
	public void addQueue(T queueElement) throws QueueOverflowException;
	public void deleteQueue() throws QueueUnderflowException;

}
