#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

#include "doctor.h"

//doctor::doctor(const doctor& other) 
//{
//	*this = other;
//
//}

//doctor::doctor(const char* name, const char* specialist) :employeeID(++cnt)
//{
//	this->name = new char[strlen(name) + 1];
//	this->specialist= new char[strlen(specialist) + 1];
//	strcpy(this->name,name);
//	strcpy(this->specialist , specialist);
//}

doctor::doctor(const Employee& base, const char* specialist, const char* name):Person(name),Employee(base)
{
	this->specialist = new char[strlen(specialist) + 1];
	strcpy(this->specialist, specialist);
}


void doctor::get() const
{
	cout << "Name: " << name << endl;
	cout << "Specialist: " << specialist << endl;
	cout << "ID: " << employeeID << endl;
}

doctor::~doctor()
{	
	//delete[] name;
	delete[] specialist;
}

void doctor::print() const
{
	cout << "Doctor: \n";
	Employee::print();
	cout << "Specialist: " << specialist << endl;
}