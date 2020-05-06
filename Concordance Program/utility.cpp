// This is the implementation file for the funcitions to be used
// in main.cpp
// See interface in utility.hpp
//
//	--------Copyright ©-----------
//	@Author: Adnan Hashem Mohamed
//	------------------------------
#include"utility.hpp"
#include<iostream>
#include<string>
#include<vector>
#include"bst/binary_tree.h"
#include"bst/bst_tree.h"

using std::cout; using std::cin; using std::endl;
using std::vector;

bool operator<(const book& b1, const book& b2)
{
	return b1.author < b2.author;
}

std::ostream& operator<<(std::ostream& out, const book& the_book)
{

	out << "Title: " << the_book.title << endl
		<< "Author: " << the_book.author << endl
		<< "ISBN: " << the_book.ISBN << endl
		<< "Publication Date: " << the_book.pub_date;
	return out;
}

void format_name(std::string& name)
{
	name[0] = toupper(name[0]);
	for (size_t i = 1; i < name.length(); i++)
	{
		name[i] = tolower(name[i]);
	}
	int index = name.find(' ');
	name[index + 1] = toupper(name[index + 1]);
}

std::string get_name()
{
	std::string name;
	cout << "Type the author's first and last name: ";
	getline(cin, name);
	format_name(name);
	return name;
}

bool inquire(std::string query)
{
	char answer;
	cout << query << endl;
	cout << "Type [yes/no] then press enter: ";
	std::cin >> answer;
	eat_line(std::cin);
	return toupper(answer) == 'Y';
}

void validate_commands(int argc, int right, const char usage[])
{
	try {
		if (argc != right)
			throw argc;
	}
	catch (int e)
	{
		cout << e << " arguments given, while " << right << " is expected expected.\n";
		cout << "Usage: " << usage << endl;
		cout << "In visual studio, the program name is passed automatically.\n";
		exit(1);
	}

}

void instruct()
{
	cout << "\t**** Welcome to my book database ! *****\n\n";
	cout << "You can search for books by the author name!\n";
	cout << "Type the author name then press enter to retrieve the\n"
		<< "information about the book(s) that author have written.\n\n";
}

void build_database(std::istream& fin, bst_adnan::bst<book>& records)
{
	std::string next;
	std::size_t isbn=0;

	// ignore first line.
	getline(fin, next);

	// read each line and parse the data.
	book the_book;
	
	while (!fin.eof())
	{
		getline(fin, next, ';'); // reading the title
		the_book.title = next;
		getline(fin, next, ';'); // reading the ISBN
		the_book.ISBN = next;
		getline(fin, next, ';'); // reading the author's name
		the_book.author = next;
		fin >> the_book.pub_date;
		records.insert(the_book);
		eat_line(fin);
	}
}

void eat_line(std::istream& in)
{
	char next;
	do {
		in.get(next);
	} while (in && next != '\n');
}

bool name_match(const book& the_book, const std::string& name)
{
	return the_book.author == name;
}

std::vector<book> get_books(const bst_adnan::bst<book>& b, const std::string& name)
{
	std::vector<book>temp;
	binary_tree_adnan::get_items(b.get_root_ptr(), name_match, name, temp);
	return temp;
}

void print_books(std::ostream& out, std::vector<book> books)
{
	for (auto b : books)
	{
		out << "===================\n\n"
			<< b << endl << endl
			<< "===================\n\n";
	}
}