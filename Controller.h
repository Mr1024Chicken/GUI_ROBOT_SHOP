#include <iostream>
#include <string>
#include <vector>

#include "Robo.h"
#include "Robot_arms.h"
#include "Robot_body.h"
#include "Robot_head.h"
#include "Robot_motor.h"
#include "Robot_battery.h"
#include "Robot_model.h"
#include "Order.h"

using namespace std;


#ifndef Controller_H
#define Controller_H

class Controller{
public:

	Robo add_arms(Robo);
	Robo add_body(Robo);
	Robo add_head(Robo);
	Robo add_battery(Robo);
	Robo add_motor(Robo);
	Robo add_model(Robo);
	Robo test_add_model(Robo);
	Robo add_Order(Robo);
	Robo add_SA(Robo);

	Robo Test_add(Robo);


};

class Controller_exception{};

#endif