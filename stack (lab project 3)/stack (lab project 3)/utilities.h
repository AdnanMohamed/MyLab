// @Author: Adnan H. Mohamed
//
// stack<String> infix_to_postfix(std::istream& in)
//	Precondition: in is the input stream to a file (or could be keyboard)
//	Postcondition: The return value is a stack of strings which represents
//  the postfix equivalent to the infix expression read by the function.

#ifndef UTILITIES_H
#define	UTILITIES_H
#include"string.hpp"
#include"stack.hpp"
#include<fstream>

stack<String> infix_to_postfix(std::istream& in);

#endif // !UTILITIES_H

