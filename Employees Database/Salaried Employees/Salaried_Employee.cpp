// This is the implimentation file for the class Salaried_Employee
// The interface is in Salaried_Employee.h
//
// CLASS INVARIANT:
//   1- salary_ should be greater than OR equal to the MINIMUM_WAGE = $300
//   2- hours_per_month should be as specified in the contract ( and >= MINIMUM_HOURS = 40 h/month).
//   3- hours_worked should be >= 0.
//
// @Author: Adnan Mohamed

#include<iostream>
#include"Salaried_Employee.h"
#include<cassert>

namespace salaried_employee_adnan
{

	Salaried_Employee::Salaried_Employee(employees_adnan::Name name, int ID,
		double salary, double hours_p_month, double hours_worked)
		:employees_adnan::Employee(name, ID)
	{
		salary_ = salary;
		hours_per_month_ = hours_p_month;
		hours_worked_ = hours_worked;
	}

	void Salaried_Employee::set_salary(double salary)
	{
		assert(salary >= MINIMUM_WAGE);
		salary_ = salary;
	
	}

	void Salaried_Employee::set_hours_p_month(double hours_per_month)
	{
		assert(hours_per_month >= MINIMUM_HOURS);
		hours_per_month_ = hours_per_month;
	}

	void Salaried_Employee::set_hours_worked(double hours_worked)
	{
		assert(hours_worked >= 0);
		hours_worked_ = hours_worked;
	}

	void Salaried_Employee::increase_annual_salary(double percent)
	{
		assert(percent > 0 && percent <= 1);
		salary_ *= (1 + percent);
	}

	double Salaried_Employee::overtime()const
	{
		double extra_hours = hours_worked_ - hours_per_month_;
		if (extra_hours > 0)
		{
			return extra_hours * (salary_ / hours_per_month_);
		}
		else
			return 0;
	}

	std::ostream& operator<<(std::ostream& outs, const Salaried_Employee& emp)
	{
		outs.setf(std::ios::fixed);
		outs.setf(std::ios::showpoint);
		outs.precision(2);
		outs << employees_adnan::Employee(emp);
		outs << "Monthly Salary: $" << emp.salary_ << std::endl;
		outs << "Annual Salary: $" << emp.get_annual_salary() << std::endl;
		outs << "Contract Working Hours (per month): " << emp.hours_per_month_ <<" hours/ month"<< std::endl;
		double extra_hours = emp.hours_worked_ - emp.hours_per_month_;
		if (extra_hours > 0)
		{
			outs << "Overtime Hours: " << extra_hours << " hours" << std::endl;;
			outs << "Overtime Pay: $" << emp.overtime() << std::endl;
		}
		outs << "------------------------\n";
		return outs;
	}

}// End of namespace