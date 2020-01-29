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

	// 컴퓨터의 수, 100 이하
	cin >> cnum;

	// 네트워크 쌍의 수 
	cin >> nnum;

	// 네트워크 쌍 입력
	for (int i = 0; i < nnum; i++) {
		int x;
		cin >> x;
		int y;
		cin >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// 1에서 탐색
	dfs(1, &count);

	cout << --count;
}