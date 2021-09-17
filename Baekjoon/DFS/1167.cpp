#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, a, b, d, ans, dest;
vector<pair<int, int>> tree[100001];
bool visited[100001];

void dfs(int node, int radius) {
	visited[node] = true;

	for (int i = 0; i < tree[node].size(); i++) {
		int nxtnode = tree[node][i].first;
		int nxtr = tree[node][i].second;

		if (visited[nxtnode]) {
			if (radius > ans) {
				ans = radius;
				dest = node;
			}
			continue;
		}
		dfs(nxtnode, radius + nxtr);
	}
}


int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1)
				break;
			cin >> d;
			tree[a].push_back({ b, d });
		}
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(dest, 0);

	cout << ans << '\n';

	return 0;
}