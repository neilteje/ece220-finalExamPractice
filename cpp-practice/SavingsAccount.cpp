#include "SavingsAccount.h"
SavingsAccount::SavingsAccount(){
	balance = 0;
	interest_rate = 0;
}

SavingsAccount::SavingsAccount(double input_balance, double input_interest_rate){
	balance = input_balance;
	interest_rate = input_interest_rate;
}

void SavingsAccount::set_balance(double input_balance){
	balance = input_balance;
}

double SavingsAccount::get_balance(void){
	return balance;
}

void SavingsAccount::set_interest_rate(double input_interest_rate){
	interest_rate = input_interest_rate;
}

double SavingsAccount::get_interest_rate(void){
	return interest_rate;
}
