#include <iostream>

using namespace std;

int N, K, B, tmp, cnt;
int ans = 100000;
int light[100000];

int main(void) {

	cin >> N >> K >> B;

	for (int i = 0; i < B; i++) {
		cin >> tmp;
		light[tmp - 1] = 1;
	}

	for (int i = 0; i < K; i++) {
		if (light[i])
			cnt++;
	}


	for (int i = K; i < N; i++ ) {
		if (light[i])
			cnt++;

		if (light[i - K])
			cnt--;
		
		ans = min(ans, cnt);
	}

	cout << ans << '\n';

 	return 0;
}