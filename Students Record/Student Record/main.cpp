// This program demonstrates the use of Students_Record class.
// Simply, it displays a menu of choices to create and play around with
// a record of students.
//
// Suggestions to improve the program:-
//	1- Prompt the user when he/she make any change in the record.
//	2- Prompt the user when he/she failed to make intended changes to the record
//	3- Handle exceptions in user input.

#include"Student Class/Student.h"
#include"students_record.h"
#include<iostream>
#include<string>

// from std
using std::cout; using std::cin; using std::endl; using std::string;
// from student_adnan
using student_adnan::Name; using student_adnan::Date; using student_adnan::Student;
// from courses_adnan
using courses_adnan::Course;
//from students_record_adnan
using students_record_adnan::menu; using students_record_adnan::newline;
using students_record_adnan::Students_Record; using students_record_adnan::get_course_info;
using students_record_adnan::get_student_info;

int main()
{
	char choice;
	char replay = 'n'; // for replaying the program
	Name student_name;
	Date birth_date;
	string course_name, letter_grade;
	int credit_hours, student_ID, num_of_courses;
	bool student_exists;
	Student student;
	Students_Record my_record;

	do {
		menu(choice);
		choice = toupper(choice);
		switch (choice)
		{
		case 'A':
			get_student_info(student_name, birth_date, student_ID);
			student.set_name(student_name);
			student.set_date_of_birth(birth_date);
			student.set_ID(student_ID);
			my_record.add_student(student);
			break;
		case '+':
			cout << "Enter the student ID: ";
			cin >> student_ID;
			newline();
			if (my_record.student_exists(student_ID))
			{
				cout << "Number of courses to add: ";
				cin >> num_of_courses;
				newline();
				for (int i = 0; i < num_of_courses; ++i)
				{
					get_course_info(course_name, credit_hours, letter_grade);
					my_record.add_course(student_ID, Course(course_name, credit_hours, letter_grade));
					cout << endl;
				}
			}
			
			break;
		case 'D':
			cout << "Enter the student ID: ";
			cin >> student_ID;
			newline();
			get_course_info(course_name, letter_grade);
			my_record.remove_course(student_ID, course_name, letter_grade);
			break;
		case '!':
			cout << "Enter the student ID: ";
			cin >> student_ID;
			newline();
			my_record.remove_student(student_ID);
			break;
		case 'V':
			cout << "Enter the student ID: ";
			cin >> student_ID;
			newline();
			my_record.view_record(student_ID);
			break;
		case 'Q':
			exit(1);
		} // end of switch
		cout << "Do you want to choose another option? (yes/no): ";
		cin >> replay;
		newline();
	} while (toupper(replay) == 'Y');


}