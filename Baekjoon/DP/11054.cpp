#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int arr[1000], dp1[1000], dp2[1000];
bool flag;

int main(void) {

	cin >> N;


	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp1[i] = max(dp1[i], dp1[j] + 1);	
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = N - 1; j >= 0; j--) {
			if (arr[j] < arr[i])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}

		ans = max(ans, dp1[i] + dp2[i]);
	}

	cout << ans - 1 << '\n';

	return 0;
}