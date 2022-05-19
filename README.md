# Task-02(Topology API)

Master Micro's task to test programming skills for summer internship applicants

An API library which provides the functionality to access, manage and store device topologies.
## Built Using 
- **C++**
- **nlohmann-json.hpp** 
- **PVS-Studio**
- **Doxygen**

## Description
1. Read a topology from a given JSON file and store it in the memory.
2. Write a given topology from the memory to a JSON file.
3. Query about which topologies are currently in the memory.
4. Delete a given topology from memory.
5. Query about which devices are in a given topology.
6. Query about which devices are connected to a given netlist node in
   a given topology.
   
   ## Classes
### Main

* This class creates an object from the ApplicationManager class which is used to Execute each functionality

### Topology

* Abstract class with pure virtual function to acheive Polymorphism
 
 
### API

This class contains the memory of the API as a HashMap and an addToMemory function to store in it.

* This class contains the functions of the API :-
	* bool readJSON(string FileName) 
	* bool writeJSON(string TopologyID)
	* json* queryTopologies() = 0;
	* bool  deleteTopology(string TopologyID)
	* void queryDevices(string TopologyID)
	* void queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID)
	 
### Testing

* This class tests each function of class API

## Documentation

## Analysis

##  Screenshots
#### Interface
<img src="screenshots/1.png" height="300" width="700">

#### Read JSON file 
<img src="screenshots/read.png" alt="2" height="600" width="700">

#### Write JSON
<img src="screenshots/write test.png" alt="3" height="300" width="700">

#### Query Topologies
<img src="screenshots/3.png" height="600" width="700">

#### Delete a topology 
<img src="screenshots/4.png"  height="600" width="700">

#### Query devices in a topology
<img src="screenshots/5.png"  height="800" width="700">

#### Query devices with netlist node
<img src="screenshots/6.png"  height="800" width="700">
 

#### Testing
<img src="screenshots/test.png"  height="600" width="700">
