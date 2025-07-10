#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

#include "nurse.h"

//int nurse::cnt = 0;

nurse::nurse(const Employee& base, int timeExperience):Person(base.getName()),Employee(base), timeExperience(timeExperience)
{

}


//nurse::nurse(const nurse& other)
//{
//	*this = other;
//}

//nurse::nurse(const char* name, int timeExperience) : employeeID(++cnt)
//{
//	this->name = new char[strlen(name) + 1];
//	this->employeeID = employeeID;
//	strcpy(this->name, name);
//	this->timeExperience = timeExperience;
//}

void nurse::setExperience(const int timeExperience)
{
	this->timeExperience = timeExperience;
}

void nurse::get() const
{
	cout << "Name: " << name << ", ID: " << employeeID << endl;
	cout << "Nurse have: " << timeExperience << " years of experience " << endl;
}

void nurse::print() const
{
	cout << "Nurse: \n";
	Employee::print();
	cout << "Time experience : " << timeExperience << endl;
}

