#include <iostream>
#include <queue>
#include <cstring>
#define INT_MAX 2147483647

using coordinates = std::pair<int, int>;
using piii = std::pair<coordinates, bool>;

std::queue<piii> q;
bool graph[1001][1001] = { false };
bool tried[1001][1001] = { false };
int time[1001][1001] = { 0 };
short xp[4] = { -1, 0, 1, 0 };
short yp[4] = { 0, -1, 0, 1 };
int vertical, horizontal, min = INT_MAX;
bool wall_break = true;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	std::cin >> vertical >> horizontal;

	for (int i = 1; i <= vertical; i++) {
			std::string input;
			std::cin >> input;

			for (int j = 0; j < horizontal; j++) {
				switch (input[j]) {
				case '1':
					graph[i][j + 1] = true;
					break;
				case '0':
					graph[i][j + 1] = false;
				}
			}
	}

	while (wall_break) {
		wall_break = false;
		memset(time, 0, sizeof(time));

		q.emplace(coordinates(1, 1), wall_break);

		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			wall_break = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + xp[i];
				int ny = y + yp[i];

				if (nx < 1 || nx > vertical) continue;
				if (ny < 1 || ny > horizontal) continue;
				if (time[nx][ny] != 0) continue;

				// 현위치에 벽이 있고
				if (graph[nx][ny]) {
					// 아직 허물지 않았고 한번도 허문 적이 없을 때
					if (!wall_break && !tried[nx][ny]) {
						tried[nx][ny] = true;

						wall_break = true;
						time[nx][ny] = time[x][y] + 1;
						q.emplace(coordinates(nx, ny), wall_break);
					}
				}
				// 벽이 없을 때
				else {
					time[nx][ny] = time[x][y] + 1;
					q.emplace(coordinates(nx, ny), wall_break);
				}
			}
		}

		if (time[vertical][horizontal] != 0) {
			if (min > time[vertical][horizontal]) {
				min = time[vertical][horizontal];
			}
		}
	}

	if (min == INT_MAX) {
		std::cout << -1;
	}
	else {
		std::cout << min + 1;
	}
}