// The implementation file for the class gift_list and a simple class Name
// See interface file in gift_list.h
//
// @Author: Adnan Hashem Mohamed
//
// CLASS INVARIANT (gift_list):
//	1- list_ is the list of person associated with his/her list of gifts


#include"gift_list.h"
#include<string>


namespace gift_list_adnan {


	void Name::format_name(std::string& name)
	{
		if (name.length() == 0)
			return;
		// Make all letters lower except the first.
		name[0] = toupper(name[0]);
		
		for (int i = 1; i < name.length(); ++i)
		{
			name[i] = tolower(name[i]);
		}
	}

	Name::Name(std::string first, std::string last, std::string middle)
	{
		format_name(first);
		format_name(middle);
		format_name(last);
		first_ = first;
		last_ = last;
		middle_ = middle;
	}

	void Name::set_first(std::string first)
	{
		format_name(first);
		first_ = first;
	}
	
	void Name::set_middle(std::string middle)
	{
		format_name(middle);
		middle_ = middle;
	}
	
	void Name::set_last(std::string last)
	{
		format_name(last);
		last_ = last;
	}

	std::ostream& operator<<(std::ostream& outs, const Name& n)
	{
		// In case middle name given.
		if (n.middle_ != "")
		{
			outs << n.first_ << " " << n.middle_[0] << ". " << n.last_;
		}
		else
		{
			outs << n.first_ <<" "<< n.last_;
		}
		
		return outs;
	}

	bool operator == (const Name& n1, const Name& n2)
	{
		return n1.first_ == n2.first_ && n1.middle_ == n2.middle_
			&& n1.last_ == n2.last_;
	}
	
	bool operator != (const Name& n1, const Name& n2)
	{
		return !(n1 == n2);
	}

	// FOR CLASS gift_list

	gift_list::gift_list()
	{
		gifts_bag person_gifts;
		list_ = person_gifts;
	}

	gift_list::gift_list(const Name& person, const gifts& the_gifts)
	{
		gifts_bag person_gifts(person, the_gifts);
		list_ = person_gifts;
	}

	void gift_list::add(const Name& person, const gifts& the_gifts)
	{
		list_.insert(person, the_gifts);
	}

	bool gift_list::in_list(const Name& person)const
	{
		return list_.is_item(person);
	}

	void gift_list::add_gift(const Name& person, const gift& the_gift)
	{
		assert(in_list(person));

		// If the_gift is already in the list don't add it
		for (auto a_gift : list_[person])
			if (a_gift.first == the_gift.first)
				return;
		list_[person].push_back(the_gift);
	}

	gift_list::gifts gift_list::get_gifts(const Name& person)const
	{
		assert(in_list(person));
		return list_[person];
	}

	double gift_list::gifts_cost(const Name& person)const
	{
		assert(in_list(person));
		double cost = 0;
		for (auto i : list_[person])
		{
			cost += i.second;
		}
		return cost;
	}
	
	double gift_list::gifts_cost()const
	{
		double cost = 0;
		// iterate over every person in the list + calculating his/her gift costs
		// and adding it to the total cost.
		for (auto person : list_)
		{
			cost += gifts_cost(person.first);
		}
		return cost;
	}

	void gift_list::remove(const Name& person)
	{
		assert(in_list(person));
		list_.remove(person);
	}

	bool gift_list::remove_gift(const Name& person, std::string gift_name)
	{
		assert(in_list(person));

		// go over the person's gifts and when the target gift is found, remove it from the vector of gifts
		for (auto it = list_[person].begin(); it != list_[person].end(); ++it)
		{
			if (it->first == gift_name)
			{
				list_[person].erase(it);
				return true;
			}
		}
		return false;
	}

	void print_list(std::ostream& outs, const gift_list& the_list)
	{
		gift_list::gifts_bag my_list = the_list.get_list();
		for (auto it = my_list.begin(); it != my_list.end(); ++it)
		{
			outs << "-----------------------\n";
			outs << "Name: ";
			outs << (*it).first << "\n\n";
			outs << "Gifts: ";
			for (auto i = 0; i < (*it).second.size(); ++i)
			{
				outs << (*it).second[i].first << "| ";
			}
			outs<<std::endl;
			outs << "-----------------------\n";
		}
	}

} // end of namespace