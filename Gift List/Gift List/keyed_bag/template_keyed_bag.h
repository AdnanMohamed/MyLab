// Interface for the template class: keyed_bag. (within namespace template_keyed_bag_adnan)
// Elements of keyed_bag stored using pair from <utility>
// 
// @Author: Adnan H. Mohamed
//
// CLASS USAGE:
//	1) key_type and v_type in keyed_bag<key_type, v_type> could be any built-in type or other types
//	like int, char, string ... which have ==, copy_constructor, and assignment operator.
//	2) Each element will have a unique key ( two elements will not have the same key).
//
// TYPEDEFS FOR CLASS keyed_bag
//   keyed_bag::size_type
//     This is the data type of any variable that keeps track of how many items
//     are in a keyed_bag
//
//   keyed_bag<key_type, v_type>::iterator and keyed_bag<key_type, v_type>::const_iterator
//     Forward iterators for a bag or a const bag.
//
// STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
//   iterator begin( )
//   const_iterator begin( ) const
//   iterator end( )
//   const iterator end( ) const
//
// CONSTRUCTORS for the class keyed_bag<class key_type, class v_type>:
//	keyed_bag()
//	 Postcondition: an empty bag is created, the bag's size = 0
//
//  keyed_bag(const key_type& key, const v_type& value)
//	 Postcondition: A bag is created with one element of key, value pair
//
// MODIFICATION MEMBER FUNCTIONS for keyed_bag<class key_type, class v_type>:
//	void insert(const key_type& key, const v_type& value)
//	 Postcondition: a new element is added to the keyed_bag with the given pair: key, value
//	 If there is already an element with the specified key, the new value will override the old value
//
//	void remove(const key_type& key)
//	 Precondition: is_item() returns true, i.e. there is an element with the specified key in the keyed_bag
//	 Postcondition: The element is removed from the keyed bag.
//
// NON-MODIFICATION MEMBERS for keyed_bag<class key_type, class v_type>:
//	size_type size() const
//	 Postcondition: Returns the number of elements in the keyed_bag
//
//	size_type count(const v_type& value) const
//	 Postcondition: Returns the number of times the given value occures in the keyed_bag
//
//	v_type value(const key_type&) const
//	 Precondition: is_item(int) returns true.
//	 Postcondition: returns the value corresponding to the passed key.
//
//  bool is_item(const key_type&) const;
//	 Postcondition: Returns true if and only if there exists an element with the specified key.
//
// OPERATORS for keyed_bag<class key_type, class v_type>:
//  v_type operator[](const key_type& key)const
//	 Precondition: key is valid, is_item(key) returs true
//	 Postcondition: returns a copy of the value corresponding to the key.
//
//	v_type& operator[](const key_type& key)
//	 Precondition: key is valid, is_item(key) returs true
//	 Postcondition: returns value itself (by ref.) corresponding to the key. 
//
// NON-MEMBERS:
//	template<class key_type, class v_type>
//	keyed_bag<key_type, v_type> operator+(const keyed_bag<key_type, v_type>& b1, const keyed_bag<key_type, v_type>& b2)
//	 Postcondition: Returns a keyed_bag with elements of both b1 and b2 such that if an element
//	 in b1 and b2 has the same key, the element in b1 only occurs in the returned bag.
//
//	template<class key_type, class v_type>
//	bool operator ==(const keyed_bag<key_type, v_type>& b1, const keyed_bag<key_type, v_type>& b2)
//	 Postcondition: Returns true if, for all (key, value) pair in lhs there exists a pair in
//	 the rhs keyed_bag such that has (key, value). Else returns false.
//
//	template<class key_type, class v_type>
//	bool operator !=(const keyed_bag<key_type, v_type>& b1, const keyed_bag<key_type, v_type>& b2)
//	 Postcondition: Returns True if, there exists an element in the lhs keyed bag with (key, value) pair
//	 such that no corresponding element in the rhs keyed_bag which has the same (key, value) pair.
//
//	template<class key_type, class v_type>
//	keyed_bag<key_type, v_type> operator-(const keyed_bag<key_type, v_type>& b1, const keyed_bag<key_type, v_type>& b2)
//	 Postcondition: Returns a keyed bag which includes the unique elements of b1 which does not occur in b2.
//	 (i.e. an element with key = k in b1 and b2 will not be in the returned bag)
//
//	template<class key_type, class v_type>
//	void print_bag(const keyed_bag<key_type, v_type>&)
//	 Precondition: key_type and v_type has << operator.
//	 Postcondition: the elements will be printed one at each line like (key: 1, value: "String")

#ifndef TEMPLATE_KEYED_BAG_H
#define TEMPLATE_KEYED_BAG_H

#include"template_node.h"
#include<utility>
#include<string>

namespace template_keyed_bag_adnan
{
	template<class key_type, class v_type>
	class keyed_bag
	{
	public:
		// TYPE_DEFS
		typedef size_t size_type;
		typedef node_iterator<std::pair<key_type, v_type>> iterator;
		typedef const_node_iterator<std::pair<key_type, v_type>> const_iterator;

		// CONSTRUCTORS
		keyed_bag();
		keyed_bag(const key_type& key, const v_type& value);

		// BIG THREE
		keyed_bag(const keyed_bag& source);
		~keyed_bag();
		keyed_bag operator=(const keyed_bag& rhs);

		// MODIFICATION MEMBER FUNCTIONS
		void insert(const key_type& key, const v_type& value);
		void remove(const key_type& key);

		// NON-MODIFICATION MEMBERS
		size_type size() const { return many_elements_; }
		size_type count(const v_type& value) const;
		v_type value(const key_type&) const;
		bool is_item(const key_type&) const;

		// OPERATORS:
		v_type operator[](const key_type& key)const;
		v_type& operator[](const key_type& key);

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
		
	private:
		node<std::pair<key_type, v_type>>* head_ptr_;
		size_type many_elements_;
	};

	// Usefull Printing function.
	template<class key_type, class v_type>
	void print_bag(const keyed_bag<key_type, v_type>&);

	// NON-MEMBERS
	template<class key_type, class v_type>
	keyed_bag<key_type, v_type> operator+(const keyed_bag<key_type, v_type>& b1, const keyed_bag<key_type, v_type>& b2);
	
	template<class key_type, class v_type>
	keyed_bag<key_type, v_type> operator-(const keyed_bag<key_type, v_type>& b1, const keyed_bag<key_type, v_type>& b2);

	template<class key_type, class v_type>
	bool operator ==(const keyed_bag<key_type, v_type>& b1, const keyed_bag<key_type, v_type>& b2);
	
	template<class key_type, class v_type>
	bool operator !=(const keyed_bag<key_type, v_type>& b1, const keyed_bag<key_type, v_type>& b2);
}

// The implementation of a template class must be included in its header file:
#include"keyed_bag.template"

#endif

