#include <bits/stdc++.h>

using namespace std;

float power(int x, int y) {
	if(y == 0)
		return 1;
	
	float temp = power(x, y / 2);
	if(y % 2 == 0)
		return temp * temp;
	
	else {
		if(y > 0)
			return (temp * temp) * x;
		else
			return (temp * temp) / x;
	}
}

int main(int argc, char const *argv[]) {
	float x {0};
	int y {0};
	cin >> x >> y;

	cout << power(x, y) << endl;
	return 0;
}