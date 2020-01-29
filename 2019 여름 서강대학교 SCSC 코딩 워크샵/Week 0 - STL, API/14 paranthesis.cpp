#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, left, right;
	bool result = 1;
	string S;

	cin >> T;

	for (int i = 0; i < T; i++) {
		left = 0;
		right = 0;
		cin >> S;

		for (int i = 0; i < S.length(); i++) {
			if (S[i] == '(')
				left++;
			if (S[i] == ')')
				right++;
			if (left < right)
				result = 0;
		}

		if (result == 0)
			cout << "NO" << endl;
		else if (right != left)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

		result = 1;
	}


	return 0;
}