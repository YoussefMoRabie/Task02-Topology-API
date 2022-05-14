#include "ApplicationManager.h"

ApplicationManager::ApplicationManager()
{
	test2 = &test1;
	Option = 0;
}

void ApplicationManager::Execute()
{
	
		cout << "\t \t \t \t \t \t \tTopology API" << endl;

		while (1)
		{
			cout << "System Options: " << endl;
			cout << "\t \t 1- Read Topolgy" << endl;
			cout << "\t \t 2- Write Topolgy" << endl;
			cout << "\t \t 3- Query Topolgies" << endl;
			cout << "\t \t 4- Delete Topolgy" << endl;
			cout << "\t \t 5- Query Devices" << endl;
			cout << "\t \t 6- Query Devices connected to a certain node" << endl;
			cout << "\t \t 7- Exit Program" << endl;
			cout << "What do you want to do? : ";
			cin >> Option;

			switch (Option)
			{
			case 1: user_option = test1.getFileName();
				test2->readJSON(user_option+".json");
				break;
			case 2: user_option = test1.getTopologyID();
				test2->writeJSON(user_option);
				break;
			case 3: test2->queryTopologies();
				break;
			case 4: user_option = test1.getTopologyID();
				test2->deleteTopology(user_option);
				break;
			case 5: user_option = test1.getTopologyID();
				test2->queryDevices(user_option);
				break;
			case 6: user_option = test1.getTopologyID();
				user_option2 = test1.getNetlistNodeID();
				test2->queryDevicesWithNetlistNode(user_option, user_option2);
				break;
			case 7:
				return;

			}
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
		}
}


