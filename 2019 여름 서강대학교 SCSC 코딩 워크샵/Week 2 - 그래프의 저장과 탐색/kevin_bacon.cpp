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
			if (dist[v] > 0) continue; // 한번이라도 지난 곳은 이미 거리가 0을 넘음
			if (v == start) continue; // 자기 자신으로 가는 경로는 제외

			q.emplace(v);
			dist[v] = dist[u] + 1; // 현재 방문 중인 곳은 이전에 방문한 곳까지의 거리 + 1
		}
	}

	int sum = 0;

	for (int i = 1; i <= n; i++)
		sum += dist[i];

	return sum;
}

int main() {
	//n(유저 수), m(관계 수)
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