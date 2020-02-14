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
		}
		else
		{
			coef[exponent] += amount;
		}
	}

}