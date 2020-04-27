// This is the implementation for the class polynomial
// See interface in: polynomial.h
/*
-------- Copyright © ---------
  @Author: Adnan Hashem Mohamed
-------------------------------
*/
//
// CLASS INVARIANT:
//  1- polynode* head_ptr;             // Head pointer for list of terms
//  2- polynode* tail_ptr;             // Tail pointer for list of terms
//  3- mutable polynode* recent_ptr;   // Most recently used term
//  4- unsigned int current_degree;    // Current degree of the polynomial

#include"polynomial.h"
#include<iostream>
#include<cassert>
#include<iomanip>
#include<climits> // provides UINT_MAX

namespace polynomial_adnan {

	void polynomial::trim()
		// Postcondition: the polynomial is adjusted in a way that every node with coef = 0
		// after the node with greatest exponent and coef != 0 are removed.
		// ex. 3x^3 + 2 will have nodes up to the node with exponent 3, every node after it will be removed.
		// The degree will be adjusted as well.
	{
		recent_ptr = tail_ptr;
		// delete the zero coef. terms upto - but not including- the node with exponent = 0
		while (recent_ptr->coef() == 0 && current_degree != 0)
		{
			recent_ptr = recent_ptr->back();
			delete recent_ptr->fore();
			tail_ptr = recent_ptr;
			--current_degree;
		}
	}

	void polynomial::set_recent(unsigned int exponent) const
		// Precondition: exponent <= degree()
	{
		assert(exponent <= degree());
		for (recent_ptr = head_ptr; recent_ptr != NULL; recent_ptr = recent_ptr->fore())
		{
			if (recent_ptr->exponent() == exponent)
				break;
		}
	}

	polynomial::polynomial(double c, unsigned int exponent)
	{		
		current_degree = exponent;

		// set the node for the which holds the term of specified coefficient 'c'
		// and exponent 'exponent'.
		head_ptr = new polynode(c, exponent);
		tail_ptr = head_ptr;
		recent_ptr = head_ptr;

		int i = exponent -1;

		while (i >= 0)
		{
			head_ptr->set_back(new polynode(0, i));
			head_ptr = head_ptr->back();
			head_ptr->set_fore(recent_ptr);
			recent_ptr = head_ptr;
			--i;
		}
		
		trim();
	}
	
	polynomial::~polynomial()
	{
		while (head_ptr != tail_ptr)
		{
			// move from the node to be deleted
			head_ptr = head_ptr->fore();
			// delete the node you just left.
			delete head_ptr->back();
		}
		delete head_ptr;
	}

	polynomial::polynomial(const polynomial& source)
	{
		current_degree = source.current_degree;

		// copy the head
		head_ptr = new polynode(source.head_ptr->coef(), source.head_ptr->exponent());
		tail_ptr = head_ptr;
		recent_ptr = head_ptr;

		for (auto cursor = source.head_ptr->fore(); cursor != NULL; cursor = cursor->fore())
		{
			tail_ptr = new polynode(cursor->coef(), cursor->exponent()); // copy the next node in source and make it the new tail.
			recent_ptr->set_fore(tail_ptr);  // modify the node previous to tail to point to tail in its front pointer
			tail_ptr->set_back(recent_ptr);  // modify tail so it points to the previous node in the d_list.
			recent_ptr = recent_ptr->fore(); // proceed recent to the next node.
		}
	}

	polynomial& polynomial::operator =(const polynomial& source)
	{
		// self assignment protection
		if (this != &source)
		{
			current_degree = source.current_degree;

			// delete the previous d_list which holds the current polynomial
			polynomial::~polynomial();

			// copy the head
			head_ptr = new polynode(source.head_ptr->coef(), source.head_ptr->exponent());
			tail_ptr = head_ptr;
			recent_ptr = head_ptr;

			for (auto cursor = source.head_ptr->fore(); cursor != NULL; cursor = cursor->fore())
			{
				tail_ptr = new polynode(cursor->coef(), cursor->exponent()); // copy the next node in source and make it the new tail.
				recent_ptr->set_fore(tail_ptr);  // modify the node previous to tail to point to tail in its front pointer
				tail_ptr->set_back(recent_ptr);  // modify tail so it points to the previous node in the d_list.
				recent_ptr = recent_ptr->fore(); // proceed recent to the next node.
			}
		}

		return *this;
	}

	void polynomial::add_to_coef(double amount, unsigned int exponent)
	{
		if (exponent <= degree())
		{
			set_recent(exponent); // make the recent_ptr point to the node holding the exponent 'exponent'
			recent_ptr->set_coef(recent_ptr->coef() + amount); //  add the amount to the current coefficient of the term
		}
		else
		{
			assign_coef(amount, exponent);
		}
		trim();
	}
	
	void polynomial::assign_coef(double coefficient, unsigned int exponent)
	{
		if (exponent <= degree()) // The node to be assigned the new coefficient already exists
		{
			set_recent(exponent); // make the recent_ptr point to the node holding the exponent 'exponent'
			recent_ptr->set_coef(coefficient); //  assign the 'coefficient' to be the coefficient of the term.
		}
		// 'exponent' is greater than the current degree of the poly. so create new node for this term
		//  create terms between the new 'exponent' and the current degree such that the term's coeff. = 0
		else  
		{	  
			int i = degree() + 1;

			while (i < exponent) // create new terms with coef = 0 up till you get to exponent.
			{
				tail_ptr->set_fore(new polynode(0, i));
				recent_ptr = tail_ptr;
				tail_ptr = tail_ptr->fore();
				tail_ptr->set_back(recent_ptr);
				++i;
			}
			tail_ptr->set_fore(new polynode(coefficient, exponent));  // create the node for the term with
			recent_ptr = tail_ptr;									  // coef = 'coefficient'.
			tail_ptr = tail_ptr->fore();
			tail_ptr->set_back(recent_ptr);
			current_degree = exponent;		// update the polynomial's degree.
		}

		trim();
	}

	void polynomial::clear()
	{
		polynomial::~polynomial();
		current_degree = 0;
		head_ptr = new polynode();
		tail_ptr = head_ptr;
		recent_ptr = head_ptr;
	}

	double polynomial::coefficient(unsigned int exponent) const
	{
		if (exponent > degree())
			return 0;
		else
		{
			set_recent(exponent);
			return recent_ptr->coef();
		}
	}

	unsigned int polynomial::next_term(unsigned int e) const
	{
		if (e < degree())
		{
			do
			{
				if (coefficient(e+1) != 0)
					return e + 1;
				++e;
			} while (coefficient(e + 1) != 0 && e < degree());
		}
		return 0;
	}

	unsigned int polynomial::previous_term(unsigned int e) const
	{
		if (e == 0)
		{
			while (e > 0)
			{
				if (coefficient(e - 1) != 0)
					return e - 1;
				--e;
			}
		}
		return UINT_MAX;
	}

	polynomial polynomial::integral() const
	{

		polynomial integ;

		for (int exp = degree(); exp >= 0; --exp)
		{
			integ.assign_coef(coefficient(exp) / double(exp + 1), exp + 1);
		}

		return integ;
	}

	double polynomial::definite_integral(double low_bound, double high_bound) const
	{
		polynomial F = integral();
		return F(high_bound) - F(low_bound);
	}

	polynomial polynomial::substitution(const polynomial& p) const
	{
		polynomial p2;

		for (int n = degree() + 1; n > 0; --n)
		{
			if (previous_term(n) != UINT_MAX)
			{
				p2 += coefficient(n-1) * (p ^ (previous_term(n)));
			}
		}

		return p2;
	}

	double polynomial::eval(double x) const
	{
		double result = 0;
		for (size_t i = 0; i < degree() + 1; ++i)
		{

			result += coefficient(i) * pow(x, i);
		}
		return result;
	}

	polynomial polynomial::derivative() const
	{

		polynomial d;

		for (int exp = degree(); exp > 0; --exp)
		{
			d.assign_coef(coefficient(exp) * exp, exp - 1);
		}

		return d;
	}

	void polynomial::find_root(
		double& answer,
		bool& success,
		unsigned int& iterations,
		double guess,
		unsigned int maximum_iterations,
		double epsilon
	)const
	{
		iterations = 0;
		success = false;
		polynomial d = derivative();
		while (iterations < maximum_iterations)
		{
			if (abs(d(guess)) < epsilon)
			{
				answer = guess;
				break;
			}
			guess = guess - (eval(guess) / d(guess));
			iterations++;
			if (abs(this->eval(guess)) <= epsilon)
			{
				success = true;
				answer = guess;
				return;
			}
		}

	}

	void polynomial::operator +=(const polynomial& poly)
	{
		for (auto cursor = poly.head_ptr; cursor != NULL; cursor = cursor->fore())
		{
			add_to_coef(cursor->coef(), cursor->exponent());
		}
	}

	void polynomial::operator -=(const polynomial& poly)
	{
		for (auto cursor = poly.head_ptr; cursor != NULL; cursor = cursor->fore())
		{
			add_to_coef(-cursor->coef(), cursor->exponent());
		}
	}

	void polynomial::operator *=(const polynomial& poly)
	{
		polynomial* product = new polynomial; // this pointer will point to the product resulting polynomial of the operation
		recent_ptr = head_ptr;
		while (recent_ptr != NULL) // multiplying each term of this polynomial by each term of 'poly' and saving the result in 'product'
		{
			for (auto cursor = poly.head_ptr; cursor != NULL; cursor = cursor->fore())
			{
				product->add_to_coef(recent_ptr->coef() * cursor->coef(), cursor->exponent() + recent_ptr->exponent());
			}
			recent_ptr = recent_ptr->fore();
		}

		current_degree = product->current_degree;
		polynomial::~polynomial();    // delete the calling polynomial
		head_ptr = product->head_ptr; //
		tail_ptr = product->tail_ptr; // make the current polynomial hold the resulting product.
		recent_ptr = head_ptr;        //
	}

	polynomial operator +(const polynomial& p1, const polynomial& p2)
	{
		polynomial sum(p1);
		sum += p2;
		return sum;
	}

	polynomial operator +(const polynomial& p, double c)
	{
		polynomial p2(p);
		p2 += c;
		return p2;
	}

	polynomial operator +(double c, const polynomial& p)
	{
		return p + c;
	}

	polynomial operator -(const polynomial& p1, const polynomial& p2)
	{
		polynomial difference(p1);
		difference -= p2;
		return difference;
	}

	polynomial operator -(const polynomial& p, double c)
	{
		return p + (-c);
	}

	polynomial operator -(double c, const polynomial& p)
	{
		return polynomial(c) - polynomial(p);
	}

	polynomial operator *(const polynomial& p1, const polynomial& p2)
	{
		polynomial product(p1);
		product *= p2;
		return product;
	}

	polynomial operator *(const polynomial& p, double c)
	{
		return p * polynomial(c);
	}

	polynomial operator *(double c, const polynomial& p)
	{
		return p * c;
	}

	polynomial operator ^(const polynomial& p, unsigned int n)
	{
		if (n == 0)
			return 1;

		polynomial p2(p);

		while (n > 1)
		{
			p2 *= p;
			--n;
		}

		return p2;
	}

	polynomial polynomial::operator -() const
	{
		return (*this) * (-1);
	}

	std::ostream& operator << (std::ostream& out, const polynomial& p)
	{
		out.setf(std::ios::showpoint);
		out.setf(std::ios::fixed);
		out.precision(2);

		int i = p.degree();
		

		while (i > 0)
		{
			if (p.coefficient(i) == 0)
			{
				--i;
				continue;
			}

			if (p.coefficient(i) > 0)
				std::cout << "+ ";
			else
				std::cout << "- ";

			if (abs(p.coefficient(i)) != 1)
			{
				std::cout << abs(p.coefficient(i));
			}
			std::cout << "x";
			if (i != 1)
			{
				std::cout << "^" << i << " ";
			}
			else
				std::cout << " ";

			--i;
		}

		if (p.coefficient(i) > 0)
			std::cout << "+ " << abs(p.coefficient(i));
		else if(p.coefficient(i) < 0)
			std::cout << "- " << abs(p.coefficient(i));


		return out;
	}

}// end of namespace