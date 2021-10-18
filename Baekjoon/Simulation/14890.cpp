#include <iostream>

using namespace std;

int N, L, ans;
int map[100][100];

int main(void) {

	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	

	for (int i = 0; i < N; i++) {
		int prev = map[i][0];
		int cnt = 1;

		for (int j = 1; j < N; j++) {
			int cur = map[i][j];

			if (prev == cur) {
				cnt++;
			}
			else if (prev - cur == 1 && cnt >= 0) {
				cnt = 1 - L;
			}
			else if(prev - cur == -1 && cnt >= L) {
				cnt = 1;
			}
			else {
				cnt = -1;
				break;
			}
			prev = cur;
		}

		if (cnt >= 0)
			ans++;
	}
	
	for (int i = 0; i < N; i++) {
		int prev = map[0][i];
		int cnt = 1;

		for (int j = 1; j < N; j++) {
			int cur = map[j][i];

			if (prev == cur) {
				cnt++;
			}
			else if (prev - cur == 1 && cnt >= 0) {
				cnt = 1 - L;
			}
			else if (prev - cur == -1 && cnt >= L) {
				cnt = 1;
			}
			else {
				cnt = -1;
				break;
			}
			prev = cur;
		}

		if (cnt >= 0)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}