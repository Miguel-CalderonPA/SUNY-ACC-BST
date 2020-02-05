//*************************************************************************************************
//										SPECIFICATION FILE
/*
Date: 5/5/19
Author: Miguel Calderon
Project: Binary Search Tree
Filename: TreeClass.h
Purpose: This file contains the specification for an ascending Ordered List Class. The list is implemented
with a  Binary Search Tree, and uses recursion to access and modify elements in the list.
Insert, Delete, Clear, Retrieve, Print, and PrintReverse, are wrapper methods for their
recursive counterparts. The class containts |   17    | public methods,|    5    | overloaded operators, |     22   | protected methods,
|	2	| Static Print Methods, constructor, copy constructor and destructor, along with a private methdod in private

Assumptions: 1) KeyType is defined as the a programmer defined data type and is used to order the list.
2) Relational operators are defined on the primitive datatype that is typedefined as KeyType
3) ItemType is defined to contain a field named key which is defined of type KeyType
4) The list cannot hold elements with duplicate keys.

Exceptions Thrown:
RetrieveOnEmpty -- Thrown when client tries to delete or retrieve a non-existent key.
OutOfMemoryException -- tries to insert when there is no available memory.
DuplicateKeyException -- Thrown when client tries to insert a key that is already in the list.
Thrown whenever OrdListClass catches a bad allocException, when the client



//*************************************************************************************************
//										Summary of Methods
public:

//~~~~~~~~~~~~~~~~~~Constructors/Deconstructor~~~~~~~~~~~~~~~

	(1)OrdListClass() -- Default constructor for class an Ordered list class
	(2)OrdListClass(const OrdListClass& orig) -- copy constructor for ordered list class
	(3)~OrdListClass() -- deconstructor for ordered list class to deallocate efficiently

//~~~~~~~~~~~~~~~~~~~~~~~~~Traversing~~~~~~~~~~~~~~~~~~~~~~~~

	(4)void FirstPosition() -- sets currPos to first position in our list
	(5)void NextPosition() -- sets currPos to next ascending position
	(6)void LastPosition() -- sets currPos to last position in our list

//~~~~~~~~~~~~~~~~~~~~~~~~~Observer Predicators~~~~~~~~~~~~~~~

	(7)bool IsEmpty() -- returns if list is empty
	(8)bool IsFull() -- returns if list is full
	(9)bool EndofList() -- returns if currPos is null
	(10)bool IsBalanced() -- returns if a tree is balanced

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Mutators~~~~~~~~~~~~~~~

	
	(11)void Insert(ItemType payload) -- inserts an item into the list while keeping order
	(12)void Delete(Keytype target) -- deletes an item from the list while keeping order
	(13)void Clear() -- clears list

//~~~~~~~~~~~~~~~~~~~~~~~~~Observer Accessors~~~~~~~~~~~~~~~
	(14)bool Find(Keytype target) -- finds a specific ID in our list
	(15)int ReturnLength() -- returns the length (# of elements) in our list
	(16)ItemType Retrieve() -- retrieves the data that is at currPos

//~~~~~~~~~~~~~~~~~~~~~~~~~Operators~~~~~~~~~~~~~~~~~~~~~~~

	(17)OrdListClass operator=(const OrdListClass& orig) -- assigns one ordered list class to another
	(18)OrdListClass operator + (const OrdListClass& otherList) -- adds two lists together (no duplicates)
	(19)OrdListClass operator - (const OrdListClass& otherList)-- subtracts items that appear in both lists
	(20)bool operator == (const OrdListClass& otherList) const -- returns true if the lists are equal
	(21)bool operator != (const OrdListClass& otherList) const --returns true if lists are NOT equal

//~~~~~~~~~~~~~~~~~~~~~~~~~Prints/Summarizers~~~~~~~~~~~~~~~

	(22)void PrintScreen() -- prints the list in an ordered ascending fashion
	(23)void PrintFile(string fileName) --prints the list in an ordered fashion, but to an output file
	(24)void PrintReverse() -- prints the list in reverse order
	(25)void PrintAsExists() -- shows how the tree which the list is stored in appears "as exist"

	//_____STATIC_____
	(26)static void Visit(ItemType item) -- used to allow changable print
	(27)static void Visit(ItemType item, ofstream& dout) -- overload of orignal, but with added feature of having an output file
	

protected:  
	(28)void Balance() -- balances tree as best as possible
	(29)node* reBuildTree(ItemType arr[], int first, int last) -- rebuilds a tree using a sorted array
	(30)ItemType* TreeToArray()-- converts a tree into an array
	(31)ItemType* MergeTreesToArray(OrdListClass& tree1, OrdListClass& tree2, int& totalNodes) -- converts two trees in one array (addition)
	(32)ItemType* FilterDupeTreesToArray(OrdListClass& tree1, OrdListClass& tree2, int& totalNodes) -- converts two trees into one array (subtraction)
	(33)bool compareTree(node* tree1, node* tree2) -- compares structures of trees, not values
	(34)node* IntOrdPred(node* currNode) -- finds the inOrderPredecessor in the list
	(35)node* IntOrdSucc(node* currNode) -- finds the inOrderSuccessor in the list
	(36)node* FindParent(node* target, node* traverse) -- finds parent of given child node, if root then nullptr
	(37)int getMaxHeight(node* traverse) -- returns max height of a subtree
	(38)int helpHeight(int leftTree, int rightTree) -- returns which number is larger
	(39)bool IsThanosed(node* root) -- recursive call that finds if a tree is balanced
	(40)void rCopyTree(node*& traverse, node* travCopy) -- used for copying one tree to another

	//~~~~~~~~~~~~~~~~~~~~~~~~~Recursive Mutators~~~~~~~~~~~~~~~ 

	(41)node* rInsert(node* currNode, ItemType payload) -- recursive insert used to insert efficiently in a tree
	(42)node* rDelete(node* currNode, Keytype target) -- recursive delete used to delete efficiently in a tree
	(43)node* rClear(node* currNode) -- recursive clear used to deallocate data efficiently in a tree
	
	//~~~~~~~~~~~~~~Recursive Accessor~~~~~~~~~~~~~~~~~~~~~~~
	(44)bool rFind(node* currNode, Keytype target) -- recurisve find used to find an item efficiently in a tree
	(45)int rCountNodes(node* traverse) -- recursive count used to find number of elements in a tree

	//~~~~~~~~~~~~~~~~~~~~~~~~~Recursive Prints~~~~~~~~~~~~~~~

	(46)void rPrintScreen(node* traverse, void Visit(ItemType item)) -- prints the inorder traversal of a tree
	(47)void rPrintFile(node* traverse, ofstream& dout, void VisitToFile(ItemType item)) -- prints the inorder traversal of a tree to a file
	(48)void rPrintReverse(node* traverse, void Visit(ItemType item)) -- prints the reverse order traveral of a tree
	(49)void rPrintExists(node* traverse, int level, int height, int height2) -- prints the tree as it exists level by level and spacing
	
	
	private:
	//~~~~~~~~~~~~~~~~~~~~~~~~~Class PDMs~~~~~~~~~~~~~~~~

	root; //anchored at first node
	prevPos;// for traversals always points to the inorder predecessor of currPos
	currPos;//for traversals

	//~~~~~~~~~~~~~~~~~~~~~~~~~Allocate new memory~~~~~~~~~~~~~~~
	(50)node* Allocate() -- Allocates a new memory
	

*/
#pragma once
#ifndef TREE_H
#define TREE_H
//Libraries
#include <iostream>
#include <string>
#include "NodeStruct.h"
#include "ItemType.h"
#include "Exceptions.h"
#include <fstream>
//Constants
const string OUTFILE = "outfile.dat";
template <class itemT>
class OrdListClass
{
public:

//~~~~~~~~~~~~~~~~~~Constructors/Deconstructor~~~~~~~~~~~~~~~

	OrdListClass();
	/*
	Pre: needs to be instantiated
	Post: class is instantiated, PDMs are set to nullptr
	Purpose: to create the foundation of a class
	*/
	OrdListClass(const OrdListClass& orig);
	/*
	Pre: needs to be instantiated with another class of the same type
	Post: a class that is an exact replica as the one entered in
	Purpose: to instantiate a class based on anther class, copy data + PDMs
	*/
	~OrdListClass();
	/*
	Pre: needs to be called
	Post: deletes a class
	Purpose: efficienty deallocation of memory
	*/
//~~~~~~~~~~~~~~~~~~~~~~~~~Traversing~~~~~~~~~~~~~~~~~~~~~~~~

	void FirstPosition();
	/*
	Pre: needs to be called
	Post: sets currPos to the lowest item in the list
	Purpose: to start at the beginning of the list
	*/
	void NextPosition();
	/*
	Pre: needs to be called
	Post: sets currPos to the next highest item in the list
	Purpose: to allow traversing through a list
	*/
	void LastPosition();
	/*
	Pre: needs to be called
	Post: sets currPos to the highest value in the list
	Purpose: to jump to the end of the list
	*/

//~~~~~~~~~~~~~~~~~~~~~~~~~Observer Predicators~~~~~~~~~~~~~~~

	bool IsEmpty();
	/*
	Pre: needs to be called
	Post: returns if root is nullptr
	Purpose: allow user to know if list is empty
	*/
	bool IsFull();
	/*
	Pre: needs to be called
	Post: returns if there is memory available , otherwise a OutofMemoryException will be thrown
	Purpose: to allow the user to know if the list is full
	*/
	bool EndofList();
	/*
	Pre: needs to be called
	Post: returns if currPos is nullptr
	Purpose: allow to user to traverse the list with an endpoint set (a while loop)
	*/
	bool IsBalanced();
	/*
	Pre: needs to be called
	Post: returns if the subtree heights are within 1 of each other
	Purpose: allows user to know if data is being stored efficiently
	*/
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Mutators~~~~~~~~~~~~~~~

	
	void Insert(itemT payload);
	/*
	Pre: needs to be given data to enter into the list
	Post: new data is in the list, duplicates will be dealt with a DuplicateKeyException
	Purpose:to add new items to the list
	*/
	void Delete(Keytype target);
	/*
	Pre: needs to be given a ID/Key to delete from the delete
	Post: if item found, it has been deleted otherwise a KeyNotThereException will be thrown
	Purpose: to delete an item from the list
	*/
	void Clear();
	/*
	Pre: needs to be called
	Post: the list has been deallocated
	Purpose: to delete the class efficiently
	*/

//~~~~~~~~~~~~~~~~~~~~~~~~~Observer Accesors~~~~~~~~~~~~~~~
	bool Find(Keytype target);
	/*
	Pre: needs to be given a target to find 
	Post:returns true if target is found, and false otherwise
	Purpose: to allow user to know if the item is in the list
	*/

	int ReturnLength();
	/*
	Pre: needs to be called
	Post: returns the number of elements in the list
	Purpose: to let the user know the length of the list
	*/
	itemT Retrieve();
	/*
	Pre: needs to be called
	Post: denoted by currPos, it returns the value in currPos, if currPos is nullptr or list is empty a KeyNotThereException will be thrown
	Purpose: to allow the user access to elements of the list
	*/

//~~~~~~~~~~~~~~~~~~~~~~~~~Operators~~~~~~~~~~~~~~~~~~~~~~~

	void operator=(const OrdListClass& orig);
	/*
	Pre: needs to be given another class to copy to "this" one
	Post: "this" list will be the same as the orig list
	Purpose: to assign one class to another
	*/
	OrdListClass operator + (const OrdListClass& otherList);
	/*
	Pre: needs to be given another class to merge with
	Post: adds each seperate key to the list and returns list, would throw Dupe Key Exception, 
	but large lists make this unrealistic to run, so a little message will be sent to inform 
	user they're data had a dupe key, this operation will rebalance the tree
	Purpose: to add two lists together without duplicates/balance tree
	*/
	OrdListClass operator - (const OrdListClass& otherList);
	/*
	Pre: needs to be given another class to subtract from
	Post: returns a list that has duplicate values completely removed from new list and balanced tree
	Purpose: to subtract two lists from each other / balance tree
	*/

	bool operator == (const OrdListClass& otherList) const;
	/*
	Pre: needs to be given another class to compare to
	Post: returns true if entire lists are the same, false otherwise
	Purpose: to determine if two lists are the same, let user know
	*/
	bool operator != (const OrdListClass& otherList) const;
	/*
	Pre: needs to be given another class to compare to
	Post: returns false if entire lists are the same, true otherwise
	Purpose: to determine if two lists are not the same, let user know
	*/

//~~~~~~~~~~~~~~~~~~~~~~~~~Prints/Summarizers~~~~~~~~~~~~~~~

	void PrintScreen(void Visit(itemT item));
	/*
	Pre: needs to be called
	Post:a printed list in ascending order is printed to the screen
	Purpose: print entire list to user
	*/
	void PrintFile(ofstream& dout, void Visit(itemT item, ofstream& dout));
	/*
	Pre:needs a file to print too
	Post:creates the file and outputs the contents of the list
	Purpose: to be able send data stored in this object to a file
	*/
	void PrintReverse(void Visit(itemT item));
	/*
	Pre: needs to be called
	Post: a printed list in descending order is printed to the screen
	Purpose: prints entire list to user
	*/
	void PrintAsExists(void Visit(itemT item));
	/*
	Pre: needs to be called
	Post: a printed structural view of how the data is stored, in this case a tree
	Purpose: gives a physical view of how their data is being stored
	*/

	//static void Visit(itemT item);
	/*
	Pre: needs to be given an item to print data from
	Post: data is printed to the screen
	Purpose: to print data inside a struct to the screen
	*/
	//static void Visit(itemT item, ofstream& dout);
	/*
	Pre: needs to be given an item to print data from and a file to print to
	Post: data is printed to the file
	Purpose: to print data inside a struct to the file
	*/

protected:
	void Balance();
	/*
	Pre: needs to be called (in IsBalance)
	Post: tree will be rebalanced
	Purpose: to make the tree more efficient and to make thanos proud
	*/

	node* reBuildTree(itemT arr[], int first, int last);
	/*
	Pre: needs to be given a sorted array, the first position and last position
	Post: returns a root of a new tree that has been built as best as possible
	Purpose: uses binary insert to insert the values in the most efficient manner to my knowledge
	*/

	itemT* TreeToArray();
	/*
	Pre: needs to be called
	Post: returns a pointer to a sorted array with all the data from the tree
	Purpose: to store the tree data into a sorted array, becoming very useful for rebuilds
	*/

	itemT* MergeTreesToArray(OrdListClass& tree1, OrdListClass& tree2, int& totalNodes);
	/*
	Pre: needs two class objects and the # of items from both
	Post: returns an array of all the different objects, balanced as well, as with operator +, it should
	throw dupe key exceptions, but with massive lists, this is not realistic
	Purpose: to take two tree and store their data as efficiently as possible (used heavily in operator+)
	*/

	itemT* FilterDupeTreesToArray(OrdListClass& tree1, OrdListClass& tree2, int& totalNodes);
	/*
	Pre: needs two class objects and the # of items from both
	Post: returns an array of all the different objects and rids of any found in both, balanced as well
	Purpose: to take two tree and store their data as efficiently as possible (used heavily in operator+)
	*/

	bool compareTree(node* tree1, node* tree2);
	/*
	Pre: needs two root nodes
	Post: returns true if trees are built the same (same structrue)
	Purpose: honestly no idea was going to use it for operator==, didn't need too. It works though :)
	*/

	node * IntOrdPred(node* currNode);
	/*
	Pre: needs a current node to start from
	Post: returns the node* that is highest value in the left subtree
	Purpose: to find a replacement in the case of a delete
	*/
	node * IntOrdSucc(node* currNode);
	/*
	Pre: needs a current node to start from
	Post: returns the node* that is lowest value in the right subtree
	Purpose: to find a replacement in the case of a delete
	*/

	node* FindParent(node* target, node* traverse);
	/*
	Pre: needs a node to traverse with and a target to find
	Post: returns parent node of the current node
	Purpose: to be able to traverse a tree easily, allowing for heading back up 
	*/

	bool IsThanosed(node* root);
	/*
	Pre: needs a root node
	Post: returns if the tree is balanced
	Purpose: to see if the tree's left and right subtree is within one height of each other at every level
	*/
	int getMaxHeight(node* traverse);
	/*
	Pre: needs a node to count to
	Post: returns the height of the node to the bottom of the tree
	Purpose: to get the height of the tree
	*/
	int helpHeight(int leftTree, int rightTree);
	/*
	Pre: needs two numbers
	Post: returns the larger
	Purpose: for comparing branches of a tree and sending up the largest
	*/
	void rCopyTree(node*& traverse, node* travCopy);
	/*
	Pre: needs to tree traversals starting a root node
	Post: a copied class object used to create a deep copy
	Purpose: creates a deep of copy of an a object, can be used in both copy constructor and operator=
	*/

	//~~~~~~~~~~~~~~~~~~~~~~~~~Recursive Mutators~~~~~~~~~~~~~~~
	node * rInsert(node* currNode, itemT payload);
	/*
	Pre: needs to be given the root intially and the data were entering
	Post: returns a pointer to root with changed tree
	Purpose: to insert new data into a list, will throw DuplicateKeyException if dupe found
	*/
	node* rDelete(node* currNode, Keytype target);
	/*
	Pre: needs to be given the root intially and the data were deleting
	Post: returns a pointer to root with changed tree
	Purpose: to delete an item from the list, will throw keyNotThereException if no key found
	*/
	bool rFind(node* currNode, Keytype target);
	/*
	Pre: needs to be given the root intially and the data were trying to find
	Post: returns true if key is found, false otherwise
	Purpose: to see if an item is in the list
	*/
	node* rClear(node* currNode);
	/*
	Pre: needs to be given the root to start
	Post: a deallocated tree
	Purpose: to rid of a tree efficiently
	*/

	//~~~~~~~~~~~~~~~~~~~~~~~Recursive Summarizers~~~~~~~~~~~~~`


	int rCountNodes(node* traverse);
	/*
	Pre: needs a root node intailly
	Post: returns the # of elements in the list
	Purpose: to head to bottom of tree and use recursion to count on the way back
	*/


	//~~~~~~~~~~~~~~~~~~~~~~~~~Recursive Prints~~~~~~~~~~~~~~~
	void rPrintScreen(node* traverse, void Visit(itemT item));
	/*
	Pre: needs to be given the node and a function to print out of
	Post: a printed list of the list in ascending order
	Purpose: to print the entire list
	*/
	void rPrintFile(node* traverse, ofstream& dout, void VisitToFile(itemT item, ofstream& dout));
	/*
	Pre: needs to be given the node and a function to print out of, and a of reader for the output file
	Post: a printed list of the list in ascending order to the file
	Purpose: to print the entire list
	*/
	void rPrintReverse(node* traverse, void Visit(itemT item));
	/*
	Pre: needs to be given the node and a function to print out of
	Post: a printed list of the list in descending order
	Purpose: to print the entire list backwards
	*/
	void rPrintExists(node* traverse, int level, int height, int height2);
	/*
	Pre: needs to be given the node, the levels, height and height again
	Post: prints the list how its being stored, level by level in our tree
	Purpose: to the structure of how the list is being stored
	*/


	
private:

	//~~~~~~~~~~~~~~~~~~~~~~~~~Class PDMs~~~~~~~~~~~~~~~~
	node* root; //anchored at first node
	node* prevPos;// for traversals always points to the inorder predecessor of currPos
	node* currPos;//for traversals

	//~~~~~~~~~~~~~~~~~~~~~~~~~Allocate new memory~~~~~~~~~~~~~~~
	node* Allocate();
	/*
	Pre: needs to be called
	Post: returns an allocated node
	Purpose: to allocate a new piece of memory
	*/
};


#include"TreeClass.cpp"

#endif // !TREE_H





