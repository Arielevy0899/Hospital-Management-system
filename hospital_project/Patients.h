#pragma once

#include "Person.h"


class Patients : public Person
{
	
public:
	enum eSex { male, female };
	Patients(const char* name);
	Patients(const Patients& p);
	Patients(const Person& p, eSex s, const char* date, const char* visitReason);
	~Patients();
	const Patients& operator= (const Patients& other)
	{
		if (this != &other)
		{
			if (this->name)
				delete[] name;
			name = strdup(other.name);
		}
		return *this;
	}
	
	void getPatientName();
	int getID() const { return ID; };
	const char* getDate() const;
	const char* getVisitReason() const;
	Patients::eSex getSex() const;
	virtual const char* getType() const { return "Patient"; }
	

private:
	int ID;
	eSex sex;
	char* visitReason;
	char* date;
	static int cnt;
	








};