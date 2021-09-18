#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N, normal = 0, abnormal = 0;
int visited[100][100] = { 0 };
char color[100][100];
int dir[4][2] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };

void dfs(char c, int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dir[i][0];
		int next_y = y + dir[i][1];

		if (0 <= next_x && N > next_x && 0 <= next_y && N > next_y)
			if (!visited[next_x][next_y] && color[next_x][next_y] == c)
				dfs(c, next_x, next_y);
	}
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> color[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(color[i][j], i, j);
				normal++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (color[i][j] == 'R')
				color[i][j] = 'G';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(color[i][j], i, j);
				abnormal++;
			}
		}
	}

	cout << normal << " " << abnormal << '\n';

	return 0;
}