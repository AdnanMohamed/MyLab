#include"stack.hpp"
#include"string.hpp"
#include"utilities.h"
#include<iostream>
#include<fstream>

using std::cout; using std::istream; using std::endl;

void print_stack(stack<String> s)
{
	while (!s.empty())
	{
		cout << s.pop();
	}
}

int main()
{
	std::fstream in;
	in.open("data3-2-1.txt");
	if (in.fail())
	{
		cout << "Failed opening data3-1.txt";
		exit(1);
	}
	while (in)
	{
		stack<String>postfix = infix_to_postfix(in);
		print_stack(postfix);
		cout << endl;
	}
}