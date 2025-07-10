

#include<iostream>
using namespace std;
#include "hospital.h"

 
 bool hospital::departmentExist(const department& d)
 {
	 for (int i = 0; i < logicalnumofDepartments; i++)
	 {
		 if (strcmp(allDepartments[i]->getDepartmentName(), d.getDepartmentName()) == 0)
			 return true;

	 }
	 return false;
 }

 bool hospital::addDepartment(const char * name)
 {
	 if (departmentExist(name))
	 {
		 return false;
	 }
	 if (logicalnumofDepartments == phisicalnumofDepartments)
	 {
		 phisicalnumofDepartments *= 2;
		 department** temp = new department * [phisicalnumofDepartments];
		 for (int i = 0; i < logicalnumofDepartments; i++)
		 {
			 temp[i] = allDepartments[i];
		 }
		 delete[] allDepartments;
		 allDepartments = temp;
	 }
	 allDepartments[logicalnumofDepartments] =  new department(name);
	 logicalnumofDepartments++;
	 return true;
 }

 void hospital::printDepartmentMembers(const char* departmentName)
 {
	 for (int i = 0; i < logicalnumofDepartments; i++)
	 {
		 if (strcmp(allDepartments[i]->getDepartmentName(), departmentName) == 0)
		 {
			

				 allDepartments[i]->printMembers();
			 
		 }
		 else
		 {
			 cout << "Invalid department" << endl;
		 }
	 }
 }

 void hospital::printAllDepartments()
 {
	 for (int i = 0; i < logicalnumofDepartments; i++)
	 {
		cout <<  allDepartments[i]->getDepartmentName();
	 }
 }

 void hospital::gethospitalMembersSortedByDepartment()
 {
	 for (int i = 0; i < logicalnumofDepartments; i++)
	 {
		 cout << "department: " << allDepartments[i]->getDepartmentName() << endl;
		 cout << "Contains:  " << endl;
		 cout << allDepartments[i]->getNumOfDocInDepartment() << " doctors: \n";
		 allDepartments[i]->printMembers();
	 }
	 
	 for (int i = 0; i < logicalnumofDepartments; i++)
	 {
		
		 cout << "Contains:  " << endl;
		 cout << allDepartments[i]->getNumOfNurseInDepartment() << " nurses: \n";
		 allDepartments[i]->printMembers();
		 cout << endl;
	 }
 }

 bool hospital::addResearcher(Researcher* r)
 {
	 return center.addResearcher(r);
 }

 bool hospital::addEmployee(Employee* e)
 {
	 if (logicalnumofEmployees == phisicalnumofEmployees)
	 {
		 cout << "-------------";
		 phisicalnumofEmployees *= 2;
		 Employee** temp = new Employee * [phisicalnumofEmployees];
		 for (int i = 0; i < logicalnumofEmployees; i++)
			 temp[i] = allEmployees[i];
		 delete[] allEmployees;
		 allEmployees = temp;
	 }

	 allEmployees[logicalnumofEmployees] = e;
	 logicalnumofEmployees++;

	 Researcher* researcher = dynamic_cast<Researcher*>(e);
	 if (researcher) 
	 {
		 center.addEmployee(e);
		 center.addResearcher(researcher);
	 }

	 return true;
 }

 Researcher* hospital::getResearcherByName(const char* name)
 {
	 for (int i = 0; i < logicalnumofResearchers; i++) 
	 {
		 if (strcmp(allResearchers[i].getName(), name) == 0) 
		 {
			 return &allResearchers[i];
		 }
	 }
	 return nullptr;
 }

 Patients* hospital::findPatientByID(int patientID) 
 {
	 for (int i = 0; i < logicalnumofPatients; i++) 
	 {
		 if (allPatients[i]->getID() == patientID) 
		 {  
			 return allPatients[i];
		 }
	 }
	 return nullptr;  
 }

 bool hospital::EmployeeExist(const Employee& e)
 {
	 for (int i = 0; i < logicalnumofEmployees; i++)
	 {
		 if (allEmployees[i]->GetEmployeeID() == e.GetEmployeeID())
			 return true;
	 }
	 return false;
 }

 void hospital::setResearchCenter(const char* name)
 {
	 center.setName(name);
	
 }

 bool hospital::patientExist(const Patients& p)
 {
	 for (int i = 0; i < logicalnumofPatients; i++)
	 {
		 if (allPatients[i]->getID() == p.getID())
			 return true;

	 }
	 return false;
 }

 bool hospital::addPatient(const Patients& p,  const char* depart)
 {
	 /*if (patientExist(p))
	 {
		 cout << "Patient already exists in the system.\n";
		 return false;
	 }*/

	 if (logicalnumofPatients == phisicalnumofPatients)
	 {
		 phisicalnumofPatients *= 2;
		 Patients** temp = new Patients * [phisicalnumofPatients];
		 for (int i = 0; i < logicalnumofPatients; i++)
		 {
			 temp[i] = allPatients[i];
		 }
		 delete[] allPatients;
		 allPatients = temp;
	 }

	 allPatients[logicalnumofPatients] = new Patients(p); 
	 logicalnumofPatients++;

	 for (int i = 0; i < logicalnumofDepartments; i++) {
		 if (strcmp(allDepartments[i]->getDepartmentName(), depart) == 0)
		 {
			 Visit* newVisit = new Visit(allPatients[logicalnumofPatients - 1],
				 depart,
				 allPatients[logicalnumofPatients - 1]->getDate(),
				 allPatients[logicalnumofPatients - 1]->getVisitReason(),
				 nullptr);

			 if (logicalnumofVisits == phisicalnumofVisits)
			 {
				 phisicalnumofVisits *= 2;
				 Visit** tempVisits = new Visit * [phisicalnumofVisits];
				 for (int j = 0; j < logicalnumofVisits; j++) {
					 tempVisits[j] = allVisits[j];
				 }
				 delete[] allVisits;
				 allVisits = tempVisits;
			 }
			 allVisits[logicalnumofVisits] = newVisit;
			 logicalnumofVisits++;

			 cout << "Patient and visit added successfully to department: " << depart << endl;
			 return allPatients[logicalnumofPatients];
		 }
	 }
	 cout << "Department not found: " << depart << endl;
	 return allPatients[logicalnumofPatients];
 }

 void hospital::printAllMedicalStaff()
 {
	 for (int i = 0; i < logicalnumofEmployees; i++)
	 {
		 allEmployees[i]->print();
	 }

 }

hospital ::  ~hospital() 
{
	cout << "----------------";
	delete[] name; 
	for (int i = 0; i < phisicalnumofDepartments; i++)
	{
		delete allDepartments[i];
	}
	delete[] allDepartments;
	
	for (int i = 0; i < phisicalnumofVisits; i++)
	{
		delete allVisits[i];
	}
	delete[] allVisits;
	for (int i = 0; i < phisicalnumofEmployees; i++)
	{
		delete allEmployees[i];
	}
	delete[] allEmployees;
	for (int i = 0; i < phisicalnumofPatients; i++)
	{
		delete allPatients[i];
	}
	delete[] allPatients;
	cout << " All memory free\n";
}
