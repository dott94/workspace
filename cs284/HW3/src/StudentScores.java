import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;

public class StudentScores {
	public static void main(String[] args) throws FileNotFoundException {

		Scanner inFile = new Scanner(new FileReader("in.txt"));
		PrintWriter outFile = new PrintWriter("outArray.txt");
		// something meaningful
		double classAverage;
		final int maxSize = 50;
		String[] students = new String[maxSize];
		double[] scores = new double[maxSize];

		int i = 0;
		while (inFile.hasNext()) {
			students[i] = inFile.next();
			scores[i] = inFile.nextDouble();
			i++;
			if (i >= maxSize)
				break;
		}
		int numberOfStudents = i;
		double sum = 0;
		for (int j = 0; j < numberOfStudents; j++) {
			sum += scores[j];
		}
		classAverage = sum / numberOfStudents;
		System.out.printf("class average = %5.2f %n", classAverage);
		outFile.printf("class average = %5.2f %n", classAverage);
		for (int j = 0; j < numberOfStudents; j++) {
			if (scores[j] < classAverage) {
				System.out.println("Student " + students[j] + " has score "
						+ scores[j] + " that is less than average");
				outFile.println("Student " + students[j] + " has score "
						+ scores[j] + " that is less than average");
			}
		}
		// find highest score
		double highestScore = 0.0;
		for (int j = 0; j < numberOfStudents; j++) {
			if (scores[j] > highestScore) {
				highestScore = scores[j];
			}
		}
		System.out.printf("highest score = %5.2f %n", highestScore);
		outFile.printf("highest score = %5.2f %n", highestScore);
		inFile.close();
		outFile.close();
		//

		// ToDo
		// implement program using Vector instead of array
		//
		Vector<Double> scoreV = new Vector<Double>();
		Vector<String> studentsV = new Vector<String>();

		Scanner inFileV = new Scanner(new FileReader("in.txt"));
		PrintWriter outFileV = new PrintWriter("outArray.txt");

		while (inFileV.hasNext()) {
			studentsV.add(inFileV.next());
			scoreV.add(inFileV.nextDouble());
		}
		int numberOfStudentsV = studentsV.size();
		double sumV = 0;
		for (int j = 0; j < numberOfStudentsV; j++) {
			sumV += scoreV.elementAt(j);
		}

		classAverage = sumV / numberOfStudentsV;
		System.out.printf("class average = %5.2f %n", classAverage);
		outFileV.printf("class average = %5.2f %n", classAverage);
		for (int j = 0; j < numberOfStudentsV; j++) {
			double score = scoreV.elementAt(j);
			String student = studentsV.elementAt(j);
			if (score < classAverage) {
				System.out.println("Student " + student + " has score "
						+ score + " that is less than average");
				outFileV.println("Student " + student + " has score "
						+ score + " that is less than average");
			}
		}
		double highestScoreV = 0.0;
		for (int j = 0; j < numberOfStudentsV; j++) {
			if (scoreV.elementAt(j) > highestScoreV) {
				highestScoreV = scoreV.elementAt(j);
			}
		}
		System.out.printf("highest score = %5.2f %n", highestScoreV);
		outFileV.printf("highest score = %5.2f %n", highestScoreV);
		inFileV.close();
		outFileV.close();
	}
}
