#include <iostream>

using namespace std;

int main(void) {

	string str, op, ans;

	cin >> str;

	for (auto s : str) {
		if (s >= 65 && s <= 90) { // 피연산자
			ans.push_back(s);
		}
		else {
			if (s == '(')
				op.push_back(s);
			else if (s == ')') {
				while (op.back() != '(') {
					ans.push_back(op.back());
					op.pop_back();
				}
				op.pop_back();
			}
			else if (s == '*' || s == '/') {
				while (!op.empty() && (op.back() == '*' || op.back() == '/')) {
					ans.push_back(op.back());
					op.pop_back();
				}
				op.push_back(s);
			}
			else {
				while (!op.empty() && op.back() != '(') {
					ans.push_back(op.back());
					op.pop_back();
				}
				op.push_back(s);
			}
		}
	}

	while (!op.empty()) {
		ans.push_back(op.back());
		op.pop_back();
	}
	cout << ans << '\n';

	return 0;
}