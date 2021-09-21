#include <iostream>

using namespace std;

int N;
char arr[10000][10000];

void recursive(int n, int r, int c) {
	
	if (n == 3) {
		arr[r][c] = '*';
		arr[r + 1][c - 1] = '*';
		arr[r + 1][c + 1] = '*';
		for (int i = c - 2; i <= c + 2; i++)
			arr[r + 2][i] = '*';

		return;
	}

	recursive(n / 2, r, c);
	recursive(n / 2, r + n / 2, c - n / 2);
	recursive(n / 2, r + n / 2, c + n / 2);
}

int main(void) {

	cin >> N;

	recursive(N, 0, N - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (arr[i][j] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}