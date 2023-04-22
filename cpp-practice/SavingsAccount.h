#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

class SavingsAccount{
	private:
		double balance;
		double interest_rate;
	public:
		SavingsAccount();
		SavingsAccount(double input_balance, double input_interest_rate);
		void set_balance(double input_balance);
		double get_balance(void);
		void set_interest_rate(double input_interest_rate);
		double get_interest_rate(void);
};

#endif
