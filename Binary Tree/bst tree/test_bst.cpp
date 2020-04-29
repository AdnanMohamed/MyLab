#include<iostream>
#include<cassert>
#include<fstream>
#include"bst_tree.h"
#include"../bt_class.h"
#include"Linked List/template_node.h"

using namespace bst_adnan;
using namespace template_node_adnan;
using std::cout; using std::endl;


void complete_btree_l(bst<int>& bs_tree)
{
	for (size_t i = 0; i < 4; i++)
	{
		bs_tree.insert(rand() % 10);
	}
	
}

void complete_btree_r(bst<int>& bs_tree)
{
	for (size_t i = 0; i < 4; i++)
	{
		bs_tree.insert(rand() % 30 + 10);
	}

}

int main() {

	//srand(time(nullptr));

	

	//cout<<ceil(list_length(head_ptr) / 2);
}



