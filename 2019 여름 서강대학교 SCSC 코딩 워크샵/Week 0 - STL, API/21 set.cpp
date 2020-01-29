#include <iostream>
#include <string>
using namespace std;

int* S;

void add(int x) {
	if (S[x - 1] == 0) {
		S[x - 1] = 1;
	}
	return;
}

void remove(int x) {
	if (S[x - 1] == 1) {
		S[x - 1] = 0;
	}
	return;
}

void check(int x) {
	if (S[x - 1] != 0) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}

void toggle(int x) {
	if (S[x - 1] == 0) {
		add(x);
	}
	else {
		remove(x);
	}
}

void all() {
	for (int i = 0; i < 20; i++) {
		S[i] = 1;
	}
}

void empty() {
	for (int i = 0; i < 20; i++) {
		S[i] = 0;
	}
}

void print() {
	for (int i = 0; i < 20; i++) {
		cout << S[i] << " ";
	}
	cout << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	S = (int*)calloc(20, sizeof(int)); print();

	int M;
	cin >> M;

	while (M--) {
		string s;
		int x;
		cin >> s;
		if (s.compare("add") * s.compare("remove") * s.compare("check") == 0) {
			cin >> x;
		}

		if (s.compare("add") == 0) {
			add(x); print();
		}
		if (s.compare("remove") == 0) {
			remove(x); print();
		}
		if (s.compare("check") == 0) {
			check(x); print();
		}
		if (s.compare("toggle") == 0) {
			toggle(x); print();
		}
		if (s.compare("all") == 0) {
			all(); print();
		}
		if (s.compare("empty") == 0) {
			empty(); print();
		}
	}
}