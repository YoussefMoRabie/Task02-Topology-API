#pragma once

#include <iostream>
#include <string>
#include "nlohmann/json.hpp"
#include "API.h"

using json = nlohmann::json;
using namespace std;

class ApplicationManager
{
private:
	//Child Class
	API test1;

	//Parent pointer to child class to acheive polymorphism
	Topology* test2;

	//Variable represent user option
	int Option ;

	//Variable to represent string entry
	string user_option;
	string user_option2;
public:
	ApplicationManager();
	void Execute();
};

