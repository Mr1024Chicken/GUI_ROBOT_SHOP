#include <iostream>
using namespace std;

#ifndef Robot_model_H
#define Robot_model_H

class Robot_model{
public:
	Robot_model(int new_head,int new_arm,int new_torso,int new_motor,int new_battery,string new_name,string new_model,int new_price,int new_weight){
	head = new_head;
	arm = new_arm;
	torso = new_torso;
	motor = new_motor;
	battery = new_battery;
	name=new_name;
	model_number= new_model;
	price = new_price;
	weight= new_weight;
	}

	int get_head(){return head;}
	int get_arm(){return arm;}
	int get_torso(){return torso;}
	int get_motor(){return motor;}
	int get_battery(){return battery;}
	string get_name(){return name;}
	string get_model(){return model_number;}
	int get_price(){return price;}
	int get_weight(){return weight;}


private:
int head;
int arm;
int torso;
int motor;
int battery;
int weight;

string name;
string model_number;
int price;

};

#endif