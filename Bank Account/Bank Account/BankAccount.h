#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<iostream>
namespace bank_account_adnan {

	class Bank_Account {
		public:
			Bank_Account(double balance = 0, double interest_rate = 0)
				:balance_(balance), interest_rate_(interest_rate) {}
			
			double get_balance()const { return balance_; }
			double get_interest_rate()const { return interest_rate_; }

			void set_balance(double balance) { balance_ = balance; }
			void set_interest_rate(double interest_rate) { interest_rate_ = interest_rate; }

			void deposit(double amount);
			void withdraw(double amount);

		protected:
			double balance_;
			double interest_rate_;
	};

	std::ostream& operator<<(std::ostream& outs, const Bank_Account& account);
}

#endif // !BANKACCOUNT_H

