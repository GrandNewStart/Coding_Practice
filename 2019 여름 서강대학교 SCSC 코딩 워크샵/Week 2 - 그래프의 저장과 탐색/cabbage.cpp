#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pii = pair<int, int>;

int board[50][50];
bool visit[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int xnum, int ynum, queue<pii> q) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= xnum) continue;
			if (ny < 0 || ny >= ynum) continue;
			if (visit[nx][ny]) continue;
			if (board[nx][ny] == 0) continue;

			visit[nx][ny] = true;
			q.emplace(pii(nx, ny));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		//매 테스트 케이스 마다 배열 초기화
		memset(board, 0, sizeof(board));
		memset(visit, 0, sizeof(visit));

		//M(가로의 길이), N(세로의 길이)
		int M, N, K;
		cin >> M >> N >> K;

		//배추 위치 입력
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		
		//탐색에 쓸 큐와 카운터 생성
		int cnt = 0;
		queue<pii> q;

		//연결요소 수 탐색
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (board[j][k] == 0) continue;
				if (visit[j][k]) continue;

				q.emplace(pii(j, k));
				visit[j][k] = true;
				cnt++;
				bfs(M, N, q);
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}