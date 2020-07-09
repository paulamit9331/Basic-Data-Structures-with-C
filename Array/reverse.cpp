#include <bits/stdc++.h>

using namespace std;

void reverse(int *arr, int low, int high) {
	while(low < high) {
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
		low++;	high--;
	}
}

int main(int argc, char const *argv[]) {
	int n {0};
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	reverse(arr, 0, n - 1);
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl;
	return 0;
}