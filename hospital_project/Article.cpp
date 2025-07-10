
#include "Article.h"
#include <iostream>
using namespace std;

int Article::cnt = 0;


Article::Article(const char* name, const char* PublicationDate, int pages):numOfArticles(++cnt)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->numOfPages = pages;
	this->PublicationDate = new char[strlen(PublicationDate) + 1];
	strcpy(this->PublicationDate, PublicationDate);
}

Article::Article(const Article& a)
{
	*this = a;
}

void Article::showAllArticles()
{
	
		cout << "Article name: " << name << endl;
		cout << "Publication date: " << PublicationDate << endl;
		cout << "Number of pages: " << numOfPages << endl;
	
}




Article::~Article()
{
	delete[] name;
	delete[] PublicationDate;
}