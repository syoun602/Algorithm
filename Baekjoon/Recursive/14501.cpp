#include <iostream>

using namespace std;

int N;
int day[15], profit[15];
int ans = 0;

void recursive(int date, int total) {
	if (date == N) {
		ans = max(ans, total);
		return;
	}

	if (date + day[date] <= N)
		recursive(date + day[date], total + profit[date]);
	if (date + 1 <= N)
		recursive(date + 1, total);
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> day[i] >> profit[i];

	recursive(0, 0);

	cout << ans << '\n';

	return 0;
}