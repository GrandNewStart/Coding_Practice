#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> graph; // ��������Ʈ
bool visit[101]; // �湮�� TRUE

void dfs(int u) {
	for (int v : graph[u]) {
		if (visit[v]) continue;
		visit[v] = true;
		dfs(v);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v = 1, cnt = 0; // n(������ ��), m(������ ��), v(ù��°�� Ž���� ����), cnt(���̷����� �ɸ� ��ǻ���� ��)
	cin >> n >> m;
	graph.resize(n + 1);

	//��������Ʈ �Է�
	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}

	//�Էµ� �ֵ� ����
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	//Ž��
	visit[v] = true;
	dfs(v);

	for (int i = 2; i <= n; i++) {
		if (visit[i]) cnt++;
	}

	cout << cnt;

	return 0;
}