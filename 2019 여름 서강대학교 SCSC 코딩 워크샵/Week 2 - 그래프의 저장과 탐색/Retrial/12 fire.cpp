#include <iostream>
#include <queue>
#include <cstring>

using pii = std::pair<int, int>;

std::queue<pii> fire;
std::queue<pii> sanggeun;
char graph[1001][1001] = { '.' };
bool visited[1001][1001] = { false };
short xp[4] = { -1, 0, 1, 0 };
short yp[4] = { 0, -1, 0, 1 };
int vertical, horizontal, time = 0;
bool success = false;

void print() {
	std::cout << "\n";
	for (int i = 0; i < vertical; i++) {
		for (int j = 0; j < horizontal; j++) {
			std::cout << graph[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void FireMove() {
	std::queue<pii> fire_temp;
	fire_temp = fire;

	while (!fire_temp.empty()) {
		int fx = fire.front().first;
		int fy = fire.front().second;
		fire.pop();
		fire_temp.pop();

		for (int i = 0; i < 4; i++) {
			int nx = fx + xp[i];
			int ny = fy + yp[i];

			if (nx >= 0 && nx < vertical &&
				ny >= 0 && ny < horizontal &&
				(graph[nx][ny] == '.' || graph[nx][ny] == '@') &&
				!visited[nx][ny]) {

				graph[nx][ny] = '*';
				visited[nx][ny] = true;
				fire.emplace(pii(nx, ny));

			}
		}
	}
}

void SanggeunMove() {
	std::queue<pii> sanggeun_temp;
	sanggeun_temp = sanggeun;

	time++;

	while (!sanggeun_temp.empty()) {
		int sx = sanggeun.front().first;
		int sy = sanggeun.front().second;
		sanggeun.pop();
		sanggeun_temp.pop();

		if (sx == 0 || sx == vertical - 1 ||
			sy == 0 || sy == horizontal - 1) {

			std::cout << time << "\n";
			success = true;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = sx + xp[i];
			int ny = sy + yp[i];

			if (nx >= 0 && nx < vertical &&
				ny >= 0 && ny < horizontal &&
				graph[nx][ny] == '.') {

				if (nx == 0 || nx == vertical - 1 ||
					ny == 0 || ny == horizontal - 1) {

					std::cout << ++time << "\n";
					success = true;
					return;
				}

				graph[nx][ny] = '@';
				sanggeun.emplace(pii(nx, ny));
			}
		}
	}
}

int main() {
	int testcase;
	std::cin >> testcase;

	while (testcase--) {
		memset(graph, '.', sizeof(graph));
		memset(visited, false, sizeof(visited));
		while (!fire.empty()) {
			fire.pop();
		}
		while (!sanggeun.empty()) {
			sanggeun.pop();
		}
		success = false;
		time = 0;

		std::cin >> horizontal >> vertical;

		for (int i = 0; i < vertical; i++) {
			for (int j = 0; j < horizontal; j++) {
				std::cin >> graph[i][j];
				switch (graph[i][j]) {
				case '@':
					sanggeun.emplace(pii(i, j));
					break;
				case '*':
					fire.emplace(pii(i, j));
				}
			}
		}

		if (fire.empty()) {
			while (!sanggeun.empty()) {
				SanggeunMove();
			}
			if (!success) {
				std::cout << "IMPOSSIBLE" << "\n";
			}
		}
		else {
			while (!fire.empty()) {
				FireMove();
				SanggeunMove();
				//print();

				if (success) {
					break;
				}
			}
			if (!success) {
				std::cout << "IMPOSSIBLE" << "\n";
			}
		}
	}
}