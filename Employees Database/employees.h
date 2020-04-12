// This is the implementation file for the class employees.
// employees is a collection class storing the record for the employees
// of a firm.
// Class is within namespace employees_db_adnan
//
//  --------Copyright ©-------- -
//  @Author: Adnan Hashem Mohamed
// ------------------------------ -
//
// CONSTRUCTOR
//  employees()
//	 Postcondition: initializes an empty employees class (no employees).
//
// MODIFICATION MEMBER VARIABLES
//	void add_employee(employee& emp)
//	 Postcondition: The given employee is added to the employees.
//
//  void remove_employee(int id)
//   Precondition: There exists an employee with the specified id.
//	 Postcondition: The employee is removed from the record.
//
//	std::vector<employee> get_employees(const name& emp_name)
//	 Postcondition: employees with the name emp_name are filled in the 
//	 returned vector. (could be an empty vector if no employees have such a name).
//
//  employee& get_employee(int id)
//	 Precondition: There exists an employee with the specified name.
//	 Postcondition: A reference of the employee is returned.
//
//	void raise_salary(int id, double percent)
//	 Precondition: There exists an employee with the specified. 
//	 percentage must be 0 < percent <= 1
//	 Postcondition: The employee's ANNUAL salary is raised by the given percent.
//
//	void raise_salary_all(double percent)
//	 Precondition: There exists an employee with the specified. 
//	 percentage must be 0 < percent <= 1
//	 Postcondition: ALL employees' ANNUAL salaries are raised by the 
//   specified percent.
//
//  NON-MODIFICATION MEMBER FUNCTIONS
//	
//	employee get_employee(int id)const;
//	 Precondition: There exists an employee with the specified id.
//	 Postcondition: A copy of the employee's is returned.
//
//	std::vector<employee> get_employees(const name& emp_name)
//	 Postcondition: A vector of employees of the given name is returned.
//   ( Could be an empty vector if no employee holds emp_name)
//
//	std::size_t count(const name& emp_name)const
//	 Postcondition: returns the number of employees holding the same 
//	 name (first middle_initial and last).
//	
//	std::size_t count(double salary)const
//	 Postcondition: returns the number of employees which have
//	 a (monthly) salary greater than or equal to the specified salary.
//
//	bool exists(int id)const
//	 Postcondition: Returns true iff there exists an employee with the specified id.
//
//	bool exists(const name& emp_name)const
//	 Postcondition: Returns true iff there exists an employee with the same name (first middle_initial and last)
//
//  std::size_t how_many()const
//	 Postcondition: Returns the total number of employees in the system.
//
#ifndef EMPLOYEES_DATABASE_H
#define EMPLOYEES_DATABASE_H

#include"Salaried Employees/Salaried_Employee.h"
#include"binary search tree/bst_tree.h"
#include<vector>

namespace employees_db_adnan {

	class employees {
	public:
		typedef salaried_employee_adnan::Salaried_Employee employee;
		typedef employees_adnan::Name name;

		// CONSTRUCTOR
		employees();
		
		// MODIFICATION MEMBER VARIABLES
		void add_employee(employee& emp) { emp_db.insert(emp); }
		void remove_employee(int id);
		std::vector<employee> get_employees(const name& emp_name);
		employee& get_employee(int id);
		void raise_salary(int id, double percent);
		void raise_salary_all(double percent);

		// NON-MODIFICATION MEMBER FUNCTIONS
		employee get_employee(int id)const;
		std::size_t count(const name& emp_name)const;
		std::size_t count(double salary)const;
		bool exists(int id)const { return emp_db.is_present(employee(name(), id)); }
		bool exists(const name& emp_name)const;
		std::size_t how_many()const { return emp_db.size(); }

	private:
		bst_adnan::bst<employee> emp_db; // employees database
	};

} // end of namespace


#endif // !EMPLOYEES_DATABASE_H



