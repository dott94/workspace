
public interface Arithmetics<T> {

	public T zero();
	public T add( T a, T b );
	public T subtract( T a, T b);
	public T multiply (T a, T b);
	public T parseString( String str );
	public String toString( T a );

}
