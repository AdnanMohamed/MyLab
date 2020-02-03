// This is the implementation file for the class bag.
// See the interface for the class bag in bag.h
// @Author: Adnan
//
// INVARIANT for the bag ADT: (THE INVARIANT'S written by Main and Savitch)
//   1. The items in the bag are stored in a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The total number of items in the list is stored in the member variable
//      many_nodes.
//

#include<iostream>
#include"bag.h"
#include"linked_list.cpp"

using std::cout; using std::cin; using std::endl;
using namespace node_adnan;

namespace bag_adnan
{
	bag::bag()
	{
		many_nodes = 0;
		head_ptr = NULL;
	}

	bag::bag(const bag& source)
	{
		many_nodes = source.many_nodes;
		list_copy(source.head_ptr, head_ptr);
	}

	bag::~bag()
	{
		many_nodes = 0;
		list_clear(head_ptr);
	}

	bag::size_type bag::erase(const value_type& target)
	{
		size_type count = 0;
		Node_Ptr temp;
		while (head_ptr != NULL && head_ptr->data() == target)
		{
			list_head_remove(head_ptr);
			++count;
		}
		
		for (temp = head_ptr; temp != NULL; temp = temp->link())
		{
			while (temp->link()!= NULL && temp->link()->data() == target)
			{
				++count;
				list_remove(temp);
			}

		}
		many_nodes -= count;
		return count;
	}

	bool bag::erase_one(const value_type& target)
	{
		Node_Ptr temp = list_search(head_ptr, target);
		if (head_ptr->data() == target)
		{
			list_head_remove(head_ptr);
			many_nodes--;
			return true;
		}
		for (temp = head_ptr; temp->link() != NULL; temp = temp->link())
		{
			if (temp->link()->data() == target)
			{
				list_remove(temp);
				many_nodes--;
				return true;
			}
		}
		return false;
	}

	void bag::insert(const value_type& entry)
	{
		list_head_insert(head_ptr, entry);
		++many_nodes;
	}

	std::ostream& operator<<(std::ostream& outs, const bag& the_bag)
	{
		outs << the_bag.head_ptr;
		return outs;
	}

	void bag::operator +=(const bag& addend)
	{
		Node_Ptr cursor;
		for (cursor = addend.head_ptr; cursor != NULL; cursor = cursor->link())
		{
			list_head_insert(head_ptr, cursor->data());
			++many_nodes;
		}
	}

	void bag::operator =(const bag& source)
	{
		if (this == &source)  // self-assignment protection
			return;

		many_nodes = source.many_nodes;
		list_clear(head_ptr);
		list_copy(source.head_ptr, head_ptr);
	}

	bag::size_type bag::count(const value_type& target) const
	{
		size_type count = 0;
		const node* cursor = list_search(head_ptr, target);
		while (cursor != NULL)
		{
			++count;
			cursor = list_search(cursor->link(), target);
		}
		return count;
	}

	bag::value_type bag::grab() const
	{
		int position;
		position = (rand() % many_nodes) + 1;
		return list_locate(head_ptr, position)->data();
	}

	bag operator +(const bag& b1, const bag& b2)
	{
		bag result(b1);
		result += b2;
		return result;
	}
}
