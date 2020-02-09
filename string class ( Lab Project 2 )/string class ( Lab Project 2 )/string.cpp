// This is the implementation file for the class String.
// The classe's interface is in the file: string.hpp
//
// @Author: Adnan Mohamed
//
#include"string.hpp"
#include<cassert>

String::String()                                                                  
{
	length_ = 0;
	str[0] = '\0';
}

String::String(char ch)                                                                 
{
	length_ = 1;
	str[0] = ch;
	str[1] = '\0';
}

String::String(const char the_str[])
{
	length_ = 0;
	int index = 0;
	while (the_str[index] != '\0' && length_<STRING_SIZE-1)
	{
		str[index] = the_str[index];
		++index;
		++length_;
	}
	str[index] = '\0';
}

char& String::operator[](int index)                                                            
{
	// check the validity of the index
	assert(index >= 0 && index < length_);
	return str[index];
}

char String::operator[](int index)const
{
	// check the validity of the index
	assert(index >= 0 && index < length_);
	return str[index];
}

int String::capacity()const                    
{
	return STRING_SIZE - 1;
}

int String::length()const
{
	return length_;
}

std::istream& operator>>(std::istream& ins, String& the_string)
{
	ins >> the_string.str;
	return ins;
}

std::ostream& operator<<(std::ostream& outs, const String& the_string)
{
	for (int i = 0; i < the_string.length_; ++i)
	{
		outs << the_string.str[i];
	}
	return outs;
}