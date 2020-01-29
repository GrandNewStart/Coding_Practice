#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pii = pair<int, int>;

string board[100];
bool visit[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pii> q;

int main() {
	int N, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j]) continue;

			q.emplace(pii(i, j));
			visit[i][j] = true;
			char rgb = board[i][j];

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];

					if (nx < 0 || nx >= N) continue;
					if (ny < 0 || ny >= N) continue;
					if (visit[nx][ny]) continue;
					if (board[nx][ny] != rgb) continue;

					visit[nx][ny] = true;
					q.emplace(pii(nx, ny));
				}
			}

			cnt++;
		}
	}

		cout << cnt << '\n';

		cnt = 0;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j]) continue;

				q.emplace(pii(i, j));
				visit[i][j] = true;
				char rgb = board[i][j];

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int d = 0; d < 4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];

						if (nx < 0 || nx >= N) continue;
						if (ny < 0 || ny >= N) continue;
						if (visit[nx][ny]) continue;
						if (board[nx][ny] != rgb) {
							if (rgb == 'R' || rgb == 'G') {
								if (board[nx][ny] == 'B') continue;
							}
							else continue;
						}

						visit[nx][ny] = true;
						q.emplace(pii(nx, ny));
					}
				}

				cnt++;
			}
		}

	cout << cnt;

	return 0;
}