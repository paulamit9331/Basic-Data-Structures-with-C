package ArraySum;
import java.util.*;

public class Main {
	
	public static int arraySum(int[] array, int n) {
		if(n <= 0)
			return 0;
		else
			return (arraySum(array, n - 1) + array[n - 1]);
	}

	public static void main(String[] args) {
		int[] array = new int[] {1, 2, 3, 4, 5};

		System.out.println(arraySum(array, array.length));
	}
}