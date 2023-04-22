#include "BankCustomer.h"
#include <string>
#include <iostream>

using namespace std;

void print_account_information(BankCustomer * current_customer){
	cout << "Name: " << current_customer->get_customer_name() << endl;
	cout << "Savings Balance: " << current_customer->query_savings_balance() << endl << endl;
}

//Main function: modify if desired for testing purposes, but do not put any required code in this file
int main(int argc,char *argv[])
{
	//Test for constructors
	BankCustomer customer1 = BankCustomer("Bob", "Smith", 200, .01);
	BankCustomer customer2 = BankCustomer("Jane", "Doe");
	customer2.define_savings(250, .005);
	cout << "Initial Account Information: " << endl;
	print_account_information(&customer1);
	print_account_information(&customer2);

	//Deposit savings test
	customer1 + 100;
	cout << "Deposit of 100 into savings" << endl;
	print_account_information(&customer1);

	//Withdraw savings test
	bool success = customer1 - 50;
	cout << "Withdraw of 50 from savings" << endl;
	if(success){
		cout << "Withdraw was successful" << endl;
	}
	else{
		cout << "Withdraw was not successful" << endl;
	}
	print_account_information(&customer1);
	

	//Add interest test
	cout << "Accumulating Interest" << endl;
	customer1.add_interest();
	cout << "Final account state: " << endl;
	print_account_information(&customer1);

	return 0;
}
