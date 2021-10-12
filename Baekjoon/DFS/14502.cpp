#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cnt, ans;
vector<vector<int>> board(8, vector<int>(8));
vector<pair<int, int>> pv;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void bfs(vector<vector<int>> check) {

	queue<pair<int, int>> q;

	vector<pair<int, int>> pvv;
	pvv.assign(pv.begin(), pv.end());


	while (!pvv.empty()) {
		q.push(pvv.back());
		pvv.pop_back();
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || check[nx][ny] > 0)
				continue;

			check[nx][ny] = 2;
			q.push({ nx, ny });
		}
	}

	int safe = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j])
				safe++;
		}
	}

	ans = max(ans, safe);

}


void dfs(int wallnum, vector<vector<int>> tmp) {

	if (wallnum == cnt + 3) {
		bfs(tmp);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!tmp[i][j]) {
				tmp[i][j] = 1;
				dfs(wallnum + 1, tmp);
				tmp[i][j] = 0;
			}
		}
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 1)
				cnt++;

			if (board[i][j] == 2)
				pv.push_back({ i, j });
		}
	}

	dfs(cnt, board);

	cout << ans << '\n';

	return 0;
}