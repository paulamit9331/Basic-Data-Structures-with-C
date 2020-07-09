package BinarySearch;
import java.util.*;

public class Main {
	public static int binarySearch(int[] array, int start, int end, int target) {
		if(end < start)
			return -1;
		else {
			int mid = (start + end) / 2;

			if(array[mid] == target)
				return mid;
			else if(array[mid] < target)
				return binarySearch(array, mid + 1, end, target);
			else
				return binarySearch(array, start, mid - 1, target);
		}
	}

	public static void main(String[] args) {
		int[] array = new int[] {1, 3, 4, 5, 9};

		System.out.println(binarySearch(array, 0, array.length - 1, 0));
	}
}