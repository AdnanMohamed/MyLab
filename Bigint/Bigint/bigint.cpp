// This is the implementation file for the class bigint.
// You could see the interface in bigint.h
// @ Coded by: Adnan Mohamed

#include<iostream>
#include"bigint.hpp"
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
		number_[i] = 0;
	}

}

bigint::bigint(const char number[])
{
	length_ = 0;
	for (int i = 0; number[i] != '\0'; ++i)
	{
		++length_;
	}
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
	for (int i = CAPACITY - 1; i >= 0; --i)
	{
		outs << number_[i] << "|";
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
	do
	{
		ins.get(next);
	} while (ins && isspace(next));
	int index = 0;
	while (next != ';' && !ins.eof())
	{
		if (!isspace(next) || next != '\n')
		{
			temp[index] = next;
			++index;
		}

		ins.get(next);

	}
	temp[index] = '\0';

	number.length_ = index;
	--index;
	for (int j = 0; index >= 0; --index, ++j)
	{
		number.number_[j] = digit_to_int(temp[index]);
	}
	for (int i = number.length_; i < CAPACITY; ++i)
	{
		number.number_[i] = 0;
	}

	do
	{
		if (!isspace(ins.peek()))
			break;
		ins.get(next);
	} while (ins && next!='\n');


	return ins;
}

bigint bigint::operator+(const bigint& addend) const
{
	int sum[CAPACITY] = {};
	int largest;
	if (addend.length_ > length_)
		largest = addend.length_;
	else
	{
		largest = length_;
	}

	for (int i = 0; i < largest; ++i)
	{
		if (sum[i] + addend.number_[i] + number_[i] > 9)
		{
			sum[i + 1] = (sum[i] + addend.number_[i] + number_[i]) / 10;
			sum[i] = (sum[i] + addend.number_[i] + number_[i]) % 10;
		}
		else
		{
			sum[i] += (addend.number_[i] + number_[i]);
		}
	}

	bigint temp;
	temp.number_[0] = sum[0];
	for (int i = 1; i < largest; ++i)
	{
		temp.number_[i] = sum[i];
		temp.length_++;
	}
	if (sum[largest] != 0)
	{
		temp.number_[largest] = sum[largest];
		temp.length_++;
	}
	return temp;
}

bigint bigint::timesDigit(int num) const
{
	bigint product;
	if (num == 0)
		return product;

	int sum;
	int i;
	for (i = 0; i < length_; ++i)
	{
		sum = (product.number_[i] + num * number_[i]);
		product.number_[i] = sum % 10;
		product.number_[i + 1] = sum / 10;
	}

	if (product.number_[i] != 0)
	{
		product.length_ = i + 1;
	}
	else
	{
		product.length_ = i;
	}
	return product;
}

bigint bigint::times10(int num) const
{
	bigint result; // initialized to zero
	if (*this == result) // this means the bigint that called the function is zero
		return result;	 // so anything times zero should be directly returned as zero.

	for (int i = 0; i < length_; ++i)
	{
		result.number_[i + num] = number_[i];
	}
	result.length_ = num + length_;
	return result;
}

bigint operator* (const bigint& num1, const bigint& num2)
{
	bigint zero; // The product now is zero

	// Check if either numbers are zero then return 
	// a bigint which equals zero.
	if (num1 == zero || num2 == zero)
		return zero;
	
	bigint temp;
	bigint product;
	if (num1.length_ >= num2.length_)
	{
		for (int i = 0; i < num1.length_; ++i)
		{
			product = num2.timesDigit(num1.number_[i]);
			temp = temp + product.times10(i);
		}
	}
	else
	{
		for (int i = 0; i < num2.length_; ++i)
		{
			temp = temp + num1.timesDigit(num2[i]).times10(i);
		}
	}

	return temp;
}