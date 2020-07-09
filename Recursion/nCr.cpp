#include <bits/stdc++.h>

using namespace std;

float nCr(int n, int r) {
	if(r == 0 || r == n)
		return 1;

	return nCr(n - 1, r - 1) + nCr(n - 1, r);		// nCr = n-1 C r-1 + n-1 C r -> using Pascal's Triangle
}

int main(int argc, char const *argv[]) {
	int n {0}. r {0};
	cin >> n >> r;

	cout << nCr(n, r) << endl;
	return 0;
}