#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Choice.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Scrollbar.H>
#include "Controller.h"
#include "Robo.h"
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Text_Buffer.H>

#include "Robot_motor.h"

using namespace std;

#ifndef Input_Dialog_H
#define Input_Dialog_H

class Input_Dialog{
public:
	Robo get_Robo();
	
	void print_stuff(int,int);
	Robo arm_dialog(int, Controller,Robo);
	void print_model(int x);
	void Model();

	void SA();
	void view_SA();
	void Customer();
	void view_Customer();

	void view_arm();
	void view_head();
	void view_torso();
	void view_battery();
	void view_motor();

	int head_size();
	int motor_size();
	int arm_size();
	int battery_size();
	int body_size();
	int model_size();

	void Test_add();

private:
	

	Fl_Return_Button *create;
	Fl_Button *cancel;
};


#endif