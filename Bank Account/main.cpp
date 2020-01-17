// This program asks the user to enter the following his / her bank account :-
// account number, balance, annual interest rate, yearly deposit, target balance.
// The program will calculate the time needed for the current balance to reach the target balance
// based on the account's specifications entered by the user.


#include"BankAccount.h"
#include<iostream>


using std::cout; using std::cin; using std::endl;
using namespace bank_account_adnan;



int main()
{
	char repeat;
	Bank_Account bbk_account;
	double target_balance;
	double annual_deposits;
	int months;
	do
	{
		cout << "Enter the information of your account.\n";
		cin >> bbk_account;
		cout << endl;
		cout << "--------------------\n";
		cout << "Your account information:-\n";
		cout << bbk_account;
		cout << endl;
		cout << "--------------------\n";
		cout << "How much is your target balance? $";
		cin >> target_balance;
		cout << "How much will be the annual deposits ( if none enter zero ): $";
		cin >> annual_deposits;
		cout << endl;

		try {
			months = target_time(bbk_account, target_balance, annual_deposits);
			double years = months / double(12);
			cout << "Based on your:-\n"
				<< "current balance: $" << bbk_account.get_balance() << endl
				<< "annual interest rate: " << bbk_account.get_interest_rate() << endl
				<< "annual deposits: $" << annual_deposits << endl;
			cout << "It will take you " << years << "year(s) (" << months << " months) to reach $" << target_balance << endl;
			cout << "------------------\n";
		}
		catch (invalid_balance)
		{
			cout << "Error: the desired balance should be greater than $" << bbk_account.get_balance() << endl;
		}
		catch (negative_amount)
		{
			cout << "Error: the yearly deposit should be greater than $0.00" << endl;
		}
		catch (Bank_Account)
		{
			cout << "Based on what you entered, your current balance will not grow to $" << target_balance << endl;
			exit(1);
		}
		catch (double e)
		{
			cout << e;
			cout << "Can't proceed this operation.";
		}
		cout << "Do you want to try again? (yes/no)\n";
		cin >> repeat;
		newline();

	} while (tolower(repeat) == 'y');

}