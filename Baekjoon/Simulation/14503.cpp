// 백준 14503 로봇 청소기

#include <iostream>
#include <queue>

using namespace std;

int N, M, x, y, d, cnt = 0;
int arr[50][50];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main(void) {

	cin >> N >> M >> x >> y >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	bool stop = false;

	while (1) {

		if (!arr[x][y]) {
			arr[x][y] = 2;
			cnt++;
		}

		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;

			int nx = x + dir[d][0];
			int ny = y + dir[d][1];

			if (!arr[nx][ny]) {
				x = nx;
				y = ny;
				break;
			}

			if (i == 3) {
				nx = x - dir[d][0];
				ny = y - dir[d][1];

				if (arr[nx][ny] == 1)
					stop = true;

				x = nx;
				y = ny;
			}
		}

		if (stop)
			break;
	}

	cout << cnt << '\n';

	return 0;
}