#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
using pic = pair<int, char>;

pic v[10000];

int d(int n) {
	return (n * 2) % 10000;
}

int s(int n) {
	if (n > 0) return n - 1;
	else return 9999;
}

int l(int n) {
	int left = n / 1000;
	return (n * 10 + left) % 10000;
}

int r(int n) {
	int right = n % 10;
	return n / 10 + right * 1000;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;

		memset(v, 0, sizeof(v));

		queue<int> q;
		q.emplace(A);
		v[A] = pic(-1, '_');

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			int dx = d(x);
			int sx = s(x);
			int lx = l(x);
			int rx = r(x);

			if (v[dx].second == 0) {
				v[dx] = pic(x, 'D');
				if (dx == B) break;
				q.emplace(dx);
			}
			if (v[sx].second == 0) {
				v[sx] = pic(x, 'S');
				if (sx == B) break;
				q.emplace(sx);
			}
			if (v[lx].second == 0) {
				v[lx] = pic(x, 'L');
				if (lx == B) break;
				q.emplace(lx);
			}
			if (v[rx].second == 0) {
				v[rx] = pic(x, 'R');
				if (rx == B) break;
				q.emplace(rx);
			}
		}

		stack<char> rs;
		int i = B;
		while (i != A) {
			pic x = v[i];
			rs.emplace(x.second);
			i = x.first;
		}

		while (!rs.empty()) {
			cout << rs.top();
			rs.pop();
		}

		cout << '\n';
	}
	
	return 0;
}