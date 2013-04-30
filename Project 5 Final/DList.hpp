//**************************************************************************************************************
// CLASS: DList
//
// DESCRIPTION
// Declares a class the represents a doubly-linked list.
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
#ifndef DLIST_HPP
#define DLIST_HPP

#include <cstddef>  // For size_t data type.

#include <string>
using std::string;

#include "DListData.hpp"
#include "DListIterator.hpp"

// Tell the compiler that DListIterator is a class.
class DListIterator;

// Tell the compiler that DListNode is a class.
class DListNode;

//--------------------------------------------------------------------------------------------------------------
// REMARK ON INCLUDING HEADER FILES
//
// We can get away without including DListNode.hpp in this source code file, and in DList.cpp, because the only
// use of the DListNode class in these files is in the context of specifying types which are pointers to DList-
// Node objects. That is, the only use of DListNode in this file, and in DList.cpp, is by writing "DListNode *"
// when specifying the type of something (a data member, return value from a function, function parameter).
// Since the size of a a pointer is the same, regardless of the data type of the data to which the pointer
// points, the compiler does need to know information about the internal details of DListNode (since we are not
// writint code that accesses internal data or function members. All the compiler needs to know is that DList-
// Node is a class, and so that is what we told it in the "class DListNode;" line above. If the only use of
// DListNode in these files was by specying the types of things as "DListNode&", we also would not need to in-
// clude DListNode.hpp because references are really just pointers as well. In general, the fewer header files
// a source code file includes, the better, because that source code file will compile more quickly, so this
// little trick could (some one would say should) be used to speed things up.
//
// Notice that DListIterator.hpp *is* included, because within this code, we use DListIterator *not* in the
// context of DListIterator* or DListIterator&. For example, the return value from the Iterator() function is a
// DListIterator object. Consequently, in order to generate the code for that function, the compiler must know
// information about the internals of a DListIterator object. And where does it get that information? From the
// class declaration in the DListIterator.hpp header file.
//--------------------------------------------------------------------------------------------------------------

//==============================================================================================================
// CLASS: DList
//==============================================================================================================
class DList {
    
	//==========================================================================================================
	// FRIENDS
	//==========================================================================================================
    
	friend class DListIterator;
    
public:
	//==========================================================================================================
	// PUBLIC FUNCTION MEMBERS
	//=========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// Default ctor. Initializes the list to be empty.
	//----------------------------------------------------------------------------------------------------------
	DList();
    
	//----------------------------------------------------------------------------------------------------------
	// Copy ctor. Makes this DList a *deep* copy of pList.
	//----------------------------------------------------------------------------------------------------------
	DList(DList const& pList);
    
	//----------------------------------------------------------------------------------------------------------
	// Destructor. Erases the list by calling Erase().
	//----------------------------------------------------------------------------------------------------------
	virtual ~DList();
    
	//----------------------------------------------------------------------------------------------------------
	// Appends a new node containing data member pData to the end of the list.
	//----------------------------------------------------------------------------------------------------------
	DList& Append(tDListData const pData);
    
	//----------------------------------------------------------------------------------------------------------
	// Erases (deletes) every element in the list.
	//----------------------------------------------------------------------------------------------------------
	DList& Erase();
    
	//----------------------------------------------------------------------------------------------------------
	// Erases (deletes) every element in the list from the element pointed to by pIterator the end of the list.
	//
	// REMARK
	// If the iterator is in the empty or invalid state, this function does nothing.
	//----------------------------------------------------------------------------------------------------------
	DList& Erase(DListIterator&  pIterator);
    
	//----------------------------------------------------------------------------------------------------------
	// Erases (deletes) every element in the list from the element pointed to by pIterBegin to pIterEnd, includ-
	// ing the elements pointed to by pIterBegin and pIterEnd.
	//
	// REMARK
	// If either iterator is in the empty of invalid state, this function does nothing.
	//----------------------------------------------------------------------------------------------------------
	DList& Erase(DListIterator&  pIterBegin, DListIterator& pIterEnd);
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if the list is empty and false if it is not.
	//----------------------------------------------------------------------------------------------------------
	bool IsEmpty() const
	{
		return mSize == 0;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Returns an iterator for this DList.
	//----------------------------------------------------------------------------------------------------------
	DListIterator Iterator() const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns a string representation of the list. Intended for testing and debugging only.
	//----------------------------------------------------------------------------------------------------------
	virtual operator string() const;
    
	//----------------------------------------------------------------------------------------------------------
	// Appends a new node containing data pData to the end of the list by calling Append().
	//----------------------------------------------------------------------------------------------------------
	DList& operator+(tDListData const pData);
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this DList is equal to pList. Two lists are equal if they have the same size and every
	// corresponding data member is equal.
	//----------------------------------------------------------------------------------------------------------
	bool operator==(DList const &pList) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this DList is not equal to pList. See operator==().
	//----------------------------------------------------------------------------------------------------------
	bool operator!=(DList const &pList) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Assigns pList to this list by performing a deep copy operation.
	//----------------------------------------------------------------------------------------------------------
	DList& operator=(DList const &pList);
    
	//----------------------------------------------------------------------------------------------------------
	// Prepends a new node containing data member pData to the beginning of the list.
	//----------------------------------------------------------------------------------------------------------
	DList& Prepend(tDListData const pData);
    
	//----------------------------------------------------------------------------------------------------------
	// Returns the number of elements in the list.
	//----------------------------------------------------------------------------------------------------------
	size_t Size() const
	{
		return mSize;
	}
    
protected:
	//==========================================================================================================
	// PROTECTED FUNCTION MEMBERS
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// Makes this list a *deep* copy of pList.
	//----------------------------------------------------------------------------------------------------------
	virtual DList& Copy(DList const& pList);
    
	//----------------------------------------------------------------------------------------------------------
	// Accessor function for mHead.
	//----------------------------------------------------------------------------------------------------------
	DListNode *Head() const
	{
		return mHead;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for mHead.
	//----------------------------------------------------------------------------------------------------------
	void Head(DListNode * const pHead)
	{
		mHead = pHead;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for mSize.
	//----------------------------------------------------------------------------------------------------------
	void Size(size_t const pSize)
	{
		mSize = pSize;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Accessor function for mTail.
	//----------------------------------------------------------------------------------------------------------
	DListNode *Tail() const
	{
		return mTail;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for mTail.
	//----------------------------------------------------------------------------------------------------------
	void Tail(DListNode * const pTail)
	{
		mTail = pTail;
	}
    
private:
	//==========================================================================================================
	// PRIVATE DATA MEMBERS AND FUNCTION MEMBERS
	//==========================================================================================================
    
	DListNode     *mHead;
	size_t         mSize;
	DListNode     *mTail;
};

//==============================================================================================================
// NONMEMBER FUNCTION PROTOTYPES
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Overloads the stream insertion operator << so DList objects may be sent to an output stream. This is primari-
// ly designed for testing and debugging.
//--------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& pStream, DList const& pList);

#endif
