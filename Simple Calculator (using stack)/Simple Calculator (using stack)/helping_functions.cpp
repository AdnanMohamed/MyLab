// This is the implementation file for the helping functions used in calc.cpp
// The functions are within the namespace (calc_adnan)
// See functions' prototypes in helping_functions.h
//
// 7/Mar/2020
// @ Author: Adnan Hashem Mohamed
//

#include"helping_functions.h"
#include"stack.h"

namespace calc_adnan {

	void validate_argc(int argc, int right, const char usage[])
	{
		if (argc != right)
		{
			std::cerr << usage;
			exit(1);
		}
	}

	bool evaluate_stack_top(char operation, stack_adnan::stack<double>& numbers)
	{
		if (numbers.size() < 2 || strchr("*\-+", operation) == NULL)
			return false;

		double left_operand, right_operand;
		right_operand = numbers.top();
		numbers.pop();
		left_operand = numbers.top();
		numbers.pop();

		switch (operation)
		{
		case '+':numbers.push(left_operand + right_operand);
			break;
		case '-':numbers.push(left_operand - right_operand);
			break;
		case '*':numbers.push(left_operand * right_operand);
			break;
		case '/':numbers.push(left_operand / right_operand);
			break;
		}
		return true;
	}

	bool evaluate_line(std::istream& input, double& answer)
	{
		double num;
		char opr;
		stack_adnan::stack<double> numbers;
		const char DECIMAL = '.';

		do
		{
			if (isdigit(input.peek()) || input.peek() == DECIMAL)
			{
				input >> num;
				numbers.push(num);
			}
			else if (strchr("*+-/", input.peek()) != NULL)
			{
				input.get(opr);
				if (!evaluate_stack_top(opr, numbers))
					return false;
			}
			else
			{
				input.ignore();
			}

		} while (input && input.peek() != '\n');

		if (input)
			input.get(opr);
		answer = numbers.top();
	}

} // end of namespace