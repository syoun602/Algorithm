#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
string arr[64];

void solve(int size, int x, int y) {

	char cur = arr[x][y];
	bool flag = true;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (cur != arr[i][j])
				flag = false;
		}
	}

	if (flag) {
		cout << cur;
		return;
	}
	else {
		cout << '(';
		solve(size / 2, x, y);
		solve(size / 2, x, y + (size / 2));
		solve(size / 2, x + (size / 2), y);
		solve(size / 2, x + (size / 2), y + (size / 2));
		cout << ')';
	}

}
int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	solve(N, 0, 0);

	return 0;
}