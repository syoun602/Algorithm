#include <iostream>
#include <queue>

using namespace std;

int N, M;
int board[500][500];
int ans = 0;

vector<pair<int, int>> cur;
vector<vector<pair<int, int>>> shapes =
{ {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
{{0, 0}, {1, 0}, {2, 0}, {3, 0}},

{{0, 0}, {0, 1}, {1, 0}, {1, 1}},

{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
{{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
{{0, 0}, {1, 0}, {0, 1}, {0, 2}},

{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
{{0, 0}, {1, 0}, {2, 0}, {0, 1}},
{{0, 0}, {0, 1}, {0, 2}, {1, 2}},

{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},

{{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
{{0, 0}, {0, 1}, {1, 1}, {1, 2}},

{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
{{0, 0}, {0, 1}, {1, 1}, {-1, 1}},
{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
{{0, 0}, {1, 0}, {2, 0}, {1, 1}} };


void find_sum(int x, int y) {

	for (int i = 0; i < shapes.size(); i++) {
		cur = shapes[i];
		bool flag = true;
		int total = 0;

		for (int j = 0; j < cur.size(); j++) {
			int nx = x + cur[j].first;
			int ny = y + cur[j].second;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				flag = false;
				break;
			}

			total += board[nx][ny];
		}

		if (flag && total > ans)
			ans = total;
	}
}


int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			find_sum(i, j);
		}
	}

	cout << ans << '\n';

	return 0;
}