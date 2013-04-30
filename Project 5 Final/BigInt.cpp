//**************************************************************************************************************
// CLASS: BigInt
//
// DESCRIPTION
// The implementation of the BigInt class declared in BigInt.hpp.
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
#include <cstdlib>  // abs()

#include <istream>
using std::istream;

#include <ostream>
using std::ostream;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include "BigInt.hpp"

//--------------------------------------------------------------------------------------------------------------
// The increment and decrement operators require us to use BigInt(1), so rather than constructing and destruct-
// ing it every time those functions are called, we define a static class object for BigInt(1).
//
// This constant is declared in the BigInt class declaration in BigInt.hpp.
//
// PSEUDOCODE
// Define PosOne to be the BigInt 1.
//--------------------------------------------------------------------------------------------------------------
PosOne = BigInt(1);

//--------------------------------------------------------------------------------------------------------------
// BigInt::BigInt()
//
// PSEUDOCODE
// Because BitInt is a derived class of DList, the default ctor of the DList class will be automatically called.
// In the member init list, initialize mSign to ePos.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::BigInt(char const *)
//
// PSEUDOCODE
// Because BitInt is a derived class of DList, the default ctor of the DList class will be automatically called.
// In the member init list, initialize mSign to eNeg if the first char of pString is '-' or ePos if it is not.
//   Hint: use the conditional ?: operator.
// Call Init(char const *) passing pString as the parameter.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::BigInt(int const)
//--------------------------------------------------------------------------------------------------------------
BigInt::BigInt(int const pInt)
{
	Init(pInt);
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::BigInt(unsigned const)
//--------------------------------------------------------------------------------------------------------------
BigInt::BigInt(unsigned const pUint)
{
	Init(pUint);
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::BigInt(string const&)
//
// PSEUDOCODE
// Because BitInt is a derived class of DList, the default ctor of the DList class will be automatically called.
// In the member init list, initialize mSign to eNeg if the first char of pString is '-' or ePos if it is not.
//   Hint: use the conditional ?: operator.
// Call Init(char const *) passing a pointer to the C-string stored in pString as the parameter.
//   Hint: there is a string class function that returns a pointer to the C-string stored within a C++ string.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::BigInt(BigInt const&)
//
// This is the copy ctor. It needs to make this BigInt an identical (deep) copy of pBigInt.
//
// PSEUDOCODE
// By default, the DList default ctor will be automatically called. But that's not the one we need to call. The
//   one we need to call is the DList copy ctor. Write the code in the member init list to call the DList copy
//   ctor passing pBigInt as the param.
// In the member init list, initialize mSign to the mSign data member of pBigInt.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::Abs() const
//
// PSEUDOCODE
// Instantiate a BigInt object named absThis and set it equal to *this (invokes operator=()).
// Change the mSign data member of absThis to be ePos.
// Return absThis.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::Add(BigInt const& pRhsOp) const
//
// Implements the standard addition algorithm that you learned in kindergarten (I learned it in the third grade,
// but you kids are much smarter than we were in my day).
//
// PRECONDITIONS
// Both this BigInt and pRhsOp are positive.
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::Add(BigInt const& pRhsOp) const
{
	int carry = 0;
	BigInt sum;
	BigInt const& term1 = Size() > pRhsOp.Size() ? *this : pRhsOp;
	BigInt const& term2 = Size() > pRhsOp.Size() ? pRhsOp : *this;
	DListIterator it1 = term1.Iterator().End(), it2 = term2.Iterator().End();
	for (; it1; --it1, --it2) {
		int digit1 = it1();
		int digit2 = it2 ? it2() : 0;
		int minisum = carry + digit1 + digit2;
		sum.Prepend(minisum % 10);
		carry = minisum / 10;
	}
	if (carry) sum.Prepend(carry);
	return sum;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Copy(BigInt const&)
//
// Makes this BigInt an identical (deep) copy of pBigInt.
//
// PSEUDOCODE
// Call the Copy() function of the DList class passing pBigInt as the param.
// Set the sign of this BigInt to the sign of pBigInt.
// Return a reference to this BigInt.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::Divide(BigInt const& pRhsOp, BigInt& pRemainder) const
//
// On input, this BigInt is the dividend and pRhsOp is the divisor. See Knuth's algorithm D in the lab project
// document. Implement it here.
//
// PRECONDITIONS
// Both this BigInt and pRhsOp are positive.
// this BigInt is greater than or equal to pRhsOp (if it's not, the quotient is 0 and the remainder is pRhsOp).
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::Divide(BigInt const& pRhsOp, BigInt& pRemainder) const
{
	BigInt quotient;
	???
	return quotient;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Init(char const *)
//--------------------------------------------------------------------------------------------------------------
void BigInt::Init(char const *pString)
{
	char const *digit = *pString == '-' ? pString + 1 : pString;
	for (; digit && *digit; ++digit) Append(*digit - '0');
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Init(int const pInt)
//
// PSEUDOCODE
// Call Init(unsigned const) passing the absoluate value of pInt typecasted to unsigned const as the param.
// Set the sign of this BigInt to ePos or eNeg depending on the sign of pInt.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::Init(unsigned const pUint)
//--------------------------------------------------------------------------------------------------------------
void BigInt::Init(unsigned const pUint)
{
	unsigned n = pUint;
	do { Prepend(n % 10); n /= 10; } while (n);
	mSign = ePos;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::IsZero() const
//
// PSEUDOCODE
// A BigInt is 0 if: (1) mSize is 1; and (2) mHead->mData is 0.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::Max(BigInt const&) const
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::Max(BigInt const& pBigInt) const
{
	return *this >= pBigInt ? *this : pBigInt;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Min(BigInt const&) const
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::Min(BigInt const& pBigInt) const
{
	return *this <= pBigInt ? *this : pBigInt;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Multiply(BigInt const& pRhsOp) const
//
// Multiplies this BigInt (the multiplicand) by pRhsOp (the multiplier). See the project document for the
// Multiply pseudocode.
//
// PRECONDITIONS
// Both this BigInt and pRhsOp are positive.
// this BigInt is greater than or equal to pRhsOp.
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::Multiply(BigInt const& pRhsOp) const
{
	BigInt product;
	???
	return product;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Negate()
//
// Negates the sign of this BigInt.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator++(int const) -- Postincrement
//
// Adds 1 to this BigInt.
//
// PSEUDOCODE
// Look at how I implemented this function in the DListIterator class. What you need to do here is similar.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator--(int const) -- Postdeccrement
//
// Subtracts 1 from this BigInt.
//
// PSEUDOCODE
// Look at how I implemented this function in the DListIterator class. What you need to do here is similar.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator++() -- Preincrement
//
// PSEUDOCODE
// Add PosOne to this BigInt.
// Return a reference to this BigInt.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator--() -- Predeccrement
//
// PSEUDOCODE
// Subtract PosOne from this BigInt.
// Return a reference to this BigInt.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator string()
//
// Returns a string representation of this BigInt. You don't need to write the code for this function, but you
// ought to study it until you understand it.
//--------------------------------------------------------------------------------------------------------------
BigInt::operator string() const
{
	stringstream sstr;
	if (mSign == eNeg) sstr << '-';
	for (DListIterator it = Iterator(); it; ++it) sstr << static_cast<char>(it() + '0');
	return sstr.str();
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator-() -- Negation operator
//
// Returns a new BigInt which is the same as this BigInt but with the sign negated.
//
// PSEUDOCODE
// Instantiate a new BigInt named negThis calling the copy ctor to initialize negThis to this BigInt.
// Call Negate() on negThis to negate the sign.
// Return negThis.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator*(BigInt const&)
//
// Multiplies this BigInt by pRhsOp. Needs to call Multiply() such that the Multiply() preconditions are met.
// This function handles that and deals with figuring out the sign of the returned product.
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator*(BigInt const& pRhsOp) const
{
	BigInt product;
	???
	return product;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator/(BigInt const&)
//
// Divides this BigInt by pRhsOp. Needs to call Divide() such that the Divide() preconditions are met. This
// function handles that and deals with figuring out the sign of the returned quotient.
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator/(BigInt const& pRhsOp) const
{
	BigInt quotient;
	???
	return quotient;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator%(BigInt const&)
//
// Divides this BigInt by pRhsOp and returns the remainder. Needs to call Divide() such that the Divide() pre-
// conditions are met. This function handles that and deals with figuring out the sign of the returned remain-
// der.
//
// REMARK
// There is some ambiguity that can arise when modulus is applied to negative operands. In general, if q = a / b
// and r is the remainder, then by algebra,
//
//     a = q * b + r
//
// For example, consider a = 10 and b = 4. q would be 2 and r would be 2, so
//
//     10 = 2 * 4 + 2
//
// However, what if a = -10?
//
//       -2 <-- this is the quotient, q
//    +----
//  4 | -10
//       -8
//      ---
//       -2 <-- this is the remainder, r
//
// or it could be 2,
//
//       -3 <-- this is the quotient, q
//    +----
//  4 | -10
//      -12
//      ---
//        2 <-- this is the remainder, r
//
// Consequently, -10 mod 4 could be either -2 or 2 depending on how you want to define it. To see how C and C++
// handle it, consider this C program and it's output,
//
// #include <stdio.h>
// int main()
// {
//     int a = 10, b = 4;
//     printf("%d mod %d = %d\n",  a,  b,  a %  b);
//     printf("%d mod %d = %d\n", -a,  b, -a %  b);
//     printf("%d mod %d = %d\n",  a, -b,  a % -b);
//     printf("%d mod %d = %d\n", -a, -b, -a % -b);
//     return 0;
// }
//
// 10 mod 4 = 2
// -10 mod 4 = -2
// 10 mod -4 = 2
// -10 mod -4 = -2
//
// Notice that a mod b is positive when a is positive and negative when a is negative. Therefore, the rule we
// we apply is: the sign of a mod b is the sign of a.
//
// PSEUDOCODE
// Call Divide() such that the preconditions are met. Divide() returns the remainder, and this function must
// set the sign of the remainder to the sign of this BigInt.
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator%(BigInt const& pRhsOp) const
{
	BigInt remainder;
	???
	return remainder;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator+(BigInt const&)
//
// Calls Add() or Subtract() to add this BigInt and pRhsOp. This function deals with the signs of the operands
// and the sum. In particular, we have three cases:
//
// 1. If this BigInt and pRhsOp are both positive,
//
//    We simply call Add() on this BigInt passing pRhsOp and set the sign of the returned sum to ePos.
//
// 2. If this BigInt and pRhsOp are both negative,
//
//    We create two BigInts, term1 and term2, setting the signs of each to ePos.
//    Call Add() on term1 passing term2 as the param.
//    Set the sign of the returned sum to eNeg.
//
// 3. The signs of this BigInt and pRhsOp are different,
//
//    We create two BigInts: term1 = Max(|*this|, |pRhsOp|) and term2 = Min(|*this|, |pRhsOp|).
//    We call Subtract() on term1 passing term2 as the param.
//    We set the sign of the returned sum to the sign of this BigInt if |*this| > |pRhsOp| or the sign of pRhsOp
//      otherwise.
//
// REMARK
// In the process of adding, we could end up (due to the way the Add() function is implemented) with a BigInt
// which as leading 0's, for example,
//
//     9999988
//    +     11
//    --------
//     0000099
//
// The Trim() function would return the BigInt 0000099 as 99 (i.e., by deleting the leading 0's).
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator+(BigInt const& pRhsOp) const
{
	BigInt sum;
	if (mSign == ePos && pRhsOp.mSign == ePos) {
		sum = Add(pRhsOp);
		sum.mSign = ePos;
	} else if (mSign == pRhsOp.mSign) {
		BigInt term1 = *this, term2 = pRhsOp;
		term1.mSign = term2.mSign = ePos;
		sum = term1.Add(term2);
		sum.mSign = eNeg;
	} else {
		BigInt absThis = Abs(), absRhsOp = pRhsOp.Abs();
		BigInt term1 = absThis.Max(absRhsOp), term2 = absThis.Min(absRhsOp);
		sum = term1.Subtract(term2);
		sum.mSign = absThis > absRhsOp ? mSign : pRhsOp.mSign;
	}
	return sum.Trim();
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator-(BigInt const&)
//
// Implements subtraction by handling the signs of the operands, calling Subtract(), and setting the sign of the
// returned diff appropriately. If you can figure out what I did in operator+() then you should be able to un-
// derstand this code.
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::operator-(BigInt const& pRhsOp) const
{
	BigInt diff;
	if (mSign == ePos && pRhsOp.mSign == ePos) {
		BigInt term1 = Max(pRhsOp), term2 = Min(pRhsOp);
		diff = term1.Subtract(term2);
		diff.mSign = *this < pRhsOp ? eNeg : ePos;
	} else if (mSign == pRhsOp.mSign) {
		BigInt absThis = Abs(), absRhsOp = pRhsOp.Abs();
		BigInt term1 = absThis.Max(absRhsOp), term2 = absThis.Min(absRhsOp);
		diff = term1.Subtract(term2);
		diff.mSign = *this < pRhsOp ? eNeg : ePos;
	} else {
		BigInt absThis = Abs(), absRhsOp = pRhsOp.Abs();
		diff = absThis.Add(absRhsOp);
		diff.mSign = mSign;
	}
	return diff.Trim();
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator<(BigInt const&)
//
// Check for some trivial cases first,
//
// 1. If the sign of this BigInt and the sign of pRhsOp are different: returns true if this BigInt is negative,
//    otherwise returns false.
//
// 2. If the signs are the same and the number of digits in this BigInt is greater than than the number of
//    digits in pRhsOp: returns true if this BigInt is negative, otherwise returns false.
//
// 3. If the signs are the same and the number of digits in this BigInt is less than than the number of digits
//    in pRhsOp: returns true if this BigInt is positive, otherwise returns false.
//
// If none of those cases are satisfied, then we have two BigInts, with the same signs and the same number of
// digits. Therefore, we have to resort to comparing them digit-by-digit from the most-significant digit to the
// least-significant digit. The first mismatch we find will tell us if this BigInt is less than pRhsOp.
//--------------------------------------------------------------------------------------------------------------
bool BigInt::operator<(BigInt const& pRhsOp) const
{
	// Case 1:
	if (mSign != pRhsOp.mSign) return mSign == eNeg;
    
	// Case 2:
	else if (Size() > pRhsOp.Size()) return mSign == eNeg;
    
	// Case 3:
	else if (Size() < pRhsOp.Size()) return mSign == ePos;
    
	// Compare the BigInts digit-by-digit.
	DListIterator it = Iterator();
	DListIterator itRhsOp = pRhsOp.Iterator();
	for (; it && it() == itRhsOp(); ++it, ++itRhsOp) { }
    
	// When we drop out of the loop, it will be false if the iterator is in the invalid state. This will happen
	// if we iterated over the entire list of digits without finding a mismatch. Consequently, the two BigInts
	// are, in fact, equal, so we return false (if a and b are equal, then a < b is false).
	if (!it) return false;
    
	// If the digit that iterator it is pointing to is greater than the digit that iterator itRhsOp is pointing
	// to then return true if this BigInt is negative, otherwise return false.
	else if (it() > itRhsOp()) return mSign == eNeg;
    
	// The digit that iterator it is pointing to is less than the digit that iterator itRhsOp is pointing to
	// so return true if the sign of this BigInt is positive, otherwise return false.
	else return mSign == ePos;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator>(BigInt const&)
//
// Note that by implementing operator==() and operator<() all four of the remaining relational operators can
// be implemented using those two. Pretty cool, huh?
//--------------------------------------------------------------------------------------------------------------
bool BigInt::operator>(BigInt const& pRhsOp) const
{
	return !(*this <= pRhsOp);
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator<=(BigInt const&)
//
// Note that by implementing operator==() and operator<() all four of the remaining relational operators can
// be implemented using those two. Pretty cool, huh?
//--------------------------------------------------------------------------------------------------------------
bool BigInt::operator<=(BigInt const& pRhsOp) const
{
	return *this < pRhsOp || *this == pRhsOp;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator>=(BigInt const&)
//
// Note that by implementing operator==() and operator<() all four of the remaining relational operators can
// be implemented using those two. Pretty cool, huh?
//--------------------------------------------------------------------------------------------------------------
bool BigInt::operator>=(BigInt const& pRhsOp) const
{
	return !(*this < pRhsOp);
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator==(BigInt const&)
//
// Check a trivial case first: if the signs of this BigInt and pRhsOp are different, they cannot be equal.
// Otherwise, the signs are the same so we have to perform a digit-by-digit comparison. Since the DList class
// implements an operator=() function which does exactly that, we don't have to write it ourselves; we simply
// call it.
//--------------------------------------------------------------------------------------------------------------
bool BigInt::operator==(BigInt const& pRhsOp) const
{
	if (mSign != pRhsOp.mSign) return false;
	return DList::operator==(pRhsOp);
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator!=(BigInt const&)
//
// Note that by implementing operator==() and operator<() all four of the remaining relational operators can
// be implemented using those two. Pretty cool, huh?
//--------------------------------------------------------------------------------------------------------------
bool BigInt::operator!=(BigInt const& pRhsOp) const
{
	return !(*this == pRhsOp);
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator*=(BigInt const&)
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator*=(BigInt const& pRhsOp)
{
	*this = *this * pRhsOp;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator/=(BigInt const&)
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator/=(BigInt const& pRhsOp)
{
	*this = *this / pRhsOp;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator%=(BigInt const&)
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator%=(BigInt const& pRhsOp)
{
	*this = *this % pRhsOp;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator+=(BigInt const&)
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator+=(BigInt const& pRhsOp)
{
	*this = *this + pRhsOp;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator-=(BigInt const&)
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator-=(BigInt const& pRhsOp)
{
	*this = *this - pRhsOp;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator=(BigInt const&)
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator=(BigInt const& pRhsOp)
{
	if (this != &pRhsOp) Copy(pRhsOp);
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator=(char const* pString)
//
// This function permits me to write code like this,
//
// BigInt a;
// a = "-12389123871298371298371293712931273";
//
// REMARK
// If you write,
//
// BigInt a = "-12389123871298371298371293712931273";
//
// it does not call this function, but rather it invokes BigInt::BigInt(char const *).
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator=(char const *pRhsOp)
{
	Erase();
	Init(pRhsOp);
	if (*pRhsOp == '-') mSign = eNeg;
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator=(int const)
//
// This function permits me to write code like this,
//
// BigInt a;
// a = -213123123;
//
// REMARK
// If you write,
//
// BigInt a = -213123123;
//
// it does not call this function, but rather it invokes BigInt::BigInt(int const).
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator=(int const pRhsOp)
{
	Erase();
	Init(pRhsOp);
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator=(unsigned const)
//
// This function permits me to write code like this,
//
// BigInt a;
// a = 234234234U;
//
// REMARK
// If you write,
//
// BigInt a = 234234234U;
//
// it does not call this function, but rather it invokes BigInt::BigInt(unsigned const).
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator=(unsigned const pRhsOp)
{
	Erase();
	Init(pRhsOp);
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::operator=(string const&)
//
// This function permits me to write code like this,
//
// BigInt a;
// string foo = "3213491239123912391231231231239";
// a = foo;
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::operator=(string const& pRhsOp)
{
	*this = pRhsOp.c_str();
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Sign()
//
// Accessor function for mSign.
//--------------------------------------------------------------------------------------------------------------
BigInt::tSign BigInt::Sign() const
{
	return mSign;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Sign(tSign const)
//
// Mutator function for mSign.
//--------------------------------------------------------------------------------------------------------------
void BigInt::Sign(tSign const pSign)
{
	mSign = pSign;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Subtract(BigInt const& pRhsOp) const
//
// PRECONDITIONS
// On input, the signs of this BigInt and pRhsOp must be the same and this BigInt must be greater than pRhsOp.
// These preconditions are handled in operator-().
//--------------------------------------------------------------------------------------------------------------
BigInt BigInt::Subtract(BigInt const& pRhsOp) const
{
	int borrow = 0;
	BigInt diff;
	DListIterator it1 = Iterator().End(), it2 = pRhsOp.Iterator().End();
	for (; it1; --it1, --it2) {
		int digit1 = it1(), digit2 = it2 ? it2() : 0;
		if (borrow) { --digit1; borrow = 0; }
		if (digit1 < digit2) borrow = 10;
		int minidiff = borrow + digit1 - digit2;
		diff.Prepend(minidiff);
	}
	return diff;
}

//--------------------------------------------------------------------------------------------------------------
// BigInt::Trim()
//
// Deletes all leading 0's. If we delete every node in the list, then the resulting BigInt is 0.
//--------------------------------------------------------------------------------------------------------------
BigInt& BigInt::Trim()
{
	DListIterator it = Iterator();
	while (it && it() == 0) { it.Delete(); }
	if (!it) { mSign = ePos; Prepend(0); }
	return *this;
}

//--------------------------------------------------------------------------------------------------------------
// operator<<(ostream&, BigInt const&)
//
// PSEUDOCODE
// Typecast pBigInt to string and send the resulting string to pStream.
// Return pStream.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// operator>>(istream&, BigInt const&)
//
// PSEUDOCODE
// Define a string object named strBigInt.
// Read a string from pStream into strBigInt.
// Assign strBigInt to pBigInt (this invokes BigInt::operator=(string const&)).
// Return pStream.
//--------------------------------------------------------------------------------------------------------------
???