#include <iostream>
#include <string>
using namespace std;

class Queue {
public:
	Queue() : data(NULL), ptr(NULL) {};

	void push(int data) {
		if (this->data == NULL) {
			this->data = data;
		}
		else {
			Queue* temp = new Queue;
			Queue* last = new Queue;
			temp->data = data;
			last = this;
			
			while (last->ptr != NULL) {
				last = last->ptr;
			}

			last->ptr = temp;
		}
	}

	int pop() {
		int result;
		result = this->data;

		if (this->data == NULL)
			return -1;

		if (this->ptr != NULL)
			*this = *this->ptr;
		else
			this->data = NULL;

		return result;
	}

	int size() {
		if (this->data == NULL) {
			return 0;
		}

		int cnt = 1;
		Queue* temp = new Queue;
		temp = this;

		while (temp->ptr != NULL) {
			cnt++;
			temp = temp->ptr;
		}

		return cnt;
	}

	int empty() {
		if (this->data == NULL)
			return 1;
		else
			return 0;
	}

	int front() {
		if (this->data == NULL)
			return -1;
		return this->data;
	}

	int back() {
		int result;
		Queue* temp = new Queue;
		*temp = *this;

		if (this->data == NULL)
			return -1;
		while (this->ptr != NULL)
			*this = *(this->ptr);

		result = this->data;
		*this = *temp;

		return result;
	}

private:
	int data;
	Queue* ptr;
};

int main() {
	int N, X;
	string S;
	Queue queue;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S;

		if (S == "push") {
			cin >> X;
			queue.push(X);
		}
		else if (S == "pop") {
			cout << queue.pop() << endl;
		}
		else if (S == "size") {
			cout << queue.size() << endl;
		}
		else if (S == "empty") {
			cout << queue.empty() << endl;
		}
		else if (S == "front") {
			cout << queue.front() << endl;
		}
		else if (S == "back") {
			cout << queue.back() << endl;
		}
	}

	return 0;
}