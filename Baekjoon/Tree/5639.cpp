#include <iostream>

using namespace std;

int N;

struct node {
	struct node* left;
	struct node* right;
	int data;
};

void postorder(node* n) {
	if (n->left != NULL)
		postorder(n->left);
	if (n->right != NULL)
		postorder(n->right);
	cout << n->data << '\n';
}

node* insert(node* n, int data) {
	if (n == NULL) {
		n = new node();
		n->data = data;
		n->left = NULL;
		n->right = NULL;
	}
	else if (data <= n->data)
		n->left = insert(n->left, data);
	else
		n->right = insert(n->right, data);

	return n;
}

int main(void) {

	node* root = NULL;

	while (cin >> N)
		root = insert(root, N);
	
	postorder(root);

	return 0;
}