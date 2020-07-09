package SortingCheck;
import java.util.*;

public class Main {
	
	public static boolean isSorted(int[] array, int n) {
		if(n <= 1)
			return true;
		else if(array[n - 1] < array[n - 2])
			return false;
		else
			return isSorted(array, n - 1);
	}

	public static void main(String[] args) {
		int[] array = new int[] {1, 4, 3, 4, 5};

		if(isSorted(array, array.length))
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}