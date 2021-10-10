#include <iostream>
#include <deque>

using namespace std;

int N, d, k, c, ans, cnt = 0;
int sushi[3000000];
int type[3001];
deque<int> dq;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) 
		cin >> sushi[i];
	
	for (int i = 0; i < k; i++) {
		dq.push_back(sushi[i]);
		
		if (!type[sushi[i]])
			cnt++;

		type[sushi[i]]++;
	}

	ans = cnt;

	for (int i = k; i < N + k - 1; i++) {
		
		if (!(--type[dq.front()]))
			cnt--;

		dq.pop_front();
		dq.push_back(sushi[i % N]);
		
		if (!(type[sushi[i % N]]++))
			cnt++;

		if (!type[c])
			ans = max(ans, cnt + 1);
		else
			ans = max(ans, cnt);
	}

	cout << ans << '\n';

	return 0;
}