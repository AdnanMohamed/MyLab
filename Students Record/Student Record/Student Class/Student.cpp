// This is the implementation file for the class Student.
// The class is within namespace student_adnan.
// The interface for the class Student is in Student.h
//
// CLASS INVARIANT:
//  1- name_ is the student's first & last name
//	2- 0 <= GPA <= 4.0
//  3- head_ptr_ points to the first node of the linked list.
//  4- credit_earned_ is the sum of each course he/she taken
//	5- student_ID_ must be greater than zero
//
// Suggestions to improve the program:-
//	1- Handle exceptions for user entry
//	2- Enhance the Date class to only accept valid dates.
//
// @ Author: Adnan Mohamed

#include<iostream>
#include<cassert>
#include"Student.h"
#include"course_list.h"

using std::cout; using std::cin; using std::endl;
using namespace courses_adnan;
namespace student_adnan {

	Student::Student(const Name& name, const Date& birth, int ID, double GPA)
		:name_(name), birth_(birth)
	{
		assert(GPA >= 0 && GPA <= 4);
		assert(ID > 0);
		GPA_ = GPA;
		student_ID_ = ID;
		head_ptr_ = NULL;
		credit_earned_ = 0;
	}

	void Student::set_GPA(double GPA)
	{
		assert(GPA >= 0 && GPA <= 4);
		GPA_ = GPA;
	}

	void Student::set_ID(int id)
	{
		assert(id > 0);
		student_ID_ = id;
	}

	bool Student::course_exists(std::string name, std::string grade)
	{
		return list_search(head_ptr_, Course(name, 0, grade)) != NULL;
	}
	
	void Student::add_course(const course& new_course)
	{
		assert(new_course.get_course_grade() == "A" || new_course.get_course_grade() == "B" || 
			new_course.get_course_grade() == "C" || new_course.get_course_grade() == "D" || 
			new_course.get_course_grade() == "F");
		if (list_search(head_ptr_, new_course) == NULL)
		{
			list_head_insert(head_ptr_, new_course);
			// calculate new GPA
			int credits = new_course.get_course_hours();
			std::string grade = new_course.get_course_grade();
			GPA_ = (1 / double(credit_earned_ + credits)) * (GPA_ * credit_earned_ + credits * letter_to_credits(grade));
			credit_earned_ += credits;
		}
		else
			cout << "The course already exists.\n\n";
	}

	void Student::remove_course(std::string name, std::string grade)
	{
		node* target = list_search(head_ptr_, Course(name, 0, grade));
		if (target != NULL)
		{
			double removed_hours = target->data().get_course_hours();
			target->set_data(head_ptr_->data());
			list_head_remove(head_ptr_);
			// UPDATE GPA
			if (head_ptr_ != NULL)
			{
				GPA_ = (GPA_ - (double(removed_hours) * letter_to_credits(grade)) / credit_earned_) * (credit_earned_ / (credit_earned_ - removed_hours));
			}
			else
				GPA_ = 0;
			
			credit_earned_ -= removed_hours;
		}

	}

	Student::~Student() 
	{ 
		courses_adnan::list_clear(head_ptr_);
		GPA_ = 0;
		credit_earned_ = 0;
	}

	void Student::remove_all()
	{
		list_clear(head_ptr_);
		GPA_ = 0;
		credit_earned_ = 0;
	}

	Student::Student(const Student& student)
	{
		name_ = student.name_;
		birth_ = student.birth_;
		GPA_ = student.GPA_;
		student_ID_ = student.student_ID_;
		credit_earned_ = student.credit_earned_;
		head_ptr_ = NULL;
		list_copy(student.head_ptr_, head_ptr_);
	}

	Student& Student::operator=(const Student& rhs)
	{
		if (this != &rhs)
		{
			list_clear(head_ptr_);
			name_ = rhs.name_;
			birth_ = rhs.birth_;
			student_ID_ = rhs.student_ID_;
			GPA_ = rhs.GPA_;
			credit_earned_ = rhs.credit_earned_;
			list_copy(rhs.head_ptr_, head_ptr_);
		}

		return *this;
	}


	bool operator==(const Student& st1, const Student& st2)
	{
		return st1.birth_ == st2.birth_ &&
			st1.name_ == st2.name_ || (st1.student_ID_ == st2.student_ID_);
	}

	std::ostream& operator<< (std::ostream& outs, const Student& st)
	{
		outs.setf(std::ios::showpoint);
		outs.setf(std::ios::fixed);
		outs.precision(2);
		outs << "***********************\n";
		outs << "Name: " << st.name_.first_name_<<" "<<st.name_.last_name_ << endl;
		outs << "Student ID: " << st.student_ID_ << endl;
		outs << "Date of Birth: " << st.birth_.month_ << "/ " << st.birth_.day_ << "/ " << st.birth_.year_ << endl;
		outs << "Total Credits: " << st.credit_earned_ << endl;
		outs << "GPA: " << st.GPA_ << endl;
		outs << endl;
		outs << "Courses List:\n\n";
		for (auto cursor = st.head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			outs << cursor->data() << endl;
			outs << "-------------------\n";
		}
		outs << endl;
		outs << "***********************\n";
		return outs;
	}

	double letter_to_credits(std::string letter_grade)
	{
		assert(letter_grade == "A" || letter_grade == "B" || letter_grade == "C" ||
			letter_grade == "D" || letter_grade == "F");
		switch (letter_grade[0])
		{
		case 'A':
			return 4.0;
			break;
		case 'B':
			return 3.0;
			break;
		case 'C':
			return 2.0;
			break;
		case 'D':
			return 1.0;
			break;
		case 'F':
			return 0.0;
			break;
		}
	}

} // end of namespace