#include <iostream>
#include <string>

#ifndef Robot_battery_H
#define Robot_battery_H
using namespace std;
class Robot_battery{

public:
    Robot_battery(string, string, int, int ,int,string);
			//name, serial,  price, weight, energy, describe
	string get_name(){return name;}
	string get_serial(){return serial_num;}
	int get_price(){return price;}
	int get_weight(){return weight;}
	int get_energy(){return energy;}
	string get_describe(){return describe;}
private:

	string name;
	string serial_num;
	int energy;    //kilo Watts HRS
	int weight;
	int price;
	string describe;


};

#endif