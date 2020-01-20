// File: Employee.h (includes the classes Employee, Name)
// Written by: Adnan Mohamed
//
// NAME CLASS:
//  CONSTRUCTOR:
//   Name(std::string first = " ", std::string last = " ", char middle = ' ')
//	   Postcondition: Whatever given by the user will be set to be the name.
//	   The argument which is not given will be a space in the person's name.
//	
//  FRIEND FUNCTIONS:
//	  std::ostream& operator<<(std::ostream& outs, const Name&);
//		Precondition: Name must contain at least the first and last name.
//		Postondition: The name will be displayed in the forms:-
//		First M. Last (if all are specified)
//		First Last (if no middle initial)
//		
// EMPLOYEE CLASS:
//   CONSTRUCTOR:
//	  Employee(Name name = Name(), int ID = 0);
//	    Postcondition: sets the employee to have the given name as his/her name
//		and the employees ID to the given ID or to 0 if not specified.
//		If the name was not specified it will be an empty string.
//
//	  void set_name(Name name)
//		Postcondition: name will be the employee's name
//
//	  void set_ID(int ID)
//		Precondition: ID must be between 3-5 digits long. 
//		Postcondition: ID will be the employee's ID.
//
//	  Name get_name()const
//		Postcondition: returns an object of Name which holds the employee's name.
//
//	  int get_ID()const
//		Postcondition: returns the employee's ID number.
//
//	 FRIEND FUNCTIONS
//	  friend std::ostream& operator<<(std::ostream& outs, const Employee&)
//		Precondition: The employee must have -both- First and Last names.
//		Employee must have a valid ID number (3-5 digits long).
//		Postcondition: The employee's information will be displayed to the where the ostream is connected.

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include<string>
#include<ostream>
namespace employees_adnan {

	class Name{
	public:
		Name(std::string first = " ", std::string last = " ", char middle = ' ')
			:first_name(first), middle_initial(middle), last_name(last) {}

		friend std::ostream& operator<<(std::ostream& outs, const Name&);
		
		std::string first_name;
		char middle_initial = ' ';
		std::string last_name;
	};

	class Employee{
	public:
		// CONSTRUCTOR
		Employee(Name name = Name(), int ID = 0) :name_(name), ID_(ID) {}

		//MUTATORS
		void set_name(Name name) { name_ = name; }
		void set_ID(int ID);

		//ACCESSORS
		Name get_name()const { return name_; }
		int get_ID()const { return ID_; }

		//FRIEND FUNCTIONS
		friend std::ostream& operator<<(std::ostream& outs, const Employee&);
	protected:
		Name name_;
		int ID_;
		bool valid_ID(int ID);
	};

}

#endif // !EMPLOYEE_H

