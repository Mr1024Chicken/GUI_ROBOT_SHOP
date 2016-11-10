#include <iostream>
#include <vector>
#include <string>

using namespace std;


#ifndef Order_H
#define Order_H

class Order{

public:
	/*
	Order(int,int,int,int,int,int,string,string);*/
	//	 sub_total,amount,shiping,total_price,model_number, customer_index, date , order_number
	Order(double _tax, double _shiping, double _price,int _model,int _amount, string _date, string _receipt,double,int,int,string );


	string get_order(){return order_number;}
	string get_date(){return date;}

	int get_sub_total(){return sub_total;}
	int get_tax(){return tax;}
	int get_shiping(){return shiping;}
	int get_amount(){return amount;}
	//int get_customer(){return customer_index;}
	int get_total(){return total_price;}
	int get_SA(){ return SA_index;}
	int get_customer(){return customer_index;}
	int get_model_index(){return model_number;}
	string get_name(){return Name;}

	vector <Order> get_Order(){return Order_vec;}

		void add_Order(Order info);
		void print_Order(vector <Order>& info);
private:
	string order_number;
	double sub_total;
	string date;
	int amount;
	double shiping;
	double tax; //12% of subtotal
	double total_price;
	int customer_index;
	int SA_index;
	int model_number; //model index
	vector <Order> Order_vec;
	string Name;

};

#endif