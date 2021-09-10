#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, shark_size = 2, eat = 0, ans = 0;
int start_x, start_y;
int visited[20][20];
int arr[20][20];
int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

struct Fish {
	int x;
	int y;
	int dist;
};

vector<Fish> prey;

bool comp(const Fish& a, const Fish& b) {
	if (a.dist == b.dist) {
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	return a.dist < b.dist;
}

void bfs(int x,int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dir[i][0];
			int ny = cur_y + dir[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			if (arr[nx][ny] <= shark_size && !visited[nx][ny]) {
				visited[nx][ny] = visited[cur_x][cur_y] + 1;
				if (arr[nx][ny] > 0 && arr[nx][ny] < shark_size) {
					Fish f;
					f.x = nx, f.y = ny, f.dist = visited[nx][ny];
					prey.push_back(f);
				}
				q.push({ nx, ny });
			}
		}
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				start_x = i;
				start_y = j;
				arr[i][j] = 0;
			}
		}

	while (1) {
		memset(visited, 0, sizeof(visited));
		prey.clear();
		bfs(start_x, start_y);

		if (!prey.empty()) {
			sort(prey.begin(), prey.end(), comp);
			Fish next = prey[0];
			start_x = next.x;
			start_y = next.y;
			ans += next.dist;
			arr[next.x][next.y] = 0;
			eat++;
			
			if (shark_size == eat) {
				shark_size++;
				eat = 0;
			}
		}
		else
			break;
	}

	cout << ans << '\n';

	return 0;
}