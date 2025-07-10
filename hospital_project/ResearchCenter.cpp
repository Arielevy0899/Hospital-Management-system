#pragma warning (disable: 4996)


#include <iostream>
using namespace std;
#include "ResearchCenter.h"

//ResearchCenter::ResearchCenter(const char* name)
//{
//	this->name = new char[strlen(name) + 1];
//	strcpy(this->name, name);
//}

void ResearchCenter::showAllArticles()
{
	for (int i = 0; i < logicalNumOfArt; i++)
	{
		allArticles[i]->showAllArticles();
	}
}

bool ResearchCenter::addArticle(const Article& a)
{
	if (articleExist(a))
	{
		cout << "Article exist\n";
		return false;
	}
	if (logicalNumOfArt == PhisicalNumOfArt)
	{
		PhisicalNumOfArt *= 2;
		Article** temp = new Article * [PhisicalNumOfArt];
		for (int i = 0; i < logicalNumOfArt; i++)
		{
			temp[i] = allArticles[i];
		}
		delete[] allArticles;
		allArticles = temp;
	}
	allArticles[logicalNumOfArt] = new Article(a);
	logicalNumOfArt++;
	return true;
}


bool ResearchCenter::articleExist(const Article& a)
{
	for (int i = 0; i < logicalNumOfArt; i++)
	{
		if (allArticles[i]->showName() == a.showName())
			return true;
	}
	return false;


}



ResearchCenter::~ResearchCenter()
{
	delete[] name;
	delete[] allEmployees;
	delete[] allResearchers;
	delete[] allArticles;
}

//bool ResearchCenter::addResearcher(const Researcher& r)
//{
//	if (researcherExist(r))
//	{
//		return false;
//	}
//	if (logicalNumOfResearchers == PhisicalNumOfResearchers)
//	{
//		PhisicalNumOfResearchers *= 2;
//		Researcher** temp = new Researcher * [PhisicalNumOfResearchers];
//		for (int i = 0; i < logicalNumOfResearchers; i++)
//		{
//			temp[i] = allResearchers[i];
//		}
//		delete[] allResearchers;
//		allResearchers = temp;
//	}
//	allResearchers[logicalNumOfResearchers] = new Researcher(r);
//
//	logicalNumOfResearchers++;
//
//	return true;
//}
//
//bool ResearchCenter::researcherExist( Researcher* r)
//{
//	for (int i = 0; i < logicalNumOfResearchers; i++)
//	{
//		if (allResearchers[i]->getID() == r->getID())
//			return false;
//		return true;
//	}
//}

bool ResearchCenter::addResearcher(Researcher* r)
{
	/*if (researcherExist(r)) 
	{
		return false;
	}*/

	if (logicalNumOfResearchers == PhisicalNumOfResearchers)
	{
		PhisicalNumOfResearchers *= 2;
		Researcher** temp = new Researcher * [PhisicalNumOfResearchers];

		for (int i = 0; i < logicalNumOfResearchers; i++)
		{
			temp[i] = allResearchers[i];
		}

		delete[] allResearchers;
		allResearchers = temp;
	}

	allResearchers[logicalNumOfResearchers] = r; 
	logicalNumOfResearchers++;
	addEmployee(r);
	return true;
}

bool ResearchCenter::addEmployee(Employee* e) {
	if (logicalNumOfResearchers == PhisicalNumOfResearchers) {
		PhisicalNumOfResearchers *= 2;
		Employee** temp = new Employee * [PhisicalNumOfResearchers];
		for (int i = 0; i < logicalNumOfResearchers; i++)
			temp[i] = allEmployees[i];
		delete[] allEmployees;
		allEmployees = temp;
	}

	allEmployees[logicalNumOfResearchers] = e;
	logicalNumOfResearchers++;

	return true;
}

//bool ResearchCenter::addResearcher(Researcher* r) {
//	if (r == nullptr) return false;
//
//	for (int i = 0; i < logicalNumOfResearchers; i++) {
//		if (allEmployees[i] == r) {
//			cout << r->getName() << " is already an employee. Adding reference only.\n";
//			return true;
//		}
//	}
//
//	ResearchDoc* researchDoc = dynamic_cast<ResearchDoc*>(r);
//	if (researchDoc) {
//		std::cout << researchDoc->getName() << " is a doctor-researcher. Adding reference only.\n";
//		return true;
//	}
//	else {
//		if (logicalNumOfResearchers == PhisicalNumOfResearchers) {
//			PhisicalNumOfResearchers *= 2;
//			Researcher** temp = new Researcher * [PhisicalNumOfResearchers];
//			for (int i = 0; i < logicalNumOfResearchers; i++)
//				temp[i] = allResearchers[i];
//			delete[] allResearchers;
//			allResearchers = temp;
//		}
//
//		allResearchers[logicalNumOfResearchers] = new Researcher(*r); 
//		logicalNumOfResearchers++;
//
//		std::cout << r->getName() << " is a researcher. Creating new instance in ResearchCenter.\n";
//		return true;
//	}
//}

void ResearchCenter::setName(const char* name)
{
	delete[] name;
	this->name = strdup(name);

}
