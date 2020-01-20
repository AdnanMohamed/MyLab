//This is the implimentation file for the class Employee.
//And the associate class Name.
//
//Written by : Adnan Mohamed

#include<iostream>
#include"Employee.h"
#include<cassert>

using std::cout; using std::cin; using std::endl;

namespace employees_adnan {

	std::ostream& operator<<(std::ostream& outs, const Name& name)
	{
		assert(name.first_name != " " && name.last_name != " ");

		if (name.middle_initial == ' ')
		{
			cout << name.first_name << " " << name.last_name << endl;
		}
		else if (name.first_name == " ")
		{
			cout << name.last_name << endl;
		}
		else if (name.last_name == " ")
		{
			cout << name.first_name << endl;
		}
		else
			cout << name.first_name << " " << name.middle_initial << ". " << name.last_name << endl;

		return outs;
	}

	bool Employee::valid_ID(int ID)
	{
		return ID > 99 && ID < 100000;
	}

	void Employee::set_ID(int ID)
	{
		if (valid_ID(ID))
		{
			ID_ = ID;
		}
		else
			cout << "INVALID ID!";
	}

	std::ostream& operator<<(std::ostream& outs, const Employee& emp)
	{
		outs << "Name: " << emp.name_;
		outs << "ID: " << emp.ID_ << endl;
		return outs;
	}
}

