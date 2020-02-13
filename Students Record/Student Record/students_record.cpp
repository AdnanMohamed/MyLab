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
		}
	}

	void Students_Record::add_student(const student& new_student)
	{
		node_student_adnan::list_head_insert(head_ptr_, new_student);
	}

	void Students_Record::remove_course(int id, std::string course_name, std::string grade)
	{
		auto target = node_student_adnan::list_search(head_ptr_, Student(Name(), Date(), id));
		if (target != NULL)
		{
			target->actual_data().remove_course(course_name, grade);
		}
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
		cout << "The student is not in the record.";
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

	/*void add_record(node_student_adnan::Node_Ptr& head_ptr, const student_adnan::Student& student)
	{
		list_head_insert(head_ptr, student);
	}

	void delete_record(node_student_adnan::Node_Ptr& head_ptr, student_adnan::Name name, student_adnan::Date birth)
	{
		node_student_adnan::Node_Ptr target = list_search(head_ptr, student_adnan::Student(name, birth));
		if (target != NULL)
		{
			target->set_data(head_ptr->data());
			list_head_remove(head_ptr);
		}
	}

	void view_record(node_student_adnan::Node_Ptr& head_ptr, const student_adnan::Student& student)
	{
		for (auto cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		{
			if (cursor->data() == student)
			{
				cout << cursor->data();
				return;
			}
		}
		cout << "The student is not in the record";
	}*/

	bool is_valid(char choice)
	{
		choice = toupper(choice);
		return choice == 'A' || choice == '!' || choice == 'V' || choice == 'Q';
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

		while (!is_valid(choice))
		{
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
		name = student_adnan::Name(first_name, last_name);
		birth = student_adnan::Date(month, day, year);
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

	/*void insert_course(node_student_adnan::Node_Ptr& head_ptr, const student_adnan::Student& student, std::string course_name, int credit_hours, std::string letter_grade)
	{
		
		for (auto cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		{
			node_student_adnan::node::value_type temp;
			if (cursor->data() == student)
			{
				temp = cursor->data();
				temp.add_course(course_name, credit_hours, letter_grade);
				cursor->set_data(temp);
				return;
			}
		}
		cout << "The student is not in the record";
	}*/

	/*void remove_course(node_student_adnan::Node_Ptr& head_ptr, const student_adnan::Student& student, std::string course_name, std::string letter_grade)
	{
		for (auto cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		{
			node_student_adnan::node::value_type temp;
			if (cursor->data() == student)
			{
				temp = cursor->data();
				if (temp.course_exists(course_name, letter_grade))
				{
					temp.remove_course(course_name, letter_grade);
				}
				else
					cout << "COURSE NOT FOUND\n";
				cursor->set_data(temp);
				return;
			}
		}
		cout << "The student is not in the record";
	}*/

	bool record_exists(node_student_adnan::Node_Ptr& head_ptr, const student_adnan::Name& name, const student_adnan::Date& birth)
	{
		return node_student_adnan::list_search(head_ptr, student_adnan::Student(name, birth)) != NULL;
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