#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string s1, string s2) {
	if (s1.length() < s2.length())
		return true;
	else if (s1.length() == s2.length())
		return s1 < s2;
	else
		return false;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	vector<string> lexicons;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		lexicons.push_back(input);
	}

	sort(lexicons.begin(), lexicons.end(), cmp);

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cout << lexicons[i] << "\n";
			continue;
		}

		string previous = lexicons[i - 1];
		string current = lexicons[i];

		if (!previous.compare(current)) {
			continue;
		}

		cout << lexicons[i] << "\n";
	}
}