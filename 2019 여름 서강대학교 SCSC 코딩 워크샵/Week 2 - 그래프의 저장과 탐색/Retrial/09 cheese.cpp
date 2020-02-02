#include <iostream>
#include <queue>
#include <cstring>

using pii = std::pair<int,int>;
std::queue<pii> border;
bool graph[100][100] = { false };
bool visited[100][100] = { false };
int hours[100][100] = { 0 };
short xp[4] = { -1, 0, 1, 0 };
short yp[4] = { 0, -1, 0, 1 };

int bfs(int vertical, int horizontal) {
	std::queue<pii> q;
	int last = 0;
	q.emplace(pii(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + xp[i];
			int ny = y + yp[i];

			if (nx >= 0 && nx < vertical &&
				ny >= 0 && ny < horizontal &&
				!visited[nx][ny]) {

				if (!graph[nx][ny]) {
					visited[nx][ny] = true;
					q.emplace(pii(nx, ny));
				}
				else {
					visited[nx][ny] = true;
					border.emplace(pii(nx, ny));
					hours[nx][ny] = hours[x][y] + 1;
				}
			}
		}
	}

	while (!border.empty()) {
		int i = border.front().first;
		int j = border.front().second;
		border.pop();
		graph[i][j] = false;
		last++;
	}

	memset(visited, false, sizeof(visited));

	return last;
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int horizontal, vertical, max = 0, last;
	std::cin >> vertical >> horizontal;

	for (int i = 0; i < vertical; i++) {
		for (int j = 0; j < horizontal; j++) {
			bool input;
			std::cin >> input;
			graph[i][j] = input;
		}
	}
	
	while (true) {
		int melted = bfs(vertical, horizontal);
		if (!melted) {
			break;
		}
		last = melted;
		max++;
	}

	std::cout << max << "\n";
	std::cout << last;
}