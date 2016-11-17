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
using namespace std;

#ifndef Input_Dialog_H
#define Input_Dialog_H

class Input_Dialog{
public:

	Input_Dialog(){
	dialog = new Fl_Window(340,300,"Robot Parts");

	name = new Fl_Input(120,40,210,25,"Name:");

	serial = new Fl_Input(120,70,210,25,"Serial NUmber:");
	
	weight = new Fl_Input(120,100,210,25,"Weight:");
	
	cost = new Fl_Input(120,130,130,25,"Cost:");

	description = new Fl_Multiline_Input(120,160,210,75,"Description:");
	
	create = new Fl_Return_Button(145,240,120,25,"Create");

	cancel = new Fl_Button(270,240,60,25,"Cancel");

	dialog->end();
	dialog->set_non_modal();
	}
	void show(){dialog->show();}
	void hide() {dialog->hide();}
	string name(){return name->value();}
	string serial(){return serial->value();}
	string weight(){return weight->value();}
	string cost(){return cost->value();}
	string description(){return description->value();}
	
	/*string name(){return (*name).value();}
	string serial(){return (*serial).value();}
	string weight(){return (*weight).value();}
	string cost(){return (*cost).value();}
	string description(){return (*description).value();}
	*/
private:
	
	Fl_Window *dialog;
	Fl_Input *name;
	Fl_Input *serial;
	Fl_Input *weight;
	Fl_Input *cost;
	Fl_Input *description;
	Fl_Return_Button *create;
	Fl_Button *cancel;
};


#endif