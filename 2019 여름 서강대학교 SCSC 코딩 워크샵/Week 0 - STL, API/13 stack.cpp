#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N, X;
	string S;
	stack<int> s;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S;

		if (S == "push") {
			cin >> X;
			s.push(X);
		}
		else if (S == "pop") {
			if (s.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (S == "size") {
			cout << s.size() << endl;
		}
		else if (S == "empty") {
			cout << s.empty() << endl;
		}
		else if (S == "top") {
			if (s.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << s.top() << endl;
			}
		}
	}

	return 0;
}