#pragma once
#include<iostream>
#include<string>
#include"nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

/*Abstract class with pure virtual function to acheive Polymorphism*/

class Topology
{
protected:
	int size = 1;
	int topologies_counter = 0;
	json* topologies = new json[size];

public:
	virtual void readJSON(string FileName) = 0;
	virtual void writeJSON(string TopologyID) = 0;
	virtual void queryTopologies() = 0;// TopologyList
	virtual void deleteTopology(string TopologyID) = 0;
	virtual void queryDevices(string TopologyID) = 0;//DeviceList
	virtual void queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID) = 0;//DeviceList
};

