package KnapsackProblem;
import java.util.*;
import java.math.*;

public class Main {
	
	public static int knapsack(int[] wt, int[] val, int w, int n) {
		if(n == 0 || w == 0)
			return 0;
		if(wt[n - 1] <= w)		// if we choose										// if we don't choose
			return Math.max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
		else
			return knapsack(wt, val, w, n - 1);		// wt[n - 1] > w    so we can't choose
	}

	public static void main(String[] args) {
		int[] wt = new int[] {1, 3, 4, 5};
		int[] val = new int[] {1, 4, 5, 7};
		int w = 10;

		System.out.println(knapsack(wt, val, w, wt.length));
	}
}