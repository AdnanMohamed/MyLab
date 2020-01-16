//File: BankAccount.h (This file is for project 16 in chapter 2 of the book:
//Data Structures and Other Objects Using C++ Fourth Edition by Michael Main and Walter Savitch)
//CLASS PROVIDED: Bank_Account (ADT for bank accounts that have a balance and annual interest rates)
//The classes belong to the namespace bank_account_adnan
//
//CONSTRUCTOR:
//Bank_Account(double balance = 0, double interest_rate = 0, int account_number = 0)
//// Precondition: balance and interest rate should not be negative, account_number should be
//// non-negative and 5 digit number.
//// Postcondition: A bank account with the given balance and interest rate would be initialized.
//// If the arguments were not specified the balance and interest rate will be zero.
//
//double get_balance()const
//// Postcondition: returns the balance amount in the account
//
//double get_interest_rate()const
//// Postcondition: returns the annual interest rate of the calling account
//
//int get_account_number()const
//// Postcondition: returns the account's number.
//
//void set_balance(double balance)
//// Precondition: balance should be >= 0
//// Postcondition: the balance of the account would be equal to the given argument.
//
//void set_interest_rate(double interest_rate)
//// Precondition: interest_rate should be >= 0
//// Postcondition: the annual interest rate of the account would be equal to the given argument.
//
//void set_account_number(int account_number)
//// Precondition: The account number must be non-negative 5 digit number.
//// Postcondition: The account number is set equal to account_number
//
//void deposit(double amount)
//// Precondition: amount >= 0
//// Postcondition: The new balance will be balance = balance + amount.
//
//void withdraw(double amount)
//// Precondition: amount >= 0, and amount <= the account's balance.
//// Postcondition: The new balance will be balance = balance - amount.
//
//void add_interest(double years)
//// Precondition: years >= 0
//// Postondition: the amount of interest deserved for the years specified -using the current interest rate- 
//// will be added to the balance
//
//NON MEMBER FUNCTIONS:-
//
//friend std::istream& operator>> (std::istream& ins, Bank_Account&)
//// Postcondition: The user will be asked to input the balance and annual interest
//// rate of the give bank account
//
//std::ostream& operator<<(std::ostream& outs, const Bank_Account& account)
//// Postcondition: Prints the account balance and annual interest rate
//
//double target_time(const Bank_Account&, double desired_balance, double yearly_deposit = 0)
//// Precondition: desired_balance should be greater than the
//// original balance in the bank account and greater than $0.00; yearly_deposit >= $0.00
//// Postcondition: The number of months to reach this balance will be returned

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<iostream>
namespace bank_account_adnan {

	class Bank_Account {
		public:
			Bank_Account(double balance = 0, double interest_rate = 0, int account_number = 0);
			
			double get_balance()const { return balance_; }
			double get_interest_rate()const { return interest_rate_; }
			int get_account_number()const { return account_number_; }

			void set_balance(double balance);
			void set_interest_rate(double interest_rate);
			void set_account_number(int account_number);

			void deposit(double amount);
			void withdraw(double amount);

			void add_interest(double years);

			friend std::istream& operator>> (std::istream& ins, Bank_Account&);

		protected:
			double balance_;
			double interest_rate_;
			int account_number_;
			bool isvalid(int);
	};

	std::ostream& operator<<(std::ostream& outs, const Bank_Account& account);

	double target_time(const Bank_Account&, double desired_balance, double yearly_deposit = 0);
}

#endif // !BANKACCOUNT_H

