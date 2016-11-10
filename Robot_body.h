#include <iostream>
#include <string>
using namespace std;
#ifndef Robot_body_H
#define Robot_body_H

class Robot_body{

public:
	Robot_body(string,string,int,int,int,string);
			// name , serial , price, weight , battery slot 1-3, description.
	//void set_serial_num(string);
	//void set_batt_dur(int);
	//void set_price(int);
	string get_name(){return name;}
	string get_serial(){return serial_num;}
	int get_price(){return price;}
	int get_weight(){return weight;}
	int get_batt(){return batt_slot;}
	string get_describe(){ return describe;}

private:
	string serial_num;
	int price;
	int batt_slot;  //battery slot 1-3
	string name;
	int weight;
	string describe;

};


#endif
