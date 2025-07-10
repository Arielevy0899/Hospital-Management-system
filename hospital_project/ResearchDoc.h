#pragma once
#ifndef __RESEARCH_DOC_H__
#define __RESEARCH_DOC_H__

#include "Researcher.h"
#include "doctor.h"

class ResearchDoc : public Researcher , public doctor
{
public:
	ResearchDoc(const ResearchDoc& RD) = delete;

	const ResearchDoc& operator=(const ResearchDoc&) = delete;

	ResearchDoc(const char* name , const char* specialty);

	
	virtual const char* getType() const override { return "ResearchDoc"; }

	void print() const override
	{
		cout << "ResearchDoc:" << name << ", " << "Specialty: " << endl;
	}
};

#endif // __RESEARCH_DOC_H__