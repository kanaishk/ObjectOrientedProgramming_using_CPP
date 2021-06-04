#include<iostream>
#include<stdlib.h>

using namespace std;

inline void input(string &name, int &age, float &salary)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter salary: ";
    cin >> salary;
}

inline void display(string name, int age, float salary)
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
    cout << "Salary: " << salary << endl;
}

int main()
{
	string name;
	int age;
	float salary;
	system("cls");
	input(name, age, salary);
	cout << endl;
	display(name, age, salary);
	system("pause");
	return 0;
}
