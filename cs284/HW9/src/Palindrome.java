import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Palindrome {

	static Scanner console = new Scanner(System.in);
	private String word;
	private Queue<Character> queue;
	private Stack<Character> stack;

	public Palindrome(String word) {
		this.word = word.toLowerCase();
		queue = new LinkedList<Character>();
		stack = new Stack<Character>();
		char[] array = new char[this.word.length()];
		this.word.getChars(0, this.word.length(), array, 0);
		for (int i = 0; i < this.word.length(); i++) {
			queue.add(array[i]);
			stack.push(array[i]);
		}
	}

	public boolean isPalindrome() {
		while (!queue.isEmpty()) {
			System.out.println(stack);
			System.out.println(queue);
			if (!queue.remove().equals(stack.pop()))
				return false;
		}
		return true;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * Write a program that reads a line of text, changes each uppercase
		 * letter to lowercase, and places each letter both in a queue and into
		 * a stack. The program should then verify whether the line of text is a
		 * palindrome (a set of letters or numbers that is the same whether read
		 * forward or backward).
		 */
		System.out.println("Please enter a word");
		String input = console.next();
		Palindrome p = new Palindrome(input);
		if (p.isPalindrome()) {
			System.out.println(input + " is a Palindrome");
		} else {
			System.out.println(input + " is not a Palindrome");
		}
		
	}

}
