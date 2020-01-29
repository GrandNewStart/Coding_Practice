#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
	int id;
	int age;
	string name;

	Student() {}
	Student(int id, int age, string name) {
		this->id = id;
		this->age = age;
		this->name = name;
	}
};

bool cmp1 (Student s1, Student s2) {
	if (s1.age < s2.age)
		return true;
	else if (s1.age == s2.age)
		return s1.id < s2.id;
	else 
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	vector<Student> Students;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age;
		cin >> name;
		Student s = Student(i, age, name);
		Students.push_back(s);
	}

	sort(Students.begin(), Students.end(), cmp1);

	for (int i = 0; i < N; i++)
		cout << Students[i].age << " " << Students[i].name << "\n";
}