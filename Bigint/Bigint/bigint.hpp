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
//	bigint operator+(const bigint& addend) const
//	  Postcondition: Returns the sum
//
//  bigint timesDigit(int num) const
//	  Postcondition: returns the product of the calling bigint and num
//
//  bigint times10(int num) const
//	  Postcondition: returns the calling bigint * (10 ^ num)
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
//
//  bigint operator* (const bigint& num1, const bigint& num2);
//	  Postcondition: Returns the product of num1 and num2
//
//  int operator[](int index)
//	  Precondition: the index is between 0 and get_length() (not included)
//	  Postcondition: the number will be returned (0th index is ones, index 1 is tens and so on)

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
	bigint operator+(const bigint& addend) const;
	int operator[](int index) const { return number_[index]; }
	bigint timesDigit(int num) const;
	bigint times10(int) const;

	// Accessors
	int get_length()const { return length_; }
	
	// Friends
	friend std::ostream& operator<<(std::ostream& outs, const bigint& number);
	friend bool operator==(const bigint& number1, const bigint& number2);
	friend std::istream& operator>> (std::istream& ins, bigint& number);
	friend bigint operator* (const bigint& num1, const bigint& num2);
private:
	int number_[CAPACITY];
	int length_; // stores the number of digits in the number
};

int digit_to_int(char ch);


#endif // !BIGINT_H

