#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, ans;
int board[20][20];

void move(int dir) {

	vector<int> line;

	int idx;

	switch (dir) {

	case 0: // left
		for (int i = 0; i < N; i++) {
			idx = 0;
			for (int j = N - 1; j >= 0; j--) {
				if (!board[i][j])
					continue;
				line.push_back(board[i][j]);
				board[i][j] = 0;
			}

			while (!line.empty()) {
				if (!board[i][idx]) {
					board[i][idx] = line.back();
					line.pop_back();
				}
				else if (board[i][idx] == line.back()) {
					board[i][idx] *= 2;
					line.pop_back();
					idx++;
				}
				else {
					idx++;
					board[i][idx] = line.back();
					line.pop_back();
				}
			}
		}
		break;

	case 1: // right
		for (int i = 0; i < N; i++) {
			idx = N - 1;
			for (int j = 0; j < N; j++) {
				if (!board[i][j])
					continue;
				line.push_back(board[i][j]);
				board[i][j] = 0;
			}

			while (!line.empty()) {
				if (!board[i][idx]) {
					board[i][idx] = line.back();
					line.pop_back();
				}
				else if (board[i][idx] == line.back()) {
					board[i][idx] *= 2;
					line.pop_back();
					idx--;
				}
				else {
					idx--;
					board[i][idx] = line.back();
					line.pop_back();
				}
			}
		}
		break;

	case 2: // up
		for (int i = 0; i < N; i++) {
			idx = 0;
			for (int j = N - 1; j >= 0; j--) {
				if (!board[j][i])
					continue;
				line.push_back(board[j][i]);
				board[j][i] = 0;
			}

			while (!line.empty()) {
				if (!board[idx][i]) {
					board[idx][i] = line.back();
					line.pop_back();
				}
				else if (board[idx][i] == line.back()) {
					board[idx][i] *= 2;
					line.pop_back();
					idx++;
				}
				else {
					idx++;
					board[idx][i] = line.back();
					line.pop_back();
				}
			}
		}
		break;

	case 3: // down
		for (int i = 0; i < N; i++) {
			idx = N - 1;
			for (int j = 0; j < N; j++) {
				if (!board[j][i])
					continue;
				line.push_back(board[j][i]);
				board[j][i] = 0;
			}

			while (!line.empty()) {
				if (!board[idx][i]) {
					board[idx][i] = line.back();
					line.pop_back();
				}
				else if (board[idx][i] == line.back()) {
					board[idx][i] *= 2;
					line.pop_back();
					idx--;
				}
				else {
					idx--;
					board[idx][i] = line.back();
					line.pop_back();
				}
			}
		}
		break;

	default:
		break;
	}
}

void dfs(int cnt)
{
	if (cnt == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans = max(ans, board[i][j]);

		return;
	}

	int tempboard[20][20] = { 0 };
	memcpy(tempboard, board, sizeof(board));
	for (int i = 0; i < 4; i++) {
		move(i);
		dfs(cnt + 1);
		memcpy(board, tempboard, sizeof(board));

	}
}



int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	dfs(0);

	cout << ans << '\n';

	return 0;
}
