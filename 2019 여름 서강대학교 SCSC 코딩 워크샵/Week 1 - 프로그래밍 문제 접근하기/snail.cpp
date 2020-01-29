#include <iostream>
using namespace std;

int main() {
	int A, B, V, day;
	cin >> A;
	cin >> B;
	cin >> V;

	if (A == V) {
		cout << 1;
		return 0;
	}

	day = V / (A - B);

	while (true) {
		if ((day - 1) * (A - B) + A >= V) day--;
		else break;
	}

	cout << ++day;

	return 0;
}