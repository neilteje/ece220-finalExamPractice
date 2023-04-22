#include "BankCustomer.h"

//Instantiate new customer with default accounts
BankCustomer::BankCustomer(string first_name, string last_name){
//IMPLEMENT ME
}

//Instantiate new customer with defined accounts
BankCustomer::BankCustomer(string first_name, string last_name, double init_savings_balance, double monthly_savings_interest_rate){
//IMPLEMENT ME
}

//Define parameters of current savings account (does not create new checking account)
void BankCustomer::define_savings(double init_savings_balance, double monthly_savings_interest_rate){
//IMPLEMENT ME
}

//Returns string containing first and last name separated by a space
string BankCustomer::get_customer_name(void){
//IMPLEMENT ME
}


//Returns total balance savings account
double BankCustomer::query_savings_balance(void){
//IMPLEMENT ME
}

//Deposits amount into savings (assume amount is positive)
void BankCustomer::operator + (const double& amount){
//IMPLEMENT ME
}

/* Withdraw amount from savings.  Return true if successful.
   If insuffient funds, completely deny charge and return false;
*/
bool BankCustomer::operator - (const double& amount){
//IMPLEMENT ME
}

//Adds interest to savings account = savings*interest_rate
void BankCustomer::add_interest(void){
//IMPLEMENT ME
}
