#include"BankAccount.h"
#include<iostream>
#include<vector>


using std::cout; using std::cin; using std::endl; using std::vector;
using namespace bank_account_adnan;

typedef vector<Bank_Account> Bank_Accounts;

int main()
{
	int num_of_accounts;
	//do
	//{
	//	cout << "How many accounts would you like to create?\n";
	//	cin >> num_of_accounts;
	//} while (num_of_accounts < 0);

	Bank_Account bbk(1000,0,100000);
	double years = target_time(bbk, 10590,700);
	cout << "It will take you " << years << " month(s)\n";
}