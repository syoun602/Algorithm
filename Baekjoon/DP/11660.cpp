#include <iostream>

using namespace std;

int N, M;
int dp[1025][1025];
int x, y, nx, ny;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dp[i][j];

			dp[i][j] += dp[i][j - 1];
		}
	}

	for (int i = 0; i < M; i++) {

		cin >> x >> y >> nx >> ny;

		int ans = 0;

		for (int j = x; j <= nx; j++)
			ans += (dp[j][ny] - dp[j][y - 1]);

		cout << ans << '\n';
	}

	return 0;
}