#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

void hanoi(int n, int from, int to, int mid) {
	if (n == 1)
		cout << from << " " << to << '\n';
	else {
		hanoi(n - 1, from, mid, to);
		cout << from << " " << to << '\n';
		hanoi(n - 1, mid, to, from);
	}

}

int main(void) {

	cin >> N;

	cout << (1 << N) - 1 << '\n';
	hanoi(N, 1, 3, 2);

	return 0;
 }