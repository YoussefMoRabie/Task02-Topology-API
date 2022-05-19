/**
 * @file API.h
 * @author Yousef Rabia (yousef.mohamed.rabia@gmail.com)
 * @brief Master Micro's task to test programming skills for summer internship applicants
 * @details  functionality to access, manage and store device topologies.
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
#include "Topology.h"


using namespace std;
/**
 * @brief use json from nlohmann
 * 
 */
using json = nlohmann::json;

class API:public Topology
{
public:
/**
 * @brief Read a topology from a given JSON file and store it in the memory
 * 
 * @param FileName string
 * @return true or false
 */
	bool readJSON(string FileName);
	/**
	 * @brief Write a given topology from the memory to a JSON file.
	 * 
	 * @param TopologyID string
	 * @return true 
	 * @return false
	 * 
	 */
	bool writeJSON(string TopologyID) ;
	/**
	 * @brief Query about which topologies are currently in the memory
	 * 
	 * @return json* 
	 */
	json* queryTopologies() ;
	/**
	 * @brief Delete a given topology from memory
	 * 
	 * @param TopologyID 
	 * @return true 
	 * @return false 
	 */
	bool deleteTopology(string TopologyID);
	/**
	 * @brief Query about which devices are in a given topology.
	 * 
	 * @param TopologyID string
	 */
	void queryDevices(string TopologyID) ;
	/**
	 * @brief Query about which devices are connected to a given netlist node in a given topology
	 * 
	 * @param TopologyID string
	 * @param NetlistNodeID string
	 */
	void queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID) ;//DeviceList
	
	string getFileName();
	string getTopologyID();
	string getNetlistNodeID();
	/**
	 * @brief Check if API is Empty
	 * 
	 * @return true 
	 * @return false 
	 */
	bool API_Empty();
	~API();
};

