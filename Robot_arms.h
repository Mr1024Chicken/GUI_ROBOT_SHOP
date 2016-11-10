#include <iostream>
#include <string>

using namespace std;

#ifndef Robot_arms_H
#define Robot_arms_H

class Robot_arms{
public:
	Robot_arms();
	Robot_arms(string,string,int,int,int,string,int); 
		      //name , serial, price , weight, energy consume, describe.
	void set_price(int);
	void set_serial(string);
	void set_name(string);
	void set_weight(int);
	void set_describe(string);
	void set_consume(int);

	string get_name(){return name;}
	string get_serial(){return serial_num;}
	int get_price(){return price;}
	int get_weight(){return weight;}
	string get_describe(){return describe;}
	int get_consume(){return consume;}
	int get_amount(){return amount;}
private:
	string name;
	string serial_num;
	int price;
	int weight; //kg
	string describe;
	int consume; //watts
	int amount;
};

#endif
