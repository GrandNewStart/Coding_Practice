#include <iostream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		int w;
		priority_queue<int, vector<int>, less<int>> pq;
		queue<pair<int, int>> q;

		for (int j = 0; j < n; j++) {
			cin >> w;
			q.push({ j, w });
			pq.push(w);
		}

		int count = 0;
		while (!q.empty()) {
			int nowindex = q.front().first;
			int nowweight = q.front().second;
			q.pop();
			if (pq.top() == nowweight) {
				pq.pop();
				count++;
				if (m == nowindex) {
					cout << count << "\n";
					break;
				}
			}
			else {
				q.push({ nowindex, nowweight });
			}
		}
	}
	return 0;
}