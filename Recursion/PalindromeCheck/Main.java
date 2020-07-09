package PalindromeCheck;
import java.util.*;

public class Main {
	
	public static boolean isPalindrome(String num) {
		int start = 0;
		int end = num.length() - 1;
		if(num.length() <= 1)
			return true;
		else if(num.charAt(start) != num.charAt(end))
			return false;
		else
			return isPalindrome(num.substring(start + 1, end));
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String str = sc.next();

		if(isPalindrome(str))
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}