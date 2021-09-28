#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string ans, input, del;

int main(void) {

	cin >> input >> del;

	stack<char> s;

	for (int i = 0; i < input.length(); i++) {
		int last = del.size() - 1;
		
		if (input[i] == del[last]) {
			stack<char> temp;
			bool flag = true;

			while (last--) {
				if (!s.empty() && s.top() == del[last]) {
					temp.push(s.top());
					s.pop();
				}
				else {
					while (!temp.empty()) {
						s.push(temp.top());
						temp.pop();
					};
					flag = false;
					break;
				}	
			}
			if (!flag)
				s.push(input[i]);
		}
		else
			s.push(input[i]);
	}

	if (s.empty())
		cout << "FRULA" << '\n';
	else {
		while (!s.empty()) {
			ans += s.top();
			s.pop();
		}
		reverse(ans.begin(), ans.end());
	}

	cout << ans << '\n';

	return 0;
}