//https://www.hackerrank.com/challenges/virtual-functions/problem
//Sample Input:
//4
//1
//Walter 56 99
//2
//Jesse 18 50 48 97 76 34 98
//2
//Pinkman 22 10 12 0 18 45 50
//1
//White 58 87

//Sample Output:
//Walter 56 99 1
//Jesse 18 403 1
//Pinkman 22 135 2
//White 58 87 2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/* Enter your code here. */
class Person {
protected:
	string name;
	int age;
public:
	virtual void getdata() = 0;
	virtual void putdata() = 0;
};

class Professor : public Person {
private:
	static int cur_id_counter;
	int cur_id, publications;
public:
	Professor() { cur_id = ++cur_id_counter; }
	void getdata() override {
		char buf[101];
		cin >> buf >> age >> publications;
		name = buf;
	}
	void putdata() override {
		cout << name << " " << age << " " << publications << " " << cur_id << endl;
	}
};
#define MARKS 6
class Student : public Person {
private:
	static int cur_id_counter;
	int cur_id, marks[MARKS];
	int marks_sum() {
		int sum = 0;
		for (int i = 0; i < MARKS; sum += marks[i++]);
		return sum;
	}
public:
	Student() { cur_id = ++cur_id_counter; }
	void getdata() override {
		char buf[101];
		cin >> buf >> age;
		name = buf;
		for (int i = 0; i < MARKS; i++)
			cin >> marks[i];
	}
	void putdata() override {
		cout << name << " " << age << " " << marks_sum() << " " << cur_id << endl;
	}
};

int Professor::cur_id_counter = 0;
int Student::cur_id_counter = 0;
/* End of your code. */
int main() {
	int n, val;
	cin >> n; //The number of objects that is going to be created.
	Person *per[1000]; //original problem: *per[n], but it does not compile here

	for (int i = 0; i < n; i++) {
		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.
	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;
}
