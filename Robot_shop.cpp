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

#include "Viewer.h"

using namespace std;

	Robo ob;
	Controller contr;
	Viewer hawk;
	

Fl_Window *win;

void CLoseCB(Fl_Widget*  w, void* p){
	Fl_Window *win = (Fl_Window *)w ;
	if(fl_choice("Are You Sure?","Random",fl_no,fl_yes)==2){
		win->hide();
	}
}

void ButtonCB(Fl_Widget* w, void *p){

Fl_Button *b= (Fl_Button*)w;
ob.print_body(ob.get_body());
}

void Button2CB(Fl_Widget* w, void *p){

Fl_Button *b= (Fl_Button*)w;
ob = contr.Test_add(ob);
}


int main(){

	//hawk.menu(ob,contr);

	const int x = 800, y= 600;

	Fl_Window *win = new Fl_Window(x,y,"$$-Robot Shop-$$");

	Fl_Button *button= new Fl_Button(0,90,140,50,"view torso!");
	Fl_Button *button2 = new Fl_Button(0,40,140,50,"add parts!");

	win->callback(CLoseCB);

	//Fl_Box *box = new Fl_Box(20,40,300,100,"NOOOOOOO!!!!!!");
	button->callback(ButtonCB,"view torso!");


	button2->callback(Button2CB,"add parts!");
	
	
	
	cout <<endl<<"done"<<endl;
	win->end();
	win->show();

	return Fl::run();
}


