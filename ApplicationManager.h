#pragma once
/**
 * @file ApplicationManager.h
 * @author Yousef Rabia (yousef.mohamed.rabia@gmail.com)
 * @brief Master Micro's task to test programming skills for summer internship applicants
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include "nlohmann/json.hpp"
#include "API.h"
#include "Testing.h"

/**
 * @brief use json from nlohmann
 * 
 */
using json = nlohmann::json;
using namespace std;

class ApplicationManager
{
private:
	/**
	 * @brief Test Obj
	 * 
	 */
	Testing test;
	/**
	 * @brief 	Child Obj
	 * 
	 */
	API test1;

	
	/**
	 * @brief Parent pointer to child class to acheive polymorphism
	 * 
	 */
	Topology* test2;

	
	/**
	 * @brief Variable represent user option
	 * 
	 */
	int Option ;

	/**
	 * @brief Variables to represent string entry
	 * 
	 */
	string user_option;
	string user_option2;
public:
/**
 * @brief Construct a new Application Manager object
 * 
 */
	ApplicationManager();
	/**
	 * @brief Execute function
	 * 
	 */
	void Execute();
};

