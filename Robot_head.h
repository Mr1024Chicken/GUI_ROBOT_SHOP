#include <iostream>
#include <string>
using namespace std;
#ifndef Robot_head_H
#define Robot_head_H

class Robot_head{
public:
	Robot_head(string,string,int,int,string);
	//			name, serial, price, weight, decribe.


	string get_name(){return name;}
	string get_serial(){return serial_num;}
	int get_price(){return price;}
	int get_weight(){return weight;}
	string get_describe(){return describe;}


private:
	string serial_num;
	int price;
	string name;
	int weight;
	string describe;

};


#endif