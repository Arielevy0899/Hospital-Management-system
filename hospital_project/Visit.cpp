
#include "Visit.h"
#include <iostream>
using namespace std;

Visit::Visit(const Visit& other) : patient(other.patient), staffMember(other.staffMember)
{
	department = new char[strlen(other.department) + 1];
	strcpy(department, other.department);

	date = new char[strlen(other.date) + 1];
	strcpy(date, other.date);

	visitReason = new char[strlen(other.visitReason) + 1];
	strcpy(visitReason, other.visitReason);
}

bool Visit::checkVisit(const Patients& p)
{
	return true;
}

Visit::Visit(Patients* p, const char* dept, const char* visitDate, const char* visitReason, Person* staff)
    : patient(p), staffMember(staff)
{
    if (dept)
    {
        department = new char[strlen(dept) + 1];
        strcpy(department, dept);
    }
    else
    {
        department = nullptr;
    }

    if (visitDate) 
    {
        date = new char[strlen(visitDate) + 1];
        strcpy(date, visitDate);
    }
    else 
    {
        date = nullptr;
    }

    if (visitReason)
    {
        this->visitReason = new char[strlen(visitReason) + 1];
        strcpy(this->visitReason, visitReason);
    }
    else
    {
        this->visitReason = nullptr;
    }
}

Visit:: ~Visit()
{
	delete[] department;
	delete[] date;
	delete[] visitReason;
}

void Visit::printVisitDetails() const {
	cout << "Patient Name: " << patient->getName() << endl;
	cout << "Department: " << department << endl;
	cout << "Visit Date: " << date << endl;
	cout << "Visit Reason: " << visitReason << endl;
	cout << "Staff Member: " << staffMember->getName() << endl;
}
