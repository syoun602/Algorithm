#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999

using namespace std;

int N, M, A, B, X;
vector<pair<int, int>> v[1001];
int dist[1001];

void dijkstra(int start) {

	fill(dist, dist + N + 1, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (dist[cur] < curDist)
			continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextDist = v[cur][i].second;

			if (curDist + nextDist < dist[next]) {
				dist[next] = curDist + nextDist;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main(void) {

	cin >> N >> M;
	
	while (M--) {
		cin >> A >> B >> X;
		v[A].push_back({ B, X });
	}

	cin >> A >> B;

	dijkstra(A);

	cout << dist[B] << '\n';

	return 0;
}