#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
bool visited[100] = { false };

void dfs(int start, int *count) {
	
	if (!visited[start]) {
		visited[start] = true;
		(*count)++;
	}

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		if (!visited[next]) {
			visited[next] = true;
			(*count)++;
			dfs(next, count);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnum, nnum, count = 0;

	// ��ǻ���� ��, 100 ����
	cin >> cnum;

	// ��Ʈ��ũ ���� �� 
	cin >> nnum;

	// ��Ʈ��ũ �� �Է�
	for (int i = 0; i < nnum; i++) {
		int x;
		cin >> x;
		int y;
		cin >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// 1���� Ž��
	dfs(1, &count);

	cout << --count;
}