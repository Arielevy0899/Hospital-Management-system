#pragma warning (disable: 4996)
#ifndef __RESEARCH_CENTER_H__
#define __RESEARCH_CENTER_H__
#include "Researcher.h"
#include "Article.h"
#include "Employee.h"
#include "ResearchDoc.h" 

class ResearchCenter
{
private:
	char* name;
	Researcher** allResearchers;
	Article** allArticles;
	int logicalNumOfArt, PhisicalNumOfArt;
	int logicalNumOfResearchers, PhisicalNumOfResearchers;
	int logicalNumOfEmployees, physicalNumOfEmployees;
	Employee** allEmployees;

public:
	ResearchCenter(ResearchCenter& R) = delete;

	ResearchCenter(const char* name = "RCenter", int initialSize = 10) : logicalNumOfResearchers(0), PhisicalNumOfResearchers(initialSize),
		logicalNumOfEmployees(0), physicalNumOfEmployees(initialSize)
	{
		this->name = strdup(name);
		allResearchers = new Researcher * [PhisicalNumOfResearchers];
		allEmployees = new Employee * [physicalNumOfEmployees];
	}

	bool addArticle(const Article& a);

	bool articleExist(const Article& a);

	friend ostream& operator<< (ostream& os, const ResearchCenter& r)
	{
		os << "Name: " << r.name << "\n";
	}

	void setName(const char* name);

	const ResearchCenter& operator= (const ResearchCenter& other) = delete;
	/*{
		if (this != &other)
		{
			if (this->name)
				delete[] name;
			name = strdup(other.name);
		}
		return *this;
	}*/

	void showAllArticles();

	bool addEmployee(const Employee& e);

	bool addResearcher(Researcher* r);

	bool researcherExist( Researcher* r);

	~ResearchCenter();

	bool addEmployee(Employee* e);
};

#endif // !__RESEARCH_CENTER_H__

