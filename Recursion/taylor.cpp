#include <bits/stdc++.h>

using namespace std;

float expRec(int x, int n) {
	static float s = 1;

	if(n == 0)
		return 1;
	
	s = 1 + x / n * s;
	return exp(x, n - 1);
}

float expLoop(int x, int n) {
	float s = 1;
	
	while(n--)
		s = 1 + x / n * s;

	return s;
}

int main(int argc, char const *argv[]) {
	int x {0}, n {0};
	cin >> x >> n;

	cout << expRec(x, n) << endl;
	//cout << expLoop(x, n) << endl;
	
	return 0;
}