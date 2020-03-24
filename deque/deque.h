// This is the interface for the template class deque<Item>
// deque is a double-ended queue. The class is within namespace (deque_adnan)
//
// -------- Copyright © ----------
// @Author: Adnan Hashem Mohamed
//--------------------------------
//
// TYPEDEFS for deque<Item>:
//	1- deque<Item>::value_type (The type of data stored)
//	2- deque<Item>::size_type (Type for any counting variable)
//
//	ITERATORS:
//	 Declare an iterator as follows:
//	 deque<Item>::iterator "identifier"
//	 deque<Item>::const_iterator "identifier"
//
// CONSTRUCTOR:
//	deque()
//	 Postcondition: creates an empty deque
//
//	ACCESS MEMBERS:
//	 Item front()const;
//	  Precondition: The deque is not empty. (empty() returns false)
//	  Postcondition: The return value is the first entered element in the dueue.
//
//	 Item back()const
//	  Precondition: The deque is not empty. (empty() returns false)
//	  Postcondition: The return value is the last element in the dueue.
//	 
//	 Item operator[](int index)const
//	  Precondition: index is 0<= index < size().
//	  Postcondition: returns the ith element in the deque.
//	  0th element == front(); 1st element == the element after front(); ... ; size() -1 element == back()
//
//	MODIFICATION MEMBER FUNCTIONS:
//	 Item& front()
//	  Precondition: the deque is NOT empty ( empty() returns false )
//	  Postcondtion: returns a reference for the first element in the deque.
//
//	 Item& back()
//	  Precondition: the deque is NOT empty ( empty() returns false )
//	  Postcondtion: returns a reference for the first element in the deque.
//
//	 Item& operator[](int index)
//	  Precondition: index is 0<= index < size()
//	  Postcondition: returns the ith element in the deque.
//	  0th element == front(); 1st element == the element after front(); ... ; size() -1 element == back()
//	
//	 void push_back(const Item& element);
//	  Postcondition: appends the elements to the end of the deque.
//
//	 void push_front(const Item& element)
//	  Postcondition: adds the element to the front of the deque.
//
//	 void pop_back()
//	  Precondition: the deque is NOT empty ( empty() returns false )
//	  Postcondition the last element in the deque is removed.
//
//	 void pop_front()
//	  Precondition: the deque is NOT empty ( empty() returns false )
//	  Precondition the front element is removed.
//
//	 void insert(iterator it, const Item& element)
//	  Precondition: 'it' is a valid deque iterator.
//	  Postcondition the new element will be inserted to where 'it' is pointing
//	  and the old element will be after the new inserted element.
//	  'it' will be pointing to the new inserted element.
//
//   void insert(iterator it, size_type n, const Item& element)
//	  Precondition: 'it' is a valid deque iterator. n positive integer.
//	  Postcondition: n elements will be inserted the place where 'it' was pointing.
//    'it' will be invalid.
//
//   void insert(iterator& it, const deque& the_deque)
//	  Precondition: 'it' is a valid deque iterator.
//	  Postcondition: the_deque will be inserted where 'it' was pointing.
//	  The elements starting from the one 'it' was pointing to will be after
//	  the_deque elements. The iterator 'it' will be invalid iterator.
//
// CAPACITY FUNCTIONS:
//	 size_type size()const
//	  Postcondition: The number of elements in the deque is returned
//
//	 bool empty()const
//	  Postcondition: returns true if no elements are in the deque, else false.
//
// NON-MEMBER FUNCTIONS:
//	 template<class Item>
//	 bool operator ==(const deque<Item>& d1, const deque<Item>& d2)
//	  Postcondition: returns true if d1[0] == d2[0] AND d1[1] == d2[1] ...
//	  ELSE returns false.
//
//	 template<class Item>
//	 bool operator ==(const deque<Item>& d1, const deque<Item>& d2)
//	  Postcondition: returns true if there exists and element d1[i] != d2[i]
//    ELSE returns false

#ifndef DEQUE_H
#define DEQUE_H

#include<cstdlib> // Provides size_t
#include"d_list.h" // Provides template_dlist_adnan

namespace deque_adnan {

	template<class Item>
	class deque {
	public:
		// TYPE-DEFS:
		typedef Item value_type;
		typedef std::size_t size_type;
		typedef template_dlist_adnan::node_iterator<Item> iterator;
		typedef template_dlist_adnan::const_node_iterator<Item> const_iterator;

		deque();
		deque(const deque& source);
		~deque() { template_dlist_adnan::list_clear(first); }

		// ACCESSORS
		Item front()const;
		Item back()const;
		Item operator[](int index)const;

		// CAPACITY
		size_type size()const { return count; }
		bool empty()const { return count == 0; }
		
		// MODIFICATION MEMBERS
		Item& front();
		Item& back();
		Item& operator[](int index);
		void push_back(const Item& element);
		void push_front(const Item& element);
		void pop_back();
		void pop_front();
		void insert(iterator& it, const Item& element);
		void insert(iterator& it, size_type n, const Item& element);
		void insert(iterator& it, const deque& the_deque);

		// ITERATORS:
		iterator begin() { return iterator(first); }
		const_iterator begin()const { return const_iterator(first); }
		iterator end() { return iterator(); }
		const_iterator end()const { return const_iterator(); }

		// ASSIGNMENT:
		deque& operator =(const deque& source);

		// EQUALITY:
		template<class Item>
		friend bool operator ==(const deque<Item>& d1, const deque<Item>& d2);
		template<class Item>
		friend bool operator !=(const deque<Item>& d1, const deque<Item>& d2);

	private:
		template_dlist_adnan::node<Item>* first;
		template_dlist_adnan::node<Item>* last;
		size_type count;
	};

} // end of namespace

#include"deque.template"

#endif // !DEQUE_H

