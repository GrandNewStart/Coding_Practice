#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int>> list;
	int N, x;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (list.empty()) {
				cout << 0 << "\n";
				continue;
			}
			int out = list.top();
			list.pop();
			cout << out << "\n";
		}
		else {
			list.push(x);
		}
	}
}