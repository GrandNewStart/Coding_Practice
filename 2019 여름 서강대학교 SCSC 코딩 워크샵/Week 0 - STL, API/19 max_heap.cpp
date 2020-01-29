#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	priority_queue<int> q;

	while (N--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (q.empty()) {
				cout << 0 << "\n";
				continue;
			}
			int out = q.top();
			q.pop();
			cout << out << "\n";
		}
		else {
			q.push(x);
		}
	}
}