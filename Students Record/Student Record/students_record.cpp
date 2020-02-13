// This is the implementation file for the class Students_Record.
// You can see the interface of the class Student_Record in students_record.h
// There are helping functions implemented to manipulate the record of students using a menu of choices.
//
// Suggestions to improve the program:-
//	1- Handle exceptions for user entry.
//
// @Author: Adnan Mohamed

#include<iostream>
#include"students_record.h"
#include<cassert>

using std::string; using std::cout; using std::cin; using std::endl;
using student_adnan::Date; using student_adnan::Student; using student_adnan::Name;
namespace students_record_adnan {

	Students_Record::Students_Record()
	{
		head_ptr_ = NULL;
	}

	Students_Record::Students_Record(const student& the_student)
	{
		node_student_adnan::list_head_insert(head_ptr_, the_student);
	}

	Students_Record::Students_Record(const Students_Record& source_record)
	{
		head_ptr_ = NULL;
		node_student_adnan::list_copy(source_record.head_ptr_, head_ptr_);
	}

	Students_Record::~Students_Record()
	{
		node_student_adnan::list_clear(head_ptr_);
	}

	void Students_Record::add_course(int id, const courses_adnan::Course& new_course)
	{
		auto target = node_student_adnan::list_search(head_ptr_, Student(Name(), Date(), id));
		if (target != NULL)
		{
			target->actual_data().add_course(new_course);
			return;
		}
		// print in case the student is not in the record
		cout << "The student is not in the record." << endl;
	}

	void Students_Record::add_student(const student& new_student)
	{
		if (!this->student_exists(new_student.get_ID()))
		{
			node_student_adnan::list_head_insert(head_ptr_, new_student);
			return;
		}
		// print if the student is already in the record.
		cout << "The student is already in the record" << endl;;
	}

	void Students_Record::remove_course(int id, std::string course_name, std::string grade)
	{
		auto target = node_student_adnan::list_search(head_ptr_, Student(Name(), Date(), id));
		if (target != NULL)
		{
			target->actual_data().remove_course(course_name, grade);
			return;
		}
		cout << "The student is not in the record." << endl;
	}

	void Students_Record::remove_student(int id)
	{
		auto target = node_student_adnan::list_search(head_ptr_, Student(Name(), Date(), id));
		if (target != NULL)
		{
			target->set_data(head_ptr_->data());
			node_student_adnan::list_head_remove(head_ptr_);
			return;
		}
		// print this if student is not in the record
		cout << "The student is not in the record." << endl;
	}

	Students_Record Students_Record::operator=(const Students_Record& rhs)
	{
		if (this != &rhs)
		{
			node_student_adnan::list_clear(head_ptr_);
			node_student_adnan::list_copy(rhs.head_ptr_, head_ptr_);
			return *this;
		}
		
	}

	void Students_Record::view_record(int id)
	{
		auto target = node_student_adnan::list_search(head_ptr_, Student(Name(), Date(), id));
		if (target != NULL)
		{
			cout<<target->data();
			return;
		}
		// print this if student is not in the record
		cout << "The student is not in the record." << endl;
	}

	bool Students_Record::student_exists(int id)
	{
		return node_student_adnan::list_search(head_ptr_, Student(Name(), Date(), id)) != NULL;
	}

	bool Students_Record::student_exists(const Name& student_name, const Date& birth_date)
	{
		return node_student_adnan::list_search(head_ptr_, Student(student_name, birth_date)) != NULL;
	}

	bool is_valid(char choice)
	{
		choice = toupper(choice);
		return choice == 'A' || choice == '!' || choice == 'V' || choice == 'Q' || choice == 'E';
	}

	void menu(char& choice)
	{
		std::cout << "***************\n";
		std::cout << "The choices are on the left of the text:-\n\n";
		std::cout << "A- Add New Record\n";
		std::cout << "E- Edit an Existing Record\n";
		std::cout << "!  Delete a record\n";
		std::cout << "V- View a record\n";
		std::cout << "Q- Quit Program\n";
		std::cout << "Enter Choice: ";
		std::cin >> choice;
		std::cout << std::endl;
		
		while (!is_valid(choice) || toupper(choice) == 'E')
		{
			if (choice == 'e' || choice == 'E')
			{
				do
				{
					std::cout << "Choose from the following:-\n\n";
					std::cout << "+ Add Course(s) to a record\n";
					std::cout << "D- Delete Course(s) from a record\n";
					std::cout << "Enter Choice: ";
					std::cin >> choice;
					std::cout << std::endl;
				} while (choice != '+' && toupper(choice) != 'D');
				std::cout << "***************\n";
				newline();
				return;
			}
			std::cout << "Invalid Choice\n";
			std::cout << "Enter Choice: ";
			std::cin >> choice;
			std::cout << std::endl;
		}
		newline();
		std::cout << "***************\n";
	}

	void get_student_info(student_adnan::Name& name, student_adnan::Date& birth)
	{
		string first_name, last_name;
		int month, day, year;

		cout << "Fill the student's info.:-\n";
		cout << "First Name: ";
		cin >> first_name;
		cout << "Last Name: ";
		cin >> last_name;
		cout << "Date of birth:-\n";
		cout << "Month (1-12): ";
		cin >> month;
		cout << "Day: ";
		cin >> day;
		cout << "Year: ";
		cin >> year;
		newline();

		// formating the first and last name
		first_name[0] = toupper(first_name[0]);
		last_name[0] = toupper(last_name[0]);
		for (int i = 1; i < first_name.length(); ++i)
		{
			first_name[i] = tolower(first_name[i]);
		}
		for (int i = 1; i < last_name.length(); ++i)
		{
			last_name[i] = tolower(last_name[i]);
		}

		name = student_adnan::Name(first_name, last_name);
		birth = student_adnan::Date(month, day, year);
	}

	void get_student_info(student_adnan::Name& name, student_adnan::Date& birth, int& student_ID)
	{
		string first_name, last_name;
		int month, day, year;
		int ID;

		cout << "Fill the student's info.:-\n";
		cout << "First Name: ";
		cin >> first_name;
		cout << "Last Name: ";
		cin >> last_name;
		cout << "Date of birth:-\n";
		cout << "Month (1-12): ";
		cin >> month;
		cout << "Day: ";
		cin >> day;
		cout << "Year: ";
		cin >> year;
		cout << "Student ID: ";
		cin >> ID;
		newline();

		// formating the first and last name
		first_name[0] = toupper(first_name[0]);
		last_name[0] = toupper(last_name[0]);
		for (int i = 1; i < first_name.length(); ++i)
		{
			first_name[i] = tolower(first_name[i]);
		}
		for (int i = 1; i < last_name.length(); ++i)
		{
			last_name[i] = tolower(last_name[i]);
		}

		name = student_adnan::Name(first_name, last_name);
		birth = student_adnan::Date(month, day, year);
		student_ID = ID;
	}

	void get_course_info(std::string& course_name, int& credit_hours, std::string& letter_grade)
	{
		cout << "Fill Course Info:-\n";
		cout << "Course Name: ";
		getline(cin, course_name);
		cout << "Credit Hours: ";
		cin >> credit_hours;
		cout << "Letter Grade: ";
		cin >> letter_grade;
		newline();
	}

	void get_course_info(std::string& course_name, std::string& letter_grade)
	{
		cout << "Fill Course Info:-\n";
		cout << "Course Name: ";
		getline(cin, course_name);
		cout << "Letter Grade: ";
		cin >> letter_grade;
		newline();
	}

	void newline()
	{
		char next;
		do
		{
			cin.get(next);
		} while (next != '\n');
	}

} // end of namespace