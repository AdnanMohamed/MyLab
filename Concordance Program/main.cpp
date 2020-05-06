// This is a simple interactive program. The program allows the user
// to search books by ISBN, book title, or author.
//
//	--------Copyright ©-----------
//	@Author: Adnan Hashem Mohamed
//	------------------------------

#include<iostream>
#include"bst/bst_tree.h"
#include"utility.hpp"
#include<fstream>
#include<string>

using std::cout; using std::endl; using std::cin;
using bst_adnan::bst; using std::ifstream; using std::string;
int main(int argc, const char* argv[])
{
	const char usage[] = "program_name file.txt";
	validate_commands(argc, 2, usage);
	bst<book>my_library;
	// open the input file.
	ifstream fin(argv[1]);
	if (fin.fail())
	{
		std::cerr << "Failed opening the file.\n";
		exit(1);
	}
	build_database(fin, my_library);

	std::string ask_repeat = "Do you want to search more?";

	// prompt the user about program usage
	instruct();
	cout << "------------\n";
	std::string author;
	book result;
	bool found;
	do {
		author = get_name();
		auto author_books = get_books(my_library, author);
		
		if (author_books.size()>0)
		{
			print_books(cout, author_books);
		}
		else
		{
			cout << "I am sorry, I don't have a book associated with " + author << endl;
			cout << "I am willing to help you with another author !!" << endl << endl;
		}
	} while (inquire(ask_repeat));
}