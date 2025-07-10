#pragma warning (disable: 4996)
#ifndef __DEPARTMENT_H__
#define __DEPARTMENT_H__

#include "doctor.h"
#include "nurse.h"
class doctor;
class nurse;
class department 
{
private:
	char* name;
	nurse** nurseIndepartment;
	doctor** doctorInDepartment;
	Employee** allEmployees;
	int logicalNumOfNurses, phisicalNumOfNurses;
	int logicalNumOfDoctors, phisicalNumOfDoctors;
	int phisicalnumofEmployees, logicalnumofEmployees;
	department(const department& other);
	
public:
	department(const char* name);
	const char* getDepartmentName() const { return name; }
	void setDepartment(const char* name);
	bool addNurse(nurse& other);
	bool addDoctor(doctor& other);
	/*void printDoctorMembers();
	void printNurseMembers();*/
	const department& operator=(const department& other)
	{
		if (this != &other)
		{
			delete[] name;
			name = strdup(other.name);

		}
		return *this;
	}

	friend ostream& operator<< (ostream& os, const department& dep)
	{
		os << "Department: " <<dep.name << "\n" ;
		for (int i = 0; i < dep.logicalnumofEmployees; i++)
		{
			os << " -" << *(dep.allEmployees[i]) << " |Department: " << dep.name << endl;
		}
		return os;
	}

	int getNumOfDocInDepartment();
	int getNumOfNurseInDepartment();
	bool addEmployee(Employee& other);

	~department();

	void printMembers() const;

};
#endif // !__DEPARTMENT_H__
