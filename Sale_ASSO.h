#include <iostream>
#include <vector>

using namespace std;

#ifndef Sale_ASSO_H
#define Sale_ASSO_H

class Sale_ASSO{

public:
	Sale_ASSO(string new_name,int new_ID, int new_total){
	name = new_name;
	ID = new_ID;
	total_sales = new_total;
	}

	string get_name(){return name;}
	int get_ID(){return ID;}
	int get_total_sale(){return total_sales;}
	
	void set_sale(int sales){
	total_sales += sales;
	}
private:
	string name;
	int ID;
	int total_sales;
	
	

};


#endif