#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M, ans;
int arr[100][100];
bool outer[100][100];
vector<pair<int, int>> v;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int check(int a, int b) {

	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nx = a + dir[i][0];
		int ny = b + dir[i][1];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;

		if (outer[nx][ny])
			cnt++;

		if (cnt >= 2)
			return 1;
	}

	return 0;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		outer[cur.first][cur.second] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dir[i][0];
			int ny = cur.second + dir[i][1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || outer[nx][ny])
				continue;

			if (!arr[nx][ny]) {
				outer[nx][ny] = true;
				q.push({ nx, ny });
			}
		}

	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				v.push_back({ i, j });
		}
	}

	vector<pair<int, int>> temp;
	vector<pair<int, int>> del;

	while (1) {
		del.clear();
		temp.clear();
		memset(outer, false, sizeof(outer));

		bfs();

		while (!v.empty()) {
			pair<int, int> p = v.back();
			v.pop_back();

			if (check(p.first, p.second))
				del.push_back({ p.first, p.second });
			else
				temp.push_back({ p.first, p.second });
		}

		for (int i = 0; i < del.size(); i++)
			arr[del[i].first][del[i].second] = 0;

		v = temp;
		ans++;
		
		if (v.empty())
			break;
	}

	cout << ans << '\n';
	return 0;
}