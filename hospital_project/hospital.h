#pragma once
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "doctor.h"
#include "nurse.h"
#include"department.h"
#include "Researcher.h"
#include "ResearchCenter.h"
#include "Employee.h"
#include "Patients.h"
#include "Visit.h"
#include "Article.h"
#include "Date.h"
#include <iostream>
using namespace std;


class hospital
{
private:
	char* name;
	int numberOfdoctor;
	int numberOfnurse;
	/*doctor** alldoctor;
	nurse** allnurse;*/
	department** allDepartments;
	Researcher* allResearchers;
	ResearchCenter center;
	Employee** allEmployees;
	Patients** allPatients;
	Visit** allVisits;
	Article** allArticles;
	Date* date;
	int phisicalnumofPatients, logicalnumofPatients;
	int phisicalnumofDoctors, logicalnumofDoctors;
	int phisicalnumofNurses, logicalnumofNurses;
	int phisicalnumofDepartments, logicalnumofDepartments;
	int phisicalnumofResearchers, logicalnumofResearchers;
	int phisicalnumofEmployees, logicalnumofEmployees;
	int phisicalnumofVisits, logicalnumofVisits;
	int phisicalnumofArticles, logicalnumofArticles;
	

	hospital(const hospital& other);

public:
	hospital(const char* name)
	{
		cout << "hospital create" << endl;
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
	}
	~hospital();

	Patients* findPatientByID(int patientID);

	Researcher* getResearcherByName(const char* name);

	void set(const char* name);

	const char* get() { return name; }

	void gethospital();

	bool addDoctor( const doctor& d , const char* depart);

	bool addNurse(const nurse& n, const char* depart);

	bool doctorExist(const doctor& d);

	bool nurseExist(const nurse& n);

	void deleteHospital();

	int findDocByID(int ID);

	//string getDocName(int index) { return alldoctor[index]->getName(); }
	//string getNurseName(int index) { return allnurse[index]->get_Name(); }

	int findNurseByID(int ID);

	bool departmentExist(const department& d);

	bool addDepartment( const char* name);

	void printDepartmentMembers(const char* departmentName);

	int findNurseByName(const char* name);

	//void printDepartmentNurseMembers(const char* departmentName);

	void printAllDepartments();

	bool findDocByName(const char* name);

	void gethospitalMembersSortedByDepartment();

	bool addResearcher(const Researcher& r);

	bool ResearcherExist(const Researcher& r);

	friend ostream& operator<< (ostream& os, const hospital& h)
	{
		os << "Hospital: " << h.name << endl;
		for (int i = 0; i < h.logicalnumofDepartments; i++)
		{
			os << *(h.allDepartments[i]) << endl;
		}return os;
	}

	bool addEmployee(const Employee& e , const char* specialist, int choice, const char* depart, int timeExp=0);

	bool EmployeeExist(const Employee& e);

	void setResearchCenter(const char* name);

	bool patientExist(const Patients& p);

	bool addPatient(const Patients& d, const char* depart);

	 void printAllMedicalStaff() ;

	 bool addResearcher(Researcher* r);

	 bool addEmployee(Employee* e);

	 const hospital& operator=(const hospital& h) = delete;
};
#endif // !HOSPITAL_H
