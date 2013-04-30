//**************************************************************************************************************
// CLASS: DListTest
//
// DESCRIPTION
// Tests the DList class.
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
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "DList.hpp"

static void DListTest();

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: main()
//--------------------------------------------------------------------------------------------------------------
int main()
{
	DListTest();
	return 0;
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTON: DListTest()
//--------------------------------------------------------------------------------------------------------------
static void DListTest()
{
	cout << "Create an empty list. Test the default ctor." << endl;
	DList list1;
	cout << "list1 ==> " << list1 << ". Should be an empty list." << endl;
    
	cout << "Test IsEmpty() and Size() on an empty list." << endl;
	cout << "list.Size()    ==> " << list1.Size()    << ". Should be 0." << endl;
	cout << "list.IsEmpty() ==> " << list1.IsEmpty() << ". Should be 1." << endl;
    
	cout << "Test copy ctor for empty lists." << endl;
	DList list2;
	cout << "list2 ==> " << list2 << ". Should be an empty list." << endl;
    
	cout << "Test == and != for the same empty list." << endl;
	cout << "list1 == list1 ==> " << (list1 == list1) << ". Should be 1." << endl;
	cout << "list1 != list1 ==> " << (list1 != list2) << ". Should be 0." << endl;
    
	cout << "Test == and != for different empty lists." << endl;
	cout << "list1 == list2 ==> " << (list1 == list2) << ". Should be 1 (since they are both empty lists)." << endl;
	cout << "list1 != list2 ==> " << (list1 != list2) << ". Should be 0." << endl;
    
	cout << "Test = for self-assignment of empty list." << endl;
	list1 = list1;
	cout << "list1 ==> " << list1 << ". Should be an empty list." << endl;
    
	cout << "Test = for assignment of empty list." << endl;
	list2 = list1;
	cout << "list2 ==> " << list2 << ". Should be an empty list." << endl;
    
	cout << "Test Erase() on empty list." << endl;
	list1.Erase();
	cout << "list1 ==> " << list1 << ". Should be an empty list." << endl;
    
	cout << "Test Iterator() on empty list." << endl;
	DListIterator iter1 = list1.Iterator();
	cout << "iter1 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test Erase(iterator) on empty list." << endl;
	list1.Erase(iter1);
	cout << "list1 ==> " << list1 << ". Should be an empty list." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test Erase(iterator, iterator) on empty list." << endl;
	DListIterator iter2 = list1.Iterator();
	list1.Erase(iter1, iter2);
	cout << "list1 ==> " << list1 << ". Should be an empty list." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be an empty iterator." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be an empty iterator." << endl;
    
	//cout << "Test that accessor () on an empty iterator causes assertion failure. " << endl;
	//cout << iter1();
    
	//cout << "Test that mutator (data) on an empty iterator causes assertion failure. " << endl;
	//iter1(10);
    
	cout << "Test iterator copy ctor on empty iterator." << endl;
	iter2 = iter1;
	cout << "iter1 ==> " << iter1 << ". Should be an empty iterator." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be an empty iterator." << endl;
    
	cout << "Test = for assignment of empty iterator." << endl;
	iter1 = iter2;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test == and != for the same empty iterator." << endl;
	cout << "iter1 == iter1 ==> " << (iter1 == iter1) << ". Should be 1." << endl;
 	cout << "iter1 != iter1 ==> " << (iter1 != iter1) << ". Should be 0." << endl;
    
	cout << "Test == and != for empty iterators." << endl;
	cout << "iter1 == iter2 ==> " << (iter1 == iter2) << ". Should be 1." << endl;
 	cout << "iter1 != iter2 ==> " << (iter1 != iter2) << ". Should be 0." << endl;
    
	cout << "Test that Forward() on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	iter1.Forward();
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that Backward() on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	iter1.Backward();
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that preincrement ++ on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	++iter1;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that postincrement ++ on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	iter1++;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that preincrement -- on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	--iter1;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that postincrement -- on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	iter1--;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that + on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	iter1 = iter1 + 5;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that - on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	iter1 = iter1 - 5;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that += on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	iter1 += 100;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that -= on empty iterator does nothing." << endl;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
	iter1 -= 100;
	cout << "iter11 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that (bool) on empty iterator returns false. " << endl;
	cout << "static_cast<bool>(iter1) ==> " << static_cast<bool>(iter1) << ". Should be 0." << endl;
    
	cout << "Test that Begin() on empty iterator results in an empty iterator." << endl;
	iter1.Begin();
	cout << "iter1 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	cout << "Test that End() on empty iterator results in an empty iterator." << endl;
	iter1.End();
	cout << "iter1 ==> " << iter1 << ". Should be an empty iterator." << endl;
    
	//cout << "Test that Delete() on empty iterator results in assertion failure." << endl;
	//iter1.Delete();
    
	cout << "Test InsertAfter(10) on empty iterator." << endl;
	iter1.InsertAfter(10);
	cout << "list1 ==> " << list1 << ". Should be [ 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 10." << endl;
    
	cout << "Test Erase() on list with one element." << endl;
	list1.Erase();
	cout << "list1 ==> " << list1 << ". Should be [ ]." << endl;
    
	cout << "Test multiple InsertAfter() on empty iterator." << endl;
	iter1.Begin();
	iter1.InsertAfter(10).InsertAfter(20).InsertAfter(30);
	cout << "list1 ==> " << list1 << ". Should be [ 10 20 30 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 30." << endl;
    
	cout << "Test Erase() on list with multiple elements." << endl;
	list1.Erase();
	cout << "list1 ==> " << list1 << ". Should be [ ]." << endl;
    
	cout << "Test InsertBefore(10) on empty iterator." << endl;
	iter1.Begin();
	iter1.InsertBefore(10);
	cout << "list1 ==> " << list1 << ". Should be [ 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 10." << endl;
    
	cout << "Test multiple InsertBefore() on empty iterator." << endl;
	list1.Erase();
	iter1.Begin();
	iter1.InsertBefore(10).InsertBefore(20).InsertBefore(30);
	cout << "list1 ==> " << list1 << ". Should be [ 30 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 30." << endl;
    
	cout << "Test InsertAfter() then InsertBefore() on empty list." << endl;
	list1.Erase();
	iter1.Begin();
	iter1.InsertAfter(10).InsertBefore(20);
	cout << "list1 ==> " << list1 << ". Should be [ 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 20." << endl;
    
	cout << "Test InsertBefore() then InsertAfter() on empty list." << endl;
	list1.Erase();
	iter1.Begin();
	iter1.InsertBefore(10).InsertAfter(20);
	cout << "list1 ==> " << list1 << ". Should be [ 10 20 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 20." << endl;
    
	cout << "Test multiple InsertAfter() and InsertBefore()." << endl;
	list1.Erase();
	iter1.Begin();
	iter1.InsertBefore(10).InsertBefore(20).InsertAfter(30).InsertAfter(40).InsertBefore(50).InsertAfter(60);
	cout << "list1 ==> " << list1 << ". Should be [ 20 30 50 60 40 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 60." << endl;
    
	cout << "Testing End()." << endl;
	iter1.End();
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 10." << endl;
	iter1.InsertAfter(70);
	cout << "list1 ==> " << list1 << ". Should be [ 20 30 50 60 40 10 70 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 70." << endl;
    
	cout << "Testing Begin()" << endl;
	iter1.Begin();
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 20." << endl;
	iter1.InsertBefore(80);
	cout << "list1 ==> " << list1 << ". Should be [ 80 20 30 50 60 40 10 70 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 80." << endl;
    
	cout << "Testing delete on head node." << endl;
	iter1.Delete();
	cout << "list1 ==> " << list1 << ". Should be [ 20 30 50 60 40 10 70 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 20." << endl;
    
	cout << "Testing delete on tail node." << endl;
	iter1.End();
	iter1.Delete();
	cout << "list1 ==> " << list1 << ". Should be [ 20 30 50 60 40 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Testing delete on head node." << endl;
	iter1.Begin();
	iter1.Delete();
	cout << "list1 ==> " << list1 << ". Should be [ 30 50 60 40 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing to 30." << endl;
    
	cout << "Testing delete on tail node." << endl;
	iter1.End();
	iter1.Delete();
	cout << "list1 ==> " << list1 << ". Should be [ 30 50 60 40 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Testing operator +." << endl;
	iter1.Begin();
	iter1 = iter1 + 2;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 60." << endl;
    
	cout << "Testing operator -." << endl;
	iter1 = iter1 - 2;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 30." << endl;
    
	cout << "Testing operator + past end." << endl;
	iter1.Begin();
	iter1 = iter1 + 10;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Testing operator - past beginning." << endl;
	iter1.Begin();
	iter1 = iter1 + 2;
	iter1 = iter1 - 10;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Testing operator +=." << endl;
	iter1.Begin();
	iter1 += 2;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 60." << endl;
    
	cout << "Testing operator -=." << endl;
	iter1.Begin();
	iter1 += 3;
	iter1 -= 2;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
    
	cout << "Testing operator += past end." << endl;
	iter1.Begin();
	iter1 += 100;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Testing operator -= past begining." << endl;
	iter1.Begin();
	iter1 -= 100;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Testing operator++ postincrement." << endl;
	iter1.Begin();
	iter1++;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
	iter1++;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 60." << endl;
	iter1++;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 40." << endl;
	iter1++;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Testing operator-- postdecrement." << endl;
	iter1.End();
	iter1--;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 60." << endl;
	iter1--;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
	iter1--;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 30." << endl;
	iter1--;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Testing operator++ preincrement." << endl;
	iter1.Begin();
	++iter1;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
	++iter1;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 60." << endl;
	++iter1;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 40." << endl;
	++iter1;
	cout << "iter1 ==> " << iter1 << ". Should be in end state." << endl;
    
	cout << "Testing operator-- predecrement." << endl;
	iter1.End();
	--iter1;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 60." << endl;
	--iter1;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
	--iter1;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 30." << endl;
	--iter1;
	cout << "iter1 ==> " << iter1 << ". Should be in end state." << endl;
    
	cout << "Testing that preincrement ++ returns correct value." << endl;
	iter1.Begin();
	iter2 = ++iter1;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be pointing at 50." << endl;
    
	cout << "Testing that predecrement -- returns correct value." << endl;
	iter1.End();
	iter2 = --iter1;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 60." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be pointing at 60." << endl;
    
	cout << "Testing that postincrement ++ returns correct value." << endl;
	iter1.Begin();
	iter2 = iter1++;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be pointing at 30." << endl;
    
	cout << "Testing that postdecrement -- returns correct value." << endl;
	iter1.End();
	iter2 = iter1--;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 60." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be pointing at 40." << endl;
    
	cout << "Testing == and != on nonempty iterator." << endl;
	iter1 = iter2;
	cout << "iter1 == iter2 ==> " << (iter1 == iter2) << ". Should be 1." << endl;
 	cout << "iter1 != iter2 ==> " << (iter1 != iter2) << ". Should be 0." << endl;
    
	cout << "Test Erase(iterator) on nonempty list, starting in middle." << endl;
	iter1 = list1.Iterator();
	iter1.End();
	iter1.InsertAfter(30).InsertAfter(20).InsertAfter(10);
	iter1.Begin();
	iter1 += 3;
	cout << "list1 ==> " << list1 << ". Should be [ 30 50 60 40 30 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 40." << endl;
	list1.Erase(iter1);
	cout << "list1 ==> " << list1 << ". Should be [ 30 50 60 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Test Erase(iterator) on nonempty list, starting at head." << endl;
	iter1 = list1.Iterator();
	iter1.End();
	iter1.InsertAfter(50).InsertAfter(40).InsertAfter(30).InsertAfter(20).InsertAfter(10);
	iter1.Begin();
	iter1 += 3;
	cout << "list1 ==> " << list1 << ". Should be [ 30 50 60 50 40 30 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
	iter1.Begin();
	list1.Erase(iter1);
	cout << "list1 ==> " << list1 << ". Should be [ ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be in empty state." << endl;
    
	cout << "Test Erase(iterator) on nonempty list, starting at tail." << endl;
	iter1 = list1.Iterator();
	iter1.End();
	iter1.InsertAfter(50).InsertAfter(40).InsertAfter(30).InsertAfter(20).InsertAfter(10);
	cout << "list1 ==> " << list1 << ". Should be [ 50 40 30 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 10." << endl;
	iter1.End();
	list1.Erase(iter1);
	cout << "list1 ==> " << list1 << ". Should be [ 50 40 30 20 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Test Erase(iterator, iterator)." << endl;
	iter1 = list1.Iterator();
	iter1.End();
	iter1.InsertAfter(50).InsertAfter(40).InsertAfter(30).InsertAfter(20).InsertAfter(10);
	cout << "list1 ==> " << list1 << ". Should be [ 50 40 30 20 50 40 30 20 10 ]." << endl;
	iter1.Begin();
	iter2 = iter1;
	iter2.End();
	list1.Erase(iter1, iter2);
	cout << "list1 ==> " << list1 << ". Should be [ ]." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be in empty state." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be in empty state." << endl;
    
	cout << "Test that Erase(iterator) does nothing when iterator is invalid state." << endl;
	iter1 = list1.Iterator();
	iter1.End();
	iter1.InsertAfter(50).InsertAfter(40).InsertAfter(30).InsertAfter(20).InsertAfter(10);
	iter1++;
	list1.Erase(iter1);
	cout << "list1 ==> " << list1 << ". Should be [ 50 40 30 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
    
	cout << "Test that Erase(iterator, iterator) does nothing when invalid/valid." << endl;
	iter2 = list1.Iterator();
	iter2.End();
	iter2.InsertAfter(50).InsertAfter(40).InsertAfter(30).InsertAfter(20).InsertAfter(10);
	iter1 = list1.Iterator();
	--iter1;
	list1.Erase(iter1, iter2);
	cout << "list1 ==> " << list1 << ". Should be [ 50 40 30 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be pointing at 10." << endl;
    
	cout << "Test that Erase(iterator, iterator) does nothing when valid/invalid." << endl;
	list1.Erase();
	iter2 = list1.Iterator();
	iter2.End();
	iter2.InsertAfter(50).InsertAfter(40).InsertAfter(30).InsertAfter(20).InsertAfter(10);
	iter1 = list1.Iterator();
	++iter2;
	list1.Erase(iter1, iter2);
	cout << "list1 ==> " << list1 << ". Should be [ 50 40 30 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be pointing at 50." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be in invalid state." << endl;
    
	cout << "Test that Erase(iterator, iterator) does nothing when invalid/invalid." << endl;
	list1.Erase();
	iter2 = list1.Iterator();
	iter2.End();
	iter2.InsertAfter(50).InsertAfter(40).InsertAfter(30).InsertAfter(20).InsertAfter(10);
	iter1 = list1.Iterator();
	iter1 -= 100;
	iter2 += 100;
	list1.Erase(iter1, iter2);
	cout << "list1 ==> " << list1 << ". Should be [ 50 40 30 20 10 ]." << endl;
	cout << "iter1 ==> " << iter1 << ". Should be in invalid state." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be in invalid state." << endl;
    
	cout << "Test that Erase(iterator) does nothing when invalid." << endl;
	list1.Erase();
	iter2 = list1.Iterator();
	iter2.End();
	iter2.InsertAfter(50).InsertAfter(40).InsertAfter(30).InsertAfter(20).InsertAfter(10);
	iter2 += 100;
	list1.Erase(iter2);
	cout << "list1 ==> " << list1 << ". Should be [ 50 40 30 20 10 ]." << endl;
	cout << "iter2 ==> " << iter2 << ". Should be in invalid state." << endl;
}
