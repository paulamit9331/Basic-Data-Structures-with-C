package LCS;
import java.util.*;

public class Main {
	
	public static int LCSLength(String s1, String s2, int m, int n) {
		if(m == 0 || n == 0)		// base case
			return 0;
		else if(s1.charAt(m - 1) == s2.charAt(n - 1))	// if character matches
			return 1 + LCSLength(s1, s2, m - 1, n - 1);
		else
			return Math.max(LCSLength(s1, s2, m - 1, n), LCSLength(s1, s2, m, n - 1));	// if don't match
	}

	public static void main(String[] args) {
		String s1 = "abcdefg";
		String s2 = "abedjrgw";

		System.out.println(LCSLength(s1, s2, s1.length(), s2.length()));
	}
}