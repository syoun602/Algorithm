#include <iostream>

using namespace std;

int arr[1000001];
int N, K;
long long sum, ans;

int main(void) {

	cin >> N >> K;
	int mass, coord;

	for (int i = 0; i < N; i++) {
		cin >> mass >> coord;
		arr[coord] = mass;
	}

	K = K * 2 + 1;

	for (int i = 0; i <= 1000000; i++) {
		if (i < K)
			sum += arr[i];
		else
			sum = sum + arr[i] - arr[i - K];

		ans = max(ans, sum);
	}

	cout << ans << '\n';

	return 0;
}