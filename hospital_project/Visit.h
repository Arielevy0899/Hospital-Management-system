#pragma once
#ifndef __VISIT_H__
#define __VISIT_H__
#include"Patients.h"
#include"Person.h"



class Visit
{
private: 
	Patients* patient;
	int PatientsNum;
	int phisicalnumofPatients, logicalnumofPatients;
	Person* staffMember;
	char* department;
	char* date;
	char* visitReason;


public:
	Visit(Patients* p, const char* dept, const char* visitDate, const char* visitReason, Person* staff);
	bool checkVisit(const Patients& p);
	Visit(const Visit& other);
	const Visit& operator=(const Visit& other) {
        if (this != &other) {
            delete[] department;
            delete[] date;
            delete[] visitReason;

            department = new char[strlen(other.department) + 1];
            strcpy(department, other.department);

            date = new char[strlen(other.date) + 1];
            strcpy(date, other.date);

            visitReason = new char[strlen(other.visitReason) + 1];
            strcpy(visitReason, other.visitReason);

            patient = other.patient;
            staffMember = other.staffMember;
        }
        return *this;
    }
    void printVisitDetails() const;
    Patients* getPatient() const { return patient; }
    const char* getDepartment() const { return department; }
    const char* getDate() const { return date; }
    const char* getReason() const { return visitReason; }
    Person* getStaffMember() const { return staffMember; }

    ~Visit();

};

#endif // __VISIT_H__