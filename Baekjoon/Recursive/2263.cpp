#include <iostream>

using namespace std;

int N;
int inorder[100001], postorder[100001], idx[100001];

void getPreorder(int in_s, int in_e, int post_s, int post_e) {

	if (in_s > in_e || post_s > post_e)
		return;

	int root = postorder[post_e];
	cout << root << ' ';

	getPreorder(in_s, idx[root] - 1, post_s, post_s + idx[root] - in_s - 1);
	getPreorder(idx[root] + 1, in_e, post_s + idx[root] - in_s, post_e - 1);
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
		idx[inorder[i]] = i;
	}
	for (int i = 0; i < N; i++)
		cin >> postorder[i];

	getPreorder(0, N - 1, 0, N - 1);

	return 0;
}