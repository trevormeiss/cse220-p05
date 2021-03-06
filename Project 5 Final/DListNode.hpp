//**************************************************************************************************************
// CLASS: DListNode
//
// DESCRIPTION
// Declares a class that represents each node in the doubly-linked list class, DList.
//
// AUTHOR INFORMATION
// Kevin R. Burger [KRB]
//
// Mailing Address:
// Computer Science & Engineering
// School of Computing, Informatics, and Decision Systems Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
// Email: burgerk@asu
// Web:   http://kevin.floorsoup.com
//**************************************************************************************************************
#ifndef DLISTNODE_HPP
#define DLISTNODE_HPP

#include <string>
using std::string;

#include "DListData.hpp"

// Forward declaration. Tell the compiler that DList is a class. This line is necessary because:
//
// 1. This file does not include "DList.hpp", and
// 2. We declare the DList class to be a friend of the DListNode class below.
class DList;

// Forward declaration. Tell the compiler that DListIterator is a class. Same reason.
class DListIterator;

//==============================================================================================================
// CLASS: DListNode
//==============================================================================================================
class DListNode {
    
	//==========================================================================================================
	// FRIENDS
	//==========================================================================================================
    
	friend class DList;
	friend class DListIterator;
    
public:
	//==========================================================================================================
	// PUBLIC FUNCTION MEMBERS
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// Default ctor. Initializes mData to 0. Initializes mNext and mPrev to null.
	//----------------------------------------------------------------------------------------------------------
	DListNode();
    
	//----------------------------------------------------------------------------------------------------------
	// Another ctor. Initializes mData to pData, mNext and mPrev to null.
	//----------------------------------------------------------------------------------------------------------
	DListNode(tDListData const pData);
    
	//----------------------------------------------------------------------------------------------------------
	// Another ctor. Initializes mData to pData, mNext to pNext, and mPrev to pPrev.
	//----------------------------------------------------------------------------------------------------------
	DListNode(tDListData const pData, DListNode * const pPrev, DListNode * const pNext);
    
	//----------------------------------------------------------------------------------------------------------
	// Copy ctor. Makes this DListNode an identical copy of pNode.
	//----------------------------------------------------------------------------------------------------------
	DListNode(DListNode const& pNode);
    
	//----------------------------------------------------------------------------------------------------------
	// Destructor. Does nothing because there are no dynamically-allocated objects to delete.
	//----------------------------------------------------------------------------------------------------------
	~DListNode()
	{
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Accessor function for mData.
	//----------------------------------------------------------------------------------------------------------
	tDListData Data() const
	{
		return mData;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for mData.
	//----------------------------------------------------------------------------------------------------------
	void Data(tDListData const pData)
	{
		mData = pData;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Accessor function for mNext.
	//----------------------------------------------------------------------------------------------------------
	DListNode *Next() const
	{
		return mNext;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for mNext.
	//----------------------------------------------------------------------------------------------------------
	void Next(DListNode * const pNext)
	{
		mNext = pNext;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Returns a string representation of this DListNode. Intended for testing and debugging only.
	//----------------------------------------------------------------------------------------------------------
	operator string() const;
    
	//----------------------------------------------------------------------------------------------------------
	// Accessor function for mPrev.
	//----------------------------------------------------------------------------------------------------------
	DListNode *Prev() const
	{
		return mPrev;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for mPrev.
	//----------------------------------------------------------------------------------------------------------
	void Prev(DListNode * const pPrev)
	{
		mPrev = pPrev;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads the assignment = operator.
	//----------------------------------------------------------------------------------------------------------
	DListNode& operator=(DListNode const& pNode);
    
protected:
	//==========================================================================================================
	// PROTECTED FUNCTION MEMBERS
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// Makes this DListNode an identical copy of pNode.
	//----------------------------------------------------------------------------------------------------------
	DListNode& Copy(DListNode const& pNode);
    
private:
	//==========================================================================================================
	// PRIVATE DATA MEMBERS AND FUNCTION MEMBERS
	//==========================================================================================================
    
	tDListData  mData;
	DListNode  *mNext;
	DListNode  *mPrev;
};

//==============================================================================================================
// NONMEMBER FUNCTION PROTOTYPES
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Overloads the stream insertion operator << so DListNode objects may be sent to an output stream. This is
// primarily designed for testing and debugging.
//--------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& pStream, DListNode const& pNode);

#endif
