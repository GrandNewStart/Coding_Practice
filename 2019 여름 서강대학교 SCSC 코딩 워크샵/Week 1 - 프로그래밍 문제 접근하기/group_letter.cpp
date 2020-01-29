#include <iostream>
using namespace std;

bool check(string S) {
	bool result = 1;
	bool list[26] = {0};
	int i = 0;
	
	while (S[i] != NULL)
		list[S[i++] - 97] = 1;

	for (i = 0; i < S.length(); i++) {
		if (list[S[i] - 97] == 0) {
			result = 0;
			break;
		}
		
		if (S[i] != S[i + 1])
			list[S[i] - 97] = 0;
		else continue;
	}

	return result;
}

int main() {
	int N, cnt = 0;
	string S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S;
		if (check(S)) cnt++;
	}

	cout << cnt;

	return 0;
}