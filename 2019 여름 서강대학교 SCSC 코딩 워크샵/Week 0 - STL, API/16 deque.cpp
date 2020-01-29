#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, x;
	string S;
	deque<int> d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S;
		if (S == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		if (S == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		if (S == "pop_front") {
			if (d.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << d.front() << endl;
				d.pop_front();
			}
		}
		if (S == "pop_back") {
			if (d.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << d.back() << endl;
				d.pop_back();
			}
		}
		if (S == "front") {
			if (d.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << d.front() << endl;
			}
		}
			
		if (S == "back") {
			if (d.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << d.back() << endl;
			}
		}
		if (S == "size")
			cout << d.size() << endl;
		if (S == "empty")
			cout << d.empty() << endl;
	}

	return 0;
}