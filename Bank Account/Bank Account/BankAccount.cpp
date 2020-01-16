#include"BankAccount.h"
#include<iostream>
#include<assert.h>

using std::cout; using std::cin; using std::endl;
using std::ostream; using std::istream;
namespace bank_account_adnan {

	struct negative_balance {};	// error handling struct to throw when the operation makes the balance negative
	struct negative_amount {};	// error handling struct to throw when the amount given by the user is negative
	struct negative_years{}; // error handling struct to be thrown when the user inputs negative number
							 //	corresponding for the years in add_interest function
	struct invalid_balance {}; //error handling struct to be thrown for the function target_time()
	struct invalid_account_number {}; // error handling struct to be thrown if the given account number is invalid

	bool Bank_Account::isvalid(int number)
	{
		return number > 0 &&
			number > 9999
			&& number < 100000;
	}

	Bank_Account::Bank_Account(double balance, double interest_rate, int account_number)
	{
		assert(balance >= 0);
		assert(interest_rate >= 0);
		assert(isvalid(account_number));
		balance_ = balance;
		interest_rate_ = interest_rate;
		account_number_ = account_number;
	}

	void Bank_Account::deposit(double amount)
	{
		try {
			if (amount < 0)
			{
				throw negative_amount();
			}
			balance_ += amount;
			cout << "You successfully deposited $" << amount << endl;
			cout << "Your new balance: $" << balance_ << endl;
		}
		catch (negative_amount)
		{
			cout << "**Error: The deposit amount must be greater than $ 0.00**\n\n";
		}
		catch (...)
		{
			cout << "**Error: Something unpredicted happened! ** \n";
			exit(1);
		}
	}

	void Bank_Account::withdraw(double amount)
	{
		try {
			if (balance_ - amount < 0)
			{
				throw negative_balance();
			}
			else if (amount < 0)
			{
				throw negative_amount();
			}

			balance_ -= amount;
			cout << "You successfully withdrawed $" << amount << endl;
			cout << "Your new balance: $" << balance_ << endl;

		}
		catch (negative_balance)
		{
			cout << "**Error: The operation cannot happen. The balance is not enough.**\n\n";
		}
		catch (negative_amount)
		{
			cout << "**Error: The withdraw amount must be greater than $ 0.00**\n\n";
		}
		catch (...)
		{
			cout << "**Error: Something unpredicted happened! ** \n";
			exit(1);
		}
	}

	void Bank_Account::set_balance(double balance)
	{
		assert(balance >= 0);
		balance_ = balance;
	}
	void Bank_Account::set_interest_rate(double interest_rate)
	{
		assert(interest_rate >= 0);
		interest_rate_ = interest_rate;
	}

	//void Bank_Account::set_account_number(int account_number)
	//{
	//	// Complete This Function
	//}

	void Bank_Account::add_interest(double years)
	{

		try {
			if (years < 0)
				throw negative_years();
			balance_ *= pow(1 + interest_rate_, years);
			cout << "The interest has been successfully added to your account.\n";
		}
		catch (negative_years)
		{
			cout << "** Error: Years of interest must be greater than zero. **\n";
		}

		cout.setf(std::ios::fixed);
		cout.setf(std::ios::showpoint);
		cout.precision(2);
		cout << "Current Balance: $" << balance_ << endl;
	}

	istream& operator>> (istream& ins, Bank_Account& account)
	{
		cout << "Enter the balance: $";
		ins >> account.balance_;
		cout << "Enter the annual interest rate (in decimal): ";
		ins >> account.interest_rate_;
		return ins;
	}

	ostream& operator<<(ostream& outs, const Bank_Account& account)
	{
		outs << "Current Balance: $" << account.get_balance() << endl;
		outs << "Annual Interest Rate: " << account.get_interest_rate() << endl;
		return outs;
	}

	double target_time(const Bank_Account& acc, double desired_balance, double yearly_deposit)
	{
		try {
			if (desired_balance < acc.get_balance() && desired_balance > 0)
				throw invalid_balance();
			else if (desired_balance < 0)
				throw desired_balance;
			else if (yearly_deposit < 0)
				throw negative_amount();
			else if (acc.get_balance() == 0 && yearly_deposit == 0
				|| (acc.get_balance() < desired_balance && yearly_deposit == 0 && acc.get_interest_rate() == 0))
				throw Bank_Account();
			Bank_Account temp = acc;
			int months = 0;
			double monthly_rate = acc.get_interest_rate() / double(12);
			double balance = acc.get_balance();
			
			while (balance < desired_balance)
			{
				balance *= (1 + monthly_rate);
				months += 1;
				if (months % 12 == 0)
				{
					balance += yearly_deposit;
				}
			}
			return months;
		}
		catch (invalid_balance)
		{
			cout << "** Error: The desired balance must be >= current balance **\n";
			cout << "The program will exit.";
			exit(1);
		}
		catch (double)
		{
			cout << "** Desired balance must be > $0.00 **";
			cout << "The program will exit.";
			exit(1);
		}
		catch (negative_amount)
		{
			cout << "** Error: The yearly deposit amount must be greater than $ 0.00 **\n\n";
			cout << "The program will exit.";
			exit(1);
		}
		catch (Bank_Account)
		{
			cout << "No sufficient balance to make this possible.\n";
			cout << "This program will exit.";
			exit(1);
		}
	}


}