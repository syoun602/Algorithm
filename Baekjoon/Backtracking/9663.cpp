#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, ans;
int board[15];

bool check(int idx) {

	for (int i = 0; i < idx; i++) {
		if (board[idx] == board[i])
			return false;
		else if(abs(board[idx] - board[i]) == abs(idx-i))
			return false;
	}

	return true;
}
void queen(int idx) {
	
	if (idx == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		board[idx] = i;
		if (check(idx)) {
			queen(idx + 1);
		}
	}

}

int main(void) {

	cin >> N;

	queen(0);

	cout << ans << '\n';

	return 0;
}