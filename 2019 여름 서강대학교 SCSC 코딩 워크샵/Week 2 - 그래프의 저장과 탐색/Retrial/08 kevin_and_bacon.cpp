#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool graph[101][101] = { false };
int dist[101] = { 0 };

int bfs(int start, int users) {
	memset(dist, 0, sizeof(dist));

	queue<int> q;
	q.emplace(start);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 1; v <= users; v++) {
			if (graph[u][v]){
				if (dist[v] > 0) continue; // �ѹ��̶� ���� ���� �̹� �Ÿ��� 0�� ����
				if (v == start) continue; // �ڱ� �ڽ����� ���� ��δ� ����

				q.emplace(v);
				dist[v] = dist[u] + 1; // ���� �湮 ���� ���� ������ �湮�� �������� �Ÿ� + 1
			}
		}
	}

	int sum = 0;

	for (int i = 1; i <= users; i++)
		sum += dist[i];

	return sum;
}

int main() {
	int users, relationships, min, winner;
	cin >> users >> relationships;

	for (int i = 0; i < relationships; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = true;
		graph[y][x] = true;
	}

	min = bfs(1, users);
	winner = 1;

	for (int i = 2; i <= users; i++) {
		int temp = bfs(i, users);
		if (min > temp) {
			min = temp;
			winner = i;
		}
		if (min == temp) {
			if (winner > i) {
				winner = i;
			}
		}
	}

	cout << winner;
}