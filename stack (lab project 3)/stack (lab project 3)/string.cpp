// This is the implementation file for the class string
// Project 2 Milstone 2
//
// @Author: Adnan H. Mohamed

#include"string.hpp"
#include<cassert>
#include<vector>

String::String()
{
	stringSize = 1;
	str = new char[stringSize];
	str[0] = '\0';
}

String::~String() { delete[] str; }

String::String(char ch)
{
	stringSize = 2;
	str = new char[stringSize];
	str[0] = ch;
	str[1] = '\0';
}

String::String(const char s[])
{
	// compute the size of s
	stringSize = 1;
	for (int i = 0; s[i] != '\0'; ++i, ++stringSize)
	{
		// empty
	}

	str = new char[stringSize];
	// initialize each element of str to the corresponding in s
	for (int i = 0; s[i] != '\0'; ++i)
	{
		str[i] = s[i];
	}

	str[stringSize - 1] = '\0';
}

String::String(const String& source)
{
	stringSize = source.stringSize;
	str = new char[stringSize];

	for (int i = 0; i < stringSize; ++i)
	{
		str[i] = source.str[i];
	}
}

String& String::operator= (String rhs)
{
	if (this != &rhs)
	{
		stringSize = rhs.stringSize;
		delete[]str;
		str = new char[stringSize];

		for (int i = 0; i < stringSize; ++i)
		{
			str[i] = rhs.str[i];
		}
	}

	return *this;
}

void String::swap(String& the_string)
{
	// swaping sizes
	int temp_size = stringSize;
	stringSize = the_string.stringSize;
	the_string.stringSize = temp_size;

	// swaping char[]
	char* temp = str;
	str = the_string.str;
	the_string.str = temp;

}

char& String::operator[](int index)
{
	// check the validity of the index
	assert(index >= 0 && index <= this->length());
	return str[index];
}

char String::operator[](int index)const
{
	// check the validity of the index
	assert(index >= 0 && index <= this->length());
	return str[index];
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

int String::capacity()const
{
	return stringSize - 1;
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

String  String::operator+(const String& addend)const
{
	char* temp = new char[length() + addend.length() + 1];
	for (int i = 0; i < length(); ++i)
	{
		temp[i] = str[i];
	}
	int j = length();
	for (int i = 0; i <= addend.length(); ++i, ++j)
	{
		temp[j] = addend.str[i];
	}
	String new_str(temp);
	return new_str;
}

String& String::operator+=(const String& addend)
{

	char* new_str = new char[addend.stringSize + stringSize - 1];
	for (int i = 0; i < stringSize; ++i)
	{
		new_str[i] = str[i];
	}

	for (int i = stringSize - 1, j = 0; j < addend.stringSize; ++i, ++j)
	{
		new_str[i] = addend.str[j];
	}
	stringSize += addend.length();
	delete[] str;
	str = new_str;
	return *this;
}

String operator+(const char st1[], const String& st2)
{
	String temp(st1);
	return temp + st2;
}

String  operator+(const String& s1, const char s2[])
{
	return s1 + String(s2);
}

String  operator+ (const String& s, char c)
{
	return s + String(c);
}

String operator+ (char c, const String& st2)
{
	String temp(c);
	return temp + st2;
}

String& operator+=(String& s, char c)
{
	return s += String(c);
}

String& operator+=(String& s1, const char s2[])
{
	return s1 += String(s2);
}

std::ostream& operator<<(std::ostream& outs, const String& the_string)
{
	for (int i = 0; i < the_string.length(); ++i)
	{
		outs << the_string.str[i];
	}
	return outs;
}

bool operator==(const char st1[], const String& st2)
{
	return String(st1) == st2;
}

bool operator==(char c, const String& the_string)
{
	return String(c) == the_string;
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

	// assert(end < string_len);
	// assert(start <= end);
	// assert(start >= 0 && end >= 0);
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
	// assert(start >= 0 && start < string_len);
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

	// assert(start >= 0 && start < string_length);
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

std::istream& operator>>(std::istream& ins, String& s)
{
	char next;
	do
	{
		ins.get(next);
	} while (!ins.eof() && isspace(next));
	s = String();
	while (!ins.eof() && !isspace(next))
	{
		s += next;
		ins.get(next);
	}
	s.resetCapacity(s.length() + 1);
	return ins;
}

void  String::resetCapacity(int n)
{
	if (n > stringSize)
	{
		char* new_str = new char[n];
		for (int i = 0; i < stringSize; ++i)
		{
			new_str[i] = str[i];
		}
		stringSize = n;
		delete[] str;
		str = new_str;
	}
}

String::String(int c)
{
	stringSize = c + 1;
	str = new char[stringSize];
	str[0] = '\0';
}

String::String(int c, const char s[])
{

	str = new char[c + 1];
	int index = 0;
	while (s[index] != '\0')
	{
		str[index] = s[index];
		++index;
	}
	str[index] = '\0';
	stringSize = c + 1;
}

std::vector<String> String::split(char c) const
{
	std::vector<String> v;
	String s;
	if (length() == 0)
	{
		v.push_back(s);
		return v;
	}

	for (int i = 0; i < length(); ++i)
	{
		if (str[i] == c)
		{
			v.push_back(s);
			s = String();
		}
		else
			s += str[i];
	}
	v.push_back(s);
	return v;
}