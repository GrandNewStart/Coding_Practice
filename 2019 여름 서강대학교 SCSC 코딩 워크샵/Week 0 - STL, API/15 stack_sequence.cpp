#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, x = 1, plusCount = 0;
	vector<int> sequence;
	stack<int> result;
	stack<char> result_2;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		sequence.push_back(input);
	}

	result.push(x);
	result_2.push('+');
	plusCount++;

	for (int i = 0; i < n;) {
		if (result.empty()) {
			result_2.push('+');
			result.push(++x);
			plusCount++;
		}

		int top = result.top();

		if (top == sequence[i]) {
			result.pop();
			result_2.push('-');
			i++;
			if (i == n) {
				break;
			}
		}
		else {
			result_2.push('+');
			result.push(++x);
			plusCount++;
		}

		if (plusCount > n) {
			cout << "NO";
			return 0;
		}
	}

	vector<char> out;
	while (!result_2.empty()) {
		out.push_back(result_2.top());
		result_2.pop();
	}
	for (int i = out.size(); i > 0; i--) {
		cout << out[i-1] << "\n";
	}
}