#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, L, cnt;
bool board[100][100];
bool visited[100][100];
queue<pair<int, char>> dir;
queue<pair<int, int>> snake;
pair<int, int> cur = { 0, 1 }; // current direction
pair<int, int> pos = { 0, 0 }; // current position

void change_dir(char c) {
	int tmp = cur.first;

	if (c == 'L') {
		if (cur.first == 0) {
			cur.first = -cur.second;
			cur.second = tmp;
		}
		else {
			cur.first = cur.second;
			cur.second = tmp;
		}
	}
	else if (c == 'D') {
		if (cur.first == 0) {
			cur.first = cur.second;
			cur.second = tmp;
		}
		else {
			cur.first = cur.second;
			cur.second = -tmp;
		}
	}
}
int main(void) {

	cin >> N >> K;
	
	int a, b;

	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		visited[a - 1][b - 1] = true;
	}

	cin >> L;

	int sec;
	char direction;

	for (int i = 0; i < L; i++) {
		cin >> sec >> direction;
		dir.push({ sec, direction });
	}

	snake.push({ 0, 0 });

	while (1) {
		cnt++;

		int nx = pos.first + cur.first;
		int ny = pos.second + cur.second;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			break;

		if (board[nx][ny])
			break;

		board[nx][ny] = true;

		if (visited[nx][ny]) {
			snake.push({ nx, ny });
			visited[nx][ny] = false;
		}
		else {
			board[nx][ny] = true;
			snake.push({ nx, ny });
			board[snake.front().first][snake.front().second] = false;
			snake.pop();
		}

		if (!dir.empty() && dir.front().first == cnt) {
			change_dir(dir.front().second);
			dir.pop();
		}

		pos = { nx, ny };
	}

	cout << cnt << '\n';

	return 0;
}