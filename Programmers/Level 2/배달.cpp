#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999

using namespace std;

vector<pair<int, int>> v[51];
int dist[51];

void dijkstra(int start) {

	fill(dist, dist + 51, INF);

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

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i = 0; i < road.size(); i++) {
        int src = road[i][0];
        int dest = road[i][1];
        int val = road[i][2];
        
        v[src].push_back({dest, val});
        v[dest].push_back({src, val});
    }

    dijkstra(1);
    
    for(int i = 1; i <= N; i++) {
        if(dist[i] <= K)
            answer++;
    }
    return answer;
}