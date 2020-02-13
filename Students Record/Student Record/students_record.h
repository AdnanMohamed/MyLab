// The header file for the class Students_Record.
// The class is within namespace students_record_adnan
//
// @Author: Adnan Mohamed
//
// CLASS Students_Record:
//	TYPEDEFS: 
//	 student: class Student is used you should be familiar with it to use
//	 student_record class. see Student class in Student.h
//
// CONSTRUCTORS
//	Students_Record()
//	 Postcondition: Empty Record
//
//	Students_Record(const student& the_student)
//	 Postcondition: The record has the_student as its first record
//
// MODIFICATION MEMBERS
//	void add_course(int id, const courses_adnan::Course& new_course);
//	 Predcondition: There is a student with the specified id, and new_course
//	 is not in the list of the student's courses.
//	 Postcondition: The course is in the student's list.
//
//	void add_student(const student& new_student);
//	 Precondition: new_student is not already in the list.
//	 Postcondition: The new record is added to the list of students
//
//	void remove_course(int id, std::string course_name, std::string grade)
//	Precondition: There is a student with the given id.
//	The student has a course with the specified name and grade.
//	Postcondition: The course is removed from the list of taken courses by the students
//
//	void remove_student(int id);
//	 Precondition: There is a student in the record with the specified id.
//	 Postcondition: The record is deleted.
//
//	void view_record(int id);
//	 There is a student in the record with the specified id.
//	 Postcondition: The details of the student will be displayed to the screen.
//
// NON-MODIFICATION MEMBERS
//  bool student_exists(int id)
//	 Postcondition: Returns true if the student is in the record, else false.
//
//	bool student_exists(const Name& student_name, const Date& birth_date)
//   Postcondition: Returns true if the student is in the record, else false.
//
// OTHER FUNCTIONS:
//  void menu(char& choice)
//	 Postcondition: prints out a menu of choices.
//	 The user's choice is stored in choice.
//
//  bool is_valid(char choice)
//   Postcondition: Returns true if the choice is in the menu, else false.
//
//  void get_student_info(student_adnan::Name& name, student_adnan::Date& birth);
//	 Postcondition: The user have inputted the name and date of birth.
//	 and the entries are saved to name and birth respectively.
//
//  void get_student_info(student_adnan::Name& name, student_adnan::Date& birth, int& student_ID)
//	 Postcondition: The user have inputted the name, date of birth, and student_ID.
//	 and the entries are saved to name, birth, and student_ID respectively.
//
//  void get_course_info(std::string& course_name, int& credit_hours, std::string& letter_grade)
//	 Postcondition: The user entered the course name, credit hours, and letter grade.
//	 The entries are saved to the arguments.
//
//	void get_course_info(std::string& course_name, std::string& letter_grade)
//	 Postcondition: The user will be asked to enter the course_name and letter_grade.
//	 The user input will be saved to the arguments.
//
#ifndef STUDENTS_RECORD_H
#define STUDENTS_RECORD_H
#include"students_list.h"

namespace students_record_adnan {

	class Students_Record
	{
	public:
		typedef node_student_adnan::node student_node;
		typedef node_student_adnan::node::value_type student;
		// CONSTRUCTORS
		Students_Record(); // @AM
		Students_Record(const student& the_student); //@AM
		Students_Record(const Students_Record& source_record);
		// DESTRUCTOR
		~Students_Record(); // @AM
		
		// MODIFICATION MEMBERS
		void add_course(int id, const courses_adnan::Course& new_course); //@AM
		void add_student(const student& new_student); // @AM
		void remove_course(int id, std::string course_name, std::string grade); // @AM
		void remove_student(int id); // @ AM
		void view_record(int id); // @ AM
		
		// ASSIGNMENT OPERATOR
		Students_Record operator=(const Students_Record& rhs); //@ AM
		// NON-MODIFICATION MEMBERS
		bool student_exists(int id); // @AM
		bool student_exists(const student_adnan::Name& student_name, const student_adnan::Date& birth_date); // @AM
	private:
		student_node* head_ptr_;
	};

	void menu(char& choice);
	bool is_valid(char choice);
	void get_student_info(student_adnan::Name& name, student_adnan::Date& birth);
	void get_student_info(student_adnan::Name& name, student_adnan::Date& birth, int& student_ID);
	void get_course_info(std::string& course_name, int& credit_hours, std::string& letter_grade);
	void get_course_info(std::string& course_name, std::string& letter_grade);
	void newline();
}

#endif // !STUDENTS_RECORD_H

