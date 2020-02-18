// This is the implementation file for the class polynomial (within namespace: dynamic_poly_adnan)
// See interface in dynamic_poly.h
//
// @ Author: Adnan Hashem Mohamed
//
// CLASS INVARIANT:
//	1- size_t current_array_size ( Keeps track of the size of the array of coefficients.
//	2- double* coef ( A pointer to the array of coefficients)
//

#include"dynamic_poly.h"
#include<cassert>
#include<algorithm>
#include<cmath>
#include<climits>

namespace dynamic_poly_adnan {
	polynomial::polynomial()
	{
		current_array_size = 1;
		coef = new double[current_array_size];
		coef[0] = 0;
	}

	polynomial::polynomial(const polynomial& source)
	{
		current_array_size = source.current_array_size;
		coef = new double[current_array_size];
		std::copy(source.coef, source.coef + source.current_array_size, coef);
	}

	polynomial::polynomial(double c, unsigned int exponent)
	{
		current_array_size = exponent + 1;
		coef = new double[current_array_size];
		for (unsigned int i = 0; i <= exponent; ++i)
		{
			if (i != exponent)
				coef[i] = 0;
			else
				coef[i] = c;
		}
	}

	void polynomial::add_to_coef(double amount, unsigned int exponent)
	{
		
		if (exponent >= current_array_size)
		{
			double* temp = new double[exponent + 1];
			for (unsigned int i = 0; i <= exponent; ++i)
			{
				if (i != exponent && i < current_array_size)
					temp[i] = coef[i];
				else if (i != exponent)
					temp[i] = 0;
				else
					temp[i] = amount;
			}
			delete[] coef;
			coef = temp;
			current_array_size = exponent + 1;
		}
		else
		{
			coef[exponent] += amount;
		}
	}

	void polynomial::assign_coef(double coefficient, unsigned int exponent)
	{
		
		if (exponent >= current_array_size)
		{
			double* temp = new double[exponent + 1];
			for (unsigned int i = 0; i <= exponent; ++i)
			{
				if (i != exponent && i < current_array_size)
					temp[i] = coef[i];
				else if (i != exponent)
					temp[i] = 0;
				else
					temp[i] = coefficient;
			}
			delete[] coef;
			coef = temp;
			current_array_size = exponent + 1;
		}
		else
		{
			coef[exponent] = coefficient;
		}
	}

	void polynomial::clear()
	{
		for (int i = 0; i < current_array_size; ++i)
		{
			coef[i] = 0;
		}
	}

	void polynomial::reserve(size_t number)
	{
		size_t min_array_size = current_array_size;
		size_t i = 1;
		while (coef[min_array_size - i] == 0)
		{
			++i;
		}

		if (number >= min_array_size - i + 1)
		{
			current_array_size = min_array_size - i + 1;
		}
	}
	
	void polynomial::trim()
	{
		if (coef[current_array_size - 1] != 0 || current_array_size == 1) // no need to go further if the array is already 
		{									   // fitting its size
			return;
		}

		size_t min_array_size = current_array_size;
		size_t i = 1;
		while (coef[min_array_size - i] == 0)
		{
			++i;
		}

		min_array_size = min_array_size - i + 1;

		if (min_array_size == 0)
			min_array_size = 1;  // The smallest polynomial instance is 0, so 0 takes 1 space in the array of coef.
		
		double* new_array = new double[min_array_size];
		std::copy(coef, coef + min_array_size, new_array);
		delete[] coef;
		coef = new_array;
		current_array_size = min_array_size;
		

	}

	polynomial& polynomial::operator =(const polynomial& source)
	{
		current_array_size = source.current_array_size;
		if (this != &source)
		{
			delete[]coef;
			coef = new double[current_array_size];
			for (size_t i = 0; i < source.current_array_size; ++i)
			{
				coef[i] = source.coef[i];
			}
		}

		return *this;
	}

	polynomial& polynomial::operator -=(const polynomial& p)
	{
		for (size_t i = 0; i < p.current_array_size; ++i)
		{
			add_to_coef(-p.coef[i], i);
		}
		return *this;
	}

	polynomial& polynomial::operator +=(const polynomial& p)
	{
		for (size_t i = 0; i < p.current_array_size; ++i)
		{
			add_to_coef(p.coef[i], i);
		}
		return *this;
	}

	polynomial& polynomial::operator *=(const polynomial& p)
	{
	
		double* new_coef = new double[current_array_size + p.current_array_size - 1]{};

		for (size_t i = 0; i < current_array_size; ++i)
		{
			for (size_t j = 0; j < p.current_array_size; ++j)
			{
				new_coef[i + j] += coef[i] * p.coef[j];
			}
		}
		
		delete[] coef;
		coef = new_coef;
		current_array_size = current_array_size + p.current_array_size - 1;
		return *this;
	}
	
	polynomial& polynomial::operator *=(double c)
	{
		for (size_t i = 0; i < current_array_size; ++i)
		{
			assign_coef(coef[i] * c, i);
		}
		return *this;
	}

	double polynomial::coefficient(unsigned int exponent) const
	{
		assert(exponent < current_array_size);
		return coef[exponent];
	}

	double polynomial::eval(double x) const
	{
		double result = 0;
		for (size_t i = 0; i < current_array_size; ++i)
		{
			
			result += coef[i] * pow(x, i);
		}
		return result;
	}

	polynomial polynomial::derivative(unsigned int n) const
	{
		if (n == 0)			// the 0th derivative is just the same poly.
			return *this;

		polynomial d;

		for (size_t exp = current_array_size - 1; exp > 0; --exp)
		{
			d.assign_coef(coef[exp] * exp, exp - 1);
		}

		return d.derivative(n-1);
	}

	polynomial polynomial::integral(unsigned int n) const
	{
		if (n == 0)			// the 0th integral is just the same poly.
			return *this;
		
		polynomial integ;

		for(int exp = current_array_size - 1; exp >= 0; --exp)
		{
			integ.assign_coef(coef[exp] / double(exp + 1) , exp + 1);
		}

		return integ.integral(n-1);
	}

	double polynomial::definite_integral(double low_bound, double high_bound) const
	{
		polynomial F = integral();
		return F(high_bound) - F(low_bound);
	}

	unsigned int polynomial::next_term(unsigned int e) const
	{
		if (e < degree())
		{
			if (coef[e + 1] != 0)
				return e + 1;
		}
		return UINT_MAX;
	}

	unsigned int polynomial::previous_term(unsigned int e) const
	{
		if (e <= degree() + 1)
		{
			if (coef[e - 1] != 0)
			{
				return e - 1;
			}
		}
		return UINT_MAX;
	}

	double polynomial::numeric_integral(double low_bound, double high_bound, unsigned int many_trapezoids)const
	{
		double delta_x = (high_bound - low_bound) / many_trapezoids;
		double area = (delta_x / 2.0) * (eval(low_bound) + eval(high_bound));

		double x = low_bound + delta_x;
		while (x < high_bound)
		{
			area += (delta_x / 2.0) * (2 * eval(x));
			x += delta_x;
		}
		
		return area;
	}

	//polynomial polynomial::substitution(const polynomial& p) const
	//{
	//	polynomial p2;
	//	
	//	for (int n = degree() + 1; n > 0; --n)
	//	{
	//		if (previous_term(n) != UINT_MAX)
	//		{
	//			p2 += p ^ (previous_term(n));
	//		}
	//	}

	//	return p2;
	//}

	polynomial operator +(const polynomial& p1, const polynomial& p2)
	{
		polynomial p3(p1);
		return p3 += p2;
	}

	polynomial operator +(const polynomial& p, double c)
	{
		polynomial p2(p);
		return p2 += c;
	}

	polynomial operator +(double c, const polynomial& p)
	{
		return p + c;
	}

	polynomial operator -(const polynomial& p1, const polynomial& p2)
	{
		polynomial p3(p2);
		p3 *= -1;
		return p1 + p3;
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
		polynomial p3(p1);
		return p3 *= p2;
	}

	polynomial operator *(const polynomial& p, double c)
	{
		return p * polynomial(c);
	}

	std::ostream& operator << (std::ostream& out, const polynomial& p)
	{
		// Edit this function such that displays as follows:-
		//	1- If the polynomial is zero display 0
		//  2- If normal display like: 2.00 x^2 + 3.20 x^4 - 7
		//	3- DON'T display + at the beggining
		//  4- display x^1 or x^0 1.00x^5 as x, 1, x^5 respectively.
		out.setf(std::ios::showpoint);
		out.setf(std::ios::fixed);
		out.precision(2);
		for (int n = p.degree() + 1; n > 0; --n)
		{
			if (p.previous_term(n) != UINT_MAX)
			{
				if (p.previous_term(n) > 0)
				{
					out.setf(std::ios::showpos);
					out << p.coefficient(p.previous_term(n)) <<"x^"<< p.previous_term(n)<<" ";
				}
				else
				out << p.coefficient(p.previous_term(n)) << "x^" << p.previous_term(n) << " ";
			}
		}
		return out;
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

} // end of namespace