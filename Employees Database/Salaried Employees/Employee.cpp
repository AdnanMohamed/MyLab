//This is the implimentation file for the class Employee.
//And the associate class Name.
//
//Written by : Adnan Mohamed

#include<iostream>
#include"Employee.h"
#include<cassert>

using std::cout; using std::cin; using std::endl;

namespace employees_adnan {

	void Name::format_name(std::string& name)
	{
		if (name.length() == 0)
			return;
		// Make all letters lower except the first.
		name[0] = toupper(name[0]);

		for (int i = 1; i < name.length(); ++i)
		{
			name[i] = tolower(name[i]);
		}
	}

	Name::Name(std::string first, std::string last, std::string middle)
	{
		format_name(first);
		format_name(middle);
		format_name(last);
		first_ = first;
		last_ = last;
		middle_ = middle;
	}

	void Name::set_first(std::string first)
	{
		format_name(first);
		first_ = first;
	}

	void Name::set_middle(std::string middle)
	{
		format_name(middle);
		middle_ = middle;
	}

	void Name::set_last(std::string last)
	{
		format_name(last);
		last_ = last;
	}

	std::ostream& operator<<(std::ostream& outs, const Name& n)
	{
		// In case middle name given.
		if (n.middle_ != "")
		{
			outs << n.first_ << " " << n.middle_[0] << ". " << n.last_;
		}
		else
		{
			outs << n.first_ << " " << n.last_;
		}

		return outs;
	}

	bool operator == (const Name& n1, const Name& n2)
	{
		return n1.first_ == n2.first_ && n1.middle_ == n2.middle_
			&& n1.last_ == n2.last_;
	}

	bool operator != (const Name& n1, const Name& n2)
	{
		return !(n1 == n2);
	}

	bool Employee::valid_ID(int ID)
	{
		return ID > 99 && ID < 100000;
	}

	std::ostream& operator<<(std::ostream& outs, const Employee& emp)
	{
		outs << "Name: " << emp.name_ << endl;
		outs << "ID: " << emp.ID_ << endl;
		return outs;
	}

	bool operator <(const Employee& emp1, const Employee& emp2)
	{
		return emp1.ID_ < emp2.ID_;
	}

}

