// This is the implementation file for the helping functions used in calc.cpp
// The functions are within the namespace (calc_adnan)
// See functions' prototypes in helping_functions.h
//
// 7/Mar/2020
// @ Author: Adnan Hashem Mohamed
//

#include"helping_functions.h"
#include"stack.h"
#include<string>

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

	bool higher_equal(char op1, char op2)
	{
		return !(strchr("+-", op1) != NULL && strchr("*/", op2) != NULL);
	}

	bool evaluate_infix(std::string expression, double& answer)
	{
		// stack for numbers
		stack_adnan::stack<double>numbers;
		// stack of '(' and '*/+-'
		stack_adnan::stack<char>operators;

		const char DECIMAL = '.';

		for (int i = 0; i < expression.size(); ++i)
		{
			if (isdigit(expression[i]) || expression[i] == DECIMAL)
			{
				auto end = expression.find(' ', i);
				numbers.push(std::stod(expression.substr(i, end)));
				i = end;
			}
			else if (strchr("(*/+-", expression[i]) != NULL)
			{
				if (operators.size() != 0 && (expression[i] != '(' && operators.top() != '(')
					&& higher_equal(operators.top(), expression[i]))
				{
					if (!evaluate_stack_top(operators.top(), numbers))
						return false;
					operators.pop();
				}
				operators.push(expression[i]);
			}
			else if (expression[i] == ')')
			{
				while (operators.top() != '(')
				{
					if (!evaluate_stack_top(operators.top(), numbers))
						return false;
					operators.pop();
				}
				// pop the left peranthesis
				operators.pop();
			}
		}
		answer = numbers.top();
		return true;
	}

	bool evaluate_postfix(std::string expression, double& answer)
	{
		// stack to keep track of numbers
		stack_adnan::stack<double> numbers;
		
		const char DECIMAL = '.';

		for (int i = 0; i < expression.size(); ++i)
		{
			if (isdigit(expression[i]) || expression[i] == DECIMAL)
			{
				auto end = expression.find(' ', i);
				numbers.push(std::stod(expression.substr(i, end)));
				i = end;
			}
			else if (strchr("*/+-", expression[i]) != NULL)
			{
				if (!evaluate_stack_top(expression[i], numbers))
					return false;
			}
		}

		answer = numbers.top();
		return true;
	}

	//std::string infix_to_postfix(const std::string& infix)
	//{
	//	std::string postfix;
	//	const char DECIMAL = '.';
	//	const char LEFT_PARANTH = '(';
	//	const char RIGHT_PARANTH = ')';

	//	// stack to hold the operations
	//	stack_adnan::stack<char>operators;

	//	for (int i = 0; i < infix.size(); ++i)
	//	{
	//		if(isdigit(infix[i])
	//			|| (infix[i] == '-' && i != infix.size() && isdigit(infix[i+1])))
	//			postfix+=infix[i];
	//		
	//		else if (strchr("(*-/+", infix[i]) != NULL)
	//		{
	//			if (infix.size() != 0 && (infix[i] != '(' && operators.top() != '(')
	//				&& higher_equal(operators.top(), infix[i]))
	//			{
	//				postfix += " " + operators.top();
	//				operators.pop();
	//			}
	//			operators.push(infix[i]);
	//		}
	//		
	//		else if(infix[i] == RIGHT_PARANTH)
	//		{
	//			while (operators.top() != '(')
	//			{
	//				postfix += " " + operators.top();
	//				operators.pop();
	//			}
	//			// pop the left peranthesis
	//			operators.pop();
	//		}
	//	}

	//	return postfix;
	//}

} // end of namespace