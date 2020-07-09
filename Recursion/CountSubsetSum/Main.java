package CountSubsetSum;
import java.util.*;

public class Main {
	
	public static int countSubsetSum(int[] array, int n, int sum) {
		if(sum == 0)
			return 1;
		else if(sum != 0 && n == 0)
			return 0;
		else
			if(array[n - 1] <= sum)
				return countSubsetSum(array, n - 1, sum - array[n - 1]) + countSubsetSum(array, n - 1, sum);
			else
				return countSubsetSum(array, n - 1, sum);
	}

	public static void main(String[] args) {
		int[] array = new int[] {2, 3, 5, 6, 8, 10};
		int sum = 10;

		System.out.println(countSubsetSum(array, array.length, sum));
	}
}