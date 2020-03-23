// @Author: Adnan H. Mohamed
//

#include"string.hpp"
#include"stack.hpp"
#include<fstream>

stack<String> infix_to_postfix(std::istream& in)
{
	// The stack which holds the postfix expression
	stack<String> postfix;

	String s;
	in >> s;
	while (s != ';')
	{
		if (s == ')')
		{
			String right = postfix.pop();
			String opr = postfix.pop();
			String left = postfix.pop();
			postfix.push(left + " " + right + " " + opr);
		}
		else if (s != '(')
			postfix.push(s);
		in >> s;
	}
	return postfix;
}