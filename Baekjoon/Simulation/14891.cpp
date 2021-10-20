#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int K, num, dir, ans;
string arr[4];
bool visited[4];

void turn(int n, int d) {

	visited[n] = true;

	char two = arr[n][2];
	char six = arr[n][6];
	string temp = "";

	if (d == 1) {
		temp += arr[n][7];
		temp += arr[n].substr(0, 7);
	}
	else if (d == -1) {
		temp += arr[n].substr(1, 7);
		temp += arr[n][0];
	}

	arr[n] = temp;

	if (n + 1 < 4 && two != arr[n + 1][6]) {
		if(!visited[n+1])
			turn(n + 1, -d);
	}

	if (n - 1 >= 0 && six != arr[n - 1][2]) {
		if(!visited[n-1])
			turn(n - 1, -d);
	}
}

int main(void) {

	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	cin >> K;
	
	for (int i = 0; i < K; i++) {
		cin >> num >> dir;

		turn(num - 1, dir);
		memset(visited, 0, sizeof(visited));
	}

	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == '1')
			ans += pow(2, i);
	}

	cout << ans << '\n';

	return 0;
}