#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using pii = std::pair<int, std::string>;

int D(int);
int S(int);
int L(int);
int R(int);

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int testcase;
	std::cin >> testcase;

	while (testcase--) {
		pii dist[10001];

		int A, B;
		std::cin >> A >> B;

		std::queue<int> q;
		q.emplace(A);

		dist[A] = pii(0, "");

		while (!q.empty()) {
			int front = q.front();
			q.pop();

			int next[4] = { D(front), S(front), L(front), R(front) };

			for (int i = 0; i < 4; i++) {
				int nx = next[i];

				if (dist[nx].first == 0 && nx != A) {

					dist[nx].first = dist[front].first + 1;
					q.emplace(nx);

					switch (i) {
					case 0:
						dist[nx].second = dist[front].second + "D";
						break;
					case 1:
						dist[nx].second = dist[front].second + "S";
						break;
					case 2:
						dist[nx].second = dist[front].second + "L";
						break;
					case 3:
						dist[nx].second = dist[front].second + "R";
					}
				}
			}

			if (dist[B].first != 0) {
				for (int i = 0; i < dist[B].second.size(); i++) {
					std::cout << dist[B].second[i];
				}
				std::cout << "\n";
				break;
			}
		}
	}
}

int D(int input) {
	int result = input * 2;

	if (result > 9999) {
		result %= 10000;
	}

	return result;
}

int S(int input) {
	int result = input - 1;

	if (result < 0) {
		result += 10000;
	}

	return result;
}

int L(int input) {
	int result = 0;
	int arr[4];

	for (int i = 0; i < 4; i++) {
		int temp = input % 10;
		arr[3 - i] = temp;
		input /= 10;
	}

	result += arr[0];
	result += arr[1] * 1000;
	result += arr[2] * 100;
	result += arr[3] * 10;

	return result;
}

int R(int input) {
	int result = 0;
	int arr[4];

	for (int i = 0; i < 4; i++) {
		int temp = input % 10;
		arr[3 - i] = temp;
		input /= 10;
	}

	result += arr[0] * 100;
	result += arr[1] * 10;
	result += arr[2];
	result += arr[3] * 1000;

	return result;
}