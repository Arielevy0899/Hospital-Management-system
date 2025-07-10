#ifndef NURSE_H
#define NURSE_H


#pragma warning (disable: 4996)
#include "Employee.H"

class department;  

class nurse: public Employee
{
private:

	int timeExperience;

public:
	nurse(const Employee& base, int timeExperience);
	
	void setExperience( int timeExperience);
	void get() const;
	int get_id() const { return employeeID; }
	const char* get_Name() const { return name; }
	int get_timeExperience() const { return timeExperience; }
	const nurse& operator= (const nurse& other)
	{
		if (this != &other)
		{
			delete[] name;
			name = strdup(other.name);
			employeeID = other.employeeID;
			timeExperience = other.timeExperience;
		}
		return *this;
	}
	friend ostream& operator<< (ostream& os, const nurse& n)
	{
		os << static_cast<const Employee&> (n) << " | Expertise: " << n.timeExperience << " years";
		return os;
	}
	virtual const char* getType() const { return "Nurse"; }

	void print() const;



};
#endif // !NURSE_H