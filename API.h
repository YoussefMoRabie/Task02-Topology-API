#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
#include "Topology.h"


using namespace std;
using json = nlohmann::json;

class API:public Topology
{
public:
	void readJSON(string FileName);
	void writeJSON(string TopologyID) ;
	void queryTopologies() ;// TopologyList
	void deleteTopology(string TopologyID);
	void queryDevices(string TopologyID) ;//DeviceList
	void queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID) ;//DeviceList
	
	string getFileName();
	string getTopologyID();
	string getNetlistNodeID();
	bool API_Empty();
};

