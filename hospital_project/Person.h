#pragma warning (disable: 4996)
#ifndef __PERSON_H__
#define __PERSON_H__
#include <iostream>
using namespace std;

class Person {

protected:
	char* name;



public:
     Person(const char* name);
	virtual ~Person();
	const Person& operator= (const Person& other)
	{
		if (this != &other)
		{
			if(this->name)
				delete[] name;
			name = strdup(other.name);
		}
		return *this;
	}
	Person(const Person& p);
	const char* getName() const { return name; }

	virtual const char* getType() const { return "Person"; }

	virtual void print() const;

	friend ostream& operator<<(ostream& os, const Person& p)
	{
		os << "Name: " << p.getName();
		return os;
	}

};
#endif // __PERSON_H__