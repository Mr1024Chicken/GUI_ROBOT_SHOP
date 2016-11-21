#include "Input_Dialog.h"

Controller king;
Robo champ;
int type;

	Fl_Window *dialog=0;
	Fl_Input *name;
	Fl_Input *serial;
	Fl_Input *weight;
	Fl_Input *cost;
	Fl_Input *description;
	Fl_Input *consumption;
	Fl_Input *amount;
	Fl_Input *slot;

	Fl_Window *win2;
	Fl_Input *speed;
	Fl_Scrollbar *scrollbar;
	


	Fl_Input *power;
	vector <Robot_motor> motorola = champ.get_motor();

	int Input_Dialog::model_size(){return champ.get_model().size();}


	void close(){
		dialog->hide();
	}
	void show(){
		dialog->show();
	}
	void cancel_CB(Fl_Widget *w, void *p){
	close();
	}
	int Input_Dialog::arm_size(){
		return champ.get_arms().size();
	}
	int Input_Dialog::body_size(){
		return champ.get_body().size();
	}
	int Input_Dialog::head_size(){
		return champ.get_head().size();
	}
	int Input_Dialog::motor_size(){
		return champ.get_motor().size();
	}
	int Input_Dialog::battery_size(){
		return champ.get_batt().size();
	}


	void create_armCB(){
		string name_ = name->value();
		string serial_ = serial->value();
		string describe_ = description->value();
		string _weight = weight->value();
		string _cost = cost->value();
		
		string con = consumption->value();

		
		int weight_ = stoi(_weight);
		
		int cost_ = stoi(_cost);
		int consume = stoi(con);
		
		champ = king.add_arm(name_,serial_,describe_,cost_,weight_,consume,champ);
	}
	void create_headCB(){
		string name_ = name->value();
		string serial_ = serial->value();
		string describe_ = description->value();
		string _weight = weight->value();
		string _cost = cost->value();
		
		int cost_ = stoi(_cost);
		int W = stoi(_weight);

		champ = king.add_head(name_, serial_,cost_,W,describe_,champ);
	}
	void create_torsoCB(){
		string name_ = name->value();
		string serial_ = serial->value();
		string describe_ = description->value();
		string _weight = weight->value();
		string _cost = cost->value();
		string _slot = slot->value();

		int temp_cost = stoi(_cost);
		int temp_weight = stoi(_weight);
		int temp_slot = stoi(_slot);

		champ = king.add_torso(name_, serial_, describe_,temp_cost,temp_weight,temp_slot,champ);

	}

	void create_batteryCB(){
	string name_ = name->value();
		string serial_ = serial->value();
		string describe_ = description->value();
		string _weight = weight->value();
		string _cost = cost->value();
		string _power = power->value();

		int temp_cost = stoi(_cost);
		int temp_weight = stoi(_weight);
		int temp_power = stoi(_power);
		champ = king.add_battery(name_, serial_, describe_, temp_cost,temp_weight,temp_power,champ);
	}
	void create_motorCB(){
	string name_ = name->value();
		string serial_ = serial->value();
		string describe_ = description->value();
		string _weight = weight->value();
		string _cost = cost->value();
		string _consume = consumption->value();
		string _speed = speed->value();

		int temp_cost = stoi(_cost);
		int temp_weight = stoi(_weight);
		int temp_consume = stoi(_consume);
		int temp_speed = stoi(_speed);

		champ = king.add_motor(name_,serial_,describe_, temp_cost, temp_weight, temp_speed, temp_consume , champ);

	}

	void Input_Dialog::view_arm(){
		champ.print_arms(champ.get_arms()); 
	}

	void Input_Dialog::view_head(){
		champ.print_head(champ.get_head());
	}

	void Input_Dialog::view_torso(){
		champ.print_body(champ.get_body());
	}

	void Input_Dialog::view_battery(){
		champ.print_batt(champ.get_batt());
	}

	void Input_Dialog::view_motor(){
		champ.print_motor(champ.get_motor());
	}

	Robo Input_Dialog::get_Robo(){return champ;}

	void create_CB(Fl_Widget *w, void *p){
		if(type == 1){
			cout<<"HI"<<endl;
		create_armCB();
		}
		else if(type ==2 ){
		create_headCB();
		}
		else if (type == 3){
		create_torsoCB();
		}
		else if (type ==4){
		create_motorCB();
		}
		else if (type ==5 ){
		create_batteryCB();
		}
		close();
	}

Robo Input_Dialog::arm_dialog(int x,Controller Mo, Robo robie){
	

	type = x;
	const char *label;
	if(x == 1){
		label= "Arm";
	}
	else if (x ==2){
	label = "Head";
	}
	else if(x ==3){
		label = "Torso";
	}
	else if(x ==4){
		label = "Motor";
	}
	else if(x == 5){
	label = "Battery";
	}
	dialog = new Fl_Window(370,430,label);

	name = new Fl_Input(120,40,210,25,"Name:");

	serial = new Fl_Input(120,70,210,25,"Serial NUmber:");
	
	weight = new Fl_Input(120,100,210,25,"Weight:");
	
	cost = new Fl_Input(120,130,210,25,"Cost:");

	if(type != 2 && type != 3 && type!=5){
	consumption = new Fl_Input(120,160,210,25,"Energy Consume");
	}
	
	if(type ==3 ){
	slot = new Fl_Input(120,220,210,25,"Battery Slot");
	}
	if(type == 4){
	speed = new Fl_Input(120,250,210,25,"Max Speed");
	}
	if(type == 5){
	power = new Fl_Input(120,280,210,25,"Power(Wat)");
	}
	description = new Fl_Multiline_Input(120,310,210,75,"Description:");
	
	create = new Fl_Return_Button(145,400,120,25,"Create");

	cancel = new Fl_Button(270,400,60,25,"Cancel");

	create->callback((Fl_Callback *) create_CB,0);
	cancel->callback((Fl_Callback *) cancel_CB,0);
	dialog->end();
	dialog->set_non_modal();
	show();

	return champ;
}

//void print_body(vector <Robot_body>& info){
//	
//	int temp = info.size();
//	cout <<endl<<endl<<"------List of available TORSO------"<<endl;
//	for(int i =0; i < temp; i++){
//	
//	cout<<"(Model #"<<i+1<<")"<<endl;
//		cout<<"Name: "<<info[i].get_name()<<setw(30)<<"Serial_number: "<< info[i].get_serial()<<endl
//			<<"Price($): "<<info[i].get_price()<<setw(30)<<"Weight(Kg): "<<info[i].get_weight()<<endl
//			<<"Battery Slot: "<<info[i].get_batt()<<setw(30)<<"Description: "<< info[i].get_describe()
//			<<endl<<endl;
//	
//}

void Scrollbar_CB(Fl_Widget*, void *) {
	if(scrollbar->value()){
	cout<<"1";
	}
}
	Fl_Output *pname, *pserial, *pprice, *pweight, *penergy, *pdescribe, *pslot, *pamount, *pspeed, *pconsume , *Iarm,*Ihead,*Imotor,*Ibattery,*Itorso;
	Fl_Multiline_Output *desc;
void Input_Dialog::print_stuff(int x, int type){
	int y = type;
	const char *label;

	if(y == 1){
		label= "Arm";
	}
	else if (y ==2){
	label = "Head";
	}
	else if(y ==4){
		label = "Torso";
	}
	else if(y ==3){
		label = "Motor";
	}
	else if(y == 5){
	label = "Battery";
	}

	win2 = new Fl_Window(400,600,label);
	string temp_name;
	const char *char_name;

	if (type ==1){

	temp_name = champ.get_arms()[x].get_name();
	char_name = temp_name.c_str();
	pname = new Fl_Output(80,20,100,20,"Name");
	pname->value(char_name);

	temp_name = champ.get_arms()[x].get_serial();
	char_name = temp_name.c_str();
	pserial = new Fl_Output(80,50,100,20,"Serial");
	pserial->value(char_name);


	temp_name = champ.get_arms()[x].get_describe();
	char_name = temp_name.c_str();
	pdescribe = new Fl_Multiline_Output(80,500,300,75,"Description");
	pdescribe->value(char_name);

	int price = champ.get_arms()[x].get_price();
	temp_name = to_string(static_cast <long long>(price));
	char_name = temp_name.c_str();
	pprice = new Fl_Output(80,80,100,20,"Price");
	pprice->value(char_name);
	
	int weight = champ.get_arms()[x].get_weight();
	temp_name = to_string(static_cast <long long> (weight));
	char_name = temp_name.c_str();
	pweight = new Fl_Output(80,110,100,20,"Weight");
	pweight->value(char_name);

	int amount = champ.get_arms()[x].get_amount();
	temp_name = to_string(static_cast <long long> (amount));
	char_name = temp_name.c_str();
	pamount = new Fl_Output(80,140,100,20,"Arms #");
	pamount->value(char_name);
	
	}

	if (type ==2){

	temp_name = champ.get_head()[x].get_name();
	char_name = temp_name.c_str();
	pname = new Fl_Output(80,20,100,20,"Name");
	pname->value(char_name);

	temp_name = champ.get_head()[x].get_serial();
	char_name = temp_name.c_str();
	pserial = new Fl_Output(80,50,100,20,"Serial");
	pserial->value(char_name);


	temp_name = champ.get_head()[x].get_describe();
	char_name = temp_name.c_str();
	pdescribe = new Fl_Multiline_Output(80,500,300,75,"Description");
	pdescribe->value(char_name);

	int price = champ.get_head()[x].get_price();
	temp_name = to_string(static_cast <long long>(price));
	char_name = temp_name.c_str();
	pprice = new Fl_Output(80,80,100,20,"Price");
	pprice->value(char_name);
	
	int weight = champ.get_head()[x].get_weight();
	temp_name = to_string(static_cast <long long> (weight));
	char_name = temp_name.c_str();
	pweight = new Fl_Output(80,110,100,20,"Weight");
	pweight->value(char_name);
	}


		if (type ==3){
	temp_name = champ.get_motor()[x].get_name();
	char_name = temp_name.c_str();
	pname = new Fl_Output(80,20,100,20,"Name");
	pname->value(char_name);

	temp_name = champ.get_motor()[x].get_serial();
	char_name = temp_name.c_str();
	pserial = new Fl_Output(80,50,100,20,"Serial");
	pserial->value(char_name);


	temp_name = champ.get_motor()[x].get_describe();
	char_name = temp_name.c_str();
	pdescribe = new Fl_Multiline_Output(80,500,300,75,"Description");
	pdescribe->value(char_name);

	int price = champ.get_motor()[x].get_price();
	temp_name = to_string(static_cast <long long>(price));
	char_name = temp_name.c_str();
	pprice = new Fl_Output(80,80,100,20,"Price");
	pprice->value(char_name);
	
	int weight = champ.get_motor()[x].get_weight();
	temp_name = to_string(static_cast <long long> (weight));
	char_name = temp_name.c_str();
	pweight = new Fl_Output(80,110,100,20,"Weight");
	pweight->value(char_name);

	int speed = champ.get_motor()[x].get_speed();
	temp_name = to_string(static_cast <long long> (speed));
	char_name = temp_name.c_str();
	pspeed = new Fl_Output(80,140,100,20,"Speed");
	pspeed->value(char_name);

	int consume = champ.get_motor()[x].get_consume();
	temp_name = to_string(static_cast <long long > (consume));
	char_name = temp_name.c_str();
	pconsume = new Fl_Output(80,170,100,20,"Consume");
	pconsume->value(char_name);
	}

	if (type ==4){
	temp_name = champ.get_body()[x].get_name();
	char_name = temp_name.c_str();
	pname = new Fl_Output(80,20,100,20,"Name");
	pname->value(char_name);

	temp_name = champ.get_body()[x].get_serial();
	char_name = temp_name.c_str();
	pserial = new Fl_Output(80,50,100,20,"Serial");
	pserial->value(char_name);


	temp_name = champ.get_body()[x].get_describe();
	char_name = temp_name.c_str();
	pdescribe = new Fl_Multiline_Output(80,500,300,75,"Description");
	pdescribe->value(char_name);

	int price = champ.get_body()[x].get_price();
	temp_name = to_string(static_cast <long long>(price));
	char_name = temp_name.c_str();
	pprice = new Fl_Output(80,80,100,20,"Price");
	pprice->value(char_name);
	
	int weight = champ.get_body()[x].get_weight();
	temp_name = to_string(static_cast <long long> (weight));
	char_name = temp_name.c_str();
	pweight = new Fl_Output(80,110,100,20,"Weight");
	pweight->value(char_name);

	int consume = champ.get_body()[x].get_batt();
	temp_name = to_string(static_cast <long long > (consume));
	char_name = temp_name.c_str();
	pslot = new Fl_Output(80,170,100,20,"Battery slot");
	pslot->value(char_name);
	}
	if (type ==5){
	temp_name = champ.get_batt()[x].get_name();
	char_name = temp_name.c_str();
	pname = new Fl_Output(80,20,100,20,"Name");
	pname->value(char_name);

	temp_name = champ.get_batt()[x].get_serial();
	char_name = temp_name.c_str();
	pserial = new Fl_Output(80,50,100,20,"Serial");
	pserial->value(char_name);


	temp_name = champ.get_batt()[x].get_describe();
	char_name = temp_name.c_str();
	pdescribe = new Fl_Multiline_Output(80,500,300,75,"Description");
	pdescribe->value(char_name);

	int price = champ.get_batt()[x].get_price();
	temp_name = to_string(static_cast <long long>(price));
	char_name = temp_name.c_str();
	pprice = new Fl_Output(80,80,100,20,"Price");
	pprice->value(char_name);
	
	int weight = champ.get_batt()[x].get_weight();
	temp_name = to_string(static_cast <long long> (weight));
	char_name = temp_name.c_str();
	pweight = new Fl_Output(80,110,100,20,"Weight");
	pweight->value(char_name);

	int consume = champ.get_batt()[x].get_energy();
	temp_name = to_string(static_cast <long long > (consume));
	char_name = temp_name.c_str();
	penergy = new Fl_Output(80,170,100,20,"Power(Watt)");
	penergy->value(char_name);
	}


	win2->end();
	win2->show();
	
}
	Fl_Window *model_dialog;

void Input_Dialog::print_model(int x){
		string temp_name;
	const char *char_name;

	model_dialog = new Fl_Window(500,500,"Robot Model");
	temp_name = champ.get_model()[x].get_name();
	char_name = temp_name.c_str();
	pname = new Fl_Output(80,20,100,20,"Name");
	pname->value(char_name);

	temp_name = champ.get_model()[x].get_model();
	char_name = temp_name.c_str();
	pserial = new Fl_Output(80,50,100,20,"Serial");
	pserial->value(char_name);

	int price = champ.get_model()[x].get_price();
	temp_name = to_string(static_cast <long long>(price));
	char_name = temp_name.c_str();
	pprice = new Fl_Output(80,80,100,20,"Price");
	pprice->value(char_name);
	
	int weight = champ.get_model()[x].get_weight();
	temp_name = to_string(static_cast <long long> (weight));
	char_name = temp_name.c_str();
	pweight = new Fl_Output(80,110,100,20,"Weight");
	pweight->value(char_name);

	temp_name = champ.get_model()[x].get_describe();
	char_name = temp_name.c_str();
	pdescribe = new Fl_Multiline_Output(80,400,300,75,"Description");
	pdescribe->value(char_name);

	int armI , headI, motorI, torsoI,batteryI;

	armI = champ.get_model()[x].get_arm();
	temp_name = to_string(static_cast <long long> (armI));
	char_name = temp_name.c_str();
	Iarm = new Fl_Output(80,140,100,20,"Arm #");
	Iarm->value(char_name);
	
	headI = champ.get_model()[x].get_head();
	temp_name = to_string(static_cast <long long> (headI));
	char_name = temp_name.c_str();
	Ihead = new Fl_Output(80,170,100,20,"Head #");
	Ihead->value(char_name);

	torsoI = champ.get_model()[x].get_torso() + 1;
	temp_name = to_string(static_cast <long long> (torsoI));
	char_name = temp_name.c_str();
	Itorso = new Fl_Output(80,200,100,20,"Torso #");
	Itorso->value(char_name);

	batteryI = champ.get_model()[x].get_battery();
	temp_name = to_string(static_cast <long long> (batteryI));
	char_name = temp_name.c_str();
	Ibattery = new Fl_Output(80,230,100,20,"Battery #");
	Ibattery->value(char_name);

	motorI = champ.get_model()[x].get_motor();
	temp_name = to_string(static_cast <long long> (motorI));
	char_name = temp_name.c_str();
	Imotor = new Fl_Output(80,260,100,20,"Motor #");
	Imotor->value(char_name);

	model_dialog->end();
	model_dialog->show();

}


Fl_Window *make_model;
Fl_Scrollbar *arm_, *head_, *motor_, *battery_, *body_;
Fl_Button *armB, *headB, *motorB, *batteryB, *bodyB, *create_model;
Fl_Output *arm_out, *head_out, *motor_out, *battery_out, *body_out, *price_out;
Input_Dialog talk;
Fl_Input *model_name, *model_weight, *model_price,*model_serial;
Fl_Multiline_Input  *model_describe;
	//char s[20];
	////bscroll->value();
	//
	//sprintf(s,"%d",scroll->value());
	//out->value(s);

void arm_output_CB(Fl_Widget *w, void *p){
	char s[20];
	sprintf(s,"%d",arm_->value());
	arm_out->value(s);
}

void head_output_CB(Fl_Widget *w, void *p){
	char s[20];
	sprintf(s,"%d",head_->value());
	head_out->value(s);
}

void motor_output_CB(Fl_Widget *w, void *p){
	char s[20];
	sprintf(s,"%d",motor_->value());
	motor_out->value(s);
}
void price_output_CB(Fl_Widget *w, void *p){
	int temp=0;
	if(champ.get_arms().size() !=0 && champ.get_batt().size() !=0 && champ.get_body().size() !=0 && champ.get_head().size() !=0 && champ.get_motor().size()!=0){
		
		 if(arm_->value() !=0 ){temp += champ.get_arms()[arm_->value()-1].get_price() ;}
		 if( head_->value() !=0){temp += champ.get_head()[head_->value()-1].get_price();}
		 if(battery_->value()!=0){temp += champ.get_batt()[battery_->value()-1].get_price(); }
		 if(body_->value()!=0){temp += champ.get_body()[body_->value()-1].get_price(); }
		 if(motor_->value() !=0){temp +=  champ.get_motor()[motor_->value()-1].get_price();}
	
	string temp_price = to_string(static_cast <long long> (temp));
	const char *s = temp_price.c_str();
	price_out->value(s);
	
	}
}
void body_output_CB(Fl_Widget *w, void *p){
	char s[20];
	sprintf(s,"%d",body_->value());
	body_out->value(s);
}
void battery_output_CB(Fl_Widget *w, void *p){
	char s[20];
	sprintf(s,"%d",battery_->value());
	battery_out->value(s);
}



void show_armCB(Fl_Widget *w, void *p){
	//win2->hide();
	if(champ.get_arms().size() !=0 && arm_->value() !=0){
	talk.print_stuff(arm_->value()-1,1);
	}
}

void show_headCB(Fl_Widget *w, void *p){
	//win2->hide();
	if(champ.get_head().size() !=0 && head_->value() !=0){
	talk.print_stuff(head_->value()-1,2);
	}
}
void show_motorCB(Fl_Widget *w, void *p){
	if(champ.get_motor().size() !=0 && motor_->value() !=0){
	talk.print_stuff(motor_->value()-1,3);
	}
}
void show_bodyCB(Fl_Widget *w, void *p){
	if(champ.get_body().size() !=0 && body_->value() !=0){
	talk.print_stuff(body_->value()-1,4);
	}
}

void show_batteryCB(Fl_Widget *w, void *p){
	if(champ.get_batt().size() !=0 && battery_->value() !=0){
	talk.print_stuff(battery_->value()-1,5);
	}
}

void create_modelCB(){
	string name_ = model_name->value();
	string price_ = model_price->value();
	string describe_ = model_describe->value();
	string serial_ = model_serial->value();

	int cost = stoi(price_);
	int weight = champ.get_arms()[arm_->value()-1].get_weight() + champ.get_batt()[battery_->value()-1].get_weight() + champ.get_body()[body_->value()-1].get_weight() + champ.get_head()[head_->value()-1].get_weight() + champ.get_motor()[motor_->value()-1].get_weight();
	int head = head_->value();
	int arm = arm_->value();
	int motor = motor_->value();
	int body = body_->value();
	int battery = battery_->value();

	champ = king.add_model(name_,serial_,describe_,arm, head, body, motor  ,battery , cost,weight,champ);
	make_model->hide();
}

void Input_Dialog::Model(){

	make_model = new Fl_Window(400,600,"Create Model");
	arm_ = new Fl_Scrollbar(30,30,200,15,"Arm");
	arm_out = new Fl_Output(110,60,50,20);
	armB = new Fl_Button(280,30,110,30,"Show Arm");
	arm_->type(FL_HORIZONTAL);
	arm_->slider_size(.1);
	arm_->bounds(0,champ.get_arms().size());
	arm_->value(0);
	arm_->step(1);
	arm_->callback(arm_output_CB, (void*)&arm_);
	armB->callback((Fl_Callback *) show_armCB);

	head_ = new Fl_Scrollbar(30,100,200,15,"Head");
	head_out = new Fl_Output(110,130,50,20);
	headB = new Fl_Button(280,100,110,30,"Show Head");
	head_->type(FL_HORIZONTAL);
	head_->slider_size(.1);
	head_->bounds(0,champ.get_head().size());
	head_->value(0);
	head_->step(1);
	head_->callback(head_output_CB, (void*)&head_);
	headB->callback((Fl_Callback *) show_headCB);

	motor_ = new Fl_Scrollbar(30,170,200,15,"Motor");
	motor_out = new Fl_Output(110,200,50,20);
	motorB = new Fl_Button(280,170,110,30,"Show Motor");
	motor_->type(FL_HORIZONTAL);
	motor_->slider_size(.1);
	motor_->bounds(0,champ.get_motor().size());
	motor_->value(0);
	motor_->step(1);
	motor_->callback(motor_output_CB, (void*)&motor_);
	motorB->callback((Fl_Callback *) show_motorCB);

	battery_ = new Fl_Scrollbar(30,240,200,15,"Battery");
	battery_out = new Fl_Output(110,270,50,20);
	batteryB = new Fl_Button(280,240,110,30,"Show Batttery");
	battery_->type(FL_HORIZONTAL);
	battery_->slider_size(.1);
	battery_->bounds(0,champ.get_batt().size());
	battery_->value(0);
	battery_->step(1);
	battery_->callback(battery_output_CB, (void*)&battery_);
	batteryB->callback((Fl_Callback *) show_batteryCB);

	body_ = new Fl_Scrollbar(30,310,200,15,"Body");
	body_out = new Fl_Output(110,340,50,20);
	bodyB = new Fl_Button(280,310,110,30,"Show Body");
	body_->type(FL_HORIZONTAL);
	body_->slider_size(.1);
	body_->bounds(0,champ.get_body().size());
	body_->value(0);
	body_->step(1);
	body_->callback(body_output_CB, (void*)&body_);
	bodyB->callback((Fl_Callback *) show_bodyCB);
	
	model_name = new Fl_Input(70,380,150,20,"Name");
	model_price = new Fl_Input(70,420,150,20,"Price");
	price_out = new Fl_Output(300,420,50,20,"Fix");
	model_serial = new Fl_Input (70,460,150,20,"Serial");
	model_describe = new Fl_Multiline_Input(70,500,150,75,"Describe");
	price_out->callback((Fl_Callback *) price_output_CB);

	create_model = new Fl_Button(280,550,100,40,"Create Model");
	create_model->callback((Fl_Callback *) create_modelCB);

	make_model->end();
	make_model->show();
}


void Input_Dialog::Test_add(){

	champ = king.add_arm("Iron Thunder 2100(lvl)","IRN_0025","Latest Iron Series Model!!!!",125,5,3,champ);
	champ = king.add_arm("Ice Breaker","ICE-2369","Freezzzing COOOOLLLLLL !!!!!",200,2,4,champ);
	champ = king.add_arm("Fist of God","GOD-2500","Gold Plated Fist Worthy For A GOD !!!!!",550,7,6,champ);

	champ = king.add_head("Killer Clown","CLW-6236",120,2,"Scary Clown Head",champ);
	champ = king.add_head("Iron-Mask","IRN-1021",400,4,"Cool Iron Style Mask Head",champ);
	champ = king.add_head("Guffy","GFF-6965",420,2,"Comedy Mask Head",champ);

	champ = king.add_torso("Knight-Ranger","KNR-5621","Vintage Knight Armor",1400,40,3,champ);
	champ = king.add_torso("Steel-Man","STL-6912","Industrial Product",1250,60,2,champ);
	champ = king.add_torso("Uncle_BOB","BOB-3030","Cheap Alternative",200,25,1,champ);

	champ = king.add_battery("Lithium ION-2000","ION-2530","Regular Battery",350,1,3,champ);
	champ = king.add_battery("Plutonium Charge","NCL-9999","Life-time Worth of Energy",5200,30,999999999,champ);
	champ = king.add_battery("Universal Charge","UNI-6531","Constant Universe Re-newable Energy",8000,15,999999999,champ);
	
	champ = king.add_motor("Electric Power Engine","EPE-5200","Clean Energy Racing Engine 0 Noise",8000,25,200,400 , champ);
	champ = king.add_motor("2 Stroke 0.5L","2SK-6210","Slow But Steady Import Engine",500,20,35,30, champ);
	champ = king.add_motor("V-8 Diesel Power Stroke","V8D-2500","Extreme Racing Engine",4000,60,1200,400, champ);
}

Fl_Window *customer_dialog;
Fl_Input *customer_name,*customer_phone;
Fl_Button *create_customer;

void create_customerCB(){
	string name_ = customer_name->value();
	string phone_ = customer_phone->value();

	champ = king.add_customer(name_,phone_,champ);
	customer_dialog->hide();
}

void Input_Dialog::Customer(){
	customer_dialog = new Fl_Window(500,200, "Customer Info");
	customer_name = new Fl_Input(200,50,250,30,"Name");
	customer_phone = new Fl_Input(200,100,250,30,"Phone Number");

	create_customer = new Fl_Button(350,150,130,30,"Create Customer");
	create_customer->callback((Fl_Callback *) create_customerCB);

	customer_dialog->end();
	customer_dialog->show();

}
Fl_Window *sa;
Fl_Input *SA_name, *SA_ID;
Fl_Button *create_SA;

void create_SACB(){
	string name_ = SA_name->value();
	string ID_ = SA_ID->value();

	champ = king.add_SA(name_,ID_,champ);
	sa->hide();
}

void Input_Dialog::SA(){

	sa = new Fl_Window(500,200,"Sales Associate");
	SA_name = new Fl_Input(200,50,250,30,"Name");
	SA_ID = new Fl_Input(200,100,250,30," ID");

	create_SA =new Fl_Button(350,150,130,30,"Create");
	create_SA->callback((Fl_Callback *) create_SACB);
	sa->end();
	sa->show();
}
Fl_Output *N_SA, *ID_SA, *total;

void Input_Dialog::view_SA(){

	sa = new Fl_Window(500,400,"Sales Associate");
	N_SA = new Fl_Output(200,50,250,30,"Name");
	ID_SA = new Fl_Output(200,100,250,30," ID");
	total = new Fl_Output(200,150,250,30,"Sales $");

}