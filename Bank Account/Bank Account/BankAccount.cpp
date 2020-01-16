#include"BankAccount.h"
#include<iostream>

using std::cout; using std::cin; using std::endl;
using std::ostream;
namespace bank_account_adnan {

	struct negative_balance {};	// error handling struct to throw when the operation makes the balance negative
	struct negative_amount {};	// error handling struct to throw when the amount given by the user is negative


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

	ostream& operator<<(ostream& outs, const Bank_Account& account)
	{
		outs << "Current Balance: $" << account.get_balance() << endl;
		outs << "Annual Interest Rate: " << account.get_interest_rate() << endl;
		return outs;
	}

}