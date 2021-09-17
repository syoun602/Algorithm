#include <iostream>
#include <string>
#include <algorithm>

#define MAX 110

using namespace std;

int N, M;
string dp[MAX][MAX];

string calcSum(string a, string b) {

	if (a.size() < b.size())
		swap(a, b);
		
	string temp = "";
	int carry = 0;

	while (a.size() != 0) {

		int a_num = a.back() - '0';
		int b_num = b.empty() ? 0 : b.back() - '0';
		int remainder = (a_num + b_num + carry) % 10;
		carry = (a_num + b_num + carry) / 10;
		temp = char(remainder + '0') + temp;

		a.pop_back();
		if(!b.empty()) b.pop_back();
	}

	if (carry)
		temp = (char)(carry + '0') + temp;

	return temp;
}

void calcDP(int n) {
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i-1; j++)
			dp[i][j] = calcSum(dp[i-1][j-1], dp[i-1][j]);
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i < MAX; i++) {
		dp[i][0] = "1";
		dp[i][i] = "1";
		for (int j = 1; j < i; j++) {
			dp[i][j] = "0";
		}
	}

	calcDP(N);

	cout << dp[N][M] << '\n';

	return 0;
}