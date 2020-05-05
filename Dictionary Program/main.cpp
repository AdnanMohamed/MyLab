// This is a simple interactive dictionary. The user is asked to
// type a word and its definition will be displayed. The user can
// keep looking up definitions until he/she command to quit.
//
//-------- Copyright © ---------
//  @Author: Adnan Hashem Mohamed
//-------------------------------
//

#include"dictionary.h"
#include<iostream>
#include<fstream>

using std::cout; using std::endl; using std::cin;
using table3_adnan::table; using std::ifstream;

int main(int argc, const char*argv[])
{
	const char usage[] = "program_name file.txt";
	validate_commands(argc, 2, usage);
	table < word_def, TABLE_SIZE, hashkey>dictionary;
	// open the input file.
	ifstream fin(argv[1]);
	if (fin.fail())
	{
		std::cerr << "Failed opening the file.\n";
		exit(1);
	}
	build_dictionary(fin, dictionary);
	
	std::string ask_repeat = "Do you want to search more?";

	// prompt the user about program usage
	instruct();
	cout << "------------\n";
	std::string word;
	word_def result;
	bool found;
	do {
		cout << "Enter the word: ";
		std::getline(cin, word);
		format_word(word);
		dictionary.find(word, found, result);
		format_definition(result.def);
		if (found)
		{
			cout << endl;
			cout << word << ": " << result.def << endl;
			cout << "======================\n\n";
		}
		else
		{
			cout << "I am sorry, I don't know the definition of " + word << endl;
			cout << "I am willing to help you with another word !!" << endl << endl;
		}
	} while (inquire(ask_repeat));
}