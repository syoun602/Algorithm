#include<iostream>
#include<vector>

using namespace std;

typedef vector<vector<long long>> matrix;

matrix a = { {1,1}, {1,0} };
matrix ans = { {1,0}, {0,1} };

long long n, mod = 1000000007;


matrix matrix_mul (matrix a, matrix b)
{
	matrix tmp(2, vector<long long>(2));

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				tmp[i][j] += a[i][k] * b[k][j];

			tmp[i][j] %= mod;
		}
	return tmp;
}

int main()
{
	cin >> n;

	while (n > 0)
	{
		if (n % 2 == 1)
			ans = matrix_mul(ans, a);
		a = matrix_mul(a, a);
		n /= 2;
	}

	cout << ans[0][1] << '\n';
}