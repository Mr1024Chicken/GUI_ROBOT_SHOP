#include "Viewer.h"
#include <fstream>
#include <cctype>

#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Choice.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Scrollbar.H>

Fl_Scrollbar *scroll,*model_scroll;
Fl_Window *win;

#include "Input_Dialog.h"

int type_G=0;

Robo mark;
Controller whip;
Input_Dialog input;
Fl_Window *win_slide;
Fl_Menu_Bar *menu;
Input_Dialog *input_dialog;
Fl_Output *out,*model_out;
Fl_Button *show ,*show_model;
Fl_Window *new_win;
Fl_Scrollbar *model_scroll1;


int head_size = mark.get_head().size()+1;

void scroll_barCB(int);
void V_torso_CB(Fl_Widget* w, void *p);  
void V_battery_CB(Fl_Widget* w, void *p);
void V_motor_CB(Fl_Widget* w, void *p);

void cancel_armCB(Fl_Widget *w, void *p);
void menu_armCB(Fl_Widget *w, void *p);
void create_armCB(Fl_Widget *w, void *p);
void V_arms_CB(Fl_Widget* w, void *p);

void create_headCB(Fl_Widget *w, void *p);
void cancel_headCB(Fl_Widget *w, void *p);
void menu_headCB(Fl_Widget *w, void *p);
void V_head_CB(Fl_Widget* w, void *p);

void create_torsoCB(Fl_Widget *w, void *p);
void create_battery(Fl_Widget *w, void *p);
void create_motorCB(Fl_Widget *w, void *p);
void showCB(Fl_Widget *w, void *p);
void arm_CB(){
	cout<<"hi";
	input.arm_dialog(1,whip,mark);
	mark = input.get_Robo();
}

void head_CB(){
	input.arm_dialog(2,whip,mark);
	mark = input.get_Robo();
}
void body_CB(){
	input.arm_dialog(3,whip,mark);
	mark = input.get_Robo();
}

void motor_CB(){

	mark = input.arm_dialog(4,whip,mark);
	mark = input.get_Robo();
	
}

void battery_CB(){
	mark=input.arm_dialog(5,whip,mark);
	
}

void view_armCB(){
	//input.view_arm();
	type_G=1;
	scroll_barCB(1);
}

void view_headCB(){
	//input.view_head();
	type_G=2;
	scroll_barCB(2);
	
}

void view_torsoCB(){
	//input.view_torso();
	type_G=4;
	scroll_barCB(4);
	
	
}
void view_batteryCB(){
	//input.view_battery();
	type_G=5;
	scroll_barCB(5);
	
}
void view_motorCB(){
	//input.view_motor();
	//input.print_stuff(0,4);
	type_G = 3;
	scroll_barCB(3);

}


void scrollbar_CB(Fl_Widget *w, void *p)
{
	char s[20];
	//bscroll->value();
	
	sprintf(s,"%d",scroll->value());
	out->value(s);
	
}

void scroll_barCB(int type){
	type = type_G;
	const char *label;
	int size=0;
	bool flag = true;
	if(type_G == 1){
		label = "Arm #";
	size = input.arm_size();
	if (size ==0 ){flag = false;}
	}
	else if(type_G ==2 ){
		label = "Head #";
	size= input.head_size();
	if (size ==0 ){flag = false;}
	}
	else if (type_G ==3){
		label = "Motor #";
	size = input.motor_size();
	if (size ==0 ){flag = false;}
	}
	else if (type_G == 4){
		label = "Body #";

	size = input.body_size();
	if (size ==0 ){flag = false;}
	}
	else if (type_G == 5){
		label = "Battery #";
	size = input.battery_size();
	if (size ==0 ){flag = false;}
	}

	win_slide = new Fl_Window(500,300,label);
	scroll = new Fl_Scrollbar(200,30,200,30,label);
	scroll->type(FL_HORIZONTAL);
	scroll->slider_size(.1);
	scroll->bounds(0,size);
	scroll->value(0);
	scroll->step(1);
	scroll->callback(scrollbar_CB, (void*)&out);
	out = new Fl_Output(200,70,50,20,label);
	show = new Fl_Button(400,260,100,40,"Show Parts");
	if(flag){
	show->callback((Fl_Callback *) showCB,0);
	}
	show->show();
	win_slide->end();
	win_slide->show();
	
}
void menu_scrollbarCB(Fl_Widget *w, void *p){
	char s[20];
	//bscroll->value();
	
	sprintf(s,"%d",model_scroll1->value());
	model_out->value(s);
}
void show_modelCB(){
	int temp =model_scroll1->value()-1;
	if(model_scroll1->value() >0){
	input.print_model(temp);
	}
}

void model_scrollCB(){
	int size = input.model_size();

	new_win = new Fl_Window(500,300,"Robot Model");
	model_scroll1 = new Fl_Scrollbar(200,30,200,30,"Model");
	model_out = new Fl_Output(200,70,50,20,"Model");

	model_scroll1->type(FL_HORIZONTAL);
	model_scroll1->slider_size(.1);
	model_scroll1->bounds(0,size);
	model_scroll1->value(0);
	model_scroll1->step(1);
	model_scroll1->callback(menu_scrollbarCB, (void*)&model_out);
	
	show_model = new Fl_Button(400,260,100,40,"Show Model");
	show_model->callback((Fl_Callback *) show_modelCB);

	

	new_win->end();
	new_win->show();

}
Fl_Window *customer_dialog2;
void SA_index(){
	char s[20];
	sprintf(s,"%d",model_scroll->value());
	model_out->value(s);
}
void SACB(){
	int temp =model_scroll1->value()-1;
	input.view_SA(temp);
}

void CICB(){
	int temp = model_scroll1->value()-1;
	input.view_Customer(temp-1);
}
void SA_scrollCB(){
	int size = input.SA_size();
	customer_dialog2 = new Fl_Window(500,400,"Customer Info");
	model_scroll1 = new Fl_Scrollbar(200,30,200,30,"Customer");
	model_scroll1->type(FL_HORIZONTAL);
	model_scroll1->slider_size(.1);
	model_scroll1->bounds(0,size);
	model_scroll1->value(0);
	model_scroll1->step(1);
	model_scroll1->callback(menu_scrollbarCB, (void*)&model_scroll1);
	model_out = new Fl_Output(200,70,50,20,"SA");
	show_model = new Fl_Button(350,260,100,40,"Show SA");
	show_model->callback((Fl_Callback *) SACB,0);
	customer_dialog2->end();
	customer_dialog2->show();
}


void test_caseCB(){
	input.Test_add();
}

void make_modelCB(Fl_Widget *w, void *p){
	input.Model();
}

void make_customerCB(Fl_Widget *w,void *p){
	input.Customer();
}

void make_SACB(Fl_Widget *w,void *p){
	input.SA();
}

void customer_scrollCB(Fl_Widget *w,void *p){
	int size = input.customer_size();
	customer_dialog2 = new Fl_Window(500,400,"Customer Info");
	model_scroll1 = new Fl_Scrollbar(200,30,200,30,"Customer");
	model_scroll1->type(FL_HORIZONTAL);
	model_scroll1->slider_size(.1);
	model_scroll1->bounds(0,size);
	model_scroll1->value(0);
	model_scroll1->step(1);
	model_scroll1->callback(menu_scrollbarCB, (void*)&model_scroll1);
	model_out = new Fl_Output(200,70,50,20,"Customer");
	show_model = new Fl_Button(350,260,100,40,"Show SA");
	show_model->callback((Fl_Callback *) CICB,0);
	customer_dialog2->end();
	customer_dialog2->show();
}
void make_orderCB(Fl_Widget *w,void *p){
	input.make_order();
}
void show_orderCC(){
	int temp = model_scroll1->value();
	input.view_Order(temp-1);

}
void order_scrollCB(){

	int size = input.order_size();
	customer_dialog2 = new Fl_Window(500,400,"Order");
	model_scroll1 = new Fl_Scrollbar(200,30,200,30,"Order #");
	model_scroll1->type(FL_HORIZONTAL);
	model_scroll1->slider_size(.1);
	model_scroll1->bounds(0,size);
	model_scroll1->value(0);
	model_scroll1->step(1);
	model_scroll1->callback(menu_scrollbarCB, (void*)&model_scroll1);
	model_out = new Fl_Output(200,70,50,20,"Order");
	show_model = new Fl_Button(350,260,100,40,"Show Order");
	show_model->callback((Fl_Callback *) show_orderCC,0);
	customer_dialog2->end();
	customer_dialog2->show();
}

int Viewer::user_menu(){
	

	const int x = 800, y= 600;

	win = new Fl_Window(x,y,"$$-Robot Shop-$$");
	menu = new Fl_Menu_Bar(0,0,x,30);


	Fl_Menu_Item menu_items[] = {

		{"View Parts",0,0,0 ,FL_SUBMENU},
		{"Torso",0,(Fl_Callback *) view_torsoCB},
		{"Arms",0,(Fl_Callback *) view_armCB},
		{"Motor",0,(Fl_Callback *) view_motorCB},
		{"Head",0,(Fl_Callback *) view_headCB},
		{"Battery",0, (Fl_Callback *) view_batteryCB},
		{"Robot Model",0 ,(Fl_Callback *) model_scrollCB},
		{"Customer",0,(Fl_Callback *) customer_scrollCB},
		{"SA",0,(Fl_Callback *) SA_scrollCB},
		{"Orders",0,(Fl_Callback *) order_scrollCB},
		{0},
		{"Create",0,0,0, FL_SUBMENU},
		//{"Parts",0 ,0,0,FL_SUBMENU},
		{"Robot Arms",0,(Fl_Callback *) arm_CB},
		{"Robot Motor",0,(Fl_Callback *) motor_CB},
		{"Robot Head", 0 , (Fl_Callback *) head_CB},
		{"Robot Battery",0,(Fl_Callback *) battery_CB},
		{"Robot Torso",0, (Fl_Callback *) body_CB},
		{"Robot Model",0, (Fl_Callback *) make_modelCB},
		{"Customer",0, (Fl_Callback *) make_customerCB},
		{"SA",0,(Fl_Callback *) make_SACB},
		{"Order",0,(Fl_Callback *) make_orderCB},
		{"Test_case",0,(Fl_Callback *) test_caseCB},
		{0},
		{0}
	};

	
	
	//win->callback(create_partCB);
	menu->menu(menu_items);
	//Fl_Box *box = new Fl_Box(20,40,300,100,"NOOOOOOO!!!!!!");

	
	cout <<"done"<<endl;
	win->end();
	win->show();

	return Fl::run();

}
void showCB(Fl_Widget *w, void *p){
	int temp =scroll->value()-1;
	input.print_stuff(temp,type_G);
}



void V_torso_CB(Fl_Widget* w, void *p){

Fl_Button *b= (Fl_Button*)w;
mark.print_body(mark.get_body());
}







void V_head_CB(Fl_Widget* w, void *p){

Fl_Button *b= (Fl_Button*)w;
mark.print_head(mark.get_head());
}

void V_battery_CB(Fl_Widget* w, void *p){

Fl_Button *b= (Fl_Button*)w;
mark.print_batt(mark.get_batt());
}

void V_motor_CB(Fl_Widget* w, void *p){

Fl_Button *b= (Fl_Button*)w;
mark.print_motor(mark.get_motor());
}




/*******************ARM-FUNCT********************************/
void V_arms_CB(Fl_Widget* w, void *p){

Fl_Button *b= (Fl_Button*)w;
mark.print_arms(mark.get_arms());
}

//void cancel_armCB(Fl_Widget*  w, void* p){
//		input_arm->hide();	
//}
//
//void create_armCB(Fl_Widget *w, void *p){
//
//	input_arm->hide();
//	int temp_cost = stoi(input_arm->set_cost());
//	int temp_conssume= stoi (input_arm->set_consumption());
//	int temp_weight = stoi(input_arm->set_weight());
//	int temp_amount = stoi(input_arm->set_amount());
//	mark = whip.add_arm(input_arm->set_name(),input_arm->set_serial(),input_arm->set_description(),temp_cost,temp_weight,temp_conssume,temp_amount,mark);
//}
//
//void menu_armCB(Fl_Widget *w, void *p){
//	input_arm->show();
//}
/***********************************************************/


































/*void Viewer::menu(Robo Roger, Controller Lord){

bool flag = true;
//int choice=0;
//int temp=0;
//int parts =0;

//while(flag){
//	int choice=0;
//int temp=0;
//int parts =0;
//	
//	cout <<endl<<"Main Menu"<<endl<<"******************"<<endl;
//	cout <<"(Press 1) To Create."<<endl
//		<<"(Press 2) To View Reports."<<endl
//		<<"(Press 7) To Auto input Parts(1st)."<<endl
//		
//		<<"(Press 9) To Quit>"<<endl;
//	cin >> choice;
//
//
//	if(choice == 1){
//	while(temp != 9 ){
//		parts=0;
//		cout <<endl<<"Create"<<endl<<"******************"<<endl;
//		cout <<"(Press 1) To create Robot Parts."<<endl
//			<<"(Press 2) To Create New Robot Model."<<endl
//			<<"(Press 3) To Create Order."<<endl
//			<<"(Press 4) To create Sales Associate (Needed To make Order"<<endl
//			<<"(Press 9) Quit To Main Menu."<<endl;
//		cin >>temp;
//
//		if(temp ==1){
//			while(parts !=9){
//		cout <<endl<<"Robot Parts"<<endl<<"******************"<<endl;
//		cout <<"(Press 1) To Create Torso."<<endl
//			<<"(Press 2) To Create Arms."<< endl
//			<<"(Press 3) To Create Battery."<<endl
//			<<"(Press 4) To Create Head."<<endl
//			<<"(Press 5) To Create Motor."<<endl
//			<<"(Press 9) Quit To Create Menu."<<endl;
//		cin >> parts;
//		if(parts ==1){Roger = Lord.add_body(Roger);}
//		if(parts ==2){Roger = Lord.add_arms(Roger);}
//		if(parts ==3){Roger = Lord.add_battery(Roger);}
//		if(parts ==4){Roger = Lord.add_head(Roger);}
//		if(parts ==5){Roger = Lord.add_motor(Roger);}
//				}
//			}
//		
//		if(temp==2){ Roger = Lord.add_model(Roger);}
//		
//	if(temp ==3) {Roger = Lord.add_Order(Roger);}
//	if(temp==4){Roger = Lord.add_SA(Roger);}
//
//		}
//	}
//
//
//	if(choice ==2){
//		while(temp !=9){
//			parts=0;
//	cout <<endl<<"Reports"<<endl<<"******************"<<endl;
//	cout<< "(Press 1) To View Parts"<<endl
//		<<"(Press 2) To View Robot Models"<<endl
//		<<"(Press 3) To View Orders."<<endl
//		<<"(Press 4) To View Sale ASSociate."<<endl
//		<<"(Press 9) Quit To Main Menu."<<endl;
//		cin >> temp;
//
//		if(temp ==1){
//			while(parts !=9){
//				cout<<endl<<"Parts"<<endl<<"******************"<<endl;
//			cout<<"(Press 1) To View Torso."<<endl
//				<<"(Press 2) To View Arm." <<endl
//				<<"(Press 3) To View Motor."<<endl
//				<<"(Press 4) To View Battery."<<endl
//				<<"(Press 5) To View Head."<<endl
//				<<"(Press 9) Quit To View Menu"<<endl;
//			cin >>parts;
//
//			if(parts ==1){Roger.print_body(Roger.get_body());}
//			if(parts ==2){Roger.print_arms(Roger.get_arms());}
//			if(parts ==3){Roger.print_motor(Roger.get_motor());}
//			if(parts==4){Roger.print_batt(Roger.get_batt());}
//			if(parts ==5){Roger.print_head(Roger.get_head());}
//			}
//			}
//		if(temp ==2){Roger.print_model(Roger.get_model());
//		int flag;
//		bool triger = true;
//		int size = Roger.get_model().size();
//		while(triger){
//			cout<<endl<<"Select the model # to view in detail(press 0 to return)";
//		cin>>flag;
//		
//		if(flag <=size && flag !=0) {Roger.print_model_detail(Roger.get_model(),Roger.get_batt(),Roger.get_arms(),Roger.get_head(),Roger.get_body(),Roger.get_motor(),flag-1);}
//		
//		else triger =false;
//		}
//		}
//		
//		if(temp ==3){ Roger.print_Order(Roger.get_order(),Roger.get_SA());
//		bool flag = true;
//		int index=-1;
//		
//		int size = Roger.get_order().size();
//		while(flag){
//		
//
//		cout<<endl<<"Select the model # to view in detail(press 0 to return)";
//		cin >> index;
//		
//		if(index <= size && index !=0){
//		int target = Roger.get_model_index(Roger.get_order(),index-1);
//		cout << target;
//				Roger.print_model_detail(Roger.get_model(),Roger.get_batt(),Roger.get_arms(),Roger.get_head(),Roger.get_body(),Roger.get_motor(),target-1);
//		}
//		else if( index == 0) flag =false;
//		
//		}
//			
//		
//		}
//
//		
//		
//		if(temp ==4){Roger.print_SA(Roger.get_SA());}
//
//		}
//	}
//	if(choice ==7){Roger = Lord.Test_add(Roger);}
//	
//
//
//	if(choice == 9) flag = false;
//}



}*/