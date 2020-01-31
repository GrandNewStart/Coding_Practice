#include <iostream>
#include <cstring>
using namespace std;

bool graph[101][101] = { false };
bool path[101][101] = { false };
bool visited[101] = { false };

void dfs(int start, int vertices) {
	for (int i = 1; i <= vertices; i++) {
		if (!visited[i] && graph[start][i]) {
			visited[i] = true;
			dfs(i, vertices);
		}
	}
}

int main() {
	int vertices;
	cin >> vertices;
	for (int i = 1; i <= vertices; i++) {
		for (int j = 1; j <= vertices; j++) {
			bool input;
			cin >> input;
			graph[i][j] = input;
		}
	}
	
	for (int i = 1; i <= vertices; i++) {
		dfs(i, vertices);
		for (int j = 1; j <= vertices; j++) {
			if (visited[j]) {
				path[i][j] = true;
			}
		}
		memset(visited, false, sizeof(visited));
	}

	cout << "\n";

	for (int i = 1; i <= vertices; i++) {
		for (int j = 1; j <= vertices; j++) {
			cout << (int)path[i][j] << " ";
		}
		cout << "\n";
	}
}