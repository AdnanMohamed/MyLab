// This is the implementation file for the class: employees
// The class interface is in: employees.h
// 
//	------ - Copyright © -------- -
//	@Author: Adnan Hashem Mohamd
//	------------------------------ 
//
// CLASS INVARIANT:
//	1- Employees are stored in a binary search tree.
//

#include"employees.h"
#include<iostream>
#include"binary search tree/bst_tree.h"

namespace employees_db_adnan {

	bool emps_with_salary(employees::employee emp, double salary)
	// Postcondition: returns True iff the employee's salary is greater than
	// or equal to 'salary', else false is returned.
	{
		return emp.get_salary() >= salary;
	}

	bool emps_with_name(employees::employee emp, const employees::name& emp_name)
	// Postcondition: Returns true iff the employee's name is EXACTLY the same
	// as 'emp_name' (EXACTLY means: first = first Middle_initial = middle initial and last= last)
	// else false is returned.
	{
		return emp.get_name() == emp_name;
	}

	void salary_raise(employees::employee& emp, double percent)
	// Precondition: 0 < percent <= 1
	// Postcondition: increases the employee's ANNUAL salary by the given percent.
	{
		emp.increase_annual_salary(percent);
	}

	employees::employees()
	{
		emp_db = bst_adnan::bst<employee>();
	}

	void employees::remove_employee(int id)
	{
		try {
			if (!emp_db.erase(employee(name(), id)))
				throw id;
		}
		catch (int the_id)
		{
			std::cerr << "-------------------------------------\n\n";
			std::cerr << "*** ERROR: No employee has ID : " << the_id << std::endl;
			std::cerr << "The record is unchanged.\n";
			std::cerr << "-------------------------------------\n\n";
		}
	}

	std::size_t employees::count(const name& emp_name)const
	{
		return binary_tree_adnan::counter(emp_db.get_root_ptr(), emps_with_name, emp_name);
	}

	std::vector <employees::employee> employees::get_employees(const employees::name& emp_name)
	{
		std::vector<employees::employee> same_name_emps;
		binary_tree_adnan::get_items(emp_db.get_root_ptr(), emps_with_name, emp_name, same_name_emps);
		return same_name_emps;
	}

	employees::employee employees::get_employee(int id)const
	{
		// handle the exception of giving a non-existing id.
		try {
			auto cursor = emp_db.get_root_ptr();
			
			// Traverse the BST of employees and return the employee
			// with the given id.
			while (cursor != NULL)
			{
				if (cursor->data().get_ID() < id)
					cursor = cursor->right();
				else if(id < cursor->data().get_ID())
					cursor = cursor->left();
				else
					return cursor->data();
			}
			throw id;
		}
		catch (int the_id)  // display the error message and exit if no employee found with the specified ID.
		{
			std::cerr << "-------------------------------------\n\n";
			std::cerr << "*** ERROR: No employee has ID : " << the_id << std::endl;
			std::cerr << "-------------------------------------\n\n";
			std::cerr << "Exiting the program.\n";
			exit(1);
		}
	}

	employees::employee& employees::get_employee(int id)
	{
		// handle the exception of giving a non-existing id.
		try {
			auto cursor = emp_db.get_root_ptr();

			// Traverse the BST of employees and return the employee
			// with the given id.
			while (cursor != NULL)
			{
				if (cursor->data().get_ID() < id)
					cursor = cursor->right();
				else if (id < cursor->data().get_ID())
					cursor = cursor->left();
				else
					return cursor->data();
			}
			throw id;
		}
		catch (int the_id)  // display the error message and exit if no employee found with the specified ID.
		{
			std::cerr << "-------------------------------------\n\n";
			std::cerr << "*** ERROR: No employee has ID : " << the_id << std::endl;
			std::cerr << "-------------------------------------\n\n";
			std::cerr << "Exiting the program.\n";
			exit(1);
		}
	}

	std::size_t employees::count(double salary)const
	{
		return binary_tree_adnan::counter(emp_db.get_root_ptr(), emps_with_salary, salary);
	}

	bool employees::exists(const name& emp_name)const
	{
		return binary_tree_adnan::counter(emp_db.get_root_ptr(), emps_with_name, emp_name) > 0;
	}

	void employees::raise_salary(int id, double percent)
	{
		salary_raise(get_employee(id), percent);
	}
	
	void employees::raise_salary_all(double percent)
	{
		binary_tree_adnan::apply_feature(emp_db.get_root_ptr(), salary_raise, percent);
	}

} // end of namespace