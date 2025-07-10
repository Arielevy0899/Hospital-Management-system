
#include "ResearchDoc.h"
#include <iostream>
using namespace std;

ResearchDoc::ResearchDoc(const char* name, const char* specialty):Person(name),Employee(name),doctor(Employee(name),specialty,"yossi"), Researcher(Employee("yossi"),"clinic","yossi")
{

}





