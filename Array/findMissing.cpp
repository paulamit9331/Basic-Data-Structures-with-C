#include <bits/stdc++.h>

using namespace std;

int findSingleMissing(int *arr, int n) {
	int diff = arr[0] - 0;
	for (int i = 0; i < n; ++i)
		if(diff != arr[i] - i)
			return diff + i;

	return -1;
}
/*
void findMultipleMissing(int *arr, int n) {		// space optimized
	int diff = arr[0] - 0;
	for (int i = 0; i < n; ++i) {
		if(diff != arr[i] - i) {
			while(diff < arr[i] - i) {
				cout << diff + i << " ";
				diff++;
			}
		}
	}
	cout << endl;
}

void findMultipleMissing(int *arr, int n) {			// time optimized
	int min = INT_MAX;
	int max = INT_MIN;
	for(int i = 0; i < n; i++) {
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}

	int *temp = new int[max];
	for (int i = 0; i < n; ++i)
		temp[arr[i]]++;

	for(int i = min; i < max; i++) {
		if(temp[i] == 0)
			cout << i << " ";
	}
	cout << endl;
}*/

int main(int argc, char const *argv[]) {
	int n {0};
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	// cout << findSingleMissing(arr, n) << endl;
	// findMultipleMissing(arr, n);
	return 0;
}
