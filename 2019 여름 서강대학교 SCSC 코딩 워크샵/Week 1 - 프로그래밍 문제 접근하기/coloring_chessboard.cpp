#include <iostream>
using namespace std;

int check(char board[50][50], int row, int col) {
	int result_B = 0;
	int result_W = 0;
	int k = 1;

	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			if (k == 1) {
				if (board[i][j] == 'B') result_W++;
				else result_B++;
			}
			else {
				if (board[i][j] == 'W') result_W++;
				else result_B++;
			}
			k *= -1;
			if (j == col + 7) k *= -1;
		}
	}

	if (result_B > result_W) return result_W;
	else return result_B;
}

int main() {
	int M, N, result, temp;
	char board[50][50] = {44};
	string S;
	cin >> M;
	cin >> N;
	for (int i = 0; i < M; i++) {
		cin >> S;
		for (int j = 0; j < N; j++)
			board[i][j] = S[j];
	}

	result = 64;

	for (int i = 0; i < M - 7; i++) {
		for (int j = 0; j < N - 7; j++) {
			temp = check(board, i, j);
			if (result > temp)
				result = temp;
		}
	}

	cout << result;

	return 0;
}