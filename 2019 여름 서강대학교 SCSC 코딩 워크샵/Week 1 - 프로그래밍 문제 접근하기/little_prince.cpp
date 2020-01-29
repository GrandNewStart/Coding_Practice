#include <iostream>
#include <cmath>
using namespace std;

struct axis {
	int x;
	int y;
};

struct planet {
	int x;
	int y;
	int radius;
};

int dist(int x1, int y1, int x2, int y2) {
	int dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return dist;
}

int main() {
	int T, n, cnt = 0;
	bool l = 0, m = 0;
	axis start, end;
	planet arr[50] = {NULL};

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> start.x;
		cin >> start.y;
		cin >> end.x;
		cin >> end.y;

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j].x;
			cin >> arr[j].y;
			cin >> arr[j].radius;
		}

		for (int j = 0; j < n; j++) {
			if (dist(start.x, start.y, arr[j].x, arr[j].y) < arr[j].radius) l = 1;
			if (dist(end.x, end.y, arr[j].x, arr[j].y) < arr[j].radius) m = 1;

			if (l != m) cnt++;
			l = 0;
			m = 0;
		}

		cout << cnt << endl;
		cnt = 0;
	}

	return 0;
}