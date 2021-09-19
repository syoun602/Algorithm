#include <iostream>
#include <queue>

using namespace std;

int N, M, ans;
int arr[1001][1001];
int visited[1001][1001][2];
int dir[4][2] = { {0, 1}, {0, -1}, {1,0}, {-1,0} };
bool flag = false;

void bfs() {

	visited[0][0][0] = 1;
	queue<pair<pair<int, int>, bool>> q;

	q.push({ {0, 0}, false });

	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int curs = q.front().second;

		q.pop();
		
		if (curx == N - 1 && cury == M - 1) {
			if (curs)
				flag = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curx + dir[i][0];
			int ny = cury + dir[i][1];

			if (nx >= N || nx < 0 || ny >= M || ny < 0)
				continue;

			if (!arr[nx][ny] && !visited[nx][ny][0] && !curs) {
				visited[nx][ny][0] = visited[curx][cury][0] + 1;
				q.push({ {nx, ny}, false });
			}
			else if(arr[nx][ny] && !curs) {
				visited[nx][ny][1] = visited[curx][cury][0] + 1;
				q.push({ {nx, ny}, true });
			}
			else if (!arr[nx][ny] && curs && !visited[nx][ny][1]) {
				visited[nx][ny][1] = visited[curx][cury][1] + 1;
				q.push({ {nx, ny}, true });
			}
		}
	}
}

int main(void) {

	cin >> N >> M;

	if (N < 1 || M < 1)
		return 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &arr[i][j]);

	bfs();

	if (!visited[N - 1][M - 1][0] && !visited[N - 1][M - 1][1])
		cout << -1 << '\n';
	else {
		if(flag)
			cout << visited[N - 1][M - 1][1] << '\n';
		else
			cout << visited[N - 1][M - 1][0] << '\n';
	}
	
	return 0;
}