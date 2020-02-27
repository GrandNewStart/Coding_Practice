#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2) {
	if (p1.first.compare(p2.first) == -1)
		return true;
	else
		return false;
}

int Parse(string query) {
	int result = 0;

	for (int i = query.length() - 1, j = 0; i >= 0; i--, j++) {
		result += ((query[i] - 48) * pow(10, j));
	}

	return result;
}

int binary_search(vector<pair<string, int>> input, string target) {
	int left, right, mid;
	left = 0;
	right = input.size() - 1;

	while (left <= right) {
		mid = left + (right - left) / 2;

		if (input[mid].first.compare(target) < 0) {
			left = mid + 1;
		}
		else if (!input[mid].first.compare(target)) {
			return input[mid].second;
		}
		else {
			right = mid - 1;
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// 포켓몬을 알파벳 순서로 저장하는 배열
	vector<pair<string, int>> alphabet;
	// 포켓몬을 id 순서대로 저장하는 배열
	vector<string> index;

	int N, M, id = 0;
	cin >> N >> M;

	while (N--) {
		string name;
		cin >> name;
		pair<string, int> p = make_pair(name, id);
		alphabet.push_back(p);
		index.push_back(name);
		id++;
	}

	// alphabet 배열은 알파벳 순서로 정렬
	sort(alphabet.begin(), alphabet.end(), comp);

	while (M--){
		string query;
		cin >> query;

		//검색어의 첫 글자가 숫자인 경우
		if (query[0] > 47 && query[0] < 58) {
			int id = Parse(query);
			cout << index[id - 1] << "\n";
		}
		//검색어의 첫 글자가 알파벳 대문자인 경우
		else if (query[0] > 64 && query[0] < 91) {
			int id = binary_search(alphabet, query);
			cout << id + 1 << "\n";
		}
	}
}