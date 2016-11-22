#include <iostream>
#include <string>
#include <vector>

#include "Robo.h"
#include "Robot_arms.h"
#include "Robot_body.h"
#include "Robot_head.h"
#include "Robot_motor.h"
#include "Robot_battery.h"
#include "Robot_model.h"
#include "Order.h"
#include "Customer.h"
#include "Sale_ASSO.h"


using namespace std;


#ifndef Controller_H
#define Controller_H

class Controller{
public:
	Robo add_arm(string, string,string, int,int,int,Robo);
	Robo add_head(string,string,int,int,string,Robo);
	Robo add_torso(string name1,string serial1, string describe1, int cost, int weight, int slot,Robo);
	Robo add_battery(string name, string serial, string describe, int price, int weight, int power, Robo info);
	Robo add_motor(string name, string serial, string describe, int price, int weight, int consume, int speed, Robo info);
	Robo add_model(string name, string serial, string describe, int arm_index, int head_index, int body_index, int motor_index, int battery_index, int price, int weight, Robo info);
	
	Robo add_order(double _tax, double _shiping, double _price,int _model,int _amount, string _date, 
		string _receipt,double sub_total,int customer_index,int SA_index,string customer_name,Robo info);


	Robo add_customer(string name, string phone, Robo info);
	Robo add_SA(string name, string ID, Robo info);
	//Robo add_arms(Robo);
	//Robo add_body(Robo);
	//Robo add_head(Robo);
	//Robo add_battery(Robo);
	//Robo add_motor(Robo);
	//Robo add_model(Robo);
	//Robo test_add_model(Robo);
	//Robo add_Order(Robo);
	//Robo add_SA(Robo);

	Robo Test_add(Robo);


};

class Controller_exception{};

#endif