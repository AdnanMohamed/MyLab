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
//   bag<Item>::iterator and bag<Item>::const_iterator
//     Forward iterators for a bag or a const bag.
//
// STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
//   iterator begin( )
//   const_iterator begin( ) const
//   iterator end( )
//   const iterator end( ) const
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
//	void remove(int key)
//	 Precondition: is_item() returns true, i.e. there is an element with the specified key in the keyed_bag
//	 Postcondition: The element is removed from the keyed bag.
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
//
// OPERATORS:
//  std::string operator[](int key)const
//	 Precondition: key is valid, is_item(key) returs true
//	 Postcondition: returns a copy of the value corresponding to the key.
//
//	std::string& operator[](int key)
//	 Precondition: key is valid, is_item(key) returs true
//	 Postcondition: returns value itself (by ref.) corresponding to the key. 
//
// NON-MEMBERS
//	keyed_bag operator+(const keyed_bag& b1, const keyed_bag& b2)
//	 Postcondition: Returns a keyed_bag with elements of both b1 and b2 such that if an element
//	 in b1 and b2 has the same key, the element in b1 only occurs in the returned bag.
//
//  bool operator==(const keyed_bag&)
//	 Postcondition: Returns true if, for all (key, value) pair in lhs there exists a pair in
//	 the rhs keyed_bag such that has (key, value). Else returns false.
//
//  bool operator!=(const keyed_bag&)
//	 Postcondition: Returns True if, there exists an element in the lhs keyed bag with (key, value) pair
//	 such that no corresponding element in the rhs keyed_bag which has the same (key, value) pair.
//
//	keyed_bag operator-(const keyed_bag& b1, const keyed_bag& b2);
//	 Postcondition: Returns a keyed bag which includes the unique elements of b1 which does not occur in b2.
//	 (i.e. an element with key = k in b1 and b2 will not be in the returned bag)
//
//  void print_bag(const keyed_bag&)
//	 Postcondition: the elements will be printed one at each line like (key: 1, value: "String")

#ifndef KEYED_BAG_H
#define KEYED_BAG_H

#include"linked_list.h"
#include<utility>
#include<string>

namespace keyed_bag_adnan
{
	class keyed_bag
	{
	public: 
		// TYPE_DEFS
		typedef size_t size_type;
		typedef node::value_type value_type;
		typedef node_iterator iterator;
		typedef const_node_iterator const_iterator;

		// CONSTRUCTORS
		keyed_bag();
		keyed_bag(int key, std::string value);
		
		// BIG THREE
		keyed_bag(const keyed_bag& source);
		~keyed_bag();
		keyed_bag operator=(const keyed_bag& rhs);

		// MODIFICATION MEMBER FUNCTIONS
		void insert(int key, std::string value);
		void remove(int key);

		// NON-MODIFICATION MEMBERS
		size_type size() const { return many_elements_; }
		size_type count(std::string value) const;
		std::string value(int) const;
		bool is_item(int) const;

		// OPERATORS:
		std::string operator[](int key)const;
		std::string& operator[](int key);

		// FUNCTIONS TO PROVIDE ITERATORS
		iterator begin()
		{
			return iterator(head_ptr_);
		}
		const_iterator begin() const
		{
			return const_iterator(head_ptr_);
		}
		iterator end()
		{
			return iterator();
		} // Uses default constructor 
		const_iterator end() const
		{
			return const_iterator();
		} // Uses default constructor 

		// NON-MEMBERS
		friend keyed_bag operator+(const keyed_bag& b1, const keyed_bag& b2);
		friend keyed_bag operator-(const keyed_bag& b1, const keyed_bag& b2);
		friend bool operator==(const keyed_bag& b1, const keyed_bag& b2);
		friend bool operator!=(const keyed_bag& b1, const keyed_bag& b2);
		
	private:
		node* head_ptr_;
		size_type many_elements_;
	};

	// Usefull Printing function.
	void print_bag(const keyed_bag&);
}

#endif
