#include "Robot_battery.h"

Robot_battery::Robot_battery(string new_name,string new_seri, int new_price, int new_weight, int new_energy, string des){
	name= new_name;
	serial_num = new_seri;
	price = new_price;
	weight = new_weight;
	energy = new_energy;
	describe = des;
}