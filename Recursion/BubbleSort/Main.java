package BubbleSort;
import java.util.*;

public class Main {
	
	public static int[] bubbleSort(int[] array, int n) {
		if(n == 1)
			return array;
		else {
			for(int i = 0; i < n - 1; i++) {
				if(array[i] > array[i + 1]) {
					int temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
				}
			}
			return bubbleSort(array, n - 1);
		}
	}

	public static void main(String[] args) {
		int[] array = new int[] {5, 9, 0, -3, -6, 10};

		array = bubbleSort(array, array.length);
		for(int i : array)
			System.out.print(i + " ");
	}
}