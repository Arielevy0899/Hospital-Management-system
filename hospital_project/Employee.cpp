#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

#include"Employee.h"

int Employee::cnt = 0;

Employee::Employee(const Person& p) : Person(p), employeeID(++cnt)
{
}

Employee::Employee(const char* name) : Person(name), employeeID(++cnt) {}

void Employee:: print() const
{
	Person::print();
	cout << "Employee ID: " << employeeID << endl;

}

