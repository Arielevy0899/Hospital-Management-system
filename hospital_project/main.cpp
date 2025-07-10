#pragma warning (disable: 4996)

/* Hospital project for C++ OOP course */
/* By: Ariel Levy 209177864 and Ofek Kirshinboim 206385676 */
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "hospital.h"
#include "department.h"
#include "doctor.h"
#include "nurse.h"
#include "Patients.h"
#include "Visit.h"
#include "Researcher.h"
#include "ResearchDoc.h"
#include "ResearchCenter.h"
#include "Article.h"

using namespace std;

int main() {
    hospital myHospital("Shiba Hospital");

    cout << "--------------- Hospital project C++ OOP ------------ " << endl;
    cout << "------------ By: Ariel Levy & Ofek Kirshinboim ------------" << endl;
    cout << "**************************************************************************" << endl;
    bool res;
    res = myHospital.addDepartment("Cardiology");
    res = myHospital.addDepartment("Neuroscience");

    doctor* doc1 = new doctor(Employee("Alice") , "Cardiology" , "yossi");
    res = myHospital.addEmployee(doc1);

    nurse* nurse1 = new nurse("Nurse Betty", 5);
    res = myHospital.addEmployee(nurse1);

    Researcher* researcher1 = new Researcher(Employee("Dr. Charlie"), "Neuroscience" , "momo");
    res = myHospital.addEmployee(researcher1);

    ResearchDoc* rd1= new ResearchDoc("Dr. Daniel", "Brain Research");
    res = myHospital.addEmployee(rd1);
    int choice;

    do {
        cout << "Hospital Management System\n";
        cout << "1. Add Department\n";
        cout << "2. Add Nurse to a Department\n";
        cout << "3. Add Doctor to a Department\n";
        cout << "4. Add Patient Visit\n";
        cout << "5. Add Researcher to Research Center\n";
        cout << "6. Add Article to Researcher\n";
        cout << "7. Show Patients in a Department\n";
        cout << "8. Show All Medical Staff\n";
        cout << "9. Show All Researchers\n";
        cout << "10. Search Patient by ID\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: "; 
        cin >> choice;
        if (cin.fail()) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input or empty line. Try again.\n";
        }
        else {
          
            cout << "You entered " << choice << endl;
        }

        switch (choice) {
        case 1: {
            char departmentName[50];
            cout << "Enter department name: ";
            cin >> departmentName;
            myHospital.addDepartment(departmentName);
            break;
        }
        case 2: {
            char nurseName[50], departmentName[50];
            int experience;
            cout << "Enter nurse name: ";
            cin >> nurseName;
            cout << "Enter experience years: ";
            cin >> experience;
            cout << "Enter department: ";
            cin >> departmentName;

            nurse* newNurse = new nurse(nurseName, experience);
            myHospital.addEmployee(newNurse);
            break;
        }
        case 3: {
            char doctorName[50], specialty[50], departmentName[50];
            cout << "Enter doctor name: ";
            cin >> doctorName;
            cout << "Enter specialty: ";
            cin >> specialty;
            cout << "Enter department: ";
            cin >> departmentName;

            doctor* newDoctor = new doctor(Employee(doctorName), specialty, doctorName);
            myHospital.addEmployee(newDoctor);
            break;
        }
        case 4: {
            char patientName[50], departmentName[50], visitReason[50];
            cout << "Enter patient name: ";
            cin >> patientName;
            cout << "Enter department: ";
            cin >> departmentName;
            cout << "Enter visit reason: ";
            cin >> visitReason;

            Patients* newPatient = new Patients(patientName);
            myHospital.addPatient(*newPatient, departmentName);
            break;
        }
        case 5: {
            char researcherName[50], expertise[50];
            cout << "Enter researcher name: ";
            cin >> researcherName;
            cout << "Enter expertise: ";
            cin >> expertise;

            Researcher* newResearcher = new Researcher(Employee(researcherName), expertise, "momo");
            myHospital.addEmployee(newResearcher);
            break;
        }
        case 6: {
            char researcherName[50], articleName[50], journal[50];
            int numPages;
            cout << "Enter researcher name: ";
            cin >> researcherName;
            cout << "Enter article name: ";
            cin >> articleName;
            cout << "Enter journal name: ";
            cin >> journal;
            cout << "Enter number of pages: ";
            cin >> numPages;

            Researcher* researcher = myHospital.getResearcherByName(researcherName);
            if (researcher) {
                Article* newArticle = new Article(articleName, journal, numPages);
                researcher->addArticle(*newArticle);
                cout << "Article added successfully!\n";
            }
            else {
                cout << "Researcher not found!\n";
            }
            break;
        }
        case 7: {
            char departmentName[50];
            cout << "Enter department name: ";
            cin >> departmentName;
            myHospital.printDepartmentMembers(departmentName);
            break;
        }
        case 8:
            myHospital.printAllMedicalStaff();
            break;
        case 9:
            cout << myHospital << endl;;
            break;
        case 10: {
            int patientID;
            cout << "Enter patient ID: ";
            cin >> patientID;
            Patients* p = myHospital.findPatientByID(patientID);
            if (p)
                p->getPatientName();
            else
                cout << "Patient not found.\n";
            break;
        }
        case 11:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 11);

    return 0;
}





































