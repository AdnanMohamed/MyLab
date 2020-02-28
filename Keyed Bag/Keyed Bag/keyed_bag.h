// Interface for the class: keyed_bag. (within namespace keyed_bag_adnan)
// Elements of keyed_bag stored using pair from <utility>
// 
// @Author: Adnan H. Mohamed
//
// TYPEDEFS FOR CLASS keyed_bag
//   keyed_bag::size_type
//     This is the data type of any variable that keeps track of how many items
//     are in a keyed_bag
//
// CONSTRUCTORS:
//	keyed_bag()
//	 Postcondition: an empty bag is created, the bag's size = 0
//
//  keyed_bag(int key, std::string value);
//	 Postcondition: A bag is created with one element of key, value pair
//
// MODIFICATION MEMBER FUNCTIONS:
//	void insert(int key, std::string value)
//	 Postcondition: a new element is added to the keyed_bag with the given pair: key, value
//	 If there is already an element with the specified key, the new value will override the old value
//
// NON-MODIFICATION MEMBERS:
//	size_type size() const
//	 Postcondition: Returns the number of elements in the keyed_bag
//
//	size_type count(std::string value) const
//	 Postcondition: Returns the number of times the given value occures in the keyed_bag
//
//	std::string value(int) const
//	 Precondition: is_item(int) returns true.
//	 Postcondition: returns the value corresponding to the passed key.
//
//  bool is_item(int) const;
//	 Postcondition: Returns true if and only if there exists an element with the specified key.

#ifndef KEYED_BAG_H
#define KEYED_BAG_H

#include"template_node.h"
#include<utility>

namespace keyed_bag_adnan
{
	class keyed_bag
	{
	public: 
		// TYPE_DEFS
		typedef size_t size_type;
		// CONSTRUCTORS
		keyed_bag();
		keyed_bag(int key, std::string value);
		
		// BIG THREE
		keyed_bag(const keyed_bag& source);
		~keyed_bag();
		keyed_bag operator=(const keyed_bag& rhs);

		// MODIFICATION MEMBER FUNCTIONS
		void insert(int key, std::string value);

		// NON-MODIFICATION MEMBERS
		size_type size() const { return many_elements_; }
		size_type count(std::string value) const;
		std::string value(int) const;
		bool is_item(int) const;
		
	private:
		node<std::pair<int, std::string>>* head_ptr_;
		size_type many_elements_;
	};
}

#endif
