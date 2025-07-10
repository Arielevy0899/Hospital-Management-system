#pragma warning (disable: 4996)
#ifndef __RESEARCHER_H__
#define __RESEARCHER_H__
#include <iostream>
using namespace std;

#include"Employee.h"
#include "Article.h"
class Researcher: virtual public Employee
{
private: 

	char* expertise;
	int numArticles;
	const int MAX_ARTICLES = 10;
	Article** allArticles;
public:
	
	//Researcher( const char* expertise="clinic");
	Researcher(const Employee& base, const char* expertise, const char* name);
	friend ostream& operator<< (ostream& os, const Researcher& r)
	{
		os << static_cast<const Employee&>(r) << " | Research expert: " << r.expertise << endl;
		return os;
	}
	//int getID() const { return employeeID; }
	void get() const;

	virtual ~Researcher()
	{
		delete[] expertise;
	}
	virtual const char* getType() const { return "Researcher"; }

	void print() const;

	void addArticle(const Article& article);


};



#endif // !__RESEARCHER_H__
