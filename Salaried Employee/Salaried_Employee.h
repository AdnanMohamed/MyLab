// File: Salaried_Employee.h (contains the class Salaried_Employee)
// The class is within namespace salaried_employee_adnan.
// The class is derived from Employee in file: Employee.h
//
// Written by: Adnan Mohamed
// 
// CONSTRUCTOR:
//   Salaried_Employee(employees_adnan::Name name = employees_adnan::Name(" ", " ", ' '), int ID = 0,
//		double salary = 0, double hours_p_month = 0, double hours_worked = 0)
//		  Postcondition: If all given, the employee will have a name, ID number, salary,
//		  hours to work per month, and the actual hours worked.
//
// MUTATORS:
//  void set_salary(double salary);
//	  Precondition: salary >= MINIMUM_WAGE (MINIMUM_WAGE = 300)
//	  Postcondition: The employee's salary is equal to the given salary.
//
//  void set_hours_p_month(double hours_per_month);
//	  Preconditon: hours_per_month >= MINIMUM_HOURS (MINIMUM_HOURS = 40)
//	  Postcondition: The hours per month for the employee to work is to the given hours.
//
//  void set_hours_worked(double hours_worked);
//	  Precondition: hours_worked >= 0
//	  Postcondition: The hours worked in the current month is recorded as given.
//
// ACCESSORS:
//	double get_salary()const
//	  Postcondition: returns the monthly salary of the employee.
//
//	double get_contract_hours()const
//	  Postcondition: returns the monthly hours that was signed in the contract by the employee.
//
//	double get_hours_worked()const
//	  Postcondition: returns the hours the employee actually worked this month.
//
//	const int get_min_wage()const
//	  Postcondition: returns the minimum wage for all employees
//
//	const int get_min_hours()const { return MINIMUM_HOURS; }
//    Postcondition: returns the minimum hours an employee is allowed to work.
//
// MEMBER FUNCTIONS:
//  double get_annual_salary()const
//	  Postcondition: returns the annual salary of the employee.
//
//	void increase_annual_salary(double percent);
//	  Precondition: percentage must be 0 < percent <= 1
//	  Postcondition: The annual salary of the employee will raise be the given rate.
//    Accordingly, the monthly salary will change also.
//
//	double overtime()const;
//	  Postcondition: if the employee works more than the hours he was supposed to.
//	  This will return the amount he shall recieve for the extra hours worked,
//	  else returns zero.
//
//	std::ostream& operator<<(std::ostream& outs, const Salaried_Employee& emp);
//	  Precondition: The emp must have Firs And Last name.
//	  Postcondtion: prints out the employee's info to the where outs is connected.

#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H
#include"../Employee class/Employee.h"

namespace salaried_employee_adnan
{
	class Salaried_Employee : public employees_adnan::Employee
	{
	public:
		// CONSTRUCTOR
		Salaried_Employee(employees_adnan::Name name = employees_adnan::Name(" ", " ", ' '), int ID = 0,
			double salary = 0, double hours_p_month = 0, double hours_worked = 0);

		// Mutators
		void set_salary(double salary);
		void set_hours_p_month(double hours_per_month);
		void set_hours_worked(double hours_worked);

		// Accessors
		double get_salary()const { return salary_; }
		double get_contract_hours()const { return hours_per_month_; }
		double get_hours_worked()const { return hours_worked_; }
		const int get_min_wage()const { return MINIMUM_WAGE; }
		const int get_min_hours()const { return MINIMUM_HOURS; }

		// MEMBER FUNCTIONS:
		double get_annual_salary()const { return salary_ * 12; }
		void increase_annual_salary(double percent);
		double overtime()const;

		// FRIENDS:
		friend std::ostream& operator<<(std::ostream& outs, const Salaried_Employee& emp);

	private:
		double salary_; // monthly in dollars
		double hours_per_month_; // Hours that the employee signed for working each month
		double hours_worked_; // The actual hours worked in a month - Helps tracking overtime-.
		static const int MINIMUM_WAGE = 300;
		static const int MINIMUM_HOURS = 40;
	};

} // End of the namespace

#endif // !SALARIED_EMPLOYEE_H
