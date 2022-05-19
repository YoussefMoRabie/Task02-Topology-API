#pragma once
/**
 * @file Testing.h
 * @author Yousef Rabia (yousef.mohamed.rabia@gmail.com)
 * @brief Master Micro's task to test programming skills for summer internship applicants
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "API.h"
class Testing
{
private:
	API * api_test;
public:
/**
 * @brief Construct a new Testing object
 * 
 */
	Testing();
	/**
	 * @brief Destroy the Testing object
	 * 
	 */
	~Testing();
/**
 * @brief Non-existent file read test
 * 
 */
	void Test_Read_1();
	/**
	 * @brief Test reading an existing file
	 * 
	 */
	void Test_Read_2();
	/**
	 * @brief Test writing file
	 * 
	 */
	void Test_Write_1();
	/**
	 * @brief Test Query Topologies
	 * 
	 */
	void Test_queryTopologies();
	/**
	 * @brief Test Delete Topology
	 * 
	 */
	void Test_Delete_Topology();
	/**
	 * @brief Run All Tests
	 * 
	 */
	void Run_Tests();
};

