#include "Testing.h"

Testing::Testing()
{
	api_test = new API;
}

Testing::~Testing()
{
	delete api_test;
}

void Testing::Test_Read_1()
{
	cout << "Non-existent file read test\n";
	if (api_test->readJSON("NONE"))
		cout << "\t\tTest Doesn't pass\n";
	else
		cout << "\t\tPASSED Test \n";
}

void Testing::Test_Read_2()
{
	cout << "Test reading an existing file\n";
	if (api_test->readJSON("test.json"))
		cout << "\t\tPASSED Test \n";
	else
		cout << "\t\tTest Doesn't pass\n";
}

void Testing::Test_Write_1()
{
	cout << "Test writing file\n";
	if (!api_test->writeJSON("Wrong ID"))
		cout << "\t\tPASSED Test \n";
	else
		cout << "\t\tTest Doesn't pass\n";
}

void Testing::Test_queryTopologies()
{
	cout << "Test Query Topologies \n";
	if (!api_test->queryTopologies())
		cout << "\t\tPASSED Test \n";
	else
		cout << "\t\tTest Doesn't pass\n";
}

void Testing::Test_Delete_Topology()
{
	cout << "Test Delete Topology \n";
	if (api_test->deleteTopology("top1"))
		cout << "\t\tPASSED Test \n";
	else
		cout << "\t\tTest Doesn't pass\n";
}

void Testing::Run_Tests()
{
	 Test_queryTopologies();
	 Test_Read_1();
	 Test_Read_2();
	 Test_Write_1();
	 Test_Delete_Topology();
}


