//**************************************************************************************************************
// CLASS: DList
//
// DESCRIPTION
// The implementation of the DList class declared in DList.hpp.
//
// THERE ARE NO KNOWN BUGS IN THIS CODE.
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

#include <string>
using std::string;

#include "DList.hpp"

//--------------------------------------------------------------------------------------------------------------
// DList::DList()
//
// PSEUDOCODE
// In the member init list, initialize the data members mHead, mSize, and mTail, so this DList is empty. In the
// empty list, the mHead and mTail pointers are null (0 in C++), and mSize is 0.
//--------------------------------------------------------------------------------------------------------------
DList::DList() :

{
}

//--------------------------------------------------------------------------------------------------------------
// DList::DList(DList const&)
//
// This is the copy ctor, so make this DList a deep copy of pList.
//
// PSEUDOCODE
// Initialize the data members in the member init list in the same way you did for the default ctor.
// In the body of this ctor, call the Copy() function to make a deep copy of pList.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// DList::~DList()
//
// The destructor must free all of the memory allocated for the list. In particular, it must delete each of the
// nodes. This can be accomplished by calling the Erase() function.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// DList::Append(tDListData const)
//
// Creates an iterator. Moves the iterator to the last element of the list (the tail node). Inserts a new node
// containing data member pData after the tail node. Returns a reference to this DList which permits chained
// functon calls, such as the one you see below.
//--------------------------------------------------------------------------------------------------------------
DList& DList::Append(tDListData const pData)
{
	Iterator().End().InsertAfter(pData);
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DList::Copy(DList const&)
//
// Makes this DList a deep copy of pList.
//--------------------------------------------------------------------------------------------------------------
DList& DList::Copy(DList const& pList)
{
	// First, delete all of the nodes in this DList.
	Erase();
    
	// Get an iterator to this DList.
	DListIterator dstIter = Iterator();
    
	// Get an iterator for pList, and iterate over each element in pList.
	for (DListIterator srcIter = pList.Iterator(); srcIter; ++srcIter) {
        
		// Get the data stored in the node that srcIter points to, and insert a new node in this DList after
		// the node that was inserted during the previous pass of this loop.
		dstIter.InsertAfter(srcIter());
	}
    
	// Return a reference to this DList to permit chained function calls.
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DList::Erase()
//
// Erases (deletes) every node in this DList. If the list is empty, don't do anything. Note that in the for loop
// we don't have to increment iter during each pass (by writing ++iter) because the Delete() operation always
// moves the iterator forward to point to the element following the one that was just deleted. I found this out
// the hard way: if you do write ++iter in the for loop, you would actually delete every other node.
//--------------------------------------------------------------------------------------------------------------
DList& DList::Erase()
{
	if (!IsEmpty()) {
		for ( DListIterator iter = Iterator(); iter; iter.Delete() ) { }
	}
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DList::Erase(DListIterator&)
//
// Deletes every node in this DList from the node that pIterator points to, to the end of the list (including
// the last node).
//--------------------------------------------------------------------------------------------------------------
DList& DList::Erase(DListIterator& pIterator)
{
	// Only erase if pIterator is in valid state.
	if (pIterator.mState == DListIterator::eValid) {
		while (pIterator) pIterator.Delete();
	}
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DList::Erase(DListIterator&, DListIterator&)
//
// Deletes every node in this DList from the note that pIterBegin points to, to the node that pIterEnd points to
// (including the node that pIterEnd points to). It is assumed that pIterBegin points to a node that appears in
// this DList before the node that pIterEnd points to. I don't know what would happen if that were not true
// because I did not test it (ran out of time). So don't do that.
//--------------------------------------------------------------------------------------------------------------
DList& DList::Erase(DListIterator& pIterBegin, DListIterator& pIterEnd)
{
	// Only erase if both iterators are in valid state.
	if (pIterBegin.mState == DListIterator::eValid && pIterEnd.mState == DListIterator::eValid) {
		while (pIterBegin != pIterEnd) pIterBegin.Delete();
		pIterEnd.Delete();
	}
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DList::Iterator()
//
// Creates and returns an iterator which iterates over this DList.
//--------------------------------------------------------------------------------------------------------------
DListIterator DList::Iterator() const
{
	return DListIterator(*this);
}

//--------------------------------------------------------------------------------------------------------------
// DList::operator string()
//
// Returns a string representation of this DList. This function is intended to be used only for debugging and
// testing.
//--------------------------------------------------------------------------------------------------------------
DList::operator string() const
{
	stringstream sstr;
	sstr << hex << showbase << '{' << endl;
	sstr << "  mHead = " << mHead << ", mTail = " << mTail;
	sstr << dec << noshowbase << ", mSize = " << mSize << endl << "  [ ";
	for (DListIterator iter = Iterator(); iter; ++iter) {
		sstr << (int)iter() << ' ';
	}
	sstr << ']' << endl << '}';
	return sstr.str();
}

//--------------------------------------------------------------------------------------------------------------
// DList::operator+(tDListData const pData)
//
// Appends a new node containing data member pData to the end of this DList. Equivalent to calling Append().
//
// PSEUDOCODE
// Call Append() passing pData as the param and return what Append() returns.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// DList::operator==(DList const&)
//
// Two DLists are considered to be equal if:
//
// 1. They are the same lists,
//
//    DList list1;
//    ... add some data to list1
//    if (list1 == list1) { .. }    -- True since list1 and list1 are the same list.
//
// 2. They are not the same lists, but the data members are identical,
//
//    DList list1;
//    ... add some data to list1
//    DList list2(list);            -- Invokes the copy ctor on list2, so it will be a deep copy of list1.
//    if (list1 == list2) { ... }   -- True since list2 is a deep copy of list1.
//--------------------------------------------------------------------------------------------------------------
bool DList::operator==(DList const& pList) const
{
	// If this list and pList are the same list then == is obviously true.
	if (this == &pList) return true;
    
	// If this list and pList are different sizes then == is obviously false.
	if (mSize != pList.mSize) return false;
    
	// These two lists (this list and pList) are not the same list but they are the same size. Now we have to
	// compare every corresponding data member for equality. Return false on the first nonequal element.
	DListIterator thatIter = pList.Iterator();
	for (DListIterator thisIter = Iterator(); thisIter; ++thisIter, ++thatIter) {
		if (thisIter() != thatIter()) return false;
	}
	return true;
}

//--------------------------------------------------------------------------------------------------------------
// DList::operator!=(DList const&)
//
// Two lists are not equal if operator==() returns false. If that is the case, then this function should return
// true.
//--------------------------------------------------------------------------------------------------------------
bool DList::operator!=(DList const& pList) const
{
	return !(*this == pList);
}

//--------------------------------------------------------------------------------------------------------------
// DList::operator=(DList const&)
//
// Makes this DList a deep copy of pList via the assignment operator.
//--------------------------------------------------------------------------------------------------------------
DList& DList::operator=(DList const& pList)
{
	if (this != &pList) Copy(pList);
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DList::Prepend(tDListData const)
//
// Where Append() sticks a new node onto the end of the list, Prepend() sticks a new node at the beginning of
// the list.
//
// PSEUDOCODE
// Create an iterator over this DList by calling Iterator.
// Insert a new node containing data member pData at the beginning of the list by calling InsertBefore() on the
//   iterator and passing pData as the param.
// Return a reference to this DList.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// operator<<(ostream&, DList const&)
//
// Returns a string representation of pList to pStream. This function is primarily intended for testing and
// debugging.
//--------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& pStream, DList const& pList)
{
	pStream << static_cast<string>(pList);
	return pStream;
}
