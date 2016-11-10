#include <iostream>
#include <string>
using namespace std;

#ifndef Robot_motor_H
#define Robot_motor_H

class Robot_motor{

public:
	Robot_motor(string,string,int,int,int,int,string);
	//			name , serial, price, weight, consume, speed, describe

	string get_name(){return name;}
	string get_serial(){return serial;}
	int get_price(){return price;}
	int get_weight(){return weight;}
	int get_consume(){return consume;}
	int get_speed(){return speed;}
	string get_describe(){return describe;}


private:
	string name;
	string serial;
	int price;
	int weight;
	int speed;
	int consume;
	string describe;


};


#endif
