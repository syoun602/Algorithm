#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, tmp, maxi = -1e9, mini = 1e9;
int num[11];
char op[4] = { '+', '-', '*', '/' };
vector<char> v;

int operation(int a, int b, char c) {
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else if (c == '*') 
		return a * b;
	else if (c == '/')
		return a / b;
}

void solve(vector<char> list) {

	int cur = num[0];

	for (int i = 0; i < list.size(); i++)
		cur = operation(cur, num[i + 1], v[i]);

	maxi = max(maxi, cur);
	mini = min(mini, cur);
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp; j++)
			v.push_back(op[i]);
	}
	
	sort(v.begin(), v.end());

	do {
		solve(v);
	} while (next_permutation(v.begin(), v.end()));

	cout << maxi << '\n' << mini << '\n';

	return 0;
}