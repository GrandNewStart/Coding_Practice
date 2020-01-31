#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

short graph[1000][1000] = { 0 };
int days[1000][1000] = { 0 };
short xp[4] = { -1, 1, 0, 0 };
short yp[4] = { 0, 0, -1, 1 };
queue<pii> q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int horizontal, vertical, count = 0;
	cin >> horizontal >> vertical;

	for (int i = 0; i < vertical; i++) {
		for (int j = 0; j < horizontal; j++) {
			short input;
			cin >> input;
			graph[i][j] = input;
			if (input == 1) {
				q.emplace(pii(i, j));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + xp[i];
			int ny = y + yp[i];

			if (nx >= 0 && nx < vertical &&
				ny >= 0 && ny < horizontal &&
				graph[nx][ny] == 0) {

				graph[nx][ny] = 1;
				q.emplace(pii(nx, ny));
				days[nx][ny] = days[x][y] + 1;

				if (count < days[nx][ny]) {
					count = days[nx][ny];
				}
			}
		}
	}

	for (int i = 0; i < vertical; i++) {
		for (int j = 0; j < horizontal; j++) {
			if (graph[i][j] == 0) {
				count = -1;
			}
		}
	}

	cout << count;
}