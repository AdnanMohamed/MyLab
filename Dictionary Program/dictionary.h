// This is the header file for the funciton prototypes to used in main.cpp
// 
//-------- Copyright © ---------
//  @Author: Adnan Hashem Mohamed
//-------------------------------
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include"Table/table3.h"
#include<fstream>
#include<string>

struct word_def {
	std::string word;
	std::string def;
};

// constant for the size of the dictionary.
const int TABLE_SIZE = 26;


void validate_commands(int argc, int right, const char usage[]);
// Precondition: argc is the actual number of arguments passed in execution.
// argc should equal right or right -1. usage[] is the message to be displayed in
// case of error.
// Postcondition: if argc != right or right-1, then usage is displayed and the program halts.

void instruct();
// Postcondition: prompts the user on how to use the program

void eat_line(std::istream& in);
// Precondition: 'in' is a valid input stream.
// Postcondition: reads input until endline.

std::string get_user_word();
// Returns the user's entered word in formated by
// capitalizing the first letter ONLY.

void format_word(std::string& term);
// Postcondition: The string first letter capitalized only.

bool inquire(std::string query);
// Postcondition: displays the question to the user.
// Returns true if the user replies yes, else false is returned.



void format_definition(std::string& def);

std::string hashkey(const word_def& d);
// Postcondition: returns a the key.

void build_dictionary(std::istream& fin, table3_adnan::table<word_def, TABLE_SIZE, hashkey>& dict);
// Postcondition: reads the words and defintions from the file and build the dictionary
// of word/defintion pair in a table, such that a definiton can be searched by a key "word".


#endif // !DICTIONARY_H

