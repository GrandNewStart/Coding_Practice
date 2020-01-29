	#include <iostream>
	#include <algorithm>
	using namespace std;

	int main() {
		int N;
		int solution[100000];

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> solution[i];

		sort(solution, solution + N);
		int mn = abs(solution[0] + solution[N - 1]);
		int mnl = solution[0];
		int mnr = solution[N - 1];

		int s = 0, e = N - 1;

		while (s < e) {
			int l = solution[s];
			int r = solution[e];
			int sum = l + r;

			if (mn > abs(sum)) {
				mn = abs(sum);
				mnl = l;
				mnr = r;
			}
		
			if (sum < 0)
				s++;
			else if (sum > 0)
				e--;
			else
				break;
		}

		cout << mnl << " " << mnr << endl;

		return 0;
	}