#include <iostream>
#include <algorithm>

using namespace std;

int N, a, b, c;
int arr[100000][3];
int max1, max2, max3, min1, min2, min3;

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	int max_arr[3] = { 0 }, min_arr[3] = { 0 };

	for (int i = 0; i < N; i++) {
		max1 = max_arr[0];
		max2 = max_arr[1];
		max3 = max_arr[2];

		min1 = min_arr[0];
		min2 = min_arr[1];
		min3 = min_arr[2];

		max_arr[0] = max(max1, max2) + arr[i][0];
		max_arr[1] = max(max(max1, max2), max3) + arr[i][1];
		max_arr[2] = max(max2, max3) + arr[i][2];

		min_arr[0] = min(min1, min2) + arr[i][0];
		min_arr[1] = min(min(min1, min2), min3) + arr[i][1];
		min_arr[2] = min(min2, min3) + arr[i][2];
	}

	cout << max(max(max_arr[0], max_arr[1]), max_arr[2]);
	cout << ' ' << min(min(min_arr[0], min_arr[1]), min_arr[2]) << '\n';

	return 0;
}