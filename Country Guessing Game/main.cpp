// Program description:-
// This is a simple interactive program which asks the user some yes/ no questions
// and then guess the country depending on the user's answers to the questions.
// The user will provide info. to improve the program's database.
//
//	--------Copyright ©-----------
//	@Author: Adnan Hashem Mohamed
//
//	------------------------------

#include"game.h"
#include<string>
#include<iostream>
#include<fstream>

using std::cout; using std::endl;
using namespace countries_adnan;
using binary_tree_adnan::binary_tree_node;
using std::string;

void beginning_tree(std::istream& in, binary_tree_node<std::string>*& root_ptr);
void tree_to_file(std::ostream& out, binary_tree_node<std::string>*& root_ptr);
void validate_commands(int argc, int right, const char usage[]);

int main(int argc, const char*argv[]) {

	validate_commands(argc, 2, "<program> <input_file>");

	instruct();
	binary_tree_node<string>* root_ptr = NULL;
	
	// open the input file.
	std::ifstream in;
	if (argc != 1)
	{
		in.open(argv[1]);
	}
	else {
		in.open("database.txt");
	}
	if (in.fail())
	{
		std::cerr << "FAILED opening the input file: " << argv[1] << endl;
		exit(1);
	}

	beginning_tree(in, root_ptr);
	in.close();

	do
	{
		play(root_ptr);
	} while (inquire("Play again?"));
	cout << "Thanks for playing ! :)\n";

	// send the tree to the database
	std::ofstream out;
	if (argc != 1)
	{
		in.open(argv[1]);
	}
	else {
		in.open("database.txt");
	}

	if (out.fail())
	{
		std::cerr << "FAILED opening the output file : " << argv[1] << endl;
		exit(1);
	}

	tree_to_file(out, root_ptr);
	out.close();
}

void beginning_tree(std::istream& in, binary_tree_node<std::string>*& root_ptr)
{
	int next;
	in >> next;
	std::string data;
	if (!in.eof())
	{
		if (next != 0)
		{
			in.ignore(); // ignoring the :
			std::getline(in, data, ';');
			root_ptr = new binary_tree_node<std::string>(data);
			beginning_tree(in, root_ptr->left());
			beginning_tree(in, root_ptr->right());
		}
	}

}

void tree_to_file(std::ostream& out, binary_tree_node<std::string>*& root_ptr)
{
	if (root_ptr == NULL)
	{
		out << 0 << endl;
	}
	else {
		out << 1 << ":" + root_ptr->data() + ";"<< endl;
		tree_to_file(out, root_ptr->left());
		tree_to_file(out, root_ptr->right());
	}
}

void validate_commands(int argc, int right, const char usage[])
{
	try {
		if (argc != right && argc != 1)
			throw argc;
	}
	catch (int e)
	{
		cout << e << " arguments given, while " << right << " are expected.\n";
		cout <<"Usage: "<< usage << endl;
		cout << "In visual studio, the program name is passed automatically.\n";
		exit(1);
	}

}