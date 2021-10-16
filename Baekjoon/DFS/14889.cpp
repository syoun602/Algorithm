#include <iostream>
#include <vector>

using namespace std;

int N, ans = 1e9;
int arr[20][20];
int visited[20];

void solve() {
	
	int start = 0, link = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (visited[i] && visited[j])
				start += arr[i][j] + arr[j][i];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!visited[i] && !visited[j])
				link += arr[i][j] + arr[j][i];
		}
	}

	ans = min(ans, abs(start - link));
}

void dfs(int start, int depth) {

	if (depth == N / 2)
		solve();

	for (int i = start; i < N; i++) {

		if (visited[i])
			continue;

		visited[i] = 1;
		dfs(i + 1, depth + 1);
		visited[i] = 0;
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0);

	cout << ans << '\n';

	return 0;
}