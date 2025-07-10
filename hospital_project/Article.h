#pragma once
#pragma warning (disable: 4996)
#ifndef __ARTICLE_H__
#define __ARTICLE_H__
#include <iostream>
using namespace std;


class Article
{
private:
	char* name;
	int numOfPages;
	char* PublicationDate;
	int numOfArticles;
	static int cnt;

public:
	Article(const char* name, const char* PublicationDate, int pages);
	Article(const Article& a);
	const Article& operator= (const Article& other)
	{
		if (this != &other)
		{
			if (this->name)
				delete[] name;
			name = strdup(other.name);
			if (this->PublicationDate)
				delete[] PublicationDate;
			PublicationDate= strdup(other.PublicationDate);
		}
		
		return *this;
	}
	void showAllArticles() ;
	
	string showName() const { return name; }
	~Article();
};
#endif // !__ARTICLE_H__
