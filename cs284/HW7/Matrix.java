
import java.util.*;

public class Matrix<T,A extends Arithmetics<T>>
{
	private A 				arithmetics;
	private T[][] 			matrix;
	private int 			rowSize;
	private int 			columnSize;

	@SuppressWarnings({ "unchecked" })
	private void setup( Matrix<T,A> someMatrix, int rows, int columns )
	{
		someMatrix.rowSize 		= rows;
		someMatrix.columnSize 	= columns;		
		someMatrix.matrix 		= (T[][]) new Object[rows][columns];
	}

	private void init( A arithmetics, int rows, int columns )
	{
		this.arithmetics = arithmetics;
		setup(this,rows,columns);
		
		for(int i = 0; i < rowSize; ++i)
		{
			for(int j = 0; j < columnSize; ++j)
			{
				matrix[i][j] = this.arithmetics.zero();
			}
		}
	}
	
	public Matrix( A arithmetics )
	{
        init( arithmetics, 10, 10 );
	}
	
	public Matrix( A arithmetics, int rows, int columns)
	{
        init( arithmetics, rows, columns );
	}

	public void set( Matrix<T,A> right )
	{
		if (this != right) //avoid self copy
		{
			setup(this,right.rowSize,right.columnSize);
			
			for(int i = 0; i < rowSize; ++i)
			{
				for(int j = 0; j < columnSize; ++j)
				{
					matrix[i][j] = right.matrix[i][j];
				}
			}
		}
	}

	public void readMatrix(Scanner inFile)
	{
		for (int i = 0; i < rowSize; i++)
		{
			for (int j = 0; j < columnSize; j++)
				matrix[i][j] = arithmetics.parseString(inFile.next());
		}
	}

	public Matrix<T,A> add(Matrix<T,A> right) throws MatrixException
	{
		Matrix<T,A> temp = new Matrix<T,A>(arithmetics, rowSize, columnSize);

		if (rowSize != right.rowSize || columnSize != right.columnSize)
			throw new MatrixException("Cannot add matrices of different sizes");
	
		setup(temp,rowSize,columnSize);

		for (int i = 0; i < rowSize; ++i) {
			for (int j = 0; j < columnSize; ++j)
				temp.matrix[i][j] = arithmetics.add(matrix[i][j] , right.matrix[i][j]);
		}
		
	 	return temp;
	}
	
	// TODO Implement subtract and multiply methods similar to add method
	
	public Matrix<T,A> subtract(Matrix<T,A> right) throws MatrixException
	{
		Matrix<T,A> temp = new Matrix<T,A>(arithmetics, rowSize, columnSize);

		if (rowSize != right.rowSize || columnSize != right.columnSize)
			throw new MatrixException("Cannot add matrices of different sizes");
	
		setup(temp,rowSize,columnSize);

		for (int i = 0; i < rowSize; ++i) {
			for (int j = 0; j < columnSize; ++j)
				temp.matrix[i][j] = arithmetics.subtract(matrix[i][j] , right.matrix[i][j]);
		}
		
	 	return temp;
	}
	
	public Matrix<T,A> multiply(Matrix<T,A> right) throws MatrixException
	{
		Matrix<T,A> temp = new Matrix<T,A>(arithmetics, rowSize, right.columnSize);

		if (columnSize != right.rowSize)
			throw new MatrixException("Cannot multiply matrices of incompatible sizes");
	
		setup(temp,rowSize,right.columnSize);

		for (int i = 0; i < rowSize; ++i) {
			for (int j = 0; j < right.columnSize; ++j){
				T sum = arithmetics.zero();
				for(int k = 0; k < columnSize; ++k){
					sum =  arithmetics.add(sum, arithmetics.multiply(matrix[i][k] , right.matrix[k][j]));
				}
				temp.matrix[i][j] = sum;
			}
		}
		
	 	return temp;
	}
	
	
	
	
	
	
	
	public String toString()
	{
		String str ="";
		for (int i = 0; i < rowSize; i++)
		{
			for (int j = 0; j < columnSize; j++)
			{
				str+= matrix[i][j] + "\t";
			}
			str+="\n";
		}

		return str;
	}
}
