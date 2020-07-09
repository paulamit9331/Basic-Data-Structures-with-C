package ReverseArray;
import java.util.*;

public class Main {
	
	public static int[] reverseArray(int[] array, int begin, int end) {
		if(begin >= end)
			return array;
		else {
			int temp = array[begin];
			array[begin] = array[end];
			array[end] = temp;

			return reverseArray(array, begin + 1, end - 1);
		}
	}

	public static void main(String[] args) {
		int[] array = new int[] {1, 2, 3, 4, 5};

		array = reverseArray(array, 0, array.length - 1);

		for(int i : array)
			System.out.print(i + " ");
	}
}