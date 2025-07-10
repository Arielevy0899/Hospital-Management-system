#pragma warning (disable: 4996)


#include <iostream>
using namespace std;

#include "department.h"


 department:: department(const char* name)
{
	 this->name= new char[strlen(name) + 1];
	 strcpy(this->name, name);
	 phisicalNumOfDoctors = 2;  
	 logicalNumOfDoctors = 0;
	 doctorInDepartment = new doctor * [phisicalNumOfDoctors];
	 for (int i = 0; i < phisicalNumOfDoctors; i++)
	 {
		 doctorInDepartment[i] = nullptr;
	 }
}

 department::department(const department& other)
 {
	 *this = other;
 }

 department::~department()
 {
	 //delete[] doctorInDepartment;
 }

void department::setDepartment(const char* name)
{
	strcpy(this->name, name);

}

bool department::addNurse(nurse& other)
{
	if (logicalNumOfNurses == phisicalNumOfNurses)
	{
		phisicalNumOfNurses *= 2;
		nurse** temp = new nurse * [phisicalNumOfNurses];
		for (int i = 0; i < logicalNumOfNurses; i++)
		{
			temp[i] = nurseIndepartment[i];
		}
		delete[] nurseIndepartment;
		nurseIndepartment = temp;
	}
	this->nurseIndepartment[logicalNumOfNurses] = &other;
	logicalNumOfNurses++;
	return true;
	}

bool department::addDoctor(doctor& other)
{
	if (logicalNumOfDoctors == phisicalNumOfDoctors)
	{
		phisicalNumOfDoctors *= 2;
		doctor** temp = new doctor* [phisicalNumOfDoctors];
		for (int i = 0; i < logicalNumOfDoctors; i++)
		{
			temp[i] = doctorInDepartment[i];
		}
		delete[] doctorInDepartment;
		doctorInDepartment = temp;
	}
	this->doctorInDepartment[logicalNumOfDoctors] = &other;
	logicalNumOfDoctors++;
	return true;
}

//void department::printDoctorMembers()
//{
//	for (int i = 0; i < logicalNumOfDoctors; i++) {
//		if (doctorInDepartment[i] != nullptr && doctorInDepartment[i]->getName() != nullptr) {
//			cout << "Name: " << doctorInDepartment[i]->getName() << endl;
//			cout << "Employee ID: " <<  doctorInDepartment[i]->getID() << endl;
//			cout << "specialist: " << doctorInDepartment[i]->getSpecialist() << endl;
//			cout << endl;
//		}
//		else {
//			cout << "Doctor is null or name is null at index " << i << endl;
//		}
//	}
//}

//void department::printNurseMembers()
//{
//	for (int i = 0; i < logicalNumOfNurses; i++) {
//		if (nurseIndepartment[i] != nullptr && doctorInDepartment[i]->getName() != nullptr) 
//		{
//			cout << "Name: " << nurseIndepartment[i]->get_Name() << endl;
//			cout << "Employee ID: " << nurseIndepartment[i]->get_id() << endl;
//			cout << "Time experience: " << nurseIndepartment[i]->get_timeExperience();
//
//		}
//		else {
//			cout << "Doctor is null or name is null at index " << i << endl;
//		}
//	}
//
//}

int department::getNumOfDocInDepartment()
{
	return logicalNumOfDoctors;
}
int department::getNumOfNurseInDepartment()
{
	return logicalNumOfNurses;
}

bool department::addEmployee(Employee& other)
{
	if (logicalnumofEmployees == phisicalnumofEmployees)
	{
		phisicalnumofEmployees *= 2;
		Employee** temp = new Employee * [phisicalnumofEmployees];
		for (int i = 0; i < logicalnumofEmployees; i++)
		{
			temp[i] = allEmployees[i];
		}
		delete[] allEmployees;
		allEmployees = temp;
	}
	this->allEmployees[logicalnumofEmployees] = &other;
	logicalnumofEmployees++;
	return true;
}

void department::printMembers() const
{
	cout << "Members of Department:" << name << endl;
	for (int i = 0; i < logicalnumofEmployees; i++)
	{
		if (doctor* doc = dynamic_cast<doctor*>(allEmployees[i]))
		{
			cout << "Doctor:" << doc->getName() << "| Specialist: " << doc->getSpecialist() << endl;
		}
		else if (nurse* n = dynamic_cast<nurse*>(allEmployees[i]))
		{
			cout << "Nurse: " << n->getName() << " | Experience: " << n->get_timeExperience() << " years" << endl;
		}
		else
			cout << "UNKNOW" << endl;
	}
}