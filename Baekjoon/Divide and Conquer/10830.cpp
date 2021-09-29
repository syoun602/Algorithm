#include <iostream>

using namespace std;

int N;
long long B;
int arr[5][5];
int res[5][5];

void matrix_mul(int A[5][5], int B[5][5]) {

	int temp[5][5];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < N; k++)
				temp[i][j] += A[i][k] * B[k][j];

			temp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = temp[i][j];
}

int main(void) {

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		res[i][i] = 1;
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	
	while (B > 0) {
		if (B % 2 == 1)
			matrix_mul(res, arr);
		
		matrix_mul(arr, arr);
		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}