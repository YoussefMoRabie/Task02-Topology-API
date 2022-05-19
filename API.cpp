/**
 * @file API.cpp
 * @brief API CLass
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "API.h"

using namespace std;
/**
 * @brief use json from nlohmann
 * 
 */
using json = nlohmann::json;


bool API::readJSON(string FileName)
{
	try {
		/**
		 * @brief Reading json file
		 */
		ifstream file(FileName);
		json TopologyFile;
		file >> TopologyFile;

		
				/**
		 * @brief Store JSON file in the array
		 */
		topologies[size - 1] = TopologyFile;

		
				/**
		 * @brief Increament counter
		 */
		topologies_counter++;

		
				/**
		 * @brief Increament dynamic array size
		 */
		size++;
		cout << "JSON file has been read"<<endl;
		return true;

	}
	catch (...)
	{
				/**
		 * @brief Error message
		 */
		cout << "There are no JSON files with this name"<<endl;
		return false;

	}
}

bool API::writeJSON(string TopologyID)
{
	//Check the if no topologies exist
	if (API_Empty())
	{
		cout << "There are no topology now in memory to perform operations on them" << endl;
		return false;
	}
	//Check the if required topology exist
	for (int counter = 0; counter < topologies_counter; counter++)
	{
		if (topologies[counter]["id"] == TopologyID)
		{
			
				string name;
				cout << "Please enter the name of the file you want to create :" ;
				cin.ignore();
				getline(cin, name);
				ofstream save;
				save.open(name+".json");

				save << setw(1) << topologies[counter];// << endl;
				cout << "The file has been created successfully";
			return true;
		}
	}
	/*In case undefined Topology*/
	cout << "Topology " << TopologyID << " is not found" << endl;
	return false;

}

json* API::queryTopologies()
{
	/**
	 * @brief Check the if no topologies exist
	 * 
	 */
	if (API_Empty())
	{
		cout << "There are no topology now in memory " << endl;
		return NULL;
	}
	cout << "Topologies in the Memory: ";
	for (int counter = 0; counter < topologies_counter; counter++)
	{
		cout << topologies[counter]["id"]<<" ";
	}
	cout << endl;
	return topologies;
}

bool API::deleteTopology(string TopologyID)
{
	//Check the if no topologies exist
	if (API_Empty())
	{
		cout << "There are no topology now in memory to perform operations on them" << endl;
		return false;
	}
	//Check the if required topology exist
	for (int counter = 0; counter < topologies_counter; counter++)
	{
		if (topologies[counter]["id"] == TopologyID)
		{

			for (int i = counter; i < topologies_counter; i++)
			{
				//Shiftting the data to the End of array
				topologies[i] = topologies[i + 1];
			}
			//decreasing the dynamic array size so the last element will be Shiftted to the End of array
			size--;
			topologies_counter--;
			cout << "Deleted successfully\n";
			return true;
		}
	}
	/*In case undefined Topology*/
	cout << "Topology " << TopologyID << " is not found" << endl;
	return false;
}

void API::queryDevices(string TopologyID)
{
	//Check the if no topologies exist
	if (API_Empty())
	{
		cout << "There are no topology now in memory" << endl;
		return;
	}
	//Check the if required topology exist
	for (int counter = 0; counter < topologies_counter; counter++)
	{
		if (topologies[counter]["id"] == TopologyID)
		{
			cout << "Devices in " << topologies[counter]["id"] << " are : " << topologies[counter]["components"][0]["type"] << " "
				<< topologies[counter]["components"][1]["type"] << endl;
			return;
		}
	}
	/*In case undefined Topology*/
	cout << "Topology " << TopologyID << " is not found" << endl;
}

void API::queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID)
{
	//Check the if no topologies exist
	if (API_Empty())
	{
		cout << "There are no topology now in memory" << endl;
		return;
	}
	for (int counter = 0; counter < topologies_counter; counter++)
	{
		/*Check the required topology*/
		if (topologies[counter]["id"] == TopologyID)
		{
			if (topologies[counter]["components"][0]["netlist"]["t1"] == NetlistNodeID || topologies[counter]["components"][0]["netlist"]["t2"] == NetlistNodeID)
			{
				cout << "Device connected to " << NetlistNodeID << " is " << topologies[counter]["components"][0]["type"] << endl;
			}
			if (topologies[counter]["components"][1]["netlist"]["drain"] == NetlistNodeID || topologies[counter]["components"][1]["netlist"]["gate"] == NetlistNodeID || topologies[counter]["components"][1]["netlist"]["source"] == NetlistNodeID)
			{
				cout << "Device connected to " << NetlistNodeID << " is " << topologies[counter]["components"][1]["type"] << endl;
			}
			else 
				cout << "Net list" << NetlistNodeID << " is not found" << endl;
			return;
		}
	}
	/*In case undefined Topology*/
	cout << "Topology " << TopologyID << " is not found" << endl;
}

string API::getFileName()
{
	string temp;

	cout << "Enter File Name: ";
	cin >> temp;
	return temp;
}

string API::getTopologyID()
{
	string temp;

	cout << "Enter Topology ID: ";
	cin >> temp;
	return temp;
}

string API::getNetlistNodeID()
{
	string temp;

	cout << "Enter Node ID: ";
	cin >> temp;
	return temp;
}

bool API::API_Empty()
{
	return !topologies_counter;
}

API::~API()
{
	delete[]topologies;
}
