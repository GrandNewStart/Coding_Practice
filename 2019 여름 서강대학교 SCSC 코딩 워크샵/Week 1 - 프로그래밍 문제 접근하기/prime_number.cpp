#include <iostream>
using namespace std;

int main() {
	int M, N;
	cin >> M;
	cin >> N;
	
	bool prime[1000001]; //FALSE if prime
	prime[0] = false;
	prime[1] = false;
	
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == true) continue;

		if (M <= i && i <= N)
			cout << i << '\n';

		for (int x = i * 2; x <= 1000000; x += i)
			prime[x] = true;
	}
		
	return 0;
}