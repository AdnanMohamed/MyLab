#include<iostream>
#include<cassert>
#include<fstream>
#include"bst_tree.h"
#include"Linked List/template_node.h"

using namespace bst_adnan;
using std::cout; using std::endl;


void complete_btree_l(bst<int>& bs_tree)
{
	for (size_t i = 0; i < 10; i++)
	{
		bs_tree.insert(rand() % 10);
	}
	
}

void complete_btree_r(bst<int>& bs_tree)
{
	for (size_t i = 0; i < 10; i++)
	{
		bs_tree.insert(rand() % 30 + 10);
	}

}

int main() {

	//srand(time(nullptr));

	bst<int>bs_tree, bs_tree2, top;
	top.insert(10);
	complete_btree_l(bs_tree);
	complete_btree_r(bs_tree2);
	join(top, bs_tree, bs_tree2);
	//template_node_adnan::node<int>* head_ptr = NULL;

	top.print_tree();
	cout << "------------\n";
	/*auto head_ptr = to_linked_list(bs_tree);
	auto x = head_ptr;
	while (x != NULL)
	{
		cout << x->data() << " ";
		x = x->link();
	}*/
}



