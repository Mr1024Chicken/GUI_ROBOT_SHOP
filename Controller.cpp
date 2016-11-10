#include "Controller.h"


Robo Controller::add_arms( Robo info){
	string name;
	string serial;
	int price;
	int weight;
	string describe;
	int consume;
	int amount=0;

	cout <<"Name : "  ;
	cin.ignore();
	getline(cin,name);
	//cin >>name;
	cout <<"Serial Number: " ;
	//cin.ignore();
	getline(cin,serial);
	//cin >>serial;
	cout <<"Price: ";
	cin >> price;
	cout <<"Weight: ";
	cin >>weight;
	cout <<"Energy Consumtion: ";
	cin >>consume;
	
	while(amount !=1 && amount !=2){
	cout<<"Select 1 or 2 Arm: ";
	cin >> amount;
	}
	cout <<"Brief Desription: ";
	cin.ignore();
	getline(cin,describe);
	//cin >> describe;
	info.add_arm(Robot_arms(name,serial,price,weight,consume,describe,amount));
	return info;
		
}

Robo Controller::add_body(Robo info){
	string name;
	string serial;
	int price;
	int weight;
	string describe;
	int batt_slot;
	bool flag =true;

	cout <<"Name :   " ;
	cin.ignore();
	getline(cin,name);
	//cin >>name;
	cout <<"Serial Number:  ";
	//cin.ignore();
	getline(cin,serial);
	//cin >>serial;
	cout <<"Price:   ";
	cin >> price;
	cout <<"Weight:    ";
	cin >>weight;
	while(flag){
	cout <<"Battery Slot:   ";
	cin >>batt_slot;
	if(batt_slot < 4 && batt_slot > 0)flag =false;
	}
	cout <<"Brief Desription:";
	cin.ignore();
	getline(cin,describe);
	//cin >> describe;
	info.add_body(Robot_body(name,serial,price,weight,batt_slot,describe));


	return info;
}

Robo Controller::add_battery(Robo info){

	string name;
	string serial;
	int price;
	int weight;
	string describe;
	int energy;

	cout <<"Name : "  ;
	cin.ignore();
	getline(cin,name);
	//cin >>name;
	cout <<"Serial Number: " ;
	//cin.ignore();
	getline(cin,serial);
	//cin >>serial;
	cout <<"Price: ";
	cin >> price;
	cout <<"Weight: ";
	cin >>weight;
	cout <<"Energy Consumtion: ";
	cin >>energy;
	cout <<"Brief Desription: ";
	cin.ignore();
	getline(cin,describe);
	//cin >> describe;
	info.add_battery(Robot_battery(name,serial,price,weight,energy,describe));
	return info;
}

Robo Controller::add_head(Robo info){
	string name;
	string serial;
	int price;
	int weight;
	string describe;

	cout <<"Name : "  ;
	cin.ignore();
	getline(cin,name);
	//cin >>name;
	cout <<"Serial Number: " ;
	//cin.ignore();
	getline(cin,serial);
	//cin >>serial;
	cout <<"Price: ";
	cin >> price;
	cout <<"Weight: ";
	cin >>weight;
	cout <<"Brief Desription: ";
	cin.ignore();
	getline(cin,describe);
	//cin >> describe;
	info.add_head(Robot_head(name,serial,price,weight,describe));
	return info;
}

Robo Controller::add_motor(Robo info){
	string name;
	string serial;
	int price;
	int weight;
	string describe;
	int consume;
	int speed;

	cout <<"Name : "  ;
	cin.ignore();
	getline(cin,name);
	//cin >>name;
	cout <<"Serial Number: " ;
	//cin.ignore();
	getline(cin,serial);
	//cin >>serial;
	cout <<"Price: ";
	cin >> price;
	cout <<"Weight: ";
	cin >>weight;
	cout <<"Energy Consumtion: ";
	cin >>consume;
	cout <<"Max Speed:  ";
	cin >>speed;
	cout <<"Brief Desription: ";
	cin.ignore();
	getline(cin,describe);
	//cin >> describe;
	info.add_motor(Robot_motor(name,serial,price,weight,consume,speed,describe));
	return info;

}

Robo Controller::add_model(Robo info){

int arm=-1, torso=-1,battery=-1,motor=-1,head=-1,price=0,weight=0;
string name, model_number;
int size;
bool flag =true;
size = info.get_body().size();
info.print_body(info.get_body());
while(torso !=0 && flag){
cout << "Select a Torso fron this following list (**Press 0 to not include this part**):";
cin >> torso;
if(torso <=size)flag =false;
}
/*************************************************************/
info.print_head(info.get_head());
flag =true;
size =info.get_head().size();
while(head !=0 && flag){
cout << "Select a Head fron this following list (**Press 0 to not include this part**):";
cin >> head;
if(head <=size)flag =false;
}

/************************************************************/
info.print_motor(info.get_motor());
flag = true;
size = info.get_motor().size();
while(motor !=0 && flag){
cout << "Select a Motor fron this following list (**Press 0 to not include this part**):";
cin >> motor;
if(motor<=size)flag =false;
}

/************************************************************/
info.print_batt(info.get_batt());
flag = true;
size = info.get_batt().size();
while(battery !=0&& flag){
cout << "Select a Battery fron this following list (**Press 0 to not include this part**):";
cin >> battery;
if(battery <=size) flag = false;
}
/************************************************************/
info.print_arms(info.get_arms());
flag = true;
size = info.get_arms().size();
while(arm !=0 && flag){
cout << "Select a Arm fron this following list (**Press 0 to not include this part**):";
cin >>arm;
if(arm <=size) flag =false;
}

head--;
arm--;
torso--;
motor--;
battery--;

if(head >= 0) price += info.get_head_price(info.get_head(),head);
if(arm >= 0) price += info.get_arm_price(info.get_arms(),arm) * info.get_arm_amount(info.get_arms(),arm);
if(torso >= 0) price += info.get_body_price(info.get_body(), torso);
if(motor >= 0) price += info.get_motor_price(info.get_motor(), motor);
if (battery >=0 ) price+= (info.get_battery_price(info.get_batt(), battery)* info.get_battery_slot(info.get_body(),torso));

if(head >= 0) weight += info.get_head_W(info.get_head(),head);
if(arm >= 0) weight += info.get_arm_W(info.get_arms(),arm);
if(torso >= 0) weight += info.get_body_W(info.get_body(),torso);
if(motor >= 0) weight += info.get_motor_W(info.get_motor(),motor);
if(battery >= 0) weight += info.get_battery_W(info.get_batt(),battery);

cout << "Give this model a name: ";
cin.ignore();
getline(cin, name);
cout<< "Model number: ";
getline(cin,model_number);

cout<<"Set a price for this model ("<< "Parts total Cost:"<<price<<"):";
cin >>price;



if(head !=-1 && arm !=-1 && torso !=-1 && motor !=-1 && battery !=-1){
info.add_models(Robot_model(head,arm,torso,motor,battery,name,model_number,price,weight));
}
	return info;
}


Robo Controller::add_Order(Robo info){

int amount,robot_model=-1;
int SA;
int temp = info.get_order().size();
string date, order_number;
info.print_model(info.get_model());
bool flag =true;
while(robot_model < 0 || flag){
cout<<endl<< "Pick a Robot (model #) from our catalog: ";
cin >> robot_model;
if(robot_model <=temp+1) flag =false;
}

cout<< "Enter amount of purchase: ";
	cin >> amount;

cout<<"Order date: ";
cin.ignore();
getline(cin,date);
cout<<"Receipt Number: ";
getline(cin, order_number);

double sub_total = info.get_model_price(info.get_model(),robot_model-1);
double weight = info.get_model_W(info.get_model(), robot_model-1);


double tax = sub_total*.12; // 12% tax rate
double shiping = weight * 5; // 5$ per KG.
double price = tax + shiping + sub_total;
int customer_index=0;
string name;
cout <<"Customer Name: ";
//cin.ignore();
getline(cin,name);
cout<<"Sales Associate ID(Press 0 to skip): ";
cin>> SA;

int i;
int size = info.get_SA().size();
for(i=0; i<size ; i++){
	if( SA == info.get_SA_ID(info.get_SA(),i)){
	SA=i;
	}

}
if(SA >0){
info.set_SA_sale(info.get_SA(),SA,price);
}


info.add_Order(Order(tax,shiping,price,robot_model,amount,date,order_number,sub_total,customer_index,SA,name));
return info;
}

Robo Controller::Test_add(Robo info){
	info.add_arm(Robot_arms("Iron Thunder 2100(lvl)","IRN_0025",125,5,3,"Latest Iron Series Model!!!!",2));
	info.add_arm(Robot_arms("Ice Breaker","ICE-2369",200,2,4,"Freezzzing COOOOLLLLLL !!!!!",2));
	info.add_arm(Robot_arms("Fist of God","GOD-2500",550,7,6,"Gold Plated Fist Worthy For A GOD !!!!!",2));

	info.add_battery(Robot_battery("Lithium ION-2000","ION-2530",350,1,3,"Regular Battery"));
	info.add_battery(Robot_battery("Plutonium Charge","NCL-9999",5200,30,999999999,"Life-time Worth of Energy"));
	info.add_battery(Robot_battery("Universal Charge","UNI-6531",8000,15,999999999,"Constant Universe Re-newable Energy"));

	info.add_body(Robot_body("Knight-Ranger","KNR-5621",1400,40,3,"Vintage Knight Armor"));
	info.add_body(Robot_body("Steel-Man","STL-6912",1250,60,2,"Industrial Product"));
	info.add_body(Robot_body("Uncle_BOB","BOB-3030",200,25,1,"Cheap Alternative"));

	info.add_head(Robot_head("Killer Clown","CLW-6236",120,2,"Scary Clown Head"));
	info.add_head(Robot_head("Iron-Mask","IRN-1021",400,4,"Cool Iron Style Mask Head"));
	info.add_head(Robot_head("Guffy","GFF-6965",420,2,"Comedy Mask Head"));

	info.add_motor(Robot_motor("V-8 Diesel Power Stroke","V8D-2500",4000,60,1200,400,"Extreme Racing Engine"));
	info.add_motor(Robot_motor("2 Stroke 0.5L","2SK-6210",500,20,35,30,"Slow But Steady Import Engine"));
	info.add_motor(Robot_motor("Electric Power Engine","EPE-5200",8000,25,200,400,"Clean Energy Racing Engine 0 Noise"));


	return info;
}

Robo Controller::add_SA(Robo info){
	string _name;
	int _ID,sales=0;
cout <<"Sale Associate Name: ";
cin.ignore();
getline(cin,_name);
cout<<"Create an integer ID: ";
cin>>_ID;

info.add_SA(Sale_ASSO(_name,_ID,sales));

return info;
}

