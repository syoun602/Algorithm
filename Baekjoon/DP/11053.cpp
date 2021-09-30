#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int arr[1000], dp[1000];

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	

	for (int i = 0; i < N; i++) {
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}