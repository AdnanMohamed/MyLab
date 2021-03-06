// FILE: mystring.h
// @Authors: Main and Savitch
// CLASS PROVIDED: string
//   This is a simple version of the Standard Library string.
//   It is part of the namespace string_adnan, from the textbook
//   "Data Structures and Other Objects Using C++"
//   by Michal Main and Walter Savitch
//
// CONSTRUCTOR for the string class:
//   string(const char str[ ] = "") -- default argument is the empty string.
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The string contains the sequence of chars from str.
//
// CONSTRUCTOR:
//  string(char ch)
//     Postcondition: The string contains the character ch.
//
// CONSTANT MEMBER FUNCTIONS for the string class:
//   size_t length( ) const
//     Postcondition: The return value is the number of characters in the
//     string.
//
//   char operator [ ](size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
// MODIFICATION MEMBER FUNCTIONS for the string class:
//   void operator +=(const string& addend)
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated string.
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the string.
//
//   void reserve(size_t n)
//     Postcondition: All functions will now work efficiently (without
//     allocating new memory) until n characters are in the string.
//
//   void insert(const string& str, size_t index);
//     Precondition: index should be a valid index (0 to the length of calling string)
//     Postcondition: str is inserted to the sequence of characters starting at index.
//
//   void erase(size_t start, size_t end = -1);
//     Precondition: start >= 0, end > start (by default: end will be the length of the string)
//     Postcondition: If end is given, the string will be erased from start to end (NOT INCLUDED).
//     If only start given, the string will be erased from start to the rest of the string.
//  
//   void replace(const string& original, const string& new_str);
//     Postcondition: if original is a substring in the string, it is replaced by new_str.
//     otherwise, the string is not affected.
// 
//   void replace(char original, char new_char);
//     Postcondition: if original is in the string, all originals are replaced by new_str.
//     otherswise, nothing changes.
//
//   int find(char ch);
//     Postcondition: The index of the first occurence of ch is returned. If not
//     found returns -1.
//
//   int find(const string& substring)
//     Postcondition: The index of the first occurence of substring is returned. If not
//     found returns -1.
//
//   size_t count(char ch);
//     Postcondition: number of times ch occured in the string is returned
//
// NON-MEMBER FUNCTIONS for the string class:
//   string operator +(const string& s1, const string& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
//
//   istream& operator >>(istream& ins, string& target)
//     Postcondition: A string has been read from the istream ins, and the
//     istream ins is then returned by the function. The reading operation
//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
//     Then the string is read up to the next white space or the end of the
//     file. The white space character that terminates the string has not
//     been read.
//
//   ostream& operator <<(ostream& outs, const string& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
//
//   void getline(istream& ins, string& target, char delimiter = '\n')
//     Postcondition: A string has been read from the istream ins. The reading
//     operation starts by skipping any white space, then reading all characters
//     (including white space) until the delimiter is read and discarded (but
//     not added to the end of the string). The return value is ins.
//     The default delimiter, if not given, is newline.
//
//  VALUE SEMANTICS for the string class:
//    Assignments and the copy constructor may be used with string objects.
//
//  TOTAL ORDER SEMANTICS for the string class:
//    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
//    for the string class, forming a total order semantics, using the usual
//    lexicographic order on strings.
// 
// DYNAMIC MEMORY usage by the string class: 
//   If there is insufficient dynamic memory then the following functions call
//   new_handler: The constructors, resize, operator +=, operator +, and the
//   assignment operator.

#ifndef MAIN_SAVITCH_CHAPTER4_MYSTRING_H
#define MAIN_SAVITCH_CHAPTER4_MYSTRING_H
#include <cstdlib>  // Provides size_t
#include<iostream>

namespace string_adnan
{
    class string
    {
    public:
        // CONSTRUCTORS and DESTRUCTOR
        string(const char str[] = "");
        string(char ch);
        string(const string& source);
        ~string() { delete sequence; }
        // MODIFICATION MEMBER FUNCTIONS
        void operator +=(const string& addend);
        void operator +=(const char addend[]);
        void operator +=(char addend);
        void reserve(size_t n);
        void operator =(const string& source);
        //@ Written by: Adnan Mohamed
        void insert(const string& str, size_t index);
        void erase(size_t start, size_t end = -1);
        void replace(const string& original, const string& new_str);
        void replace(char original, char new_char);
        int find(char ch);
        int find(const string& substring);
        size_t count(char ch);
        // CONSTANT MEMBER FUNCTIONS
        size_t length() const { return current_length; }
        char operator [](size_t position) const;
        // FRIEND FUNCTIONS
        friend std::ostream& operator <<(std::ostream& outs, const string& source);
        friend bool operator ==(const string& s1, const string& s2);
        friend bool operator !=(const string& s1, const string& s2);
        friend bool operator >=(const string& s1, const string& s2);
        friend bool operator <=(const string& s1, const string& s2);
        friend bool operator > (const string& s1, const string& s2);
        friend bool operator < (const string& s1, const string& s2);
    private:
        char* sequence;
        size_t allocated;
        size_t current_length;
    };

    // NON-MEMBER FUNCTIONS for the string class
    string operator +(const string& s1, const string& s2);
    std::istream& operator >>(std::istream& ins, string& target);
    void getline(std::istream& ins, string& target, char delimiter = '\n');
}

#endif

