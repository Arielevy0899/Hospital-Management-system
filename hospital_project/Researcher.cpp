
#include "Researcher.h"
#include <iostream>
using namespace std;

//int Researcher::cnt = 0;

//Researcher::Researcher(const char* name, const char* expertise):employeeID(++cnt)
//{
//	this->expertise = new char[strlen(expertise) + 1];
//	strcpy(this->expertise, expertise);
//}
void Researcher::get() const
{
	cout << "Name: " << name << endl;
	cout << "Expertise: " << expertise << endl;
	cout << "ID: " << employeeID << endl;
}

Researcher::Researcher(const Employee& base, const char* expertise, const char* name): Person(name),Employee(base)
{
	this->expertise = new char[strlen(expertise) + 1];
	strcpy(this->expertise, expertise);
}

void Researcher::print() const
{
	Employee::print();
	cout << "Expertise: " << expertise << endl;


}

void Researcher::addArticle(const Article& article) {
	if (numArticles < MAX_ARTICLES) {
		allArticles[numArticles++] = new Article(article);
	}
	else {
		cout << "Cannot add more articles!" << endl;
	}
}

//Researcher::Researcher(const char* expertise = "clinic"):Person(), Employee(base)
//{
//
//}
