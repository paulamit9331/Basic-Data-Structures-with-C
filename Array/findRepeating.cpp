#include <bits/stdc++.h>
#include <map>

using namespace std;

int maxElement(int *arr, int n) {
	int max = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

void findDuplicates(int *arr, int n) {
	int max = maxElement(arr, n);

	int *temp = new int[max + 1];
	for (int i = 0; i < n; ++i)
		temp[arr[i]]++;

	for (int i = 0; i < max + 1; ++i) {
		if(temp[i] > 1)
			cout << i << " is occuring " << temp[i] << " times" << endl;
	}
}

void findDuplicates(int* arr, int n) {
	std::map<int, int> map;
	for (int i = 0; i < n; ++i) {
		map.put(pair<int, int> ())
	}
}

int main(int argc, char const *argv[]) {
	int n {0};
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	findDuplicates(arr, n);
	return 0;
}