#include <iostream>
#include <cstring>
using namespace std;

int n;
int graph[101][101];
bool visit[101];

void dfs(int u, int start) {
	for (int v = 0; v < n; v++) {
		if (visit[v]) continue;
		if (!graph[u][v]) continue;

		visit[v] = true;

		dfs(v, start);
	}
}

int main() {
	//n(������ ����)
	cin >> n;

	//������� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	//��� Ž�� & ���
	for (int i = 0; i < n; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i, i);

		for (int j = 0; j < n; j++) cout << visit[j] << ' ';
		cout << '\n';
	}

	return 0;
}