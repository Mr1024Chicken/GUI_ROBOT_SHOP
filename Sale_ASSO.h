#include <iostream>
#include <vector>

using namespace std;

#ifndef Sale_ASSO_H
#define Sale_ASSO_H

class Sale_ASSO{

public:
	Sale_ASSO(string new_name,string new_ID){
	name = new_name;
	ID = new_ID;
	total_sales =0;
	
	}

	string get_name(){return name;}
	string get_ID(){return ID;}
	int get_total_sale(){return total_sales;}
	
	void set_sale(int sales){
	total_sales += sales;
	}
private:
	string name;
	string ID;
	int total_sales;
	
	

};


#endif#include <iostream>
#include <vector>

using namespace std;

#ifndef Sale_ASSO_H
#define Sale_ASSO_H

class Sale_ASSO{

public:
	Sale_ASSO(string new_name,string new_ID){
	name = new_name;
	ID = new_ID;
	total_sales =0;
	
	}

	string get_name(){return name;}
	string get_ID(){return ID;}
	int get_total_sale(){return total_sales;}
	
	void set_sale(int sales){
	total_sales += sales;
	}
private:
	string name;
	string ID;
	int total_sales;
	
	

};


#endif#include <iostream>
#include <vector>

using namespace std;

#ifndef Sale_ASSO_H
#define Sale_ASSO_H

class Sale_ASSO{

public:
	Sale_ASSO(string new_name,string new_ID){
	name = new_name;
	ID = new_ID;
	total_sales =0;
	
	}

	string get_name(){return name;}
	string get_ID(){return ID;}
	int get_total_sale(){return total_sales;}
	
	void set_sale(int sales){
	total_sales += sales;
	}
private:
	string name;
	string ID;
	int total_sales;
	
	

};


#endif