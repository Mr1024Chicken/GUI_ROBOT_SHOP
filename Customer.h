#include <iostream>

using namespace std;

#ifndef Customer_H
#define Customer_H

class Customer{

public:
	Customer(string name_, string phone_){
	name = name_;
	phone = phone_;
	total =0;
	}

	string get_name(){return name;}
	string get_phone(){return phone;}
	int get_total(){return total;}

private:
	string name;
	string phone;
	int total;


};


#endif