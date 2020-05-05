// Implementation file for funcitons to be used in main.cpp
// See header file in dictionary.h
//
//-------- Copyright © ---------
//  @Author: Adnan Hashem Mohamed
//-------------------------------

#include"dictionary.h"
#include<iostream>

using std::cout; using std::endl; using std::cin;
using std::string; 

void eat_line(std::istream& in)
{
	char next;
	do {
		in.get(next);
	} while (in && next != '\n');
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
	cout << "\t***** Welcome to my dictionary! *****\n\n"
		<< "To look up a definition of a word, simply type\n"
		<< "the word then press enter.\n\n";
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

std::string get_user_word()
{
	std::string word;
	cout << "Type the word then press enter: ";
	cin >> word;
	format_word(word);
	return word;
}

void format_word(std::string& word)
{
	word[0] = toupper(word[0]);
	for (size_t i = 1; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
}

std::string hashkey(const word_def& d)
{
	return d.word;
}

void build_dictionary(std::istream& fin, table3_adnan::table<word_def, TABLE_SIZE, hashkey>& dict)
{
	// read the file until end.
	word_def wd;
	std::getline(fin, wd.word, '?');
	format_word(wd.word);
	std::getline(fin, wd.def, '+');
	eat_line(fin);
	while (!fin.eof())
	{
		dict.insert(wd);
		std::getline(fin, wd.word, '?');
		format_word(wd.word);
		std::getline(fin, wd.def, '+');
		eat_line(fin);
	}
}

void format_definition(std::string& def)
{
	int i = 60;
	while (i < def.length())
	{
		def.insert(def.begin() + i, '\n');
		i += 60;
	}
}