#include "Robot_arms.h"

Robot_arms::Robot_arms(string new_name, string new_seri, int newprice, int new_weight, int new_consume, string new_des,int _amount){
name = new_name;
serial_num = new_seri;
price = newprice;
weight = new_weight;
consume = new_consume;
describe = new_des;
amount = _amount;
}

void Robot_arms::set_price(int temp){
	price =temp;
}

void Robot_arms::set_serial(string temp){
	serial_num =temp;	
}

void Robot_arms::set_name(string temp){
	name =temp;
}

void Robot_arms::set_weight(int temp){
weight =temp;
}

void Robot_arms::set_consume(int temp){
consume = temp;
}

void Robot_arms::set_describe(string temp){
describe =temp;
}

