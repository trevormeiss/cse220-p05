//**************************************************************************************************************
// CLASS: DListIterator
//
// DESCRIPTION
// The implementation of the DListIterator class declared in DListIterator.cpp.
//
// THERE ARE 3 INTENTIONALLY PLANTED BUGS IN THIS CODE. THERE MAY BE OTHER, UNDIAGNOSED BUGS, AS WELL. I'M NOT
// PERFECT MAN.
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
#include <iostream>
using std::dec;
using std::endl;
using std::hex;
using std::noshowbase;
using std::showbase;

#include <ostream>
using std::ostream;

#include <sstream>
using std::stringstream;

#include "DListIterator.hpp"

//--------------------------------------------------------------------------------------------------------------
// DListIterator::DListIterator(DList const&)
//
// Initialize mIterNode to point to the head node if the list is not empty, or set it to null otherwise.
// Initialize the mList data member to refer to pList. Note: reference data members *must* be initialized in
//   the member init list. The const_cast<> operator removes the "const-ness" from pList so mList may be made
//   to refer to pList. Without that cast, you would get a syntax error.
// Set mState to eEmpty if the list is empty, otherwise set it to eValid.
//--------------------------------------------------------------------------------------------------------------
DListIterator::DListIterator(DList const& pList) :
mIterNode(pList.mSize != 0 ? pList.mHead : 0),
mList(const_cast<DList&>(pList)),
mState(pList.mSize == 0 ? eEmpty : eValid)
{
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::DListIterator(DListIterator const&)
//
// This is the copy ctor. Make this DListIterator a copy of pIterator.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// DListIterator::Backward()
//
// If the iterator is in the valid state, then move it to point to the new previous to the current node. If it
// was moved before the head node, then it changes to the invalid state.
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::Backward()
{
	// Only move backward if the iterator is in the valid state.
	if (mState == eValid) {
		mIterNode = mIterNode->mPrev;
		mState = mIterNode == 0 ? eInvalid : eValid;
	}
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::Backward(int const)
//
// Move the iterator backward pTimes times by calling Backward() pTims times, or until the iterator enters the
// invalid state.
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::Backward(int const pTimes)
{
	// Only attempt to move backward if the iterator is in the valid state.
	if (mState == eValid) {
		int times = pTimes;
		// Move the iterator backward pTimes times or until we march off the beginning of the list.
		while (mState != eInvalid && times--) Backward();
	}
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::Begin()
//
// Moves the iterator to the head node, or set it to the empty state if the list is empty.
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::Begin()
{
	return Reset();
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::Copy(DListIterator const&)
//
// Makes this iterator an identical copy of pIterator.
//--------------------------------------------------------------------------------------------------------------
void DListIterator::Copy(DListIterator const& pIterator)
{
	mIterNode = pIterator.mIterNode;
	mList = pIterator.mList;
	mState = pIterator.mState;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::Delete()
//
// Deletes the node in the DList that the iterator points to. Don't call this function when the list is empty
// (when the iterator is in the empty state) or the iterator is in the invalid state (it has been moved before
// the head node or after the tail node).
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::Delete()
{
	// Assertion failure if the iterator is in the empty or invalid states.
	assert(mState == eValid);
    
	DListNode *iterNode = mIterNode;
	--mList.mSize;
    
	// Are we deleting the only node in the list?
	if (mList.mSize == 0) {
		mList.mHead = mList.mTail = 0;
		Reset();
        
        // Are we deleting the head node in the list?
	} else if (mIterNode == mList.mHead) {
		mList.mHead = mIterNode->mNext;
		mList.mHead->mPrev = 0;
		mIterNode = mList.mHead;
        
        // Are we deleting the tail node in the list? If so, the iterator changes to the invalid state.
	} else if (mIterNode == mList.mTail) {
		mList.mTail = mIterNode->mPrev;
		mList.mTail->mNext = 0;
		mIterNode = 0;
		mState = eInvalid;
        
        // We deleting a node in the middle of the list.
	} else {
		mIterNode->mPrev->mNext = mIterNode->mNext;
		mIterNode->mNext->mPrev = mIterNode->mPrev;
		mIterNode = mIterNode->mNext;
	}
    
	delete iterNode;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::End()
//
// Moves the iterator to the last node (the tail node) of the list. If the list is empty, set it's state to the
// empty state.
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::End()
{
	mIterNode = mList.mTail;
	mState = mList.mSize == 0 ? eEmpty : eValid;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::Forward()
//
// Move the iterator forward to the next node in the list. If the iterator is moved past the tail node, set it
// to the invalid state.
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::Forward()
{
	// Only move forward if the iterator is in the valid state.
	if (mState == eValid) {
		mIterNode = mIterNode->mNext;
	}
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::Forward(int const)
//
// Moves the iterator forward pTimes times, or until it is moved past the tail node.
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::Forward(int const pTimes)
{
	// Only attempt to move forward if the iterator is in the valid state.
	if (mState == eValid) {
		int times = pTimes;
		// Move the iterator forward pTimes times or until we march off the end of the list.
		while (mState != eInvalid && times--) Forward();
	}
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::InsertAfter(tDListData const)
//
// REMARK
// We check for inserting after the tail node before we check for inserting after the head node for a reason. If
// the list has only one element and we check for inserting after head first, then the mIterNode pointer would
// be pointing at the head node, and when we set mIterNode->mNext->mPrev to newNode, the program would blow up
// with a segmentation fault since mIterNode->mNext is null. By checking for inserting after the tail node first
// if that condition is false, then when we check for inserting after the head node, we know the list has at
// least two elements (because if it didn't, then we would have been inserting after the tail node).
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::InsertAfter(tDListData const pData)
{
	// Fail if the iterator is in the invalid state.
	assert(mState != eInvalid);
    
	DListNode *newNode;
    
	if (mList.mSize == 0) {
		newNode = new DListNode(pData, 0, 0);
		mList.mHead = mList.mTail = newNode;
        
	} else if (mIterNode == mList.mTail) {
		newNode = new DListNode(pData, mIterNode, 0);
		mIterNode->mNext = newNode;
		mList.mHead = newNode;
        
	} else if (mIterNode == mList.mHead) {
		newNode = new DListNode(pData, mIterNode, mIterNode->mNext);
		mIterNode->mNext->mPrev = newNode;
		mIterNode->mNext = newNode;
        
	} else {
		newNode = new DListNode(pData, mIterNode, mIterNode);
		mIterNode->mNext->mPrev = newNode;
		mIterNode->mNext = newNode;
	}
    
	++mList.mSize;
	mIterNode = newNode;
	mState = eValid;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::InsertBefore(tDListData const)
//
// PSEUDOCODE
// Study the code for InsertAfter(). This function is similar, but obviously, not identical.
//
// By the way, there might be a bug or two in InsertAfter().
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// DListIterator::operator++(int const) -- Postincrement
//--------------------------------------------------------------------------------------------------------------
DListIterator DListIterator::operator++(int const pDummy)
{
	DListIterator preIncValue = *this;
	++(*this);
	return preIncValue;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::operator--(int const) -- Postdecrement
//--------------------------------------------------------------------------------------------------------------
DListIterator DListIterator::operator--(int const pDummy)
{
	DListIterator preDecValue = *this;
	--(*this);
	return preDecValue;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::operator string()
//--------------------------------------------------------------------------------------------------------------
DListIterator::operator string() const
{
	stringstream sstr;
	sstr << hex << showbase;
	sstr << '{' << endl << "  mIterNode = " << mIterNode;
	if (mIterNode) sstr << dec << ", mIterNode->mData = " << (int)mIterNode->mData << hex << showbase;
	sstr << ", mState = ";
	if (mState == eEmpty) sstr << "eEmpty";
	else if (mState == eInvalid) sstr << "eInvalid";
	else sstr << "eValid";
	sstr << endl << '}';
	return sstr.str();
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::operator+(int const)
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::operator+(int const pTimes)
{
	return Forward(pTimes);
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::operator-(int const)
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::operator-(int const pTimes)
{
	return Backward(pTimes);
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::operator=(DListIterator const&)
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::operator=(DListIterator const& pIterator)
{
	if (this != &pIterator) Copy(pIterator);
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListIterator::Reset()
//--------------------------------------------------------------------------------------------------------------
DListIterator& DListIterator::Reset()
{
	mIterNode = mList.mHead;
	mState = mList.mSize == 0 ? eEmpty : eValid;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// operator<<(ostream&, DListIterator const&)
//
// Sends a string representation of pIterator to pStream. This function is primarily intended for testing and
// debugging.
//--------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& pStream, DListIterator const& pIterator)
{
	pStream << static_cast<string>(pIterator);
	return pStream;
}
