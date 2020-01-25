// This is the implementation file for the class string
// You can find the class in mystring.h
// @Author: Adnan Mohamed
//
//  CLASS INVARIANT: -- the class invariant is from Savitch and Main c++ book.
// 1. The string is stored as a null - terminated string in the dynamic array that characters points to. 
// 2. The total length of the dynamic array is stored in the member variable allocated. 
// 3. The total number of characters prior to the null character is stored in current_length, 
//    which is always less than allocated.

#include<iostream>
#include"mystring.h"
#include<cstring>
using std::cout; using std::cin; using std::endl;
namespace string_adnan
{
	string::string(const char str[])
	{
		allocated = strlen(str) + 1;
		sequence = new char[allocated];
		strcpy_s(sequence, allocated, str);
		current_length = strlen(sequence);
	}

	string::string(char ch)
	{
		allocated = 2;
		current_length = 1;
		sequence = new char[allocated];
		sequence[0] = ch;
		sequence[1] = '\0';
	}

	string::string(const string& source)
	{
		allocated = source.allocated;
		current_length = source.current_length;
		sequence = new char[source.allocated];
		strcpy_s(sequence, allocated, source.sequence);
	}

	void string::operator +=(const string& addend)	
	{	
		if(allocated < current_length + addend.current_length + 1)
			this->reserve((allocated + addend.current_length) * 1.5);
		if(this != &addend)
			strcat_s(sequence, allocated, addend.sequence);
		else
		{

			char* temp = new char[allocated];
			strcpy_s(temp, allocated, sequence);
			strcat_s(temp, allocated, sequence);
			delete sequence;
			sequence = temp;
		}
		current_length += addend.current_length;
	}

	void string::operator +=(const char addend[])
	{
		if (allocated < current_length + strlen(addend) + 1)
			this->reserve((allocated + strlen(addend)) * 1.5);
		strcat_s(sequence, allocated, addend);
		current_length += strlen(addend);
	}

	void string::operator +=(char addend)
	{
		if (allocated < current_length + 2)
			this->reserve(allocated * 2);
		sequence[current_length] = addend;
		sequence[current_length + 1] = '\0';
		++current_length;
	}

	char string::operator [ ](size_t position) const
	{
		return sequence[position];
	}

	std::ostream& operator <<(std::ostream& outs, const string& source)
	{
		for (size_t i = 0; source[i] != '\0'; ++i)
		{
			outs << source[i];
		}
		return outs;
	}

	void string::reserve(size_t n) {
		if (n > current_length)
		{
			char* temp = new char[n];
			strcpy_s(temp, n, sequence);
			delete sequence;
			sequence = temp;
			allocated = n;
		}
	}

	void string::operator =(const string& source)
	{
		if (this != &source)
		{
			allocated = source.allocated;
			current_length = source.current_length;
			delete sequence;
			sequence = new char[allocated];
			for (size_t i = 0; source.sequence[i] != '\0'; ++i)
			{
				sequence[i] = source.sequence[i];
			}
			sequence[source.current_length] = '\0';
		}
	}

	void string::insert(const string& str, size_t index)
	{
		allocated += str.allocated;
		char* temp = new char[allocated];
		strncpy_s(temp, allocated,sequence, index);
		strcat_s(temp, allocated, str.sequence);
		strcat_s(temp, allocated, sequence + index);
		delete sequence;
		sequence = temp;
		current_length += str.current_length;
	}

	void string::erase(size_t start, size_t end)
	{
		if (end == -1)
			end = current_length;
		allocated -= (end - start);
		char* temp = new char[allocated];
		strncpy_s(temp, allocated, sequence, start);
		strcat_s(temp, allocated, sequence + end);
		delete sequence;
		sequence = temp;
		current_length = strlen(temp);
	}

	int string::find(char ch)
	{
		char* p;
		p = strchr(sequence, ch);
		if (p == NULL)
			return -1;
		else
			return p - sequence;
	}

	int string::find(const string& substring)
	{
		char* p;
		p = strstr(sequence, substring.sequence);
		if (p == NULL)
			return -1;
		else
			return p - sequence;
	}

	size_t string::count(char ch)
	{
		size_t sum = 0;
		char* p;
		p = strchr(sequence, ch);
		while (p != NULL)
		{
			++sum;
			p = strchr(p + 1, ch);
		}
		return sum;
	}

	void string::replace(const string& original, const string& new_str)
	{
		int index = -1;
		index = this->find(original);
		while (index != -1)
		{
			this->erase(index, index + original.length());
			this->insert(new_str, index);
			index = this->find(original);
		}
	}

	void string::replace(char original, char new_char)
	{
		int index = -1;
		index = this->find(original);
		while (index != -1)
		{
			this->erase(index, index + 1);
			this->insert(new_char, index);
			index = this->find(original);
		}
	}

	bool operator ==(const string& s1, const string& s2)
	{
		if (s1.current_length == s2.current_length)
		{
			for (size_t i = 0; i < s1.current_length; ++i)
			{
				if (s1[i] != s2[i])
					return false;
			}
			return true;
		}
		else
			return false;
	}
	bool operator !=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
	
	bool operator > (const string& s1, const string& s2)
	{
		if (s1 == s2)		// In case of equality no need to proceed.
			return false;

		size_t smallest = s1.current_length; // avoiding out-of-range index.

		if (s1.current_length > s2.current_length)
			smallest = s2.current_length;

		for (size_t i = 0; i < smallest; ++i)
		{
			if (s1[i] < s2[i])
				return false;
		}
		return true;
	}
	bool operator < (const string& s1, const string& s2)
	{
		return !(s1 == s2 || s1 > s2);
	}

	bool operator >=(const string& s1, const string& s2)
	{
		return s1 > s2 || s1 == s2;
	}
	
	bool operator <=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}

	string operator +(const string& s1, const string& s2)
	{
		string temp;
		temp += s1;
		temp += s2;
		return temp;
	}

	std::istream& operator >>(std::istream& ins, string& target)  // This is not complete. Look at header file.
	{
		char next;
		// skipping white space and first character( if it was equal to delimiter)
		do {
			ins.get(next);
		} while ((next == ' ' || next == '\n') && !ins.eof());

		while (next != '\n' && next != ' ')
		{
			target += next;
			ins.get(next);
			if (ins.eof())
				break;
		}
		return ins;
	}

	void getline(std::istream& ins, string& target, char delimiter)
	{
		char next;						
		// skipping white space.
		do {
			ins.get(next);
		} while ((next == ' ' || next == '\n') && !ins.eof());

		// Reading the rest until reaching delimeter or the end of the file.
		// delimiter will not be included to target.
		while (next != delimiter && !ins.eof())
		{
			target += next;
			ins.get(next);
		}
	
	}

} // end of namespace



