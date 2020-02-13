// This is the interface file for the class Student ( and helper classes Date, Name, Course).
// The classes are within namespace (student_adnan)
//
// @Author: Adnan Mohamed
//
// CLASS Name:
//	CONSTRUCTOR:
//	Name(std::string first_name = " ", std::string last_name = " ")
//	Postcondition: The name contains the given first_name, last_name
//
//	ACCESS/ CHANGE the first/last name by directly accessing the attributes
//	name.first_name_ / name.last_name_
//
// CLASS Date:
//	CONSTRUCTOR:
//	 Date(int month = 1, int day = 1, int year = 2020)
//	  Postcondition: the date is set to the given month/ day/ year
//
//	ACCESS/ CHANGE the day/ month/ year of the date by directly accessing the attributes
//	date.day_, date.month_, date.year_
//
// CLASS Student:
//
// CONSTRUCTOR:
//	Student(const Name& name = Name(), const Date& birth = Date(), int ID = 99999, double GPA = 0.0)
//	 Postcondition: The student's name, date of birth, ID, and GPA are set.
//	 DEFAULT: empty name, date of birth (1/1/2020), ID = 99999, GPA = 0
//	 The list of courses are empty
//
// ACCESSORS:
//  Name get_name()const
//	 Postcondition: returns the student's name
//
//	Date get_birth_date()const
//	 Postcondition: returns the student's date of birth
//
//  void get_ID() const
//	 Postcondition: returns the student's id.
//
//	double get_GPA()const
//	 Postcondition: returns the student's GPA
//
//  bool course_exists(std::string name, std::string grade)
//	 Postcondition: returns true if the_course is in the list of courses, else false.
//
// MODIFICATION MEMBER FUNCTIONS:
//	void set_name(const Name& name)
//   Postcondition: the student name is set to name.
//
//	void set_date_of_birth(const Date& date);
//	 Postcondition: the student's date of birth is set to date.
//
//	void set_GPA(double GPA)
//	 Postcondition: the student's GPA is set to the given GPA
//
//  void set_ID(int id)
//	 Precondition: id> 0
//	 Postcondition: the student has the specified id.
//
//	void add_course(const course& new_course)
//	 Precondition: No course in the list has the same name and credits
//	 The grade is in the set { 'A', 'B', 'C', 'D', 'F }
//	 Postcondition: the course is added to the list of courses
//
//  void remove_course(std::string name, std::string grade);
//	 Precondtion: the_course is in the list of courses
//	 The grade is in the set { 'A', 'B', 'C', 'D', 'F }
//	 Postcondition: the_course is deleted from the list
//
//  void remove_all()
//	 Postcondition: No courses are in the list.
//
// Operators
//  bool operator==(const Student& st1, const Student& st2)
//	 Postcondition: Returns true if st1 name and birth date are the same for st2  OR 
//	 st1 has the same student ID of st2, else false.
//
//	std::ostream& operator<< (std::ostream & outs, const Student & st)
//	 Postcondition: Prints the student name, birth date, GPA, and the list of courses took by the student.
//
// NON MEMBER FUNCTIONS:
//	double letter_to_credits(std::string letter_grade)
//	  Precondition: The grade is in the set { 'A', 'B', 'C', 'D', 'F }
//	  Postcondition: Returns the corresponding credits for the given letter grade (e.g. B = 3.0 )
//
// VALUE SEMANTICS:
//	You can use the copy constructor, assignment safely.
//
#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include"course_list.h" // provides Course class


namespace student_adnan {

	class Name {
	public:
		Name(std::string first_name = " ", std::string last_name = " ")
			:first_name_(first_name), last_name_(last_name) {}
		std::string first_name_;
		std::string last_name_;
		friend bool operator==(const Name& name1, const Name& name2)
		{
			return name1.first_name_ == name2.first_name_ &&
				name1.last_name_ == name2.last_name_;
		}
	};
	
	class Date {
	public:
		Date(int month = 1, int day = 1, int year = 2020)
			:month_(month), day_(day), year_(year) {}
		int month_;
		int day_;
		int year_;

		friend bool operator==(const Date& date1, const Date& date2)
		{
			return date1.day_ == date2.day_ &&
				date1.month_ == date2.month_ &&
				date1.year_ == date2.year_;
		}
	};


	class Student {
	public:
		typedef courses_adnan::Course course;
		// CONSTRUCTORS:
		Student(const Name& name = Name(), const Date& birth = Date(), int ID = 99999, double GPA = 0.0);
		Student(const Student& student);
		// DESTRUCTOR
		~Student();
		// MUTATORS:
		void set_name(const Name& name) { name_ = name; }
		void set_date_of_birth(const Date& date) { birth_ = date; }
		void set_GPA(double GPA);
		void set_ID(int id);
		courses_adnan::node* get_head_courses() { return head_ptr_; }
		// ACCESSORS:
		Name get_name()const { return name_; }
		Date get_birth_date()const { return birth_; }
		double get_GPA()const { return GPA_; }
		bool course_exists(std::string name, std::string grade);
		int get_ID()const { return student_ID_; }
		
		// MODIFICATION MEMBERS:
		void add_course(const course& new_course);
		void remove_course(std::string name, std::string grade);
		void remove_all();


		// ASSIGNMENT OPERATOR
		Student& operator=(const Student& rhs);

		// Operators
		friend bool operator==(const Student& st1, const Student& st2);
		friend std::ostream& operator<< (std::ostream & outs, const Student & st);
	private:
		Name name_;
		int student_ID_;
		Date birth_;
		double GPA_;
		courses_adnan::node* head_ptr_;
		int credit_earned_;
	};

	double letter_to_credits(std::string letter_grade);

}// end of namespace

#endif // !STUDENT_H

