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
#include <FL/Fl_Pack.H>
#include <FL/Fl_PNG_Image.H>

#ifndef Tool_Bar_H
#define Tool_Bar_H
const int bsize= 36;
class Tool_Bar: public Fl_Pack{
public:
	Tool_Bar(int X, int Y, int W, int H):Fl_Pack(X,Y,W,H){
	type(Fl_Pack::HORIZONTAL);
	box(FL_UP_FRAME);
	spacing (4);
	end();
	}
	void ADDButton (const char* name, Fl_PNG_Image *img=0,Fl_Callback *cb=0, void *data=0){
	
	begin();
	Fl_Button *b = new Fl_Button(0,0,bsize,bsize);
	b->box(FL_UP_BOX);
	b->clear_visible_focus();
	if(name) b->tooltip(name);
	if(img) b->image(img);
	if(cb) b->callback(cb,data);
	end();
	}
};

#endif#include <iostream>
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
#include <FL/Fl_Pack.H>
#include <FL/Fl_PNG_Image.H>

#ifndef Tool_Bar_H
#define Tool_Bar_H
const int bsize= 36;
class Tool_Bar: public Fl_Pack{
public:
	Tool_Bar(int X, int Y, int W, int H):Fl_Pack(X,Y,W,H){
	type(Fl_Pack::HORIZONTAL);
	box(FL_UP_FRAME);
	spacing (4);
	end();
	}
	void ADDButton (const char* name, Fl_PNG_Image *img=0,Fl_Callback *cb=0, void *data=0){
	
	begin();
	Fl_Button *b = new Fl_Button(0,0,bsize,bsize);
	b->box(FL_UP_BOX);
	b->clear_visible_focus();
	if(name) b->tooltip(name);
	if(img) b->image(img);
	if(cb) b->callback(cb,data);
	end();
	}
};

#endif