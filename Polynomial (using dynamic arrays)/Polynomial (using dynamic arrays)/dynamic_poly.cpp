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

	//polynomial polynomial::derivative(unsigned int n) const
	//{
	//	if (n == 0)			// the 0th derivative is just the same poly.
	//		return *this;
	//	
	//	
	//	else
	//	{
	//		double* new_coef = new double[current_array_size - n];
	//		polynomial d;

	//		//for (int i = 0; i < n; ++i)
	//		//{
	//			for (size_t exp = d.current_array_size - 1; exp > 0; --exp)
	//			{
	//				d.assign_coef(d.coef[exp] * exp, exp - 1);
	//			}
	//		//}

	//			return d.derivative(n - 1);
	//	}


	}
} // end of namespace