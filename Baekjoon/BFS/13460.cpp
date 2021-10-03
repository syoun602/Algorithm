#include <iostream>
#include <queue>

using namespace std;

int N, M;
char board[10][10];
bool visited[10][10][10][10];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

struct idx {
	int x;
	int y;
};

idx r, b;

int bfs() {

	queue<pair<pair<idx, idx>, int>> q;

	q.push({ { r, b }, 0 } );

	while (!q.empty()) {
		idx cur_r = q.front().first.first;
		idx cur_b = q.front().first.second;
		int cnt = q.front().second;

	visited[cur_r.x][cur_r.y][cur_b.x][cur_b.y] = true;
		q.pop();

		if (cnt > 10)
			return -1;

		if ((board[cur_r.x][cur_r.y] == 'O') && (board[cur_b.x][cur_b.y] != 'O'))
			return cnt;
		

		for (int i = 0; i < 4; i++) {
			int next_rx = cur_r.x;
			int next_ry = cur_r.y;
			int next_bx = cur_b.x;
			int next_by = cur_b.y;
			int next_cnt = cnt + 1;

			int red_move = 0, blue_move = 0;

			while (board[next_rx + dir[i][0]][next_ry + dir[i][1]] != '#') {
				next_rx += dir[i][0];
				next_ry += dir[i][1];
				red_move++;
				if (board[next_rx][next_ry] == 'O')
					break;
			}

			while (board[next_bx + dir[i][0]][next_by + dir[i][1]] != '#') {
				next_bx += dir[i][0];
				next_by += dir[i][1];
				blue_move++;
				if (board[next_bx][next_by] == 'O')
					break;
			}

			if (next_rx == next_bx && next_ry == next_by) {
				if (board[next_rx][next_ry] == 'O')
					continue;

				if (red_move > blue_move) {
					next_rx -= dir[i][0];
					next_ry -= dir[i][1];
				}
				else {
					next_bx -= dir[i][0];
					next_by -= dir[i][1];
				}
			}
			else if (board[next_bx][next_by] == 'O')
				continue;

			if (visited[next_rx][next_ry][next_bx][next_by])
				continue;

			q.push({ { {next_rx, next_ry}, {next_bx, next_by} }, next_cnt } );
		}
	}
	return -1;
	
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				r = { i, j };
			}
			else if (board[i][j] == 'B') {
				b = { i, j };
			}
		}

	cout << bfs() << '\n';

	return 0;
}