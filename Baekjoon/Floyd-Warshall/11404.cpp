#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9
int n, m, a, b, c;
int dist[101][101];

int main(void) {

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}

	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		if (dist[a][b] > c)
			dist[a][b] = c;
	}
		
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF || i == j) dist[i][j] = 0;
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}