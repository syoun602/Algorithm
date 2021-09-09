#include <iostream>
#include <vector>
#include <cstring>

#define INF 10000001

using namespace std;

int TC, N, M, W, S, E, T;
vector<pair<int, int>> v[510];
int dist[510];

void Bellmanford() {
	dist[1] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto it : v[j]) {
				if (dist[it.first] > dist[j] + it.second) {
					dist[it.first] = dist[j] + it.second;
					if (i == N - 1) {
						cout << "YES" << '\n';
						return;
					}
				}
			}
		}
	}

	cout << "NO" << '\n';
	return;
}
int main(void) {

	cin >> TC;

	while (TC--) {
		cin >> N >> M >> W;

		for (int i = 0; i <= N; i++)
			v[i].clear();

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			v[S].push_back({ E, T });
			v[E].push_back({ S, T });
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			v[S].push_back({ E, -T });
		}

		fill(dist, dist + 510, INF);

		Bellmanford();
	}

	return 0;
}