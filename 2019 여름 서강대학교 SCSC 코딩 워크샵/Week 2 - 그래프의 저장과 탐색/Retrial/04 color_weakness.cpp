#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> grid;
bool visited[100][100] = { false };
short xp[5] = { 0, -1, 1, 0, 0 };
short yp[5] = { 0, 0, 0, -1, 1 };

void dfs(int startX, int startY, int gridsize, char rgb, bool weak) {
	if (weak) {
		for (int i = 0; i < 5; i++) {
			int x = startX + xp[i];
			int y = startY + yp[i];
			if (x >= 0 && x < gridsize &&
				y >= 0 && y < gridsize &&
				!visited[x][y]) {
				switch (rgb) {
				case 'R':
					if (grid[x][y] == 'R' || grid[x][y] == 'G') {
						visited[x][y] = true;
						dfs(x, y, gridsize, rgb, true);
					}
					break;
				case 'G':
					if (grid[x][y] == 'R' || grid[x][y] == 'G') {
						visited[x][y] = true;
						dfs(x, y, gridsize, rgb, true);
					}
					break;
				case 'B':
					if (grid[x][y] == 'B') {
						visited[x][y] = true;
						dfs(x, y, gridsize, rgb, true);
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			int x = startX + xp[i];
			int y = startY + yp[i];
			if (x >= 0 && x < gridsize &&
				y >= 0 && y < gridsize &&
				!visited[x][y] && grid[x][y] == rgb) {
				visited[x][y] = true;
				dfs(x, y, gridsize, rgb, false);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int gridsize, count = 0;
	cin >> gridsize;

	for (int i = 0; i < gridsize; i++) {
		string row;
		cin >> row;
		grid.push_back(row);
	}

	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (!visited[i][j]) {
				dfs(i, j, gridsize, grid[i][j], false);
				count++;
			}
		}
	}

	cout << count << " ";

	count = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (!visited[i][j]) {
				dfs(i, j, gridsize, grid[i][j], true);
				count++;
			}
		}
	}

	cout << count << " ";
}