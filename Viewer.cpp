#include "Viewer.h"

void Viewer::menu(Robo Roger, Controller Lord){

bool flag = true;
//int choice=0;
//int temp=0;
//int parts =0;

while(flag){
	int choice=0;
int temp=0;
int parts =0;
	
	cout <<endl<<"Main Menu"<<endl<<"******************"<<endl;
	cout <<"(Press 1) To Create."<<endl
		<<"(Press 2) To View Reports."<<endl
		<<"(Press 7) To Auto input Parts(1st)."<<endl
		
		<<"(Press 9) To Quit>"<<endl;
	cin >> choice;


	if(choice == 1){
	while(temp != 9 ){
		parts=0;
		cout <<endl<<"Create"<<endl<<"******************"<<endl;
		cout <<"(Press 1) To create Robot Parts."<<endl
			<<"(Press 2) To Create New Robot Model."<<endl
			<<"(Press 3) To Create Order."<<endl
			<<"(Press 4) To create Sales Associate (Needed To make Order"<<endl
			<<"(Press 9) Quit To Main Menu."<<endl;
		cin >>temp;

		if(temp ==1){
			while(parts !=9){
		cout <<endl<<"Robot Parts"<<endl<<"******************"<<endl;
		cout <<"(Press 1) To Create Torso."<<endl
			<<"(Press 2) To Create Arms."<< endl
			<<"(Press 3) To Create Battery."<<endl
			<<"(Press 4) To Create Head."<<endl
			<<"(Press 5) To Create Motor."<<endl
			<<"(Press 9) Quit To Create Menu."<<endl;
		cin >> parts;
		if(parts ==1){Roger = Lord.add_body(Roger);}
		if(parts ==2){Roger = Lord.add_arms(Roger);}
		if(parts ==3){Roger = Lord.add_battery(Roger);}
		if(parts ==4){Roger = Lord.add_head(Roger);}
		if(parts ==5){Roger = Lord.add_motor(Roger);}
				}
			}
		
		if(temp==2){ Roger = Lord.add_model(Roger);}
		
	if(temp ==3) {Roger = Lord.add_Order(Roger);}
	if(temp==4){Roger = Lord.add_SA(Roger);}

		}
	}


	if(choice ==2){
		while(temp !=9){
			parts=0;
	cout <<endl<<"Reports"<<endl<<"******************"<<endl;
	cout<< "(Press 1) To View Parts"<<endl
		<<"(Press 2) To View Robot Models"<<endl
		<<"(Press 3) To View Orders."<<endl
		<<"(Press 4) To View Sale ASSociate."<<endl
		<<"(Press 9) Quit To Main Menu."<<endl;
		cin >> temp;

		if(temp ==1){
			while(parts !=9){
				cout<<endl<<"Parts"<<endl<<"******************"<<endl;
			cout<<"(Press 1) To View Torso."<<endl
				<<"(Press 2) To View Arm." <<endl
				<<"(Press 3) To View Motor."<<endl
				<<"(Press 4) To View Battery."<<endl
				<<"(Press 5) To View Head."<<endl
				<<"(Press 9) Quit To View Menu"<<endl;
			cin >>parts;

			if(parts ==1){Roger.print_body(Roger.get_body());}
			if(parts ==2){Roger.print_arms(Roger.get_arms());}
			if(parts ==3){Roger.print_motor(Roger.get_motor());}
			if(parts==4){Roger.print_batt(Roger.get_batt());}
			if(parts ==5){Roger.print_head(Roger.get_head());}
			}
			}
		if(temp ==2){Roger.print_model(Roger.get_model());
		int flag;
		bool triger = true;
		int size = Roger.get_model().size();
		while(triger){
			cout<<endl<<"Select the model # to view in detail(press 0 to return)";
		cin>>flag;
		
		if(flag <=size && flag !=0) {Roger.print_model_detail(Roger.get_model(),Roger.get_batt(),Roger.get_arms(),Roger.get_head(),Roger.get_body(),Roger.get_motor(),flag-1);}
		
		else triger =false;
		}
		}
		
		if(temp ==3){ Roger.print_Order(Roger.get_order(),Roger.get_SA());
		bool flag = true;
		int index=-1;
		
		int size = Roger.get_order().size();
		while(flag){
		

		cout<<endl<<"Select the model # to view in detail(press 0 to return)";
		cin >> index;
		
		if(index <= size && index !=0){
		int target = Roger.get_model_index(Roger.get_order(),index-1);
		cout << target;
				Roger.print_model_detail(Roger.get_model(),Roger.get_batt(),Roger.get_arms(),Roger.get_head(),Roger.get_body(),Roger.get_motor(),target-1);
		}
		else if( index == 0) flag =false;
		
		}
			
		
		}

		
		
		if(temp ==4){Roger.print_SA(Roger.get_SA());}

		}
	}
	if(choice ==7){Roger = Lord.Test_add(Roger);}
	


	if(choice == 9) flag = false;
}

}