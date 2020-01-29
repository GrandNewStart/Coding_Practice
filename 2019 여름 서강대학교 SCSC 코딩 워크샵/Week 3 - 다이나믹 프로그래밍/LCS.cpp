#include <iostream>
#include <algorithm>
using namespace std;

int D[1000][1000];

int main() {
	string A, B;
	cin >> A >> B;
	
	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++) {
			int temp = max(D[i + 1][j], D[i][j + 1]);

			if (A[i] == B[j]) {
				D[i + 1][j + 1] = max(D[i][j] + 1, temp);
			}
			else {
				D[i + 1][j + 1] = temp;
			}
		}
	}

	cout << D[A.length()][B.length()];

	return 0;
}