#include <iostream>
#include <vector>

using namespace std;

int n;
char x, y, z;
vector<pair<int, bool>> tree[100];

void preorder(int cur) {

	cout << (char)cur;

	for (int i = 0; i < tree[cur].size(); i++)
		preorder(tree[cur][i].first);
}

void inorder(int cur) {
	if (!tree[cur].empty() && tree[cur][0].second)
		inorder(tree[cur][0].first);

	cout << (char)cur;

	if (!tree[cur].empty() && !tree[cur][0].second)
		inorder(tree[cur][0].first);
	else if (tree[cur].size() == 2)
		inorder(tree[cur][1].first);
}

void postorder(int cur) {
	for (int i = 0; i < tree[cur].size(); i++)
		postorder(tree[cur][i].first);
	cout << (char)cur;
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;

		if (y != '.')
			tree[x].push_back({ y, true });
		if (z != '.')
			tree[x].push_back({ z, false });
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';

	return 0;
 }