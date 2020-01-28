// This is the implementation file for the class bigint.
// You could see the interface in bigint.h
// @ Coded by: Adnan Mohamed

#include<iostream>
#include"bigint.hpp"
#include<string.h>
using std::cout; using std::cin; using std::endl;


	bigint::bigint(int number)
	{
		int index = 0;
		length_ = 0;

		// assign the given number to the array such that ones be stored in index 0,
		// tens in index 1 and so on.
		while (number > 0)
		{
			number_[index] = number % 10;
			number /= 10;
			++index;
			++length_;
		}

		if (length_ == 0)
			length_ = 1;
		for (int i = index; i < CAPACITY; ++i)
		{
			number_[index] = 0;
		}

	}

	bigint::bigint(const char number[])
	{
		length_ = std::strlen(number);
		int index = length_ - 1;
		while (index >= 0)
		{
			number_[length_ - index - 1] = digit_to_int(number[index]);
			--index;
		}
		for (int i = length_; i < CAPACITY; ++i)
		{
			number_[i] = 0;
		}
	}

	void bigint::debugPrint(std::ostream& outs) const
	{
		for (int i = CAPACITY- 1; i >= 0; --i)
		{
			outs << number_[i]<<"|";
		}
	}

	int digit_to_int(char ch)
	{
		return static_cast<int>(ch) - static_cast<int>('0');
	}

	std::ostream& operator<<(std::ostream& outs, const bigint& number)
	{
		for (int i = number.length_ - 1; i >= 0; --i)
		{
			outs << number.number_[i];
		}
		return outs;
	}

	bool operator==(const bigint& number1, const bigint& number2)
	{
		// check their lengths if not the same return false
		// else compare each number in the arrays
		if (number1.length_ != number2.length_)
			return false;
		else
		{
			for (int i = 0; i < number1.length_; ++i)
			{
				if (number1.number_[i] != number2.number_[i])
					return false;
			}
			return true;
		}

	}

	std::istream& operator>> (std::istream& ins, bigint& number)
	{
		char* temp = new char[CAPACITY + 1];
		temp[CAPACITY] = '\0';
		char next;
		cin.get(next);
		int i = 0;
		while (next != ';')
		{
			temp[i] = next;
			cin.get(next);
			++i;
		}
		--i;
		if(i >= 0)
		number.length_ = i;
		while (i >= 0)
		{
			number.number_[i] = digit_to_int(temp[i]);
			--i;
		}
		return ins;
	}