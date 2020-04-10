// This is the header file for the functions which will be used in the guessing game.
// Functions are within namespace: (countries_adnan)
//	--------Copyright ©-----------
//	@Author: Adnan Hashem Mohamed
//	co-authors: Main and Walter Savitch
//	------------------------------
//

#ifndef COUNTRY_GUESSING_H
#define COUNTRY_GUESSING_H

#include"Binary Tree/binary_tree.h"
#include<string>
#include<fstream>

namespace countries_adnan {

	// PROTOTYPES for functions used by this game program:
	void ask_and_move(binary_tree_adnan::binary_tree_node<std::string>*& current_ptr);
	// Precondition: current_ptr points to a non-leaf node in a binary tree.
	// Postcondition: The question at the current node has been asked. The current
	// pointer has been shifted left (if the user answered yes) or right
	// (for a no answer).


	void instruct();
	// Postcondition: Instructions for playing the game have been printed to the
	// screen.

	void learn(binary_tree_adnan::binary_tree_node<std::string>*& leaf_ptr);
	// Precondition: leaf_ptr is a pointer to a leaf in a the tree. The leaf
	// contains a wrong guess that was just made.
	// Postcondition: Information has been elicited from the user, and the tree has
	// been improved.

	void play(binary_tree_adnan::binary_tree_node<std::string>* current_ptr);
	// Precondition: current_ptr points to the root of a binary tree with
	// at least two leaves.
	// Postcondition: One round of the animal game has been played, and maybe the
	// tree has been improved.

	void eat_line(std::istream& in);
	// Precondition: 'in' is a valid input stream.
	// Postcondition: reads input until endline.

	bool inquire(std::string query);
	// Precondition: query is a [yes/no] question.
	// Postcondition: Returns true if the user answers yes, otherwise no.

}


#endif // !COUNTRY_GUESSING_H


