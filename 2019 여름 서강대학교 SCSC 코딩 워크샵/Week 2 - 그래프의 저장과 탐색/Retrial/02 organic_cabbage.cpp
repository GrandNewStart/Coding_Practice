#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool field[50][50];
bool visited[50][50];
short xp[5] = { 0, -1, 0, 1, 0 };
short yp[5] = { 0, 0, -1, 0, 1 };

void dfs(int X, int Y, int horizontal, int vertical) {
	for (int i = 0; i < 5; i++) {
		if (X + xp[i] >= 0 && X + xp[i] < horizontal &&
			Y + yp[i] >= 0 && Y + yp[i] < vertical &&
			field[X + xp[i]][Y + yp[i]] &&
			!visited[X + xp[i]][Y + yp[i]]) {
			visited[X + xp[i]][Y + yp[i]] = true;
			if (i == 0) {
				continue;
			}
			dfs(X + xp[i], Y + yp[i], horizontal, vertical);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testcase, horizontal, vertical, spot;

	cin >> testcase;

	while (testcase--) {
		memset(field, 0, sizeof(field));
		memset(visited, 0, sizeof(visited));
		vector<pair<int, int>> spots;
		int count = 0;

		cin >> horizontal >> vertical >> spot;

		for (int i = 0; i < spot; i++) {
			int x, y;
			cin >> x >> y;
			field[x][y] = true;
			pair<int, int> p = make_pair(x, y);
			spots.push_back(p);
		}

		for (int i = 0; i < (int)spots.size(); i++) {
			int x = spots[i].first;
			int y = spots[i].second;
			if (!visited[x][y]) {
				dfs(x, y, horizontal, vertical);
				count++;
			}
		}

		cout << count << "\n";
	}
}