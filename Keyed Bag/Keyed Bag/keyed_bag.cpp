// The implementation file for keyed_bag class.
// The class interface is in keyed_bag.h
//
// @Author: Adnan Hashem Mohamed
//
// CLASS INVARIANT:
//	1- head_ptr_ is a pointer to a linked list of pairs
//	2- many_elements_ holds the number of elements in the bag

#include"keyed_bag.h"
#include<cassert> // Provides assert
#include<utility> // Provides pair
#include<string>  // Provides string
#include<iostream>

namespace keyed_bag_adnan {

	keyed_bag::keyed_bag()
	{
		many_elements_ = 0;
		head_ptr_ = NULL;
	}
	
	keyed_bag::keyed_bag(int key, std::string value)
	{
		many_elements_ = 1;
		list_head_insert(head_ptr_, std::pair<int, std::string>(key, value));
	}

	keyed_bag::keyed_bag(const keyed_bag& source)
	{
		many_elements_ = source.many_elements_;
		head_ptr_ = NULL;
		list_copy(source.head_ptr_, head_ptr_);
	}

	keyed_bag::~keyed_bag()
	{
		many_elements_ = 0;
		list_clear(head_ptr_);
	}
	
	keyed_bag keyed_bag::operator=(const keyed_bag& rhs)
	{
		if (this != &rhs)
		{
			many_elements_ = rhs.many_elements_;
			list_clear(head_ptr_);
			list_copy(rhs.head_ptr_, head_ptr_);
		}
		return *this;
	}

	bool keyed_bag::is_item(int key) const
	{
		for (auto cursor = head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (cursor->data().first == key)
				return true;
		}
		return false;
	}

	void keyed_bag::insert(int key, std::string value)
	{
		// If there is no pair with the given key, create a new pair
		if (!is_item(key))
		{
			list_head_insert(head_ptr_, std::pair<int, std::string>(key, value));
			many_elements_++;
			return;
		}

		// In the case which there is a pair which has the specified key, override the 
		// old value with the new value.
		for (auto cursor = head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (cursor->data().first == key)
				cursor->set_data(std::pair<int, std::string>(key, value));
		}
	}
	
	
	void keyed_bag::remove(int key)
	{
		assert(is_item(key));
		for (auto cursor = head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (cursor->data().first == key)
			{
				cursor->set_data(head_ptr_->data());
				list_head_remove(head_ptr_);
				many_elements_--;
				return;
			}
			
		}
	}

	keyed_bag::size_type keyed_bag::count(std::string value) const
	{
		size_type count = 0;

		for (auto cursor = head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (cursor->data().second == value)
				count++;
		}
		return count;
	}
	
	std::string keyed_bag::value(int key) const
	{
		assert(is_item(key));
		for (auto cursor = head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (cursor->data().first == key)
				return cursor->data().second;
		}
	}

	std::string keyed_bag::operator[](int key)const
	{
		assert(is_item(key));
		for (auto cursor = head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (cursor->data().first == key)
				return cursor->data().second;
		}
	}

	std::string& keyed_bag::operator[](int key)
	{
		assert(is_item(key));
		for (auto cursor = head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (cursor->data().first == key)
				return cursor->data().second;
		}
	}

	bool operator==(const keyed_bag& b1, const keyed_bag& b2)
	{
		// if different size then not equal bags
		if (b1.size() != b2.size())
			return false;
		for (auto cursor = b1.head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (!b2.is_item(cursor->data().first) || b1[cursor->data().first] != b2[cursor->data().first])
				return false;
		}

		return true;
	}

	bool operator!=(const keyed_bag& b1, const keyed_bag& b2)
	{
		return !(b1 == b2);
	}

	keyed_bag operator+(const keyed_bag& b1, const keyed_bag& b2)
	{
		keyed_bag b3(b1);
		for (auto cursor = b2.head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (!b3.is_item(cursor->data().first))
				b3.insert(cursor->data().first, cursor->data().second);
		}
		return b3;
	}

	keyed_bag operator-(const keyed_bag& b1, const keyed_bag& b2)
	{
		keyed_bag b3(b1);
		for (auto cursor = b2.head_ptr_; cursor != NULL; cursor = cursor->link())
		{
			if (b3.is_item(cursor->data().first))
				b3.remove(cursor->data().first);
		}
		return b3;
	}

	void print_bag(const keyed_bag& k_bag)
	{
		for (auto it = k_bag.begin(); it != k_bag.end(); ++it)
		{
			std::cout << "(key: " << (*it).first << ", value: " << (*it).second << ")" << std::endl;
		}
	}
}