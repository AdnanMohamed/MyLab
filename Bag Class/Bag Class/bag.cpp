// This is the implementation file for the class bag.
// See the interface for the class bag in bag.h
// @Author: Adnan
//
// INVARIANT for the bag ADT: (THE INVARIANT'S written by Main and Savitch)
//   1. The items in the bag are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The total number of items in the list is stored in the member variable
//      many_nodes.
//
#include<iostream>
#include"bag.h"
#include"linked_list.h"

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
		list_clear(head_ptr);
	}
}
