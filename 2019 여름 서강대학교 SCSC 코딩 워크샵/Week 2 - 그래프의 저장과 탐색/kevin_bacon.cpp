#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
int dist[101];

int bacon(int start) {
	memset(dist, 0, sizeof(dist));
		
	queue<int> q;
	q.emplace(start);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (dist[v] > 0) continue; // �ѹ��̶� ���� ���� �̹� �Ÿ��� 0�� ����
			if (v == start) continue; // �ڱ� �ڽ����� ���� ��δ� ����

			q.emplace(v);
			dist[v] = dist[u] + 1; // ���� �湮 ���� ���� ������ �湮�� �������� �Ÿ� + 1
		}
	}

	int sum = 0;

	for (int i = 1; i <= n; i++)
		sum += dist[i];

	return sum;
}

int main() {
	//n(���� ��), m(���� ��)
	cin >> n >> m;

	graph.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}

	int min = INT_MAX;
	int mni;

	for (int i = 1; i <= n; i++) {
		int temp = bacon(i);
		if (min > temp) {
			min = temp;
			mni = i;
		}
	}

	cout << mni;

	return 0;
}