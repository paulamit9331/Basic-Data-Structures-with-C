package ReverseStack;
import java.util.*;

public class Main {
	private static Stack<Integer> stack = new Stack<Integer>();

	public static void insertAtBottom(int n) {
		if(stack.isEmpty())
			stack.push(n);
		else {
			int temp = stack.peek();
			stack.pop();

			insertAtBottom(n);

			stack.push(temp);
		}
	}

	public static void reverseStack() {
		if(stack.isEmpty())
			return;
		else {
			int temp = stack.peek();
			stack.pop();

			reverseStack();

			insertAtBottom(temp);
		}
	}

	public static void main(String[] args) {
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);

		System.out.println("Original Stack : " + stack);

		reverseStack();

		System.out.println("Reversed Stack : " + stack);
	}
}