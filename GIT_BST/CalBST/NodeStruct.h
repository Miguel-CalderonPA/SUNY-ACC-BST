#pragma once
#ifndef NODE
#define NODE
#include"ItemType.h"
typedef int Keytype;

struct node
{	
	ItemType data;
	node* left;
	node* right;

};
#endif // NODE

