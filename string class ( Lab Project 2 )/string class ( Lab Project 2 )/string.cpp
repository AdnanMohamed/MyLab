// This is the implementation file for the class String.
// The classe's interface is in the file: string.hpp
//
// @Author: Adnan Mohamed
//
#include"string.hpp"
#include<cassert>

String::String()
{
	str[0] = '\0';
}

String::String(char ch)
{
	str[0] = ch;
	str[1] = '\0';
}

String::String(const char the_str[])
{
	int index = 0;
	while (the_str[index] != '\0' && index < STRING_SIZE - 1)
	{
		str[index] = the_str[index];
		++index;
	}
	str[index] = '\0';
}

char& String::operator[](int index)
{
	// check the validity of the index
	assert(index >= 0 && index < this->length());
	return str[index];
}

char String::operator[](int index)const
{
	// check the validity of the index
	assert(index >= 0 && index < this->length());
	return str[index];
}

int String::capacity()const
{
	return STRING_SIZE - 1;
}

int String::length()const
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		++count;
	}
	return count;
}

std::istream& operator>>(std::istream& ins, String& the_string)
{
	ins >> the_string.str;
	return ins;
}

std::ostream& operator<<(std::ostream& outs, const String& the_string)
{
	for (int i = 0; i < the_string.length(); ++i)
	{
		outs << the_string.str[i];
	}
	return outs;
}

String String::operator+(const String& addend)const
{
	String temp(this->str);
	int j = temp.length();
	for (int i = 0; i < addend.length(); ++i, ++j)
	{
		temp.str[j] = addend.str[i];
	}
	temp.str[j] = '\0';
	return temp;
}

bool String::operator==(const String& the_string)const
{
	if (this->length() != the_string.length()) // If the strings are not the same length, no need to proceed
		return false;

	for (int i = 0; i < the_string.length(); ++i)
	{
		if (str[i] != the_string.str[i])
		{
			return false;
		}
	}
	return true;
}

bool String::operator<(const String& the_string)const
{
	if (*this == the_string)		// In case of equality no need to proceed.
		return false;

	int smallest = the_string.length(); // avoiding out-of-range index.

	if (the_string.length() < smallest)
		smallest = the_string.length();

	for (int i = 0; i < smallest; ++i)
	{
		if (str[i] < the_string.str[i])
			return true;
		else if (str[i] > the_string.str[i])
			return false;
	}
	if (this->length() < the_string.length())
		return true;
	else
		return false;
}

String operator+(const char st1[], const String& st2)
{
	String temp(st1);
	return temp + st2;
}

String  operator+(char c, const String& st2)
{
	String temp(c);
	return temp + st2;
}

bool operator==(const char st1[], const String& st2)
{
	return String(st1) == st2;
}

bool operator==(char c, const String& the_string)
{
	return String(c) == the_string;
}

bool operator<(const char st1[], const String& st2)
{
	return String(st1) < st2;
}

bool operator<(char c, const String& the_string)
{
	return String(c) < the_string;
}

bool operator<=(const String& st1, const String& st2)
{
	return st1 < st2 || st1 == st2;
}

bool operator!=(const String& st1, const String& st2)
{
	return !(st1 == st2);
}

bool operator>=(const String& st1, const String& st2)
{
	return !(st1 < st2);
}

bool operator>(const String& st1, const String& st2)
{
	return !(st1 <= st2);
}

String String::substr(int start, int end) const
{
	int string_len = this->length();
	if (string_len == 0) // If this string is empty no need to proceed
		return String();	// The most/least you can subscript is an empty string

	assert(end < string_len);
	assert(start <= end);
	assert(start >= 0 && end >= 0);
	String substr;
	for (int i = start; i <= end; ++i)
	{
		substr = substr + String(str[i]);
	}
	return substr;
}

int String::findch(int start, char ch) const
{
	int string_len = this->length();
	if (string_len == 0) // If this string is empty no need to proceed
		return -1;
	assert(start >= 0 && start < string_len);
	for (int i = start; i < string_len; ++i)
	{
		if (str[i] == ch)
			return i;
	}
	return -1;
}

int String::findstr(int start, const String& target_str) const
{
	int string_length = this->length();
	if (string_length == 0) // If this string is empty no need to proceed
		return -1;

	assert(start >= 0 && start < string_length);
	int target_length = target_str.length();

	if (target_length > string_length)   // if target_str is longer than this string
	{									  // then it can't be a substring in this string.
		return -1;
	}

	for (int i = start; i + target_length <= string_length; ++i)
	{
		if (this->substr(i, target_length + i - 1) == target_str)
			return i;
	}
	return -1;
}