// This header file contains the struct Book and other functions that
// will be used in main.cpp.
//
//	--------Copyright ©-----------
//	@Author: Adnan Hashem Mohamed
//	------------------------------

#ifndef BOOKS_H
#define BOOKS_H

#include<string>
#include<iostream>
#include"bst/bst_tree.h"
#include<vector>
#include"bst/binary_tree.h"


struct book {
	std::string ISBN;
	std::string title;
	std::string author;
	int pub_data; // the year of publication.
	
};

std::ostream& operator<<(std::ostream& out, const book& the_book);
// Postcondition: prints the book's information.

bool operator<(const book& b1, const book& b2);
// Postcondition: returns true if the author's name of b1
// comes first (lexicographically), otherwise returns false

void format_name(std::string& name);
// Precondition: name is a string of two words, (first_name last_name).
// Postcondition: name is now capitalized (both first and last name).

std::string get_name();
// Postcondition: asks the user to type a name then returns
// a formated name from the user.

void build_database(std::istream& fin, bst_adnan::bst<book>& records);
// Postcondition: The books have been read from the file to the book records.

bool inquire(std::string query);
// Postcondition: displays the question to the user.
// Returns true if the user replies yes, else false is returned.

void instruct();
// Postcondition: prompts the user on how to use the program

void validate_commands(int argc, int right, const char usage[]);
// Precondition: argc is the actual number of arguments passed in execution.
// argc should equal right or right -1. usage[] is the message to be displayed in
// case of error.
// Postcondition: if argc != right or right-1, then usage is displayed and the program halts.

void eat_line(std::istream& in);
// Precondition: 'in' is a valid input stream.
// Postcondition: reads input until endline.

bool name_match(const book& the_book, const std::string& name);
// returns true if "name" and the_book's author's name match else returns false.

std::vector<book> get_books(const bst_adnan::bst<book>& b, const std::string& name);
// returns a vector of books that were written by the given author "name".

void print_books(std::ostream& out, std::vector<book> books);
// Prints the information associated with each book in a decorated way to out.

#endif // !BOOKS_H

