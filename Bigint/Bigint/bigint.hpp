// This is the interface file for the class Bigint.
// Bigint allows storing larger numbers than int.
//
// @Author: Adnan Mohamed
//
// CONSTRUCTORS: 
//	bigint(int number = 0)
//	  Precondition: number >= 0
//	  Postconditon: the bigint equals the given number (default- 0)
//
//	bigint(const char number[])
//	  Precondition: the number presented as a string is valid non-negative number
//	  Postcondition: the bigint equals the given number
//
// MEMBER FUNCTIONS:
//	void debugPrint(std::ostream& outs) const
//	  Postcondition: The number is printed
//
//	int get_length()const
//	  Postcondition: Returns the how many digits in the number.
//
// NON-MEMBER FUNCTIONS:
//	int digit_to_int(char ch)
//	  Precondition: ch is a valid digit (0-9).
//	  Postcondition: the integer that equals the character digit is returned.
//
//	std::ostream& operator<<(std::ostream& outs, const bigint& number)
//	  Precondition: number is a number of type bigint (non-negative)
//	  Postcondition: outputs the number to the stream.
//
//	std::istream& operator>> (std::istream& ins, bigint& number);
//	  Postcondition: Reads the number from the user till ';'
//	  The number will be the number entered by the user
//
//	bool operator==(const bigint& number1, const bigint& number2)
//	  Postcondition: Returns true if the numbers are equal false otherwise.
#ifndef BIGINT_H
#define BIGINT_H
#include<iostream>

	const int CAPACITY = 400;
	class bigint
	{
	public:
		//CONSTRUCTORS
		bigint(int number = 0);
		bigint(const char number[]);

		// MEMBER FUNCTIONS
		void debugPrint(std::ostream& outs) const;

		// Accessors
		int get_length()const { return length_; }

		// Friends
		friend std::ostream& operator<<(std::ostream& outs, const bigint& number);
		friend bool operator==(const bigint& number1, const bigint& number2);
		friend std::istream& operator>> (std::istream& ins, bigint& number);
	private:
		int number_[CAPACITY] ;
		int length_; // stores the number of digits in the number
	};

	int digit_to_int(char ch);

#endif // !BIGINT_H

