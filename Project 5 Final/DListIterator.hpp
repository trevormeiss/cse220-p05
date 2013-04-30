//**************************************************************************************************************
// CLASS: DListIterator
//
// DESCRIPTION
// Declares an iterator class for iterating over the elements of a DList.
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
#ifndef DLISTITERATOR_HPP
#define DLISTITERATOR_HPP

#include <cassert>  // For assert() macro.

#include <ostream>
using std::ostream;

#include <string>
using std::string;

#include "DList.hpp"
#include "DListNode.hpp"

//==============================================================================================================
// CLASS: DListIterator
//==============================================================================================================
class DListIterator {
    
	//==========================================================================================================
	// FRIENDS
	//==========================================================================================================
    
	friend class DList;
    
public:
	//==========================================================================================================
	// PUBLIC FUNCTION MEMBERS
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// Typedef for the iterator state. The iterator is always in one of three states,
	//
	// 1. eEmpty     When the list is empty. When in the empty state, mIterNode will be null.
	// 2. eInvalid   When the iterator does not point at a node. The iterator is invalid when it has been moved
	//               either past the tail node or before the head node. When in the invalid state, mIterNode
	//               will be null.
	// 3. eValid     When the iterator points at a node, i.e., mIterNode node is nonnull.
	//----------------------------------------------------------------------------------------------------------
	typedef enum { eEmpty, eInvalid, eValid } tState;
    
	//----------------------------------------------------------------------------------------------------------
	// Default ctor.
	//----------------------------------------------------------------------------------------------------------
	DListIterator();
    
	//----------------------------------------------------------------------------------------------------------
	// Constructor. Initializes mList to pList which ties this iterator to a specific DList. If pList is an
	// empty list, the iterator state will be set to eEmpty. Otherwise, the iterator will be set to point to the
	// head node and the state will be eValid.
	//----------------------------------------------------------------------------------------------------------
	DListIterator(DList const& pList);
    
	//----------------------------------------------------------------------------------------------------------
	// Copy constructor. Makes this DListIterator an identical copy of pIterator.
	//----------------------------------------------------------------------------------------------------------
	DListIterator(DListIterator const& pIterator);
    
	//----------------------------------------------------------------------------------------------------------
	// Destructor. Does nothing because there are no dynamically-allocated data members to be deleted.
	//----------------------------------------------------------------------------------------------------------
	virtual ~DListIterator()
	{
	}
    
	//----------------------------------------------------------------------------------------------------------
	// If the iterator is in the valid state, moves the iterator backward to the previous node in the list. If
	// the iterator is in the empty or invalid state, the this function does nothing.
	//
	// REMARK
	// If the iterator was pointing at the head node, then after moving backward, it will be in the invalid
	// state.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& Backward();
    
	//----------------------------------------------------------------------------------------------------------
	// If the iterator is in the valid state, attempts to move the iterator backward pTimes. If the iterator is
	// in the empty or invalid state, the this function does nothing.
	//
	// REMARK
	// If the iterator is would be moved before the head of the list, it changes to the invalid state.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& Backward(int const pTimes);
    
	//----------------------------------------------------------------------------------------------------------
	// Attempts to sets the iterator to point to the head node in the list. If the list is nonempty, the iterat-
	// or will be pointing at the head node and will be in the valid state. If the list is empty, mIterNode will
	// be set to null and the state will set to eEmpty.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& Begin();
    
	//----------------------------------------------------------------------------------------------------------
	// If the iterator is in the valid state, will delete the node that the iterator points to. After deleting,
	// the iterator will be advanced to the next node following the one that was deleted. If the node being
	// deleted is the tail node, then after deleting the tail node, the iterator will have been advanced past
	// the end of the list, so the iterator will be in the invalid state.
	//
	// ASSERTION
	// Fails if the iterator is not pointing at a list element. This would happen if the iterator is in the
	// empty or invalid states.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& Delete();
    
	//----------------------------------------------------------------------------------------------------------
	// Attempts to set the iterator to point to the tail node in the list. If the list is nonempty, the iterat-
	// or will be pointing at the tail node and will be in the valid state. If the list is empty, mIterNode will
	// be set to null and the state will set to eEmpty.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& End();
    
	//----------------------------------------------------------------------------------------------------------
	// If the iterator is in the valid state, moves the iterator forward to the next node in the list. If the
	// iterator is in the empty or invalid state, the this function does nothing.
	//
	// REMARK
	// If the iterator was pointing at the tail node, then after moving forward, it will be in the invalid
	// state.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& Forward();
    
	//----------------------------------------------------------------------------------------------------------
	// If the iterator is in the valid state, attempts to move the iterator forward pTimes. If the iterator is
	// in the empty or invalid state, the this function does nothing.
	//
	// REMARK
	// If the iterator would be moved past the end of the list, the iterator is set to the invalid state.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& Forward(int const pTimes);
    
	//----------------------------------------------------------------------------------------------------------
	// Attempts to insert a new node into the list after the node the iterator points to. If successful, the
	// iterator will be set to point to the newly inserted node.
	//
	// REMARK
	// If the list is empty, a new node will be created as the head of the list and the iterator will be set to
	// point to the head.
	//
	// ASSERTION
	// Fails if the iterator is in the invalid state.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& InsertAfter(tDListData const pData);
    
	//----------------------------------------------------------------------------------------------------------
	// Inserts a new node into the list before the node the iterator points to. The iterator will be set to
	// point to the newly inserted node.
	//
	// REMARK
	// If the list is empty, a new node will be created as the head of the list and the iterator will be set to
	// point to the new head.
	//
	// ASSERTION
	// Fails if the iterator has been advanced past the last element in the list.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& InsertBefore(tDListData const pData);
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads postincrement ++. Moves the iterator forward to the next node in the list by calling Forward().
	//
	// Note that the post-increment ++ operator function needs to return the current value of the thing that is
	// being incremented,
	//
	// int a = 5;
	// ++a;        -- Increment a to 6; the result of evaluating this expression is a.
	// a++;        -- The result of evaluating this expression is 5; increment a to 6.
	//
	// For preincrement, the result of the expression is a which is why the preincrement operator funct returns
	// a reference to the DListIterator object. For postincrement, the result of evaluating the expression is
	// the preincrement value of a, which is why this function returnns the DListIterator (the current value)
	// and not a reference to the DListIterator (which would actually return the wrong value).
	//----------------------------------------------------------------------------------------------------------
	DListIterator operator++(int const pDummy);
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads postincrement --. Moves the iterator backward to the previous node in the list by calling
	// Backward().
	//
	// REMARK
	// See the comment in postincrement operator++() concerning the return value.
	//----------------------------------------------------------------------------------------------------------
	DListIterator operator--(int const pDummy);
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads preincrement ++. Moves the iterator forward to the next node in the list by calling Forward().
	//----------------------------------------------------------------------------------------------------------
	DListIterator& operator++()
	{
		return Forward();
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads predecrement --. Moves the iterator backward to the previous node in the list by calling
	// Backward().
	//----------------------------------------------------------------------------------------------------------
	DListIterator& operator--()
	{
		return Backward();
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads the function call operator() to serve as an accessor function for accessing the data stored
	// at the element in the list that this iterator points to,
	//
	// DList list;                                            -- Create an empty list
	// DListIterator iter(list);                              -- Create an iterator for 'list'
	// list.InsertAfter(10).InsertAfter(20).InsertAfter(30);  -- list <- [ 10 20 30 ]
	// iter.Begin().Forward();                                -- iter pointing to 20
	// int x = iter();                                        -- x <- 20
	//
	// ASSERTION
	// Fails if the iterator is not in the valid state.
	//----------------------------------------------------------------------------------------------------------
	tDListData operator()() const
	{
		assert(mState == eValid);
		return mIterNode->mData;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads the function call operator() to serve as a mutator function for changing the data stored at the
	// element in the list that this iterator points to,
	//
	// DList list;                                            -- Create an empty list
	// DListIterator iter(list);                              -- Create an iterator for 'list'
	// list.InsertAfter(10).InsertAfter(20).InsertAfter(30);  -- list <- [ 10 20 30 ]
	// iter.Begin().Forward();                                -- iter pointing to 20
	// int x = iter();                                        -- x <- 20
	// ++iter;                                                -- iter pointing to 30
	// iter(x);                                               -- list <- [ 10 20 20 ]
	//
	// ASSERTION
	// Fails if the iterator is not in the valid state.
	//----------------------------------------------------------------------------------------------------------
	void operator()(tDListData const pData) const
	{
		assert(mState == eValid);
		mIterNode->mData = pData;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads the (bool) typecast operator to return true if the iterator is in the valid state and false
	// otherwise.
	//----------------------------------------------------------------------------------------------------------
	operator bool() const
	{
		return mState == eValid;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Returns a string representation of the iterator. Intended for testing and debugging only.
	//----------------------------------------------------------------------------------------------------------
	virtual operator string() const;
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads operator +. Moves the iterator forward pTimes times by repeatedly calling Forward(). If the
	// list is empty, this function does nothing.
	//
	// REMARK
	// If the iterator is moved past the tail node, this function immediately returns with the iterator in the
	// invalid state.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& operator+(int const pTimes);
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads operator -. Moves the iterator backward pTimes times by repeatedly calling Back(). If the list
	// list is empty, this function does nothing.
	//
	// REMARK
	// If the iterator is moved before the head node, this function immediately returns with the iterator in the
	// invalid state.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& operator-(int const pTimes);
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads operator +=. Moves the iterator forward pTimes times by repeatedly calling operator+().
	//----------------------------------------------------------------------------------------------------------
	DListIterator& operator+=(int const pTimes)
	{
		return *this + pTimes;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads operator -=. Moves the iterator backward pTimes times by repeatedly calling operator-().
	//----------------------------------------------------------------------------------------------------------
	DListIterator& operator-=(int const pTimes)
	{
		return *this - pTimes;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads the relational equality operator. Two iterators are defined to be equal if they both point to
	// the same node.
	//----------------------------------------------------------------------------------------------------------
	bool operator==(DListIterator const& pIterator)
	{
		return mIterNode == pIterator.mIterNode;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads the relational inequality operator. Two iterators are defined to be not equal if the point to
	// different nodes.
	//----------------------------------------------------------------------------------------------------------
	bool operator!=(DListIterator const& pIterator)
	{
		return !(*this == pIterator);
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Overloads the assignment operator =. Makes this DListIterator an identical copy of pIterator.
	//----------------------------------------------------------------------------------------------------------
	DListIterator& operator=(DListIterator const& pIterator);
    
protected:
	//==========================================================================================================
	// PROTECTED FUNCTION MEMBERS
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// Makes this DListIterator an identical copy of pIterator.
	//----------------------------------------------------------------------------------------------------------
	virtual void Copy(DListIterator const& pIterator);
    
	//----------------------------------------------------------------------------------------------------------
	// Accessor function for mIterNode;
	//----------------------------------------------------------------------------------------------------------
	DListNode *IterNode() const
	{
		return mIterNode;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for mIterNode;
	//----------------------------------------------------------------------------------------------------------
	void IterNode(DListNode * const pIterNode)
	{
		mIterNode = pIterNode;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Accessor function for mList.
	//----------------------------------------------------------------------------------------------------------
	DList& List() const
	{
		return mList;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Resets the iterator to the initial state it was in after being instantiated. If the list is nonempty, the
	// iterator will be pointing at the head node and will be in the valid state. If the list is empty, mIter-
	// Node will be set to null and the state will set to empty.
	//----------------------------------------------------------------------------------------------------------
    DListIterator& Reset();
    
	//----------------------------------------------------------------------------------------------------------
	// Accessor function for the mState data member.
	//----------------------------------------------------------------------------------------------------------
	tState State() const
	{
		return mState;
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for the mState data member.
	//----------------------------------------------------------------------------------------------------------
	void State(tState const pState)
	{
		mState = pState;
	}
    
private:
	//==========================================================================================================
	// PRIVATE DATA AND FUNCTION MEMBERS
	//==========================================================================================================
    
	DListNode *mIterNode;
	DList&     mList;
	tState     mState;
};

//==============================================================================================================
// NONMEMBER FUNCTION PROTOTYPES
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Overloads the stream insertion operator << so DListIterator objects may be sent to an output stream. This is
// primarily designed for testing and debugging.
//--------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& pStream, DListIterator const& pIterator);

#endif
