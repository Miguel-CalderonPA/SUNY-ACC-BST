/*
Author: Miguel Calderon

Date: 5/5/19

File Name: CalderonBST

Purpose: The list is implemented with a Binary Search Tree, and uses recursion/iteration
to access and modify elements in the list.
Also contains overloaded operators for assignement, equality,  merging and subtracting lists

Inputs: What the user puts in the struct, this can be edited later
		Must edit the static function to print what you would like
		For PrintFile() you must give a file to print too ex. PrintFile(outFile);

Outputs: Can print out the list, forwards or backwards, forwards on console and also as it exists

Assumptions: The user will be handling the exceptions , also pancakes are good

Error Checking: Throws Exceptions for Dupe key, no memory, or no key not there
*/

//Libraries
#include<iostream>
#include<fstream>
#include<string>
#include"TreeClass.h"
#include "ItemType.h"
#include<ctime>



//item1.ID = 50;
//item2.ID = 40;
//item3.ID = 60;
//item4.ID = 25;
//item5.ID = 55;
//item6.ID = 75;
//item7.ID = 45;
//item8.ID = 65;
//item9.ID = 30;
//item10.ID = 15;
//item11.ID = 35;
//item12.ID = 90;
//item13.ID = 100;
//item14.ID = 20;
//item15.ID = 80;
//// to balance;
//item16.ID = 47;
//item17.ID = 53;
//item18.ID = 85;
//item19.ID = 99;
//item20.ID = 5;



//CONSTANTS
const string TREE1FILE = "tree1.dat";
const string TREE2FILE = "tree2.dat";
const string TREE3FILE = "tree3.dat";
const string TREE4FILE = "tree4.dat";
const string TREE5FILE = "tree5.dat";
const string TREE6FILE = "tree6.dat";
const string TREE7FILE = "tree7.dat";



//________________Visit______________________________

void Visit(ItemType item)
{
	cout << "The Item ID is: " << item.ID << endl; //" and the data is " << item.MoreData << endl;
}

void Visit(ItemType item, ofstream& dout)
{
	dout << "The Item ID is: " << item.ID << endl; // cout statement
}// end Visit

using namespace std;

int main()
{
	// variables
	OrdListClass<ItemType> list1,list3;
	//OrdListClass<ItemType> list1, <ItemType>list3; //list4; // list 2 is created later as a copy constructor
	string userFile;
	ofstream t1Dout,t2Dout,t3Dout,t4Dout,t5Dout,t6Dout,t7Dout,userDout;
	cout << "OrdListClass Instantiated" << endl;
	cout <<endl<< "FULLY FUNCTIONAL" << endl<< endl;

	cout << "Please Enter an Output File for your data" << endl;
	cin >> userFile;

	// Open Files
	t1Dout.open(TREE1FILE.c_str());
	t2Dout.open(TREE2FILE.c_str());
	t3Dout.open(TREE3FILE.c_str());
	t4Dout.open(TREE4FILE.c_str());
	t5Dout.open(TREE5FILE.c_str());
	t6Dout.open(TREE6FILE.c_str());
	t7Dout.open(TREE7FILE.c_str());
	userDout.open(userFile.c_str());

	// Create Test Items and store data
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9, item10,
		item11, item12, item13, item14, item15, item16, item17, item18, item19,item20;
	ItemType testItem;
	srand((unsigned)time(NULL));
	item1.ID = rand() % 101;
	item2.ID = rand() % 101;
	item3.ID = rand() % 101;
	item4.ID = rand() % 101;
	item5.ID = rand() % 101;
	item6.ID = rand() % 101;
	item7.ID = rand() % 101;
	item8.ID = rand() % 101;
	item9.ID = rand() % 101;
	item10.ID = rand() % 101;
	item11.ID = rand() % 101;
	item12.ID = rand() % 101;
	item13.ID = rand() % 101;
	item14.ID = rand() % 101;
	item15.ID = rand() % 101;
	item16.ID = rand() % 101;
	item17.ID = rand() % 101;
	item18.ID = rand() % 101;
	item19.ID = rand() % 101;
	item20.ID = rand() % 101;


	
	//~~~~~~~~~~~~~~~~~Test Empty List Positions~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Position Empty Test" << endl;
	list1.FirstPosition();
	list1.NextPosition();
	list1.LastPosition();
	cout << "EXPECTED RESULT" << endl;
	//~~~~~~~~~~~~~~~Test IsEmpty~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << "Test IsEmpty for Empty List" << endl;

	if (list1.IsEmpty())
		cout << "EXPECTED RESULT" << endl;
	else
		cout << "OH NO, this is BAD" << endl;
	cout << endl;

	//~~~~~~~~~~~~~~~Test IsFull~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << "Test IsFull()" << endl;

	if (list1.IsFull())
		cout << "OH NO, this is BAD" << endl;
	else
		cout << "EXPECTED RESULT" << endl;
	cout << endl;

	//~~~~~~~~~~~~~~~Test Empty Prints~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << "Test List 1 Empty Prints" << endl;
	cout << endl << "Print InOrder";
	list1.PrintScreen(Visit);
	cout << endl << "Print to file TREE1FILE" << endl;
	list1.PrintFile(t1Dout,Visit);
	cout << endl << "Print Reverse Order";
	list1.PrintReverse(Visit);
	cout << endl << "Print As Exists" << endl;
	list1.PrintAsExists(Visit);

	cout << endl << "Empty Prints: EXPECTED RESULT" << endl << endl;


	//~~~~~~~~~~~~~~~Test Insert~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//__________Item 1___________
	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item1);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 1 Item ID:" << item1.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 2___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item2);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 2 Item ID:" << item2.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 3___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item3);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 3 Item ID:" << item3.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 4___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item4);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 4 Item ID:" << item4.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 5___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item5);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 5 Item ID:" << item5.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 6___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item6);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 6 Item ID:" << item6.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 7___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item7);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 7 Item ID:" << item7.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 8___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item8);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 8 Item ID:" << item8.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 9___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item9);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 9 Item ID:" << item9.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 10___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item10);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 10 Item ID:" << item10.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 11___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item11);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 11 Item ID:" << item11.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 12___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item12);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 12 Item ID:" << item12.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 13___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item13);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 13 Item ID:" << item13.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 14___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item14);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 14 Item ID:" << item14.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 15___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item15);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 15 Item ID:" << item15.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 16___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item16);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 16 Item ID:" << item16.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}

	//__________Item 17___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item17);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 17 Item ID:" << item17.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 18___________
	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item18);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 18 Item ID:" << item18.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 19___________
	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item19);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 19 Item ID:" << item19.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 20___________

	cout << endl << "Test Insert" << endl;
	try
	{
		list1.Insert(item20);
	}
	catch (DuplicateKeyException)
	{
		cout << "Can't Insert Duplicate Key" << endl;
	}
	cout << "Balanced? After 20 Item ID:" << item20.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 1 Again___________

	try
	{
		list1.Insert(item1);
	} // end try
	catch (DuplicateKeyException)
	{
		cout << endl << "Item 1 already in the list test " << endl;
	} // end catch

	cout << "Insert: EXPECTED RESULT" << endl << endl;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~Test Positions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//__________First Position___________
	cout << "Test First Position List 1" << endl;
	list1.FirstPosition();
	cout << "CurrPos After FirstPosition: " << list1.Retrieve().ID << endl;
	cout  << "EXPECTED RESULT" << endl<< endl;
	//__________Last Position___________
	cout << "Test Last Position List 1" << endl;
	list1.LastPosition();
	cout << "CurrPos After LastPosition: " << list1.Retrieve().ID << endl;
	cout  << "EXPECTED RESULT" << endl<< endl;
	//__________Next Position___________
	cout << "Next Position on nullptr goes to First Position List 1" << endl;
	list1.NextPosition();
	list1.NextPosition();
	cout << "CurrPos After Next, Next List 1 Position: " << list1.Retrieve().ID << endl;
	cout << "EXPECTED RESULT" << endl << endl;
	//__________All Positions___________
	cout << "Traversing List with Position Methods for List 1" << endl;
	while (!list1.EndofList())
	{
		cout << "ID: " << list1.Retrieve().ID << endl;
		list1.NextPosition();
	}
	cout << "EXPECTED RESULT" << endl << endl;
	//__________# of Elements___________
	cout << "Length of List" << endl;
	cout << list1.ReturnLength() << endl;
	cout << "EXPECTED RESULT" << endl << endl;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~Test Prints on Big List~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << "Test List 1 on Big List" << endl;
	cout << endl << "Print InOrder" << endl;
	list1.PrintScreen(Visit);
	cout << endl << "Print to file TREE1FILE" << endl;
	list1.PrintFile(t1Dout,Visit);
	cout << endl << "Print Reverse Order"<< endl;
	list1.PrintReverse(Visit);
	cout << endl << "Print As Exists" << endl;
	list1.PrintAsExists(Visit);

	cout << endl << "Prints: EXPECTED RESULT" << endl << endl;

	OrdListClass<ItemType> list8(list1);
	list8.PrintFile(userDout, Visit);

	//~~~~~~~~~~~~~~~Test IsEmpty~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Test IsEmpty for Empty List 1" << endl;

	if (list1.IsEmpty())
		cout << "OH NO, this is BAD" << endl;
	else
		cout << "EXPECTED RESULT" << endl;
	cout << endl;

	//~~~~~~~~~~~~~~~Test Copy Constructor~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << "Test Copy Construcor" << endl << endl;
	OrdListClass<ItemType> list2(list1);
	//~~~~~~~~~~~~~~~Test Prints list 2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Test List 2 After Copy Constructor" << endl;
	cout << endl << "Print InOrder" << endl;
	list2.PrintScreen(Visit);
	cout << endl << "Print to file TREE2FILE" << endl;
	list2.PrintFile(t2Dout, Visit);
	cout << endl << "Print Reverse Order" << endl;
	list2.PrintReverse(Visit);
	cout << endl << "Print As Exists" << endl;
	list2.PrintAsExists(Visit);

	cout << endl << "Prints: EXPECTED RESULT" << endl << endl;


	//~~~~~~~~~~~~~~~~~~Test Positions~~~~~~~~~~~~~~~~~~~~~~~~~~
	//__________First Position___________
	cout << "Test First Position List 2" << endl;
	list2.FirstPosition();
	cout << "CurrPos After FirstPosition: " << list2.Retrieve().ID << endl;
	cout << "EXPECTED RESULT" << endl << endl;
	//__________Last Position___________
	cout << "Test Last Position List 2" << endl;
	list2.LastPosition();
	cout << "CurrPos After LastPosition: " << list2.Retrieve().ID << endl;
	cout << "EXPECTED RESULT" << endl << endl;
	//__________Next Position___________
	cout << "Next Position on nullptr goes to First Position List 2" << endl;
	list2.NextPosition();
	list2.NextPosition();
	cout << "CurrPos After Next, Next List 2 Position: " << list2.Retrieve().ID << endl;
	cout << "EXPECTED RESULT" << endl << endl;
	//__________All Positions___________
	cout << "Traversing List with Position Methods for List 2" << endl;
	while (!list2.EndofList())
	{
		cout << "ID: " << list2.Retrieve().ID << endl;
		list2.NextPosition();
	}
	cout << "EXPECTED RESULT" << endl << endl;
	//__________# of Elements___________
	cout << "Length of List" << endl;
	cout << list2.ReturnLength() << endl;
	cout << "EXPECTED RESULT" << endl << endl;


	//~~~~~~~~~~~~~~~Delete~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Before Delete" << endl;
	list1.PrintAsExists(Visit);
	cout << "Test Delete()" << endl;
	// Delete All see if any case issues
	list1.FirstPosition();
	try
	{
		list1.Delete(item1.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	//__________Test Retrieve On Null___________
	try
	{
		list1.Retrieve();
	} // end try
	catch (KeyNotThereException)
	{
		cout << "Retrieve at Null Test: EXPECTED RESULT" << endl;
	} // end catch
	//__________Item 1___________
	cout << "Balanced? After 1 Item ID:" << item1.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 2___________
	try
	{
		list1.Delete(item2.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 2 Item ID:" << item2.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 3___________
	try
	{
		list1.Delete(item3.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 3 Item ID:" << item3.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 4___________
	try
	{
		list1.Delete(item4.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 4 Item ID:" << item4.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 5___________
	try
	{
		list1.Delete(item5.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 5 Item ID:" << item5.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 6___________
	try
	{
		list1.Delete(item6.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 6 Item ID:" << item6.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 7___________
	try
	{
		list1.Delete(item7.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 7 Item ID:" << item7.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 8___________
	try
	{
		list1.Delete(item8.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 8 Item ID:" << item8.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 9___________
	try
	{
		list1.Delete(item9.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 9 Item ID:" << item9.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 10___________
	try
	{
		list1.Delete(item10.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 10 Item ID:" << item10.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 11___________
	try
	{
		list1.Delete(item11.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 11 Item ID:" << item11.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 12___________
	try
	{
		list1.Delete(item12.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 12 Item ID:" << item12.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 13___________
	try
	{
		list1.Delete(item13.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 13 Item ID:" << item13.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 14___________
	try
	{
		list1.Delete(item14.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 14 Item ID:" << item14.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 15___________
	try
	{
		list1.Delete(item15.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 15 Item ID:" << item15.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 16___________
	try
	{
		list1.Delete(item16.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 16 Item ID:" << item16.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 17___________
	try
	{
		list1.Delete(item17.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 17 Item ID:" << item17.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 18___________
	try
	{
		list1.Delete(item18.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 18 Item ID:" << item18.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 19___________
	try
	{
		list1.Delete(item19.ID);
	}
	catch (KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 19 Item ID:" << item19.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Item 20___________
	try
	{
		list1.Delete(item20.ID);
	}
	catch(KeyNotThereException)
	{
		cout << "Key Not there" << endl;
	}
	cout << "Balanced? After 20 Item ID:" << item20.ID << endl;
	list1.PrintAsExists(Visit);
	if (list1.IsBalanced())
	{
		cout << "THANOS is PROUD" << endl;
	}
	else
	{
		cout << "Not Balanced! *SNAP*" << endl;
		list1.PrintAsExists(Visit);
	}
	//__________Test Delete Item 1 Again___________
	try
	{
		list1.Delete(item1.ID);
	} // end try
	catch (KeyNotThereException)
	{
		cout << "Item 1 ID not there test" << endl;
	} // end catch
	cout << "EXPECTED RESULT" << endl << endl;

	//~~~~~~~~~~~~~~~Test Prints~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << endl << "Test List 1 After Delete Test" << endl;
	cout << endl << "Print InOrder" << endl;
	list1.PrintScreen(Visit);
	cout << endl << "Print to file TREE1FILE" << endl;
	list1.PrintFile(t1Dout,Visit);
	cout << endl << "Print Reverse Order" << endl;
	list1.PrintReverse(Visit);
	cout << endl << "Print As Exists" << endl;
	list1.PrintAsExists(Visit);

	cout << endl << "Prints: EXPECTED RESULT" << endl << endl;

	//~~~~~~~~~~~~~~~Test IsEmpty~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Test IsEmpty for Empty List 1" << endl;

	if (list1.IsEmpty())
		cout << "EXPECTED RESULT" << endl;
	else
		cout << "OH NO, this is BAD" << endl;
	cout << endl << endl;

	//~~~~~~~~~~~~~~~~~Test Clear~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Clear Test for List 2" << endl;
	list2.Clear();
	cout << "Test List 2 After Clear Test" << endl;
	cout << endl << "Print InOrder" << endl;
	list2.PrintScreen(Visit);
	cout << endl << "Print to file TREE2FILE" << endl;
	list2.PrintFile(t2Dout,Visit);
	cout << endl << "Print Reverse Order" << endl;
	list2.PrintReverse(Visit);
	cout << endl << "Print As Exists" << endl;
	list2.PrintAsExists(Visit);

	cout << endl << "Prints: EXPECTED RESULT" << endl << endl;

	//~~~~~~~~~~~~~~~Test Operator== with same lists~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << "Test Operator == with same lists" << endl;
	//______Item4______
	try
	{
		list2.Insert(item4);
	}
	catch(DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//______Item12______
	try
	{
		list2.Insert(item12);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//______Item1______
	try
	{
		list2.Insert(item1);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	

	OrdListClass<ItemType> list4(list2);

	if (list4 == list2)
	{
		cout << "true == EXPECTED RESULT" << endl;
	}
	else
	{
		cout << "false == BAD RESULT" << endl;
	}
	cout << endl << "List 4" << endl;
	list4.PrintScreen(Visit);
	cout << endl << "List 2" << endl;
	list2.PrintScreen(Visit);

	cout << "EXPECTED RESULT" << endl << endl;
	//~~~~~~~~~~~~~~~Test Operator!= with same lists~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << "Test Operator != with same lists" << endl;

	if (list4 != list2)
	{
		cout << "true == BAD RESULT" << endl;
	}
	else
	{
		cout << "false == EXPECTED RESULT" << endl;
	}
	cout << endl << "List 4" << endl;
	list4.PrintScreen(Visit);
	cout << endl << "List 2" << endl;
	list2.PrintScreen(Visit);

	cout  << "EXPECTED RESULT" << endl<< endl;
	//~~~~~~~~~~~~~~~Test Operator== with different lists~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << endl;
	//______Item1______
	try
	{
		list1.Insert(item1);
	}
	catch(DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//______Item1______
	try
	{
		list1.Insert(item17);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//______Item1______
	try
	{
	list1.Insert(item12);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	

	cout << "Test Operator == with different lists" << endl;

	if (list4 == list1)
	{
		cout << "true == BAD RESULT" << endl;
	}
	else
	{
		cout << "false == EXPECTED RESULT" << endl << endl;
	}
	cout << endl << "List 4" << endl;
	list4.PrintScreen(Visit);
	cout << endl << "List 1" << endl;
	list1.PrintScreen(Visit);
	
	cout << "EXPECTED RESULT" << endl << endl;

	//~~~~~~~~~~~~~~~Test Operator!= with different lists~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << "Test Operator != with different lists" << endl;

	if (list4 != list1)
	{
		cout << "true == EXPECTED RESULT" << endl;
	}
	else
	{
		cout << "false == BAD RESULT" << endl;
	}
	cout << endl << "List 4" << endl;
	list4.PrintScreen(Visit);
	cout << endl << "List 1" << endl;
	list1.PrintScreen(Visit);

	cout <<  "EXPECTED RESULT" << endl << endl;

	list1.Clear();
	list2.Clear();
	list3.Clear();
	list4.Clear();
	cout << "Lists 1,2,3,4 should be cleared" << endl;
	cout << "List1 IsEmpty" << endl;
	if(list1.IsEmpty())
		cout << "EXPECTED RESULT" << endl;
	cout << "List2 IsEmpty" << endl;
	if (list2.IsEmpty())
		cout << "EXPECTED RESULT" << endl;
	cout << "List3 IsEmpty" << endl;
	if (list3.IsEmpty())
		cout << "EXPECTED RESULT" << endl;
	cout << "List4 IsEmpty" << endl;
	if (list4.IsEmpty())
		cout<< "EXPECTED RESULT" << endl << endl;

	//~~~~~~~~~~~~~~~Test Operator+ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//_________Empty Lists____________
	cout << "Test Operator + with Empty Lists" << endl;
	list3 = list1 + list2;
	cout << "List1" << endl;
	list1.PrintScreen(Visit);
	cout << "List2" << endl;
	list2.PrintScreen(Visit);
	cout << "List3" << endl;
	list3.PrintScreen(Visit);
	cout << "EXPECTED RESULT" << endl<< endl;
	//_________With One Element____________
	list1.Insert(item1);
	//list1.Insert(item2);
	cout << "Test Operator + with one item" << endl;
	list3 = list1 + list2;
	cout << "List1" << endl;
	list1.PrintScreen(Visit);
	cout << "List2" << endl;
	list2.PrintScreen(Visit);
	cout << "List3" << endl;
	list3.PrintScreen(Visit);
	cout << "EXPECTED RESULT" << endl<< endl;
	
	//tested as same value already
	list2.Insert(item1);
	cout << "Test Operator + with one item in both" << endl;
	list3 = list1 + list2;
	cout << "List1" << endl;
	list1.PrintScreen(Visit);
	cout << "List2" << endl;
	list2.PrintScreen(Visit);
	cout << "List3" << endl;
	list3.PrintScreen(Visit);
	cout << "EXPECTED RESULT" << endl << endl;
	//_________With Many Elements____________
	//Fill list1
	//_______ITEM2_______
	try
	{
		list1.Insert(item2);
	}
	catch(DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM3_______
	try
	{
		list1.Insert(item3);
	}
	catch(DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM4_______
	try
	{
		list1.Insert(item4);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM5_______
	try
	{
		list1.Insert(item5);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM6_______
	try
	{
		list1.Insert(item6);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM7_______
	try
	{
		list1.Insert(item7);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM8_______
	try
	{
		list1.Insert(item8);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM9_______
	try
	{
		list1.Insert(item9);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM10_______
	try
	{
		list1.Insert(item10);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM11_______
	try
	{
		list1.Insert(item11);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM12_______
	try
	{
		list1.Insert(item12);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}


	//~~~~~~~~~~~~~~~~fill list2~~~~~~~~~~~~~
	//_______ITEM9_______
	try
	{
		list2.Insert(item9);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM10_______
	try
	{
		list2.Insert(item10);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM11_______
	try
	{
		list2.Insert(item11);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM12_______
	try
	{
		list2.Insert(item12);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM13_______
	try
	{
		list2.Insert(item13);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM14_______
	try
	{
		list2.Insert(item14);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM15_______
	try
	{
		list2.Insert(item15);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM16_______
	try
	{
		list2.Insert(item16);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM17_______
	try
	{
		list2.Insert(item17);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM18_______
	try
	{
		list2.Insert(item18);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM19_______
	try
	{
		list2.Insert(item19);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM20_______
	try
	{
		list2.Insert(item20);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	


	cout << endl << "Print List 1 for Operator+" << endl;
	list1.PrintScreen(Visit);
	cout << endl << "Print List 2 for Operator+" << endl;
	list2.PrintScreen(Visit);

	try
	{
		list3 = list1 + list2;
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key in operator + test" << endl;
	}

	cout << endl << "Print List 3 After Operator+" << endl;
	list3.PrintScreen(Visit);
	cout << "EXPECTED RESULT" << endl << endl;
	list3.PrintAsExists(Visit);
	cout << endl;
	//_________With Many of the Same Elements____________
	list4 = list3;
	list4 = list4 + list3;
	list4.PrintScreen(Visit);
	list4.PrintAsExists(Visit);
	//~~~~~~~~~~~~~~~~~~~~~~~~~CHECK OPERATOR == & != AGAIN~~~~~~~~~~~~~~~~~~~
	cout << endl << "Test list3==list4" << endl;
	if (list3 == list4)
	{
		cout << "EXPECTED RESULT" << endl;
	}
	else
	{
		cout << "Ruh Roh Raggy!" << endl;
	}
	cout << endl << "Test list3==list2" << endl;
	if (list3 == list2)
	{
		cout << "Ruh Roh Raggy!" << endl;
	}
	else
	{
	cout << "EXPECTED RESULT" << endl;
	}
	cout << "EXPECTED RESULT" << endl << endl;



	//~~~~~~~~~~~~~~~~~~~~~~~~~~CLEAR LISTS AGAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	list1.Clear();
	list2.Clear();
	list3.Clear();
	list4.Clear();
	cout << "Lists 1,2,3,4 should be cleared" << endl;
	cout << "List1 IsEmpty" << endl;
	if (list1.IsEmpty())
		cout << "EXPECTED RESULT" << endl;
	cout << "List2 IsEmpty" << endl;
	if (list2.IsEmpty())
		cout << "EXPECTED RESULT" << endl;
	cout << "List3 IsEmpty" << endl;
	if (list3.IsEmpty())
		cout << "EXPECTED RESULT" << endl;
	cout << "List4 IsEmpty" << endl;
	if (list4.IsEmpty())
		cout << "EXPECTED RESULT" << endl << endl;

	//~~~~~~~~~~~~~~~Test Operator- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//_________Empty Lists____________
	cout << "Test Operator - with Empty Lists" << endl;
	list3 = list1  - list2;
	cout << "List1" << endl;
	list1.PrintScreen(Visit);
	cout << "List2" << endl;
	list2.PrintScreen(Visit);
	cout << "List3" << endl;
	list3.PrintScreen(Visit);
	cout << "EXPECTED RESULT" << endl << endl;
	//_________With One Element____________
	//_______ITEM1_______
	try
	{
		list1.Insert(item1);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM2_______
	try
	{
		list1.Insert(item2);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	
	cout << "Test Operator - with one item" << endl;
	list3 = list1  - list2;
	cout << "List1" << endl;
	list1.PrintScreen(Visit);
	cout << "List2" << endl;
	list2.PrintScreen(Visit);
	cout << "List3" << endl;
	list3.PrintScreen(Visit);
	cout << "EXPECTED RESULT" << endl << endl;

	// tested with same value
	//_______ITEM2_______
	try
	{
		list2.Insert(item2);
	}
	catch(DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	
	cout << "Test Operator - with one item in both" << endl;
	list3 = list1 - list2;
	cout << "List1" << endl;
	list1.PrintScreen(Visit);
	cout << "List2" << endl;
	list2.PrintScreen(Visit);
	cout << "List3" << endl;
	list3.PrintScreen(Visit);
	cout << "EXPECTED RESULT" << endl << endl;



	//_________With Many Elements____________
	//~~~~~~~~~~~~~~~~~~~~~~~~Fill list1~~~~~~~~~~~~~~~~~~~~~~~~
	//_______ITEM2_______
	try
	{
		//list1.Insert(item2);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM3_______
	try
	{
		list1.Insert(item3);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM4_______
	try
	{
		list1.Insert(item4);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM5_______
	try
	{
		list1.Insert(item5);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM6_______
	try
	{
		list1.Insert(item6);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM7_______
	try
	{
		list1.Insert(item7);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM8_______
	try
	{
		list1.Insert(item8);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM9_______
	try
	{
		list1.Insert(item9);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM10_______
	try
	{
		list1.Insert(item10);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM11_______
	try
	{
		list1.Insert(item11);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM12_______
	try
	{
		list1.Insert(item12);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	

	//~~~~~~~~~~~~~~~~~~~~~~~fill list2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//_______ITEM9_______
	try
	{
		list2.Insert(item9);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM10_______
	try
	{
		list2.Insert(item10);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM11_______
	try
	{
		list2.Insert(item11);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM12_______
	try
	{
		list2.Insert(item12);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM13_______
	try
	{
		list2.Insert(item13);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM14_______
	try
	{
		list2.Insert(item14);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM15_______
	try
	{
		list2.Insert(item15);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM16_______
	try
	{
		list2.Insert(item16);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM17_______
	try
	{
		list2.Insert(item17);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM18_______
	try
	{
		list2.Insert(item18);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM19_______
	try
	{
		list2.Insert(item19);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//_______ITEM20_______
	try
	{
		list2.Insert(item20);
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key" << endl;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << endl << "Print List 1 for Operator -" << endl;
	list1.PrintScreen(Visit);
	cout << endl << "Print List 2 for Operator -" << endl;
	list2.PrintScreen(Visit);

	try
	{
		list3 = list1  - list2;
	}
	catch (DuplicateKeyException)
	{
		cout << "Dupe Key in Operator - test" << endl;
	}

	cout << endl << "Print List 3 After Operator -" << endl;
	list3.PrintScreen(Visit);
	cout << "EXPECTED RESULT" << endl << endl;
	list3.PrintAsExists(Visit);
	cout << endl;
	//_________With Many of the Same Elements____________
	list4 = list3;
	list4 = list4  - list3;
	list4.PrintScreen(Visit);
	list4.PrintAsExists(Visit);

	// EXTRA TESTS
	cout << endl << "EXTRA TESTS" << endl;
	OrdListClass<ItemType> list5;
	OrdListClass<ItemType> list6(list5);

	list6 = list5 - list5;
	list6.PrintScreen(Visit);
	list6.PrintAsExists(Visit);


	if (list4 != list3)
		cout << "GOOD" << endl;

	if (list5 == list6)
		cout << "GOOD" << endl;

	OrdListClass<ItemType> list7(list3);

	if (list3 == list7)
		cout << "GOOD" << endl;

	// Print to All Files all trees
	list1.PrintFile(t1Dout,Visit);
	list2.PrintFile(t2Dout,Visit);
	list3.PrintFile(t3Dout,Visit);
	list4.PrintFile(t4Dout,Visit);
	list5.PrintFile(t5Dout,Visit);
	list6.PrintFile(t6Dout,Visit);
	list7.PrintFile(t7Dout,Visit);


	t1Dout.close();
	t2Dout.close();
	t3Dout.close();
	t4Dout.close();
	t5Dout.close();
	t6Dout.close();
	t7Dout.close();
	userDout.close();

	cout << endl << "FULLY FUNCTIONAL" << endl;
	cout << endl << "Full Screen to see accurate PrintAsExists Prints" << endl;

	system("pause");
	return 1;
}