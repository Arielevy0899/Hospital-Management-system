#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

#include"Patients.h"
int Patients::cnt = 0;

Patients::Patients(const char* name):Person(name), ID(++cnt)
{
}
Patients::Patients(const Person& p, eSex s,const char* date, const char* visitReason):Person(p),ID(++cnt)
{
	this->sex = s;
}

Patients::Patients(const Patients& p):Person(p) , ID(++cnt)
{
	*this = p;
}

void Patients::getPatientName()
{
	cout << "Patient's name is " << name << endl;
}



Patients:: ~Patients()
{
	//delete[] name;

}

const char* Patients::getDate() const {
	return date;
}

const char* Patients::getVisitReason() const {
	return visitReason;
}

Patients::eSex Patients::getSex() const {
	return sex;
}
