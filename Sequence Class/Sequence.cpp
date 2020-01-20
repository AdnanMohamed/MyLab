// This is the implementation file for the sequence class.
// You can see the class interface in the file Sequence.h
//
// INVARIANT OF THE CLASS:
//   1- If there is no items in the sequence, then any element in data_[] is ignored
//	 2- If there is items in the sequence, used_ will hold the number of items
//   3- current_index_ will be equal to the current element to be printed or deleted.
//		If there is no elements, current_index_ = used_
//
//	Written by: Adnan Mohamed
//	Date: 1/19/2020


#include<iostream>
#include"Sequence.h"

using std::cout; using std::cin; using std::endl;
using namespace sequence_adnan;

namespace sequence_adnan {

	const sequence::size_type sequence::CAPACITY;

	void sequence::start()
	{
		if (used_ > 0)
		{
			current_index_ = 0;
		}
	}

	bool sequence::is_item() const
	{
		if (used_!= 0 && current_index_ != used_)
			return true;
		else
			return false;
	}

	void sequence::advance()
	{
		if (is_item())
		{
			++current_index_;
		}
	}

	sequence::size_type sequence::size() const
	{
		return used_;
	}

	void sequence::insert(const value_type& entry)
	{
		if (size() < CAPACITY)
		{
			if (!is_item())
				current_index_ = 0;
			size_type temp_used = used_;
			while (temp_used > current_index_)
			{
				data_[temp_used] = data_[temp_used - 1];
				--temp_used;
			}
			data_[current_index_] = entry;
			++used_;
		}

	}

	sequence::value_type sequence::current() const
	{
		if (is_item())
		{
			return data_[current_index_];
		}
	}

	void sequence::attach(const value_type& entry)
	{
		if (size() < CAPACITY && size() != 0)
		{
			if (used_ - 1 == current_index_ || !is_item())
			{
				data_[used_] = entry;
				used_++;
				++current_index_;
			}
			else
			{
				size_type temp_used = used_;
				while (temp_used > current_index_ + 1)
				{
					data_[temp_used] = data_[temp_used - 1];
					--temp_used;
				}
				data_[++current_index_] = entry;
				++used_;
			}
			
		}

		if (size() == 0)
		{
			data_[0] = entry;
			++used_;
			current_index_ = 0;
		}
	}


	void sequence::remove_current() 
	{
		if (is_item())
		{
			for (size_type i = current_index_; i != used_; ++i)
			{
				data_[i] = data_[i + 1];
			}
			--used_;
		}
	}
}
