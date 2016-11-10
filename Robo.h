#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


#include "Robot_arms.h"
#include "Robot_body.h"
#include "Robot_head.h"
#include "Robot_motor.h"
#include "Robot_battery.h"
#include "Robot_model.h"
#include "Order.h"
#include "Sale_ASSO.h"


using namespace std;

#ifndef Robo_H
#define Robo_H
class Robo{
public:
	void add_arm(Robot_arms rob);
	void add_body(Robot_body bod);
	void add_head(Robot_head head);
	void add_battery (Robot_battery batt);
	void add_motor(Robot_motor moto);
	void add_models(Robot_model moda);
	void add_SA(Sale_ASSO);
	
	
	void add_Order(Order order);

	void print_arms( vector <Robot_arms>& info);
	void print_body(vector <Robot_body>& info);
	void print_head(vector <Robot_head>& info);
	void print_batt(vector <Robot_battery>& info);
	void print_motor(vector <Robot_motor>& info);
	void print_model(vector <Robot_model>& moda);
	
	void print_SA(vector <Sale_ASSO>& SA);
	void print_Order(vector <Order>& order, vector <Sale_ASSO>&);

	vector <Robot_arms> get_arms(){return arm_vec;}
	vector <Robot_body> get_body(){return body_vec;}
	vector <Robot_head> get_head(){return head_vec;}
	vector <Robot_battery> get_batt() {return batt_vec;}
	vector <Robot_motor> get_motor() {return motor_vec;}
	vector <Robot_model> get_model(){return model_vec;}
	vector <Order> get_order(){return Order_vec;}
	vector <Sale_ASSO> get_SA(){return SA_vec;}

	int get_motor_price(vector <Robot_motor>& , int );
	int get_body_price(vector <Robot_body>& ,int);
	int get_head_price(vector <Robot_head>&,int);
	int get_arm_price(vector <Robot_arms>&,int);
	int get_battery_price(vector <Robot_battery>&,int);
	/******************************************************/
	int get_battery_slot(vector <Robot_body>& ,int);
	int get_arm_amount(vector <Robot_arms>&, int);
	int get_model_price(vector <Robot_model>&,int);
	int get_SA_ID(vector <Sale_ASSO>&,int);
	string get_SA_name(vector <Sale_ASSO>&,int);
	int get_model_index(vector <Order>&,int);
	

	/******************************************************/
	int get_motor_W(vector <Robot_motor>& , int );
	int get_body_W(vector <Robot_body>& ,int);;
	int get_head_W(vector <Robot_head>&,int);
	int get_arm_W(vector <Robot_arms>&,int);
	int get_battery_W(vector <Robot_battery>&,int);

	int get_model_W(vector <Robot_model>&,int);
	//get parts index from model vector.
	int get_A_index(vector <Robot_model>&,int);
	int get_B_index(vector <Robot_model>&,int);
	int get_T_index(vector <Robot_model>&,int);
	int get_H_index(vector <Robot_model>&,int);
	int get_M_index(vector <Robot_model>&,int);


	void print_model_detail(vector <Robot_model>& info,vector <Robot_battery>& battery,vector <Robot_arms>& arm,vector <Robot_head>& head,vector <Robot_body>& body,vector <Robot_motor>& motor, int model_index);
							//model, battery,arm,head,body,motor,model_index
	

	void set_SA_sale(vector <Sale_ASSO>&, int index, int sales);

private:
	vector <Robot_arms> arm_vec;
	vector <Robot_body> body_vec;
	vector <Robot_head> head_vec;
	vector <Robot_battery> batt_vec;
	vector <Robot_motor> motor_vec;
	vector <Robot_model> model_vec;

	vector <Order> Order_vec;
	vector <Sale_ASSO> SA_vec;

};

#endif




