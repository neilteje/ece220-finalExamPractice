#include "Person.h"

Person::Person(){
	first_name = "";
	last_name = "";
}

Person::Person(string input_first_name, string input_last_name){
	first_name = input_first_name;
	last_name = input_last_name;
}

void Person::set_name(string input_first_name, string input_last_name){
	first_name = input_first_name;
	last_name = input_last_name;
}

string Person::get_first_name(void){
	return first_name;
}

string Person::get_last_name(void){
	return last_name;
}
