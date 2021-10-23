#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstring>

// 1949. [모의 SW 역량테스트] 등산로 조성 

using namespace std;

int N, K;
int mount[9][9];
int maxi;
int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
bool visited[9][9];
int ans;

void dfs(int x, int y, int cut, int cnt) {

	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
			continue;

		if (mount[x][y] > mount[nx][ny]) {
			visited[x][y] = true;
			dfs(nx, ny, cut, cnt);
			visited[x][y] = false;
		}
		else {
			if (cut > 0) {
				for (int j = 1; j <= cut; j++) {
					
					if (mount[x][y] > mount[nx][ny] - j) {
						mount[nx][ny] -= j;
						visited[x][y] = true;
						dfs(nx, ny, 0, cnt);
						mount[nx][ny] += j;
						visited[x][y] = false;
					}
					
				}
			}
		}
	}
	
	ans = max(cnt, ans);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(visited, 0, sizeof(visited));
		memset(mount, 0, sizeof(mount));
		maxi = 0;
		ans = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mount[i][j];
				maxi = max(maxi, mount[i][j]);
			}
		}	
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (maxi == mount[i][j]) {
					memset(visited, 0, sizeof(visited));
					dfs(i, j, K, 0);
				}
			}
		}

		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}