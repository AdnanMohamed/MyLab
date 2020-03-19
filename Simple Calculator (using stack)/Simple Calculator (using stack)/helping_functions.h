// This is the header file for the helping function used in calc.cpp
// The functions are within the namespace: calc_adnan
//
// 7/Mar/2020
// @Author: Adnan Hashem Mohamed

#ifndef HELPING_FUNCTIONS_H
#define HELPING_FUNCTIONS_H

#include<fstream>
#include"stack.h"

namespace calc_adnan {

	void validate_argc(int argc, int right, const char usage[]);

	bool evaluate_line(std::istream& input, double& answer);
	// Precondition: There is input to be read from the file.
	// Postcondition: One line of the input file has been read (up to
	// and including the newline character). The function has tried to
	// interpret this line as a postfix arithmetic 
	// expression made up of nonnegative double numbers and the
	// four operations + - * and /. If everything went right, then
	// the parameter answer is set to the value of this expression,
	// and true is returned. If there were problems, then returns false.

	bool evaluate_stack_top(char operation, stack_adnan::stack<double>& numbers);
	// Postconditions: 2 numbers are popped off of the stack, combinded using the
	// operation provided and the result is pushed onto the stack.  If any error
	// is encountered, e.g., numbers.size() < 2, or operation is not '+', '-', '*'
	// or '/', or division by 0.0 occurs, then the return is false otherwise returns true.

} // end of namespace

#endif // !HELPING_FUNCTIONS_H