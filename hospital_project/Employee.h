#pragma warning (disable: 4996)
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include "Person.h"
#include <iostream>
using namespace std;

class Employee: virtual public Person
{

protected:
	static int cnt;
	int employeeID;




public:
	Employee(const Person& p);
	int GetEmployeeID() const { return employeeID; }
	Employee(const char* name);
	virtual const char* getType() const { return "Employee"; }
	virtual void print() const;
	virtual ~Employee() {}
	friend ostream& operator <<(ostream& os, const Employee& e)
	{
		os << static_cast<const Person&>(e) << " | ID: " << e.employeeID;
		return os;
	}
};
#endif // __EMPLOYEE_H__