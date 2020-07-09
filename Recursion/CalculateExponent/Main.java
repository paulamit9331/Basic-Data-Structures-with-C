package CalculateExponent;
import java.util.*;

public class Main {
	
	public static int power(int x, int n) {
		if(n == 0)
			return 1;
		else if(n == 1)
			return x;
		else if(n % 2 == 0)
			return power(x, n / 2) * power(x, n / 2);
		else
			return x * power(x, n / 2) * power(x, n / 2);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.println(power(sc.nextInt(), sc.nextInt()));
	}
}