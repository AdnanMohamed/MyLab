// This is the header file for functions that will be usefull for
// other future programs. This file will be updated continually 
// whenever a reusable code aroses.
// Code is within namespace ( helper_adnan )
//
// @Author: Adnan H. Mohamed
//
// DOCUMENTATION:
//
//  template<class Item>
//	int binary_search(Item arr[], int size, const Item& target)
//	 Precondition: Item could be any type that has the <, != and == operators
//	 arr[] is an array of elements of type Item. 'size' is the size of the array
//	 'target' is the element to be searched in the array.
//	 The elements are in ASCENDENT ORDER (e0 < e1 < e2 <...<en)
//	 Postcondition: If the element is found, the index of the element which equals 'target'
//	 will be returned. else -1 will be the return value.
//
#ifndef HELPER_CODE
#define HELPER_CODE

#include<cmath>
namespace helper_adnan {

	template<class Item>
	int binary_search(Item arr[], int size, const Item& target);


} // end of namespace

#include"helper.template"
#endif // !HELPER_CODE

