//**************************************************************************************************************
// CLASS: DListNode
//
// DESCRIPTION
// The implementation of the DListNode class declared in DListNode.hpp.
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

#include "DListNode.hpp"

//--------------------------------------------------------------------------------------------------------------
// DListNode::DListNode()
//--------------------------------------------------------------------------------------------------------------
DListNode::DListNode() :
mData(0),
mNext(0),
mPrev(0)
{
}

//--------------------------------------------------------------------------------------------------------------
// DListNode::DListNode(tDListData const)
//--------------------------------------------------------------------------------------------------------------
DListNode::DListNode(tDListData const pData) :
mData(pData),
mNext(0),
mPrev(0)
{
}

//--------------------------------------------------------------------------------------------------------------
// DListNode::DListNode(tDListData const, DListNode * const, DListNode * const)
//--------------------------------------------------------------------------------------------------------------
DListNode::DListNode(tDListData const pData, DListNode * const pPrev, DListNode * const pNext) :
mData(pData),
mNext(pNext),
mPrev(pPrev)
{
}

//--------------------------------------------------------------------------------------------------------------
// DListNode::DListNode(DListNode const&)
//--------------------------------------------------------------------------------------------------------------
DListNode::DListNode(DListNode const& pNode) :
mData(pNode.mData),
mNext(pNode.mNext),
mPrev(pNode.mPrev)
{
}

//--------------------------------------------------------------------------------------------------------------
// DListNode::Copy(DListNode const&)
//--------------------------------------------------------------------------------------------------------------
DListNode& DListNode::Copy(DListNode const& pNode)
{
	mData = pNode.mData;
	mNext = pNode.mNext;
	mPrev = pNode.mPrev;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// DListNode::operator string()
//--------------------------------------------------------------------------------------------------------------
DListNode::operator string() const
{
	stringstream sstr;
	sstr << hex << showbase;
	sstr << '{' << endl << "  mPrev = " << mPrev << ", mNext = " << mNext;
	sstr << dec << noshowbase << ", mData = " << mData;
	sstr << endl << '}';
	return sstr.str();
}

//--------------------------------------------------------------------------------------------------------------
// DListNode::operator=(DListNode const&)
//--------------------------------------------------------------------------------------------------------------
DListNode& DListNode::operator=(DListNode const& pNode)
{
	if (this != &pNode) Copy(pNode);
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// operator<<(ostream&, DListNode const&)
//
// Sends a string representation of pNode to pStream. This function is primarily intended for testing and debug-
// ging.
//--------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& pStream, DListNode const& pNode)
{
	pStream << static_cast<string>(pNode);
	return pStream;
}
