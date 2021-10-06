#include <iostream>
#include <vector>

using namespace std;

double N, B, C, num;
long long ans;
vector<double> room;

double ceil_num (double n)
{
	int r = (int)n;

	if (n < 0 || n == (double)r)
		return r;
	else
		return r + 1;
}


int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		room.push_back(num);
	}
	
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		ans++;

		if ((room[i] - B) > 0)
			ans += ceil_num((room[i] - B) / C);
	}

	cout << ans << '\n';

	return 0;
}