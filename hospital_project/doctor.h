#pragma warning (disable: 4996)
#ifndef __DOCTOR_H__
#define __DOCTOR_H__
#include "Employee.h"
#include <iostream>
using namespace std;
class department;  

class doctor: virtual public Employee
{
private:
	//char* name;
	char* specialist;
	//int employeeID;
public:
	void  get() const;
	int getID() const { return employeeID; }
	const char* getSpecialist() const { return specialist; }
	const char* getName() const { return name; }
	const doctor& operator= (const doctor& other)
	{
		if (this != &other)
		{
			delete[] name;
			delete[] specialist;
			name = strdup(other.name);
			specialist = strdup(other.specialist);
		}
		return *this;
	}
	//doctor(const doctor& other);
	//doctor(const char* name, const char* specialist);
	doctor(const Employee& base, const char* specialist, const char* name);

	//doctor(const char* name, const char* specialty);

	virtual const char* getType() const { return "Doctor"; }

	virtual ~doctor();
	friend ostream& operator<< (ostream& os, const doctor& d)
	{
		os << static_cast<const Employee&>(d) << " | Specialty: " << d.specialist;
		return os;
	}

	void print() const;
};
#endif // __DOCTOR_H__