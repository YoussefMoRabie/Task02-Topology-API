#pragma once
/**
 * @file Topology.h
 * @author Yousef Rabia (yousef.mohamed.rabia@gmail.com)
 * @brief Master Micro's task to test programming skills for summer internship applicants
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
#include"nlohmann/json.hpp"
/**
 * @brief use json from nlohmann
 * 
 */
using json = nlohmann::json;
using namespace std;


/**
 * @brief Abstract class with pure virtual function to acheive Polymorphism
 * 
 */
class Topology
{
protected:

	int size = 1;
	int topologies_counter = 0;

	json* topologies = new json[size];

public:
	virtual bool readJSON(string FileName) = 0;
	virtual bool writeJSON(string TopologyID) = 0;
	virtual json* queryTopologies() = 0;
	virtual bool  deleteTopology(string TopologyID) = 0;
	virtual void queryDevices(string TopologyID) = 0;
	virtual void queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID) = 0;
};

