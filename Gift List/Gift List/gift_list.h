// This is the header file for the class gift_list and a simple class Name
// The classes are within namespace (gift_list_adnan)
// 
// @Author: Adnan Mohamed
//
// CLASS Name:
//	CONSTRUCTOR:
//	 Name(std::string first = "", std::string last = "", std::string middle = "")
//	  Postcondition: if all parameters provided, the name will have first, last, and middle name.
//	  Note that the last name parameter comes before the middle name.
//	  DEFAULT ARGUMENTS: the default will be an empty string
//
// NON-MEMBER FUNCTIONS FOR CLASS Name:
//  std::ostream& operator<<(std::ostream&, const Name&);
//	  Postcondition: outputs the name to where the ostream is connected
//
//	bool operator == (const Name&, const Name&);
//	  Postcondition: returns true if every name (first, middle, and last) of both names are equal
//	  else returns false.
//
//	bool operator != (const Name&, const Name&);
//	  Postcondition: returns true incase Name == Name2 returns false, else returns false.
//
//-----------------------------
// CLASS gift_list:
//	TYPEDEFS:
//  typedef std::pair<std::string, double> gift (the string is for the name of the gift, and double for price $)
//  typedef std::vector<gift> gifts  (type for list of gifts)
//  typedef template_keyed_bag_adnan::keyed_bag<Name, gifts> gifts_bag (type for list of people and their list of gifts)
//	typedef size_t size_type (type for any variable keeping track of size)
//
// CONSTRUCTORS
//  gift_list()
//	 Postcondition: an empty list is created (no people, no gifts)
//
//  gift_list(const Name&, const gifts&)
//	 Postcondition: a list with one person and his gifts is created
//
// MODIFICATION MEMBER FUNCTIONS
//	void add(const Name&, const gifts&);
//	 Precondition: Name x is in the list. ( is_list(Name) returns true )
//	 Postcondition: The list has the given Name and the his/her list of gifts
//
//	void add_gift(const Name&, const gift&)
//	 Precondition: Name x is in the list. ( is_list(Name) returns true )
//	 Postcondition: The gift is added to the gift list of the person given his/her name
//
//	void remove(const Name&)
//	 Precondition: Name x is in the list. ( is_list(Name) returns true )
//	 Postcondition: The given name no more exists in the list.
//	
//	bool remove_gift(const Name&, string)
//	 Precondition: Name x is in the list. ( is_list(Name) returns true )
//	 Postcondition: returns true if the gift is removed from the person's gifts.
//	 returns false if the gift is not found in the person's gifts.
//
// NON-MODIFICATION MEMBER FUNCTIONS:
//  bool in_list(const Name&)const
//	 Postcondition: Returns true if there is a person with the specified name in the list, else false
//
//	gifts get_gifts(const Name&)const;
//	 Precondition: Name x is in the list. ( is_list(Name) returns true )
//	 Postcondition: the list of gifts for the given person will be returned
//
//	double gifts_cost(const Name&)const;
//	 Precondition: Name x is in the list. ( is_list(Name) returns true )
//	 Postcondition: returns the costs of gifts for the specified person
//
//  double gifts_cost()const
//	 Postcondtion: returns the total cost of gifts
//
//  gifts_bag get_list()const
//	 Postcondition: returns the entire list of people associated with their gifts.
//
//  size_type size()const
//	 Postcondition: returns the number of people this gift_list contains
//
// NON-MEMBER FUNCTIONS:
//	void print_list(std::ostream& outs, const gift_list&)
//	 Postcondition: prints the gift_list by displaying each person and his/her gifts to where outs is connected.
//

#ifndef GIFT_LIST_H
#define GIFT_LIST_H
#include<string>
#include<utility>
#include<vector>
#include"keyed_bag/template_keyed_bag.h"

namespace gift_list_adnan
{
	class Name {
	public:
		Name(std::string first = "", std::string last = "", std::string middle = "");
		
		// GETTERS
		std::string first()const { return first_; }
		std::string middle()const { return middle_; }
		std::string last()const { return last_; }
		// SETTERS
		void set_first(std::string);
		void set_middle(std::string);
		void set_last(std::string);

		// OUTPUT OPERATOR
		friend std::ostream& operator<<(std::ostream&, const Name&);
		// EQUALITY
		friend bool operator == (const Name&, const Name&);
		friend bool operator != (const Name&, const Name&);

	private:
		std::string first_;
		std::string middle_;
		std::string last_;
		void format_name(std::string&);
	};
	

	class gift_list
	{
	public:
		typedef std::pair<std::string, double > gift;
		typedef std::vector<gift> gifts;
		typedef template_keyed_bag_adnan::keyed_bag<Name, gifts> gifts_bag;
		typedef size_t size_type;
		// CONSTRUCTORS
		gift_list();
		gift_list(const Name&, const gifts&);

		// MODIFICATION MEMBER FUNCTIONS
		void add(const Name&, const gifts&);
		void add_gift(const Name&, const gift&);
		void remove(const Name&);
		bool remove_gift(const Name&, std::string);

		// NON-MODIFICATION MEMBER FUNCTIONS
		bool in_list(const Name&)const;
		gifts get_gifts(const Name&)const;
		double gifts_cost(const Name&)const;
		double gifts_cost()const;
		gifts_bag get_list()const { return list_; }
		size_type size()const { return list_.size(); }
	private:
		gifts_bag list_;
	};

	void print_list(std::ostream& outs, const gift_list&);
	
}


#endif // !GIFT_LIST_H

