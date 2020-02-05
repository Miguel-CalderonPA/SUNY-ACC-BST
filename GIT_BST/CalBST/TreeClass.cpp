//Libaries
//#include"TreeClass.h"
#include<iomanip>
using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Constructors/Deconstructor~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//________Default Constructor__________
template <class itemT>
OrdListClass<itemT>::OrdListClass()
{// set PDMs
	root = nullptr;
	prevPos = nullptr;
	currPos = nullptr;
}

//________Copy Constructor__________
template <class itemT>
OrdListClass<itemT>::OrdListClass(const OrdListClass& orig)
{
	rCopyTree(root, orig.root);						// copy all data
	LastPosition();									// set to last position
	prevPos = currPos;								// set last to prev
	FirstPosition();								// set currPos to first
}													// if empty it will just copy nullptr 

//________Copy Constructor Helper__________
template <class itemT>
void OrdListClass<itemT>::rCopyTree(node*& traverse, node* travCopy)
{													// if other traverse is null
	if (travCopy == nullptr)
	{												// set all default pdms
		traverse = nullptr;
		currPos = nullptr;
		prevPos = nullptr;
	} // end if 
	else											// if other traverse is not null
	{
		traverse = Allocate();						//allocate new memory
		traverse->data = travCopy->data;			// copy data
		rCopyTree(traverse->left, travCopy->left);	// copy left subtree
		rCopyTree(traverse->right, travCopy->right); // copy right subtree
	} // end else
} // end helper copy constructor


//________Deconstructor__________
template <class itemT>
OrdListClass<itemT>::~OrdListClass()
{
	Clear(); //clears list
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Positional Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//________First Position__________
template <class itemT>
void OrdListClass<itemT>::FirstPosition()
{
	if (!IsEmpty())									// if list isn't empty
	{

		node* traverse = root;						// set to root
		while (traverse->left != nullptr)			// go as much left as possible
		{
			traverse = traverse->left;				// keep it going
		} // end while
		currPos = traverse;							// set currPos

		traverse = root;							// set to root
		while (traverse->right != nullptr)			// go as much right as possible
		{
			traverse = traverse->right;				// keep it going
		} // end 2nd while
		prevPos = traverse;							// set prevPos to traverse
	} // end if 

}

//________NextPosition__________
template <class itemT>
void OrdListClass<itemT>::NextPosition()
{
	if (!EndofList())
	{
		if (currPos->right != nullptr)					// if right of currPos isn't null
		{
			if (!EndofList())							// and list isn't at end of list
			{
				prevPos = currPos;						// set prev to curr
			} // end if 
			else										// if it is end of list
			{
				node* holdCurr = currPos;				// temp holder 
				LastPosition();							//set to last position
				prevPos = currPos;						//set prev to Last position
				currPos = holdCurr;						// preserve currPos
			}// end else
			node* localTraverse = currPos->right;		// now go all the way right
			while (localTraverse->left != nullptr)		// go left as much as possible
			{
				localTraverse = localTraverse->left;	// keep traversing left
			} // end if
			currPos = localTraverse;					// set currPos to localTraverse
		}
		else											// if right of currPos is a null
		{
			if (!EndofList())							// if not end of list
			{
				prevPos = currPos;						// reassign prev to currPos;
			} // end if 
			else
			{
				node* holdCurr = currPos;				// preserve currPos
				LastPosition();							// set to last position
				prevPos = currPos;						// copy last to prev
				currPos = holdCurr;						// also preserve
			}// end if
			node* parentNode = FindParent(currPos, root); // find parent node
			while (parentNode != nullptr && (parentNode->data.ID < currPos->data.ID))
			{ // while parent is nullptr, and parent data is less than current
				parentNode = FindParent(parentNode, root);
			}// end while

			currPos = parentNode;						// set parentNode to currPos;
		}
	} // if currPos is not null
	else
	{
		if (!IsEmpty())
		{
			FirstPosition();
		}
	}
}

//________NextPostition Helper, but can be used anywhere__________
template <class itemT>
node* OrdListClass<itemT>::FindParent(node* target, node* traverse)
{
	if (target == root)								// if root
	{
		return nullptr;								// base case
	}// if traverse if not null and target is the data OR traverse is not null and  also test to see if the same
	else if ((traverse->left != nullptr && traverse->left->data.ID == target->data.ID) || (traverse->right != nullptr && traverse->right->data.ID == target->data.ID))
	{
		return traverse;							// base casse 2
	} // end else if
	else											// if neither base case continue
	{
		if (target->data.ID < traverse->data.ID)
		{
			return FindParent(target, traverse->left);//keep searching in left subtree
		} // end if
		else
		{
			return FindParent(target, traverse->right); // keep searching in right subtree
		} // end else
	}// end else
} //end FindParent

//________LastPosition__________
template <class itemT>
void OrdListClass<itemT>::LastPosition()
{
	if (!IsEmpty()) // if not empty
	{
		prevPos = currPos;								// set previous to currPos

		node* traverse = root;							//copy root
		while (traverse->right != nullptr)				//keep traversing
		{
			traverse = traverse->right;					// keep going right
		}
		currPos = traverse;								//set currPos to what traverse was
	} // end if 

} // end LastPosition



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Observer Predicators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//________Empty__________
template <class itemT>
bool OrdListClass<itemT>::IsEmpty()
{
	return (root == nullptr);							//if root empty so is list
} // end IsEmpty

//________MAX__________
template <class itemT>
bool OrdListClass<itemT>::IsFull()
{
	node* IsFull;
	try
	{
		IsFull = new node;								//try allocating new memory, if failure return true
		delete IsFull;
		return false;
	}
	catch (bad_alloc)
	{
		throw OutOfMemoryException();					//throw memory didn't know which one 
		return (true);									//if here than out of memory
	}// end catch
} // end try

//________If currPos is at end of list__________
template <class itemT>
bool OrdListClass<itemT>::EndofList()
{
	return (currPos == nullptr);						//check where currPos is null
}// end EndOfList

//________If tree balanced__________
template <class itemT>
bool OrdListClass<itemT>::IsBalanced()
{
	if (IsThanosed(root))//check if balance
	{
		//cout << "THANOS is PROUD" << endl;
		return (true);
	}
	else
	{
		//cout << "Not Balanced! *SNAP*" << endl;
		Balance();
		return (false);
	}
							
} // end IsBalanced

//________IsBalancedHelper__________
template <class itemT>
bool OrdListClass<itemT>::IsThanosed(node* traverse)
{
	int leftTree;
	int rightTree;
	int diffTree;
	bool isLeftBalance, isRightBalance;
	if (traverse==nullptr)							//  base case
	{
		return true;
	} // end if 

	else												// if not base case
	{
		leftTree = getMaxHeight(traverse->left);		//find height of leftSubTree
		rightTree = getMaxHeight(traverse->right);		//find height of RightSubTree
		/* TESTING
		cout << "Left Tree is:" << leftTree << endl;
		cout << "Right Tree is:" << rightTree << endl;
		*/
		diffTree = (leftTree - rightTree);				 // find difference between heights

		isLeftBalance = (IsThanosed(traverse->left));	// check leftSubTree
		isRightBalance = (IsThanosed(traverse->right)); // check rightSubtree


		if(diffTree < 0)								//if negative
		{
			diffTree = (diffTree * -1);					//mulitply by -1 (a.k.a ABS())
		} // end if
		if((diffTree <= 1) && isLeftBalance && isRightBalance) //  if still balanceed and left and right are still balanced then good
		{
			return true;
		} // end if 2
		else // otherwise no ;(
		{
			return false;
		} // end else
	} //end else

} // end IsThansosed


//~~~~~~~~~~~~~~~~~~~~~~~~Observer Summarizers~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//_________Get Height______________
template <class itemT>
int OrdListClass<itemT>::getMaxHeight(node* traverse)
{
	int heightLeft, heightRight, totalHeight, parentHeight, parentNode = 1;
	
	if (traverse == nullptr)								// base case
	{
		return 0;
	} // end if 
	else													// if not null
	{
		heightLeft = getMaxHeight(traverse->left);			//get height of leftSubTree
		heightRight = getMaxHeight(traverse->right);		//getHeight of RightSubTree
		parentHeight = helpHeight(heightLeft, heightRight);	//get helper to check which is better
		totalHeight = parentHeight + parentNode;			// add up largest height with parent node
		return (totalHeight);								// return height
	} // end else
} // end Get Height

//_____________Height Helper__________________
template <class itemT>
int OrdListClass<itemT>::helpHeight(int leftTree, int rightTree)
{
	if (leftTree >= rightTree)								//if left bigger
	{
		return leftTree;									// go left
	} // end if
	else													//otherwise
	{
		return rightTree;									//go right
	} // end else

} // end height helper


//____________Attempted Balance, breaks everything______________

template <class itemT>
void OrdListClass<itemT>::Balance()
{
	if (!IsEmpty())
	{
		itemT* itemArr;
		int first, last = ReturnLength();					//list counter
		itemArr = new itemT[last];						//create runtiime array
		itemArr = TreeToArray();							// set to a tree to array
		first = 0;											//set first to 1 element in array
		/* TESTING
		for (int i = 0; i < last; i++)						
		{
			cout << itemArr[i].ID << endl; // testing
		} // end for 
		*/
	Clear();
		
	root = reBuildTree(itemArr, first, last-1);				//attempt to rebalance 
	} // end if
} // end balance




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Mutators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Recursive Mutators~~~~~~~~~~~~~~~~~~~~


//_____________Find________________
template <class itemT>
bool OrdListClass<itemT>::Find(Keytype target)
{
	bool found = false;
	if (!IsEmpty())											//if not empty
		found = rFind(root, target);						// send root and target

	return found;
}

//______________Recursive Find____________________
template <class itemT>
bool OrdListClass<itemT>::rFind(node* currNode, Keytype target)
{
	bool found;
	if (currNode == nullptr)								// if not empty
	{
		found = false;										// return empty
	} // end if
	else if (currNode->data.ID == target)					// if found
	{
		found = true;										// found it!
	} // end else if
	else if (currNode->data.ID > target)					// if greater go left
	{
		found = rFind(currNode->left, target);
	} // end else if 
	else													// if less go Right
	{
		found = rFind(currNode->right, target);				//keep searching
	}// end else if 
	return found;

} // end rFind



//_____________Insert________________
template <class itemT>
void OrdListClass<itemT>::Insert(itemT payload)
{
	if (!IsEmpty())										// if not empty
	{
		root = rInsert(root, payload);					// go through recursion call
	} // end if 
	else
	{
		root = Allocate();								//Create new memory
		root->data = payload;							// copy data
		LastPosition();									//set to last pos
		prevPos = currPos;								// reassign prevPos
		FirstPosition();								//set currPos to first
	} // end else
} // end Insert

//_______________Recursive Insert_____________________
template <class itemT>
node* OrdListClass<itemT>::rInsert(node* currNode, itemT payload)
{
	if (currNode == nullptr)							//if traverse is null
	{
		node* temp = Allocate();						// create new memory
		temp->data = payload;							//copy data
		return temp;									// add to Tree
	}// end if
	else if (currNode->data.ID == payload.ID)			// if same, delete it
	{
		throw DuplicateKeyException();					// throw exception
	}// end else if 
	else if (currNode->data.ID > payload.ID)			// if trav > payload keep searching
	{
		currNode->left = rInsert(currNode->left, payload);
	}// end else if 

	else
	{
		currNode->right = rInsert(currNode->right, payload);// if payload is < keep serarching
	}// end else
	return currNode;
}// end rInsert



//_____________Delete________________
template <class itemT>
void OrdListClass<itemT>::Delete(Keytype target)
{
	root = rDelete(root, target);							//call delete with root and target
} // end delete

//_______________Recursive Delete____________
template <class itemT>
node* OrdListClass<itemT>::rDelete(node* currNode, Keytype target)
{
	if (currNode == nullptr)								// if null
	{
		cout << "You are silly" << endl;					// let user know
		throw KeyNotThereException();
		return nullptr;
	} // end if 
	else if (currNode->data.ID < target)					// if target is larger keep searching
	{
		currNode->right = rDelete(currNode->right, target); // send in the right subtree
		return(currNode);
	} // end else if 
	else if (currNode->data.ID > target)					// if target is less keep searchinh
	{
		currNode->left = rDelete(currNode->left, target);	// send in the left subtree
		return(currNode);
	}// end else if 

	else // if no direct child
	{
		bool leftChild = currNode->left != nullptr;			//bool redefintion of currNode->left
		bool rightChild = currNode->right != nullptr;		//bool redefintion of currNode->right

		if(!leftChild && !rightChild) // if leaf node
		{
			if (currNode == prevPos)						//precaution for user
				prevPos = nullptr;							//precaution for user
			if (currNode == currPos)						//precaution for user
				currPos= nullptr;							//precaution for user

			delete currNode;								//begone
			currNode = nullptr;								// no need technically because leaves scope
			return nullptr;			
		} // end if 
		else if (!leftChild || !rightChild)					// if not 2 children
		{
			if (leftChild)									// if left child
			{
				node* temp = currNode->left;				// temp gets left node

				if(currNode == prevPos)						//precaution for user
					prevPos = nullptr;						//precaution for user
				if (currNode == prevPos)					//precaution for user
					currPos = nullptr;						//precaution for user

				delete currNode;							//begone
				currNode = nullptr;							// good practice
				return (temp);
			} // end if 
			else											//if right child
			{
				node* temp = currNode->right;				// go right

				if(currNode == prevPos)						//precaution for user
					prevPos = nullptr;						//precaution for user	
				if (currNode == prevPos)					//precaution for user
					currPos = nullptr;						//precaution for user

				delete currNode;							//begone
				currNode = nullptr;							//good practive
				return temp;
			} // end else

		} // end if
		else
		{
			node* temp = IntOrdPred(currNode);				// get In-OrderPred	
			currNode->data = temp->data;					// copy data
			currNode->left = rDelete(currNode->left, temp->data.ID); // recursively left
			return currNode;
		} // end if 
	}// end else
} // end r delete



//_____________Clear________________
template <class itemT>
void OrdListClass<itemT>::Clear()
{
	//if(!IsEmpty())
	root = rClear(root);									// destroy tree
} // end clear


//______________Recursive Clear____________________
template <class itemT>
node* OrdListClass<itemT>::rClear(node* currNode)
{
	if (currNode == nullptr)								// if null
	{
		return nullptr;
	} // end if
	else
	{
		currNode->left = rClear(currNode->left);			//clear left subtree
		currNode->right = rClear(currNode->right);			//clear right subtree
		delete currNode;									//begone
		return nullptr;										//good practive
	} // end else
}// end rClear


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Observer Accesors~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//_________ReturnLength___________
template <class itemT>
int OrdListClass<itemT>::ReturnLength()
{
	return (rCountNodes(root));								// returns total nodes for tree
}//end Return Length


//______Recursive Return Length_________
template <class itemT>
int OrdListClass<itemT>::rCountNodes(node* traverse)
{
	int countLeft, countRight;
	int root = 1;

	if (traverse == nullptr)								//if null
	{
		return 0;
	}// end if
	else
	{
		countLeft = rCountNodes(traverse->left);			// count left subtree
		countRight = rCountNodes(traverse->right);			//count right substree

		return (countLeft +countRight + root);				//returns counts + self
	}// end else
}// end count nodes



//__________________Retrieve___________________________
template <class itemT>
itemT OrdListClass<itemT>::Retrieve()
{
		if (!IsEmpty())										// if not list can't retrieve				
		{
			if (!EndofList())								// if not end of list return data
			{
				return (currPos->data);						//data
			} // end if
			else
			{
				throw KeyNotThereException();				//let user know
			}// end else
		}
		else
		{
			throw KeyNotThereException();					//let user know
		}// end else
}// end Retrieve


//__________________Presuccessor_______________________________
template <class itemT>
node* OrdListClass<itemT>::IntOrdPred(node* traverse)
{
	traverse = traverse->left;								//go left once
	while (traverse->right != nullptr)						//then right as possibly allowed
	{
		traverse = traverse->right;							// keep going right
	}// end while
	return traverse;
} // end InOrdPred


//_________________Successor______________________________
template <class itemT>
node* OrdListClass<itemT>::IntOrdSucc(node* traverse)
{
	traverse = traverse->right;								//go right once
	while (traverse->left != nullptr)						//then left as possibly allowed
	{
		traverse = traverse->left;							// keep going left
	}// end while
	return traverse;
}// end IntOrdSucc



//~~~~~~~~~~~~~~~~~~~~~~~~~Prints/Summarizers~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~Recursive Prints~~~~~~~~~~~~~~~~~~~~

//__________PrintScreen (InOrder)___________
template <class itemT>
void OrdListClass<itemT>::PrintScreen(void Visit(itemT item))
{
	if (!IsEmpty())											//if not empty
	{
		rPrintScreen(root, Visit);							// set root and function to print
	} // end if 
	else
	{	
		cout << "List is Empty" << endl;			//otherwise just let them know
	} // end else
} // end PrintScreem

//__________Recursive PrintScreen ___________
template <class itemT>
void OrdListClass<itemT>::rPrintScreen(node* traverse, void Visit(itemT item))
{
	if (traverse != nullptr)								// if not null
	{
		node* leftTree = traverse->left;					// set left
		node* rightTree = traverse->right;					//set right
		node* currNode = traverse;							//assign current

		rPrintScreen(leftTree, Visit);						// visit left subtree nodes first
		Visit(currNode->data);								// the print function is given to us
		rPrintScreen(rightTree, Visit);						// visit right subtree nodes last
	} // end if 
} // end rPrintScreen


//__________PrintFile (InOrder)___________
template <class itemT>
void OrdListClass<itemT>::PrintFile(ofstream& dout, void Visit(itemT item, ofstream& dout))
{
						//Opening file
	if (!IsEmpty())											// if not empty
	{
		rPrintFile(root, dout, Visit);						// send ofstream, root and function to print
	} //end if
	else													// if empty
	{
		dout << "List is Empty" << endl;					//let user know
	} // end else
	dout.close();											//close file reader
} // end PrintFile

//___________Recursive PrintFile__________
template <class itemT>
void OrdListClass<itemT>::rPrintFile(node* traverse, ofstream& dout, void Visit(itemT item, ofstream& dout))
{
	if (traverse != nullptr)								// if not null
	{
		node* leftTree = traverse->left;					//set leftSubTree
		node* rightTree = traverse->right;					//set rightSubTree
		node* currNode = traverse;							//Assign current
		
		rPrintFile(leftTree,dout,Visit);					// print left subTree first
		Visit(currNode->data, dout);						//visit self and print
		rPrintFile(rightTree, dout, Visit);					// print right subTree 
	} // end if
} // end rPrintFile

//______________Print Reverse________________
template <class itemT>
void OrdListClass<itemT>::PrintReverse(void Visit(itemT item))
{
	if (!IsEmpty())											//if not empty
	{
		rPrintReverse(root, Visit);							// send root and function
	}// end if 
	else													//if empty
	{
		cout << "r List is Empty" << endl;			//let user know
	} // end else
} // end PrintReverse

//______________Recursive PrintReverse_____________
template <class itemT>
void OrdListClass<itemT>::rPrintReverse(node* traverse, void Visit(itemT item))
{
	if (traverse != nullptr)								//if not null
	{
		node* leftTree = traverse->left;					//set left node
		node* rightTree = traverse->right;					//set right node
		node* currNode = traverse;							//assign current

		rPrintReverse(rightTree, Visit);					//print right tree
		Visit(currNode->data);								//print self
		rPrintReverse(leftTree, Visit);						//print left tree
	} // end if 
}// end rPrintReverse

//____________PrintAsExists______________
template <class itemT>
void OrdListClass<itemT>::PrintAsExists(void Visit(itemT item))
{
	if (!IsEmpty())											//if not empty
	{
		int length = ReturnLength();						//get length of list
		int height = getMaxHeight(root);					//get height of list
		for (int i = 0; i < height; i++)					// for each level do this
		{
			rPrintExists(root, i+1, height, height);		//send in root, level+1, height and length
			cout << endl<<endl;
		} // end for
	} // end if
	else
	{
		cout << "Nothing Exists, not even your world, this is just a simulation, BLUE PILL? or RED PILL?" << endl;
	}
}// end PrintAsExists

//____________Recursive PrintAsExists________________
template <class itemT>
void OrdListClass<itemT>::rPrintExists(node* traverse, int level, int height, int setIndent)
{
	string indent, endent;
	if (setIndent == 5)										//if large lists use smaller seperators
		indent = "-";
	else if (setIndent < 5)									// for heights 1-4
		indent = "--";
	else
		indent = "";
	int strLength;
	for( int i = 0; i <= height; i++)						//for each height assign space
	{
		indent = indent + indent;							//concatenation
		
	} // end for
	strLength = indent.length();
	if (setIndent < 6)										// if less than 6 otherwise just prints by level
	{
		if (strLength > 4)									//as length shrinks this becomes useless
		{
			endent = indent.substr(5);
		} // end if 
		else if (strLength <= 4)							//if around or at 4 you have to change it a little
		{
			//indent = indent.substr(1);					// get an indent with one less space
			endent = "";
		} // end else if 
		else												// if really low than no spacing
		{
			indent = "";
			endent = "";
		} // end else
	}
	if (traverse == nullptr)								//if null
	{
		if(setIndent<6)
		cout << indent <<  "-----" << endent;	//skip over it
		else
		cout << indent << "(NUL)" << endent;
	} // end if 
	else if (level==1)										//if base case level
	{
		cout << indent << '(' << left << setw(3)<< traverse->data.ID << ')'<<endent;
	} // end else if
	else
	{
		rPrintExists(traverse->left, level - 1,height-1,setIndent); // go down left tree
		rPrintExists(traverse->right, level - 1,height-1, setIndent); // go down right tree
	} // end else
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Operators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//_____________Assignment Overload______________
template <class itemT>
void OrdListClass<itemT>::operator=(const OrdListClass& orig)
{
	Clear();												//clears tree
	rCopyTree(root, orig.root);								//builds new tree
}

//____________Addition Operator Overload________
template <class itemT>
OrdListClass<itemT> OrdListClass<itemT>::operator + (const OrdListClass& otherList)
{
	OrdListClass thisList(*this);							// copy "this" list		
	OrdListClass other(otherList);							// copy "otherList"
	OrdListClass UnionList;									// where final list will be
	itemT* itemArr;
	int last;
	int first;
	
	if (thisList.IsEmpty())									//if this empty
	{
		if (other.IsEmpty())								//if other empty
		{
			return UnionList;								//return empty
		}
		else												//else return 
		{
			return (other);									//empty list
		}
	} // end if
	else if (other.IsEmpty())								// if just other is empty
	{
		return thisList;									//return thisList
	} // end else if
	else if (other.ReturnLength() == 1 && thisList.ReturnLength() == 1)
	{
		if (other.root->data.ID == thisList.root->data.ID)
		{
			return thisList;
		}
		else
		{
			UnionList.Insert(other.root->data);
			UnionList.Insert(thisList.root->data);
			return UnionList;
		}
	}

	else													//if both lists have values in them
	{
		itemArr = MergeTreesToArray(thisList, other,last);	//store both into one array
		first = 0;											//set first to 1
		UnionList.root=reBuildTree(itemArr, first, last-1);	//plug new root in and you have a new tree

		return UnionList;
	} // end else

}// end operator =

//____________BORING Addition Operator Overload________

/*
BORING OPERATOR + w/ rebalance
template <class itemT>
OrdListClass OrdListClass<itemT>::operator + (const OrdListClass& otherList)
{
	OrdListClass UnionList(*this);							//copy "this" list
	OrdListClass other(otherList);							//copy otherlist
	itemT* itemArr;
	int last;
	int first;

	if (UnionList.IsEmpty())								// if union empty
	{
		if (other.IsEmpty())								//if other empty too
		{
			return UnionList;								// return empty list
		} // end if
		else												// if other not empty
		{
			return other;									// return other
		} // end else
	} // end if
	else if (other.IsEmpty())								//if other list are empty
	{
		return UnionList;									//return thislist
	} // end else if
	else													//if no lists empty
	{
		other.FirstPosition();								//set to first position

		while (!other.EndofList())							//while not at end of otherlist
		{
			if (UnionList.Find(other.Retrieve().ID))		//get otherlist id and find in this list
			{
				cout << "Dupe Key" << endl;					// if found add only 1
				//throw DuplicateKeyException();
			}// end if
			else											// otherwise just insert
			{
				UnionList.Insert(other.Retrieve());			//insert
			} // end else
			other.NextPosition();							// next pos

		} // end while


		return UnionList;	
	}// end else

} // end operator +

*/

//____________Subtraction Operator Overload________
template <class itemT>
OrdListClass<itemT> OrdListClass<itemT>::operator - (const OrdListClass& otherList)
{
	OrdListClass thisList(*this);							//copy "this" list
	OrdListClass other(otherList);							//copy otherList
	OrdListClass diffList;
	itemT* itemArr;
	int last;
	int first;

	if (thisList.IsEmpty())									// if this list empty
	{
		if (other.IsEmpty())								//check other list, if empty
		{
			return diffList;								//return empty list
		}// end if
		else
		{
			return other;									//if full return otherlist
		} // end else
	} // end if
	else if (other.IsEmpty())								// if other list is empty
	{
		return thisList;									//return thisList
	} // end else if 

	else if (other.ReturnLength() == 1 && thisList.ReturnLength() == 1)
	{
		if (other.root->data.ID == thisList.root->data.ID)
		{
			return diffList;
		}
		else
		{
			diffList.Insert(other.root->data);
			diffList.Insert(thisList.root->data);
			return diffList;
		}
	}
	else
	{
		itemArr = FilterDupeTreesToArray(thisList, other, last); // filter both trees into array
		first = 0;											//set first to 1
		diffList.root = reBuildTree(itemArr, first, last-1); //plug new root in and you have a new tree

		return diffList;
	} // end else
}// end operator -


//____________Subtraction Operator Overload________

/*
BORING OPERATOR - 
template <class itemT>
OrdListClass OrdListClass<itemT>::operator - (const OrdListClass& otherList)
{
	OrdListClass diffList(*this);							//copy "this" list
	OrdListClass other(otherList);							//copy "otherList"
	itemT* itemArr;										
	int last;
	int first;

	if (diffList.IsEmpty())									//if diff empty
	{
		if (other.IsEmpty())								//and other empty
		{
			return diffList;								// return empty
		} // end if
		else												// if  other not empty
		{
			return other;									//return other
		} // end else
	} // end if
	else if (other.IsEmpty())								// if only other empty
	{
		return diffList;									//return "this"
	} // end else if
	else													// if both aren't empty
	{	
		other.FirstPosition();								// start at first pos for other list

		while (!other.EndofList())							// while not at end of other list
		{
			if (diffList.Find(other.Retrieve().ID))			//if you find other key in this list
			{
			//	cout << "Dupe Key" << endl;
				diffList.Delete(other.Retrieve().ID);		//delete it
				//throw DuplicateKeyException();
			} // end if
			else											// if you don't find it
			{
				diffList.Insert(other.Retrieve());			// insert it
			} // end else
			other.NextPosition();							//next pos

		} // end while

		return diffList;
	} // end operator -

}*/

//_____________Convert Tree to Array (does job, can't confirm due to balance not working)____
template <class itemT>
itemT* OrdListClass<itemT>::TreeToArray()
{
	int totalNodes;
	itemT* arr;
	itemT item;

	totalNodes = ReturnLength();							//get length of list
	arr = new itemT[totalNodes];						// set array at runtime

	FirstPosition();										//set to first position
	for (int i = 0; i <totalNodes; i++)
	{
		if(!EndofList())
		item = Retrieve();

		arr[i] = item;
			
			if(!EndofList())								//get item at that position and store it in array
			NextPosition();									//next pos
			/*
			cout << "ID: " << arr[i].ID << endl;
			cout << "String: " << arr[i].MoreData << endl;
			*/		
	}// end for
	
	return  arr;										//give back an array
}// end TreeToArray()

//_______________Merge two trees into one arry (helps addition operator)_____________
template <class itemT>
itemT* OrdListClass<itemT>::MergeTreesToArray(OrdListClass& tree1, OrdListClass& tree2, int& totalNodes)
{
	//int totalNodes;
	itemT* itemArr;
	itemT thisItem, otherItem;

	totalNodes = tree1.ReturnLength() + tree2.ReturnLength();	//get total # of nodes for both lists
	itemArr = new itemT[totalNodes];						//declare a runtime array

	tree1.FirstPosition();									//set both lists to first pos
	tree2.FirstPosition();

	for (int i = 0; i < totalNodes; i++)					//for each node
	{
		if (!tree1.EndofList())								//preserve for user
			thisItem = tree1.Retrieve();					//precaution for user
		if (!tree2.EndofList())								//precaution for user
			otherItem = tree2.Retrieve();					//precaution for user

		if (thisItem.ID == otherItem.ID)					//if keys are same
		{
			cout << "Dupe Key not added" << endl;	
			itemArr[i] = thisItem;							//don't add both and subtract from total nodes
			totalNodes--;
			//throw DuplicateKeyException();

			if(!tree2.EndofList())							// if not end of list tree2 nextpos
			{
				tree2.NextPosition();
			} // end if
						
			if (!tree1.EndofList())							// if not end of list tree1 nextpos
			{
				tree1.NextPosition();
			} // end if
			//testing
			//cout << "ID: " << itemArr[i].ID << endl;
		}// end if 
		else if (thisItem.ID > otherItem.ID && !tree2.EndofList())				//whatever ID is smallest goes into list
		{
			
				itemArr[i] = otherItem;							//copy to array
				/*	Testing
				cout << "ID: " << itemArr[i].ID << endl; */
				tree2.NextPosition();
				if (tree2.EndofList())							//preserve
				{
					otherItem.ID = thisItem.ID + 1;					//basically a flag
				} // end if

		}// end else if
		else if (otherItem.ID > thisItem.ID && !tree1.EndofList())	//whatever ID is smallest goes into lis
		{
				itemArr[i] = thisItem;							//copy to array
			/*	Testing
				cout << "ID: " << itemArr[i].ID << endl; */
				tree1.NextPosition();							// go next
				if (tree1.EndofList())							//check next
				{
					thisItem.ID = otherItem.ID + 1;				// basically a flag now
				}
		} // end else if
		else												// only gets here if a tree is at end of list
		{
			if (thisItem.ID > otherItem.ID)					// only gets here if tree2 is done
			{
				itemArr[i] = thisItem;						// add to array remaining values
				tree1.NextPosition();						// next
			} // end if
			else											// only gets here if tree1 is done
			{
				itemArr[i] = otherItem;						// add remaining values
				tree2.NextPosition();						//next
			} // end else
			
			/*Testing
			cout << "ID: " << itemArr[i].ID << endl;
			*/
		}// end else
		
	}// end for
	return (itemArr); // returned array
} // end Merge Arrays 

//____________Filter Arrays (helps subtraction operator)________
template <class itemT>
itemT* OrdListClass<itemT>::FilterDupeTreesToArray(OrdListClass& tree1, OrdListClass& tree2, int& totalNodes)
{
	itemT* itemArr;
	itemT thisItem, otherItem;

	totalNodes = tree1.ReturnLength() + tree2.ReturnLength(); // get total # of nodes
	itemArr = new itemT[totalNodes];						//an array created at runtime

	tree1.FirstPosition();									//set both lists to first position
	tree2.FirstPosition();

	for (int i = 0; i < totalNodes; i++)					// for each node
	{
		if (!tree1.EndofList())								//preserve for user		
		{
			thisItem = tree1.Retrieve();					//preserve for user
		}// end if
		if (!tree2.EndofList())								//preserve for user
		{
			otherItem = tree2.Retrieve();					//preserve for user
		} // end if

		if (thisItem.ID == otherItem.ID)					//if keys the same
		{
			totalNodes = totalNodes - 2;					//don't add either and delete 2 from max

			if (!tree2.EndofList())							//preserve for user
			{
				tree2.NextPosition();						//preserve for user
			} // end if
				
			if (!tree1.EndofList())							//preserve for user
			{
				tree1.NextPosition();						//preserve for user
			} // end if
				

			i--;											// rid of iteration
		}// end if 
		else if (thisItem.ID > otherItem.ID && !tree2.EndofList())				// if greater ID add the opposite
		{
			itemArr[i] = otherItem;
		/*Testing	cout << "ID: " << itemArr[i].ID << endl;*/
			if (!tree2.EndofList())							//preserve for user
			{
				tree2.NextPosition();						//preserve for user
			} // end if
				
		} //end else if
		else if (otherItem.ID > thisItem.ID && !tree1.EndofList()) // if greater ID add the opposite
		{
			itemArr[i] = thisItem;
		/*Testing	cout << "ID: " << itemArr[i].ID << endl; */
			if (!tree1.EndofList())							//preserve for user
			{
				tree1.NextPosition();						//preserve for user
			} // end if
				
		} // end else if
		else
		{
			if (thisItem.ID > otherItem.ID)					//if tree2 is done, control goes here
			{
				itemArr[i] = thisItem;						// copy data
				tree1.NextPosition();						// next
			} // end if
				
			else											// if tree 1 is done, control goes here
			{
				itemArr[i] = otherItem;						// copy data
				tree2.NextPosition();						// next
			} // end if
			/*testing
			cout << "ID: " << itemArr[i].ID << endl; */
		} // end else

	}// end for
	return  itemArr;
}// end filterArrays

//____________reBuildTree Method________
template <class itemT>
node* OrdListClass<itemT>::reBuildTree(itemT arr[], int first, int last)
{// BINARY INSERT
	int midpt;
	if (first > last)										//if start stil less than keep going
	{
		return nullptr;										//if so then return nullptr
	} // end if
	else													//otherwise calc midpt
	{
		midpt = (first + last) / 2;							
		node* middle = Allocate();							// new parent node
		middle->data= arr[midpt];


		middle->left = reBuildTree(arr, first, midpt - 1);	// send left child subtree
		middle->right = reBuildTree(arr, midpt + 1, last);	// send in right child subtree

		return middle;

	}// end else
}

//____________Equality Operator Overload________
template <class itemT>
bool OrdListClass<itemT>::operator == (const OrdListClass& otherList) const
{
	OrdListClass thisList(*this);							//copy of "this"	
	OrdListClass other(otherList);							//copy of "otherList"

	if (other.ReturnLength() != thisList.ReturnLength()) // check lengths 
	{
		return false; // if not equal
	} // end if
	else
	{
		other.FirstPosition();								//set both lists to first position
		thisList.FirstPosition();

		while (!other.EndofList() && (!thisList.EndofList()))	// scroll through both lists until mismatch found
		{
			if (other.Retrieve().ID == thisList.Retrieve().ID)	// check IDs
			{
				other.NextPosition();							//next pos both lists
				thisList.NextPosition();
			} //end if
			else												//otherwise not equal return false
			{
				return (false);
			}// end else

		}// end while
		return (true); 
	}
}

//____________!Equal Operator Overload________
template <class itemT>
bool OrdListClass<itemT>::operator != (const OrdListClass& otherList) const
{
	return(!(operator==(otherList)));							//just ! my == operator		
}// end operator-



//~~~~~~~~~~~~~~~~Other Features~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`

//_____________Compares the structure of tree_____________________
template <class itemT>
bool OrdListClass<itemT>::compareTree(node* tree1, node* tree2)
{
	if ((tree1 == nullptr) && (tree2 == nullptr)) // base case if still true
	{
		return true;//\(0_0)/
	}// end if
	else if(tree1->data.ID==tree2->data.ID) // if still equal keep going
	{
		return (compareTree(tree1->left, tree2->left) && (compareTree(tree1->right, tree2->right)));
	}// end else if
	else // if not equal 
	{
		return false; // <(-_-)>
	} // end else
}

//________________Allocate______________________________
template <class itemT>
node* OrdListClass<itemT>::Allocate()
{
	node* temp = new node;								//create memory
	temp->left = nullptr;								//set null to left
	temp->right = nullptr;								//set null to right
	return temp;										//give back
}// end Allocate

