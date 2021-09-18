#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int T, A, B;
int visited[10000];
char dir[4] = { 'D', 'S', 'L', 'R' };

int dslr(int cur, char c) {
	int next;

	if (c == 'D')
		next = (cur * 2) % 10000;
	else if (c == 'S')
		cur ? next = cur - 1 : next = 9999;
	else if (c == 'L')
		next = (cur % 1000) * 10 + cur / 1000;
	else
		next = (cur % 10) * 1000 + cur / 10;

	return next;
}

void bfs() {
	queue<pair<int, string>> q;
	visited[A] = 1;
	q.push({ A, "" });

	while (!q.empty()) {
		int cur = q.front().first;
		string ans = q.front().second;
		q.pop();

		if (cur == B) {
			cout << ans << '\n';
			return;
		}

		for (char i = 0; i < 4; i++) {
			int next = dslr(cur, dir[i]);
			if (visited[next] == 1) continue;
			q.push({ next, ans + dir[i] });
			visited[next] = 1;
		}
	}

}

int main(void) {

	cin >> T;

	while (T--) {
		cin >> A >> B;
		memset(visited, 0, sizeof(visited));
		bfs();
	}

	return 0;
}