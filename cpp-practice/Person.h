#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person{
	private:
		string first_name;
		string last_name;
	public:
		Person();
		Person(string input_first_name, string input_last_name);
		void set_name(string input_first_name, string input_last_name);
		string get_first_name(void);
		string get_last_name(void);
};
#endif
