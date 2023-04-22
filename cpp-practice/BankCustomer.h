#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H

#include "Person.h"
#include "SavingsAccount.h"
#include <string>

class BankCustomer{
	private:
		//Private variables
		//DO NOT INSERT ANY ADDITIONAL PRIVATE VARIABLES
		Person my_customer;
		SavingsAccount customer_savings;

	public:
		//Instantiate new customer with default accounts
		BankCustomer(string first_name, string last_name);

		//Instantiate new customer with defined accounts
		BankCustomer(string first_name, string last_name, double init_savings_balance, double monthly_savings_interest_rate);

		//Define parameters of current savings account (does not create new checking account)
		void define_savings(double init_savings_balance, double monthly_savings_interest_rate);

		//Returns string containing first and last name separated by a space
		string get_customer_name(void);
		
		//Returns total balance savings account
		double query_savings_balance(void);

		//Adds interest to savings account = savings*interest_rate
		void add_interest(void);	
		
		//Deposits amount into savings (assume amount is positive)
		void operator + (const double& amount);

		/* Withdraw amount from savings.  Return true if successful.
		   If insuffient funds, completely deny charge and return false;
		*/
		bool operator - (const double& amount);

};
#endif
