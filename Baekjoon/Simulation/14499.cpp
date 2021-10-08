#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, x, y, K;
int map[20][20];
int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
vector<int> command;
pair<int, int> pos;

struct dice {
	int center;
	int left;
	int right;
	int up;
	int down;
	int below;
};

dice d = { 0, 0, 0, 0, 0, 0 };

int main(void) {

	cin >> N >> M >> x >> y >> K;

	pos = { x, y };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int tmp;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		command.push_back(tmp - 1);
	}

	for (int i = 0; i < command.size(); i++) {
		int nx = pos.first + dir[command[i]][0];
		int ny = pos.second + dir[command[i]][1];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;

		pos = { nx, ny };
		
		dice nd;

		switch (command[i]) {
		case 0:
			nd = { d.left, d.below, d.center, d.up, d.down, d.right };
			break;

		case 1:
			nd = { d.right, d.center, d.below, d.up, d.down, d.left };
			break;

		case 2:
			nd = { d.down, d.left, d.right, d.center, d.below, d.up };
			break;

		case 3:
			nd = { d.up, d.left, d.right, d.below, d.center, d.down };
			break;
		}

		if (map[nx][ny]) {
			nd.below = map[nx][ny];
			map[nx][ny] = 0;
		}
		else {
			map[nx][ny] = nd.below;
		}

		d = nd;
		cout << d.center << '\n';
	}

	return 0;
}