#include <iostream>
using namespace std;

int main() {
	long long a, b, sum;
	cin >> a;
	cin >> b;

	if (b > a)
		sum = b * (b + 1) / 2 - a * (a + 1) / 2 + a;
	else
		sum = a * (a + 1) / 2 - b * (b + 1) / 2 + b;

	cout << sum;

	return 0;
}