package SelectionSort;
import java.util.*;

public class Main {
	
	public static int[] selectionSort(int[] array, int n) {
		if(n <= 1)
			return array;
		else {
			int max = Integer.MIN_VALUE;
			int maxIndex = -1;
			for(int i = 0; i < n; i++) {
				if(array[i] > max) {
					max = array[i];
					maxIndex = i;
				}
			}
			int temp = array[maxIndex];
			array[maxIndex] = array[n - 1];
			array[n - 1] = temp;

			return selectionSort(array, n - 1);
		}
	}

	public static void main(String[] args) {
		int[] array = new int[] {5, 9, 0, -3, -6, 10};

		array = selectionSort(array, array.length);
		for(int i : array)
			System.out.print(i + " ");
	}
}