
import java.io.*;
import java.util.Scanner;

public class DriverMatrix 
{
		
	static private IntegerArithmetics integerArithemtics = new IntegerArithmetics();
	static private DoubleArithmetics doubleArithmetics = new DoubleArithmetics();
	public static void main(String[] args)
			         throws FileNotFoundException
	{
		Scanner inFile = new Scanner (new FileReader("in.txt"));
		PrintWriter outFile = new PrintWriter("out.txt");
		
		Matrix<Integer,IntegerArithmetics> matrix1 = new Matrix<Integer,IntegerArithmetics>(integerArithemtics,2,3);
		Matrix<Integer,IntegerArithmetics> matrix2 = new Matrix<Integer,IntegerArithmetics>(integerArithemtics,2,3);
		Matrix<Integer,IntegerArithmetics> matrix3 = new Matrix<Integer,IntegerArithmetics>(integerArithemtics,2,3);
		Matrix<Integer,IntegerArithmetics> matrix4 = new Matrix<Integer,IntegerArithmetics>(integerArithemtics,2,3);
		Matrix<Integer,IntegerArithmetics> matrix5 = new Matrix<Integer,IntegerArithmetics>(integerArithemtics,3,2);
		Matrix<Integer,IntegerArithmetics> matrix6 = new Matrix<Integer,IntegerArithmetics>(integerArithemtics,2,2);
	       
		String matrixName1=inFile.next();      
		matrix1.readMatrix(inFile);
		outFile.println(matrixName1);
		System.out.println(matrixName1);
		outFile.println(matrix1);
		System.out.println(matrix1);
	
		String matrixName2=inFile.next();
		matrix2.readMatrix(inFile);
		outFile.println(matrixName2);
		System.out.println(matrixName2);
		outFile.println(matrix2);
		System.out.println(matrix2);
		
		String matrixName4=inFile.next();
		matrix4.readMatrix(inFile);
		outFile.println(matrixName4);
		System.out.println(matrixName4);
		outFile.println(matrix4);
		System.out.println(matrix4);
		
		String matrixName5=inFile.next();
		matrix5.readMatrix(inFile);
		outFile.println(matrixName5);
		System.out.println(matrixName5);
		outFile.println(matrix5);
		System.out.println(matrix5);
        
		
		Matrix<Double,DoubleArithmetics> matrix7 = new Matrix<Double,DoubleArithmetics>(doubleArithmetics,2,3);
		Matrix<Double,DoubleArithmetics> matrix8 = new Matrix<Double,DoubleArithmetics>(doubleArithmetics,2,3);
		Matrix<Double,DoubleArithmetics> matrix9 = new Matrix<Double,DoubleArithmetics>(doubleArithmetics,2,3);	
		Matrix<Double,DoubleArithmetics> matrix10 = new Matrix<Double,DoubleArithmetics>(doubleArithmetics,3,2);	       
		Matrix<Double,DoubleArithmetics> matrix11 = new Matrix<Double,DoubleArithmetics>(doubleArithmetics,2,3);
		Matrix<Double,DoubleArithmetics> matrix12 = new Matrix<Double,DoubleArithmetics>(doubleArithmetics,2,3);
		Matrix<Double,DoubleArithmetics> matrix13 = new Matrix<Double,DoubleArithmetics>(doubleArithmetics,2,2);
		
		
		String matrixName7=inFile.next();
		matrix7.readMatrix(inFile);
		outFile.println(matrixName7);
		System.out.println(matrixName7);
		outFile.println(matrix7);
		System.out.println(matrix7);
		
		String matrixName8=inFile.next();
		matrix8.readMatrix(inFile);
		outFile.println(matrixName8);
		System.out.println(matrixName8);
		outFile.println(matrix8);
		System.out.println(matrix8);
		
		String matrixName9=inFile.next();
		matrix9.readMatrix(inFile);
		outFile.println(matrixName9);
		System.out.println(matrixName9);
		outFile.println(matrix9);
		System.out.println(matrix9);
		
		String matrixName10=inFile.next();
		matrix10.readMatrix(inFile);
		outFile.println(matrixName10);
		System.out.println(matrixName10);
		outFile.println(matrix10);
		System.out.println(matrix10);
		try {
			
			matrix3 = matrix1.add(matrix2);
			System.out.println(matrixName1+" add "+matrixName2);
			outFile.println(matrixName1+" add "+matrixName2);
			System.out.println(matrix3);
			outFile.println(matrix3);
			
			matrix3 = matrix1.subtract(matrix4);
			System.out.println(matrixName1+" subtract "+matrixName4);
			outFile.println(matrixName1+" subtract "+matrixName4);
			System.out.println(matrix3);
			outFile.println(matrix3);
			
			matrix6 = matrix1.multiply(matrix5);
			System.out.println(matrixName1+" multiply "+matrixName5);
			outFile.println(matrixName1+" multiply "+matrixName5);
			System.out.println(matrix6);
			outFile.println(matrix6);
			
			matrix11 = matrix7.add(matrix8);
			System.out.println(matrixName7+" add "+matrixName8);
			outFile.println(matrixName7+" add "+matrixName8);
			System.out.println(matrix11);
			outFile.println(matrix11);
			
			matrix12 = matrix7.subtract(matrix8);
			System.out.println(matrixName7+" subtract "+matrixName8);
			outFile.println(matrixName7+" subtract "+matrixName8);
			System.out.println(matrix12);
			outFile.println(matrix12);
			
			matrix13 = matrix7.multiply(matrix10);
			System.out.println(matrixName7+" multiply "+matrixName10);
			outFile.println(matrixName7+" multiply "+matrixName10);
			System.out.println(matrix13);
			outFile.println(matrix13);
		
		} catch ( MatrixException exception ) {

			System.out.println(exception);
		}
		
		
		inFile.close();
		outFile.close();
	}
}