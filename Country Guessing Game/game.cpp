// This is the implemenation file for the function used in the main program of the guessing game
// See header file in: game.h
// namespace: countries_adnan
//
//	--------Copyright ©-----------
//	@Author: Adnan Hashem Mohamed
//
//	------------------------------
//

#include"game.h"
#include"Binary Tree/binary_tree.h"
#include<string>
#include<iostream>
#include<fstream>

using std::cout; using std::endl;
using binary_tree_adnan::binary_tree_node;

namespace countries_adnan {

	void instruct()
	{
		cout << "*** Welcome to my game!!  ****\n";
		cout << "You will answer [yes/no] questions and I'll guess the country in your mind.\n";
		cout << "You will teach me as well!!\n\n";
	}

	void ask_and_move(binary_tree_adnan::binary_tree_node<std::string>*& current_ptr)
	{
		if (inquire(current_ptr->data()))
			current_ptr = current_ptr->left();
		else
			current_ptr = current_ptr->right();
		
	}

	void learn(binary_tree_adnan::binary_tree_node<std::string>*& leaf_ptr)
	{
		std::string guess_country;   // The country that was just guessed
		std::string correct_country;  // The country that the user was thinking of
		std::string new_question;    // A question to distinguish the two countries

		// Set strings for the guessed country, correct country and a new question.
		guess_country = leaf_ptr->data();
		cout << endl;
		cout << "I give up. Which country is it? " << endl;
		getline(std::cin, correct_country);
		cout << endl;
		cout << "Please type a yes/no question that will distinguish "
		 << correct_country << " from " << guess_country << "." << endl;
		cout << "Your question: " << endl;
		getline(std::cin, new_question);
		cout << endl;
		cout << "As for " + correct_country +","<< endl;
		
		// set the new question to be in place of the previous guessed country.
		leaf_ptr->data() = new_question;
		
		// set the new correct answers based on the user reply.
		if (inquire(new_question))
		{
			leaf_ptr->set_left(new binary_tree_node<std::string>(correct_country));
			leaf_ptr->set_right(new binary_tree_node<std::string>(guess_country));
		}
		else
		{
			leaf_ptr->set_right(new binary_tree_node<std::string>(correct_country));
			leaf_ptr->set_left(new binary_tree_node<std::string>(guess_country));
		}
		
	}

	void play(binary_tree_adnan::binary_tree_node<std::string>* current_ptr)
	{
		while (!current_ptr->is_leaf())
		{
			ask_and_move(current_ptr);
		}
		cout << "My guess is " + current_ptr->data() + ". ";
		if (inquire("Am I right?"))
			cout << "\nThis is magic!\n\n";
		else
			learn(current_ptr);
	}

	void eat_line(std::istream& in)
	{
		char next;
		do {
			in.get(next);
		} while (in && next != '\n');
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


}