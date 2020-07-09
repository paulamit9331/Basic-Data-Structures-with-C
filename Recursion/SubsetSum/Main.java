package SubsetSum;
import java.util.*;

public class Main {
	
	public static boolean isSubsetPresent(int[] array, int n, int sum) {
		if(sum == 0)
			return true;
		else if(sum != 0 && n == 0)
			return false;
		else
			if(array[n - 1] <= sum)
				return isSubsetPresent(array, n - 1, sum - array[n - 1]) || isSubsetPresent(array, n - 1, sum);
			else
				return isSubsetPresent(array, n - 1, sum);
	}

	public static void main(String[] args) {
		int[] array = new int[] {2, 4, 8, 1};
		int sum = 10;

		if(isSubsetPresent(array, array.length, sum))
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}