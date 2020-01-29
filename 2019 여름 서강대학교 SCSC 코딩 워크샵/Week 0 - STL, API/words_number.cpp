#include <iostream>
#include <string>
using namespace std;

int main() {
	int i = 0, cnt = 0;
	string S;
	getline(cin, S);

	while (true) {
		if (S[i] != 32) i++;
		else {
			if (i == 0) i++;
			else {
				i++;
				cnt++;
			}
		}

		if (S[i] == NULL) {
			if (S[i - 1] == 32) cnt--;
			break;
		}
	}

	cout << ++cnt << endl;

	return 0;
}