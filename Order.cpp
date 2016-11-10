#include "Order.h"


void Order::print_Order(vector <Order>& info){
int temp = info.size();
	cout <<endl<<endl<<"------List of Current Order------"<<endl;
	for(int i =0; i < temp; i++){
	
	cout<<"(Order #"<<i+1<<")"<<endl;
	cout<<"Order date: "<<info[i].get_date()
		<<"	Order number: "<<info[i].get_customer()<<"	Amount: "<< info[i].get_amount()<<endl
		<<"Sub_total: "<< info[i].get_sub_total()<<endl
		<< "Shiping cost: "<<info[i].get_shiping()<<endl
		<<"Tax: "<<info[i].get_tax()<<endl
			<<endl<<endl;
}
}

void Order::add_Order(Order order){
	Order_vec.push_back(order);
}

Order::Order(double _tax, double _shiping, double _price,int _model,int _amount, string _date, string _receipt,double sub_to,int _customer_index,int SA,string _name){
	tax = _tax;
	shiping = _shiping;
	total_price = _price;
	amount = _amount;
	date = _date;
	order_number = _receipt;
	sub_total = sub_to;
	customer_index= _customer_index;
	SA_index = SA;
	model_number = _model;
	Name =_name;
	}