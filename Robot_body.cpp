#include "Robot_body.h"

Robot_body::Robot_body(string new_name, string new_seri, int new_price, int new_weight, int new_slot,string des){
	name =new_name;
	serial_num=new_seri;
	price = new_price;
	weight = new_weight;
	batt_slot = new_slot;
	describe = des;
}


