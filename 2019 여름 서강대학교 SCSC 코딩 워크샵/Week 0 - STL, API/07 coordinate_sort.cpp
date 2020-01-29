#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void swap(pair<int, int> *p1, pair<int, int> *p2) {
	pair<int, int> temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first > p2.first)
		return false;
	else if (p1.first == p2.first) {
		if (p1.second > p2.second)
			return false;
		else
			return true;
	}
	else 
		return true;
		
}

int main() {
	int N;
	scanf_s("%d", &N);
	vector <pair<int, int>> list;

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf_s("%d", &x);
		scanf_s("%d", &y);
		pair<int, int> p(x, y);
		list.push_back(p);
	}

	sort(list.begin(), list.end(), cmp);

	for (int i = 0; i < N; i++)
		printf("%d %d\n", list[i].first, list[i].second);

	return 0;
}