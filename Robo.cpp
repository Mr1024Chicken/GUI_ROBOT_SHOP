#include "Robo.h"

void Robo::add_arm(Robot_arms rob){
	arm_vec.push_back(rob);
}

void Robo::add_body(Robot_body bod){
	body_vec.push_back(bod);
}

void Robo::add_head(Robot_head head){
	head_vec.push_back(head);
}

void Robo::add_battery(Robot_battery batt){
	batt_vec.push_back(batt);
}

void Robo::add_motor(Robot_motor moto){
	motor_vec.push_back(moto);
}

void Robo::add_models(Robot_model moda){
	model_vec.push_back(moda);
}

void Robo::add_Order(Order order){
	Order_vec.push_back(order);
}

void Robo::add_SA(Sale_ASSO SA){
	SA_vec.push_back(SA);
}



//
//void Robo::add_SA(Sale_ASSO SA){
//	SA_vec.push_back(SA);
//}


void Robo::print_arms(vector <Robot_arms>& info){
	int temp = info.size();
	cout <<endl<<endl<<"------List of available ARMS------"<<endl;
	for(int i =0; i < temp; i++){
	
		cout<<"(Model #"<<i+1<<")"<<endl;
		cout<<"Name: "<<info[i].get_name()<<setw(30)<<"Serial_number: "<< info[i].get_serial()<<endl
			<<"Price($): "<<info[i].get_price()<<setw(30)<<"Weight(Kg): "<<info[i].get_weight()<<endl
			<<"Energy Consumtion(KwH): "<<info[i].get_consume()<<setw(20)<<"Description: "<< info[i].get_describe()
			<<endl<<endl;

		
	}
}

void Robo::print_body(vector <Robot_body>& info){
	
	int temp = info.size();
	cout <<endl<<endl<<"------List of available TORSO------"<<endl;
	for(int i =0; i < temp; i++){
	
	cout<<"(Model #"<<i+1<<")"<<endl;
		cout<<"Name: "<<info[i].get_name()<<setw(30)<<"Serial_number: "<< info[i].get_serial()<<endl
			<<"Price($): "<<info[i].get_price()<<setw(30)<<"Weight(Kg): "<<info[i].get_weight()<<endl
			<<"Battery Slot: "<<info[i].get_batt()<<setw(30)<<"Description: "<< info[i].get_describe()
			<<endl<<endl;
	
}

}

void Robo::print_head(vector <Robot_head>& info){


	int temp = info.size();
	cout <<endl<<endl<<"------List of available HEAD------"<<endl;
	for(int i =0; i < temp; i++){
	
		cout<<"(Model #"<<i+1<<")"<<endl;
		cout<<"Name: "<<info[i].get_name()<< setw(30) <<"Serial_number: "<< info[i].get_serial()<<endl
			<<"Price: "<<info[i].get_price()<< setw(30) <<"Weight: "<<info[i].get_weight()<<endl
			<<"Description: "<< info[i].get_describe()
			<<endl<<endl;

}


}

void Robo::print_batt(vector <Robot_battery>& info){

	int temp = info.size();
	cout <<endl<<endl<<"------List of available BATTERY------"<<endl;
	for(int i =0; i < temp; i++){
	
		cout<<"(Model #"<<i+1<<")"<<endl;
		cout<<"Name: "<<info[i].get_name()<<setw(20)<<"Serial_number: "<< info[i].get_serial()<<endl
			<<"Price: "<<info[i].get_price()<<setw(25)<<"Weight: "<<info[i].get_weight()<<endl
			<<"Energy (KWH): "<<info[i].get_energy()<<setw(25)<<"Description: "<< info[i].get_describe()
			<<endl<<endl;
}
}

void Robo::print_motor(vector <Robot_motor>& info)
{

		int temp = info.size();
	cout <<endl<<endl<<"------List of available MOTOR------"<<endl;
	for(int i =0; i < temp; i++){
	
	cout<<"(Model #"<<i+1<<")"<<endl;
		cout<<"Name: "<<info[i].get_name()<<setw(25)<<"Serial_number: "<< info[i].get_serial()<<endl
			<<"Price: "<<info[i].get_price()<<setw(35)<<"Weight: "<<info[i].get_weight()<<endl
			<<"Energy Consumtion: "<<info[i].get_consume()<<setw(25)<<"Speed: "<<info[i].get_speed()<<endl
			<<"Description: "<< info[i].get_describe()
			<<endl<<endl;
}
}

void Robo::print_model(vector <Robot_model>& moda){

	int i, temp = moda.size();
	for (i=0;i<temp ;i++){
		cout<<endl<<endl<<"------List of available Model------"<<endl;
		cout <<"(Model #"<<i+1<<")"<<endl;
		cout <<"Model Name: "<< moda[i].get_name()<<setw(20)
		<<"Model number: "<<moda[i].get_model()<<setw(20)
		<<"Model Price($): "<< moda[i].get_price()<<endl;
		
		if(moda[i].get_head() == -1 ) cout <<"No Head"<<endl;
		else cout << "Head model: " << moda[i].get_head() +1<<endl;

		if(moda[i].get_torso() == -1) cout <<"No Torso"<<endl;
		else cout<< "Torso model:  "<< moda[i].get_torso()+1<<endl;

		if(moda[i].get_arm() == -1) cout <<"No Arm"<<endl;
		else cout<<"Arm model:  "<< moda[i].get_arm()+1<<endl;

		if(moda[i].get_battery() == -1) cout << "No Battery"<<endl;
		else cout<<"Battery model:  "<< moda[i].get_battery()+1<<endl;

		if(moda[i].get_motor() == -1) cout <<"No Motor"<<endl;
		else cout<<"Motor model:  "<< moda[i].get_motor()+1<<endl;

		cout<<endl;
	}
}

void Robo::print_Order(vector <Order>& info,vector <Sale_ASSO>& SA){

	int temp = info.size();
	int index;
	cout <<endl<<endl<<"------List of Current Order------"<<endl;
	for(int i =0; i < temp; i++){
	
	cout<<"(Order #"<<i+1<<")"<<endl;
	cout<<"Order date: "<<info[i].get_date()<<setw(20)<<"Order number: "<<info[i].get_customer()+1<<endl
		<<"Amount: "<< info[i].get_amount()<<setw(20)<<"Receipt Number: "<< info[i].get_order()<<endl
		<<"Sub_total: "<< info[i].get_sub_total()<<endl
		<< "Shiping cost: "<<info[i].get_shiping()<<endl
		<<"Tax: "<<info[i].get_tax()<<endl
		<<"Total Cost: "<<info[i].get_total()<< " x "<< info[i].get_amount()<<" = "<<info[i].get_amount()*info[i].get_total()
		<<endl;
	index = info[i].get_SA();
	cout<<"Customer Name: "<<info[i].get_name()<<endl;
	if(index >0){
		cout << "Sale Associate: "<<SA[index].get_name()<<endl<<endl;}
}
}

void Robo::print_model_detail(vector <Robot_model>& info,vector <Robot_battery>& battery,vector <Robot_arms>& arm,vector <Robot_head>& head,vector <Robot_body>& body,vector <Robot_motor>& motor, int model_index){

	int _head = info[model_index].get_head();
	int _body = info[model_index].get_torso();
	int _battery = info[model_index].get_battery();
	int _motor = info[model_index].get_motor();
	int arms = info[model_index].get_arm();

	cout <<endl<<"(Model #"<<model_index+1<<")"<<endl;
	cout <<"Model Name: "<< info[model_index].get_name()<<setw(20)
		<<"Model number: "<<info[model_index].get_model()<<setw(20)
		<<"Model Price($): "<< info[model_index].get_price()<<endl;
	cout<<"************************Arms************************"<<endl;
	cout<<"Name: "<<arm[arms].get_name()<<setw(30)<<"Serial_number: "<< arm[arms].get_serial()<<endl
			<<"Price($): "<<arm[arms].get_price()<<setw(30)<<"Weight(Kg): "<<arm[arms].get_weight()<<endl
			<<"Energy Consumtion(KwH): "<<arm[arms].get_consume()<<setw(20)<<"Description: "<< arm[arms].get_describe()
			<<endl;

	cout<<"************************Torso************************"<<endl;
	cout<<"Name: "<<body[_body].get_name()<<setw(30)<<"Serial_number: "<< body[_body].get_serial()<<endl
			<<"Price($): "<<body[_body].get_price()<<setw(30)<<"Weight(Kg): "<<body[_body].get_weight()<<endl
			<<"Battery Slot: "<<body[_body].get_batt()<<setw(30)<<"Description: "<< body[_body].get_describe()
			<<endl;

	cout<<"************************Motor************************"<<endl;
	cout<<"Name: "<<motor[_motor].get_name()<<setw(25)<<"Serial_number: "<< motor[_motor].get_serial()<<endl
			<<"Price: "<<motor[_motor].get_price()<<setw(35)<<"Weight: "<<motor[_motor].get_weight()<<endl
			<<"Energy Consumtion: "<<motor[_motor].get_consume()<<setw(25)<<"Speed: "<<motor[_motor].get_speed()<<endl
			<<"Description: "<< motor[_motor].get_describe()
			<<endl;

	cout<<"************************Head************************"<<endl;
	cout<<"Name: "<<head[_head].get_name()<< setw(30) <<"Serial_number: "<< head[_head].get_serial()<<endl
			<<"Price: "<<head[_head].get_price()<< setw(30) <<"Weight: "<<head[_head].get_weight()<<endl
			<<"Description: "<<head[_head].get_describe()
			<<endl;

	cout<<"************************Battery************************"<<endl;
		cout<<"Name: "<<battery[_battery].get_name()<<setw(20)<<"Serial_number: "<< battery[_battery].get_serial()<<endl
			<<"Price: "<<battery[_battery].get_price()<<setw(25)<<"Weight: "<<battery[_battery].get_weight()<<endl
			<<"Energy (KWH): "<<battery[_battery].get_energy()<<setw(25)<<"Description: "<< battery[_battery].get_describe()
			<<endl;
}

void Robo::print_SA(vector <Sale_ASSO>& info){
	int size = info.size();
	int i;
	for(i=0;i<size;i++){
		cout<<endl<<"Sale Associate #"<< i+1<<endl;
		cout<< "Name: "<<info[i].get_name()<<endl
			<<"ID: "<<info[i].get_ID()<<endl;
			//<<"Total Sales: "<<info[i].get_total_sale()<<endl;
	}
}



int Robo::get_motor_price(vector <Robot_motor>& motor,int index){
 
	return motor[index].get_price();
}

int Robo::get_head_price(vector <Robot_head>& head,int index){
	return head[index].get_price();
}

int Robo::get_body_price(vector <Robot_body>& body, int index){
	return body[index].get_price();
}

int Robo::get_arm_price(vector <Robot_arms>& arm, int index){
	return arm[index].get_price();
}

int Robo::get_battery_price(vector <Robot_battery>& battery, int index){
	return battery[index].get_price();
}


int Robo::get_battery_slot(vector <Robot_body>& body, int index){
	return body[index].get_batt();
}

int Robo::get_arm_amount(vector <Robot_arms>& arm,int index){
	return arm[index].get_amount();
}

int Robo::get_SA_ID(vector <Sale_ASSO>& info, int index){
	return info[index].get_ID();
}

string Robo::get_SA_name(vector <Sale_ASSO>& info, int index){
	return info[index].get_name();
}

//int Robo::get_SA_ID(vector <Sale_ASSO>& SA){}

/*GET WEIGHT */





int Robo::get_motor_W(vector <Robot_motor>& motor, int index){
	return motor[index].get_weight();
}

int Robo::get_body_W(vector <Robot_body>& body, int index){
	return body[index].get_weight();
}

int Robo::get_head_W(vector <Robot_head>& head, int index){
	return head[index].get_weight();
}

int Robo::get_arm_W(vector <Robot_arms>& arm, int index){
	return arm[index].get_weight();
}

int Robo::get_battery_W(vector <Robot_battery>& battery, int index){
	return battery[index].get_weight();
}

/*Get model parts index*/




int Robo::get_A_index( vector <Robot_model>& info, int index){
	return info[index].get_arm();
}

int Robo::get_B_index( vector <Robot_model>& info, int index){
	return info[index].get_battery();
}
int Robo::get_T_index( vector <Robot_model>& info, int index){
	return info[index].get_torso();
}

int Robo::get_H_index( vector <Robot_model>& info, int index){
	return info[index].get_head();
}

int Robo::get_M_index( vector <Robot_model>& info, int index){
	return info[index].get_motor();
}


int Robo::get_model_price(vector <Robot_model>& info, int index){
	return info[index].get_price();
}

int Robo::get_model_W(vector <Robot_model>& info, int index){
	return info[index].get_weight();
}

void Robo::set_SA_sale(vector <Sale_ASSO>& info, int index, int sales){

	info[index].set_sale(sales);
}

int Robo::get_model_index(vector <Order>& info, int index){
	return info[index].get_model_index();
}


