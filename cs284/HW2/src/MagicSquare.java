import java.util.*;

public class MagicSquare 
{
	static final int rows = 4;
	static final int columns = 4;
	static final int listSize = 16;
	static int row, col, temp;
	static Scanner console = new Scanner (System.in);
	
	public static void createArithmeticSeq(int [] list)
	{   
		int first; 
		int diff;
		System.out.println("Enter first and diff : ");
		first = console.nextInt();
		diff  = console.nextInt();
		for (int i=0; i<listSize;i++)
		{
			list[i]=first+i*diff;
		}
	}
	
	public static void matricize (int [] list, int [][] matrix)
	{
		int i = 0;
		for (row=0; row<matrix.length; row++) 
		{
			for(col=0; col<matrix[row].length; col++) {
			matrix[row][col] = list[i++];
		}
	}
	}
	
	public static void printMatrix(int[][] matrix)
	{
		for(row=0; row<matrix.length; row++)
		{
			for(col=0; col<matrix[row].length; col++)
				System.out.print("\t" + matrix[row][col]);
			System.out.println();
				
		}
	}
	
	public static void reverseDiagonal(int [] [] matrix)
	{
		for(row=0; row<matrix.length/2; row++)
		{
			temp=matrix[row][row];
			matrix[row][row]= matrix[matrix.length-1-row][matrix.length-1-row];
			matrix[matrix.length-1-row][matrix.length-1-row]=temp;
		}
		for(row=0; row<matrix.length/2; row++)
		{
			temp=matrix[row][matrix.length-1-row];
			matrix[row][matrix.length-1-row]= matrix[matrix.length-1-row][row];
			matrix[matrix.length-1-row][row]=temp;
		}
	}
	
	public static int sumRow(int [] [] matrix, int row){
		int result = 0;
		for( int i = 0; i < matrix.length; i++){
			result = result + matrix[row][i];
		}
		return result;
	}
	
	public static int sumColumn(int [] [] matrix, int column){
		int result = 0;
		for( int i = 0; i < matrix.length; i++){
			result = result + matrix[i][column];
		}
		return result;	
	}
	
	public static int sumDiag1(int [] [] matrix){
		int result = 0;
		for( int i = 0; i < matrix.length; i++){
			result = result + matrix[i][i];
		}
		return result;	
	}
	
	public static int sumDiag2(int [] [] matrix){
		int result = 0;
		for( int i = matrix.length - 1; i >= 0; i--){
			result = result + matrix[i][matrix.length - 1 - i];
		}
		return result;	
	}
	
	public static int magicNumArray(int [] list){
		int result = 0;
		for( int i = 0; i < list.length; i++){
			result = result + list[i];
		}
		return result / 4;	
	}
	
		
	
	public static void magicCheck(int [] list, int [] [] matrix)
	{
		int magicNumber=0;
		
		magicNumber = magicNumArray(list);
		boolean isMagicNumber = true;
		for(int i = 0; i < matrix.length; i++){
			if(sumRow(matrix,i) != magicNumber || sumColumn(matrix, i) != magicNumber){
				isMagicNumber = false;
			}
		}		
		if( sumDiag1(matrix) != magicNumber || sumDiag2(matrix) != magicNumber){
			isMagicNumber = false;
		}
		
		if(isMagicNumber){
			System.out.println("it is a magicsquare" + " " +  magicNumber);
		}else{
			System.out.println("it is not a magicsquare");
		}
		
	}
		
		
	
				
	public static void main (String [] args)
	{
		int [] list = new int [listSize];
		createArithmeticSeq (list);
		int [] [] matrix = new int [rows] [columns];
		matricize(list, matrix);
		printMatrix(matrix);
		System.out.println("reverse diagonal");
		reverseDiagonal(matrix);
		printMatrix(matrix);
		magicCheck(list, matrix);
	}
}
