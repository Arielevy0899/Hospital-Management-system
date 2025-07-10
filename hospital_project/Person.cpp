
#include <iostream>
using namespace std;
#include "Person.h"


Person::Person(const char* name )
{
	if (!name) name = "yossi";
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Person::Person(const Person& p): name(nullptr)
{
	*this = p;
	
}

Person::~Person()
{
	delete[] name;
}

void Person::print() const
{
	cout << "Name: " << name << endl;
}