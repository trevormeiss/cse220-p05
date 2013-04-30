//**************************************************************************************************************
// CLASS: BigInt (derived from DList)
//
// DESCRIPTION
// Declares a class the represents a bigint.
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
#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <istream>
using std::istream;

#include <ostream>
using std::ostream;

#include "DList.hpp"

//==============================================================================================================
// CLASS: BigInt (derived from DList)
//==============================================================================================================
class BigInt : public DList {
    
public:
	//==========================================================================================================
	// PUBLIC TYPES
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// An enumerated type to rerpresent the sign of the BigInt. The mSign data member is of this type.
	//----------------------------------------------------------------------------------------------------------
	typedef enum { eNeg = -1, ePos = 1 } tSign;
    
	//==========================================================================================================
	// PUBLIC CONTANT MEMBERS
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// The increment and decrement operators require us to use BigInt(1), so rather than constructing and de-
	// structing BigInt(1) every time those functions are called, we define a static constant object for
	// BigInt(1) that can be reused.
	//----------------------------------------------------------------------------------------------------------
	static BigInt const PosOne;
    
	//==========================================================================================================
	// PUBLIC FUNCTION MEMBERS
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// BigInt() -- Default ctor.
	//
	// Initializes the BigInt to be "empty", i.e., it contains no digits. This is not the same as the BigInt 0,
	// whiich would contains one zero digit.
	//----------------------------------------------------------------------------------------------------------
	BigInt();
    
	//----------------------------------------------------------------------------------------------------------
	// BigInt(char const *)
	//
	// Initializes this BigInt to the integer contained in pString. If the first character of pString is '-'
	// then this BigInt is negative (mSign is set to eNeg), otherwise it is positive. The remaining characters
	// of pString must all be digit characters '0' - '9'.
	//----------------------------------------------------------------------------------------------------------
	explicit BigInt(char const *pString);
    
	//----------------------------------------------------------------------------------------------------------
	// BigInt(int const)
	//
	// Initializes this BigInt to the signed integer pInt.
	//----------------------------------------------------------------------------------------------------------
	explicit BigInt(int const pInt);
    
	//----------------------------------------------------------------------------------------------------------
	// BigInt(unsigned const)
	//
	// Initializes this BigInt to the unsigned integer pUint.
	//----------------------------------------------------------------------------------------------------------
	explicit BigInt(unsigned const pUint);
    
	//----------------------------------------------------------------------------------------------------------
	// BigInt(string const&)
	//
	// This ctor mirrors BigInt(char const *) for C++ strings.
	//----------------------------------------------------------------------------------------------------------
	explicit BigInt(string const& pString);
    
	//----------------------------------------------------------------------------------------------------------
	// BigInt(BigInt const&) -- Copy ctor.
	//
	// Makes this BigInt a copy of pBigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt(BigInt const& pBigInt);
    
	//----------------------------------------------------------------------------------------------------------
	// ~BigInt() -- Destructor
	//
	// The BigInt destructor has nothing to do because there is no dynamically-allocated memory to delete. How-
	// ever, note that the base class (DList) destructor *is* called before the body of this destructor executes
	// and the DList destructor deletes every node in the list, thus ensuring there are no memory leaks when a
	// BigInt object dies. Since the destructor is essentially an empty function, I have inlined it.
	//----------------------------------------------------------------------------------------------------------
	virtual ~BigInt()
	{
	}
    
	//----------------------------------------------------------------------------------------------------------
	// Returns a new BigInt which is the absolute value of this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt Abs() const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns the maximum of this BigInt and pBigInt as a new BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt Max(BigInt const& pBigInt) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns the minimum of this BigInt and pBigInt as a new BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt Min(BigInt const& pBigInt) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Postincrement operator.
	//----------------------------------------------------------------------------------------------------------
	BigInt operator++(int const pDummy);
    
	//----------------------------------------------------------------------------------------------------------
	// Postdecrement operator.
	//----------------------------------------------------------------------------------------------------------
	BigInt operator--(int const pDummy);
    
	//----------------------------------------------------------------------------------------------------------
	// Preincrement operator.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator++();
    
	//----------------------------------------------------------------------------------------------------------
	// Predecrement operator.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator--();
    
	//----------------------------------------------------------------------------------------------------------
	// Returns a new BigInt which is the negation of this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt operator-() const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns a string representation of the BigInt.
	//----------------------------------------------------------------------------------------------------------
	virtual operator string() const;
    
	//----------------------------------------------------------------------------------------------------------
	// Multiplies this BigInt by pRhsOp and returns a new BigInt which is the product.
	//----------------------------------------------------------------------------------------------------------
	BigInt operator*(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Divides this BigInt by pRhsOp and returns a new BigInt which is the quotient.
	//----------------------------------------------------------------------------------------------------------
	BigInt operator/(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns the remainder after dividing this BigInt by pRhsOp.
	//----------------------------------------------------------------------------------------------------------
	BigInt operator%(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Adds this BigInt to pRhsOp and returns a new BigInt which is the sum.
	//----------------------------------------------------------------------------------------------------------
	BigInt operator+(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Subtracts pRhsOp from this BigInt and returns a new BigInt which is the difference.
	//----------------------------------------------------------------------------------------------------------
	BigInt operator-(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this BigInt is less than pRhsOp.
	//----------------------------------------------------------------------------------------------------------
	bool operator<(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this BigInt is greater than pRhsOp.
	//----------------------------------------------------------------------------------------------------------
	bool operator>(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this BigInt is less or equal to pRhsOp.
	//----------------------------------------------------------------------------------------------------------
	bool operator<=(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this BigInt is greater than or equal to pRhsOp.
	//----------------------------------------------------------------------------------------------------------
	bool operator>=(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this BigInt is equal to pRhsOp.
	//----------------------------------------------------------------------------------------------------------
	bool operator==(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this BigInt is not equal to pRhsOp.
	//----------------------------------------------------------------------------------------------------------
	bool operator!=(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Multiplies this BigInt by pRhsOp and assigns the new product to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator*=(BigInt const& pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Divides this BigInt by pRhsOp and assigns the new quotient to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator/=(BigInt const& pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Modulos this BigInt by pRhsOp and assigns the new modulo to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator%=(BigInt const& pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Adds this BigInt and pRhsOp and assigns the new sum to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator+=(BigInt const& pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Subtracts pRhsOp from this BigInt and assigns the new difference to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator-=(BigInt const& pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Assigns the BigInt pRhsOp to this Bigint.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator=(BigInt const& pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Assigns a bigint represented as a C-string to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator=(char const *pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Assigns a bigint represented as a signed integer to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator=(int const pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Assigns a bigint represented as an unsigned integer to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator=(unsigned const pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Assigns a bigint represented as a C++ string to this BigInt.
	//----------------------------------------------------------------------------------------------------------
	BigInt& operator=(string const& pRhsOp);
    
	//----------------------------------------------------------------------------------------------------------
	// Returns the sign of the BigInt.
	//----------------------------------------------------------------------------------------------------------
	tSign Sign() const;
    
protected:
	//==========================================================================================================
	// PROTECTED FUNCTION MEMBERS
	//==========================================================================================================
    
	//----------------------------------------------------------------------------------------------------------
	// Adds this BigInt and pRhsOp and returns a new BigInt which is the sum. On input, both this BigInt and
	// pRhsOp should be positive. This function is not designed to be directly called to perform addition of
	// BigInts, but rather, is intended to be called from operator+() and operator-().
	//----------------------------------------------------------------------------------------------------------
	BigInt Add(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Makes this BigInt a copy of pBigInt. Designed to be called from operator=(BigInt const&).
	//----------------------------------------------------------------------------------------------------------
	virtual BigInt& Copy(BigInt const& pBigInt);
    
	//----------------------------------------------------------------------------------------------------------
	// Divides this BigInt by pRhsOp and returns a new BigInt which is the quotient. On input, both this BigInt
	// and pRhsOp should be positive. This function is not designed to be directly called to perform division of
	// BigInts, but rather, is intended to be called from operator/().
	//
	// pRemainder is an output parameter from this function, and returns the remainder after performing the
	// integer division. The returned remainder is used in the operator%() function.
	//----------------------------------------------------------------------------------------------------------
	BigInt Divide(BigInt const& pRhsOp, BigInt& pRemainder) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Initializes this BigInt to the integer contained within pString. The first character of pString may be
	// a '-' character indicating that the BigInt is negative.
	//----------------------------------------------------------------------------------------------------------
	void Init(char const *pString);
    
	//----------------------------------------------------------------------------------------------------------
	// Initializes this BigInt to the signed integer pInt.
	//----------------------------------------------------------------------------------------------------------
	void Init(int const pInt);
    
	//----------------------------------------------------------------------------------------------------------
	// Initializes this BigInt to the unsigned integer pUint.
	//----------------------------------------------------------------------------------------------------------
	void Init(unsigned const pUint);
    
	//----------------------------------------------------------------------------------------------------------
	// Returns true if this BigInt is 0.
	//
	// Checking for zero is a fairly common operation, so rather than calling operator==() we will do it by
	// calling this function, which is designed to be faster than testing in operator==().
	//----------------------------------------------------------------------------------------------------------
	bool IsZero() const;
    
	//----------------------------------------------------------------------------------------------------------
	// Multiplies this BigInt by pRhsOp and returns a new BigInt which is the product. On input, both this
	// BigInt and pRhsOp should be positive. This function is not designed to be directly called to perform
	// multiplication of BigInts, but rather, is intended to be called from operator*().
	//----------------------------------------------------------------------------------------------------------
	BigInt Multiply(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Negates the sign of this BigInt.
	//----------------------------------------------------------------------------------------------------------
	void Negate();
    
	//----------------------------------------------------------------------------------------------------------
	// Mutator function for mSign.
	//----------------------------------------------------------------------------------------------------------
	void Sign(tSign const pSign);
    
	//----------------------------------------------------------------------------------------------------------
	// Subtracts pRhsOp from this BigInt and returns a new BigInt which is the difference. On input, both this
	// BigInt and pRhsOp should be positive and this BigInt must be greater than or equal to pRhsOp. This func-
	// tion is not designed to be directly called to perform subtraction of BigInts, but rather, is intended to
	// be called from operator+() and operator-().
	//----------------------------------------------------------------------------------------------------------
	BigInt Subtract(BigInt const& pRhsOp) const;
    
	//----------------------------------------------------------------------------------------------------------
	// Trims this BigInt by removing any leading 0 digits. Some arithmetic operations may result in a BigInt
	// such as 000001234, which this function reduces to 1234. Also, some arithmetic operations could result
	// in a BigInt such as 0000 which this function reduces to the BigInt 0. This function is intended to be
	// called before returning the result from operator*(), operator/(), operator%(), operator+(), and
	// operator-().
	//----------------------------------------------------------------------------------------------------------
	BigInt& Trim();
    
private:
	//==========================================================================================================
	// PRIVATE DATA MEMBERS AND FUNCTION MEMBERS
	//==========================================================================================================
    
	tSign mSign;
};

//==============================================================================================================
// NONMEMBER FUNNCTION PROTOTYPES
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Overloads the << operator for output streams so a BigInt may be sent to the output stream pStream as a
// string. This permits the following,
//
// BigInt b1 = "123123213453242343243253254365465465466546";
// BigInt b2 = "e32432498324983409812091283120389123091823";
// BigInt b3 = b1 + b2;
// cout << b3;
// ofstream fout("a.big");
// fout << b3;
// fout.close();
//--------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& pStream, BigInt const& pBigInt);

//--------------------------------------------------------------------------------------------------------------
// Overloads the >> operator for output streams so a BigInt may be extracted from an input stream pStream,
//
// BigInt n;
// cout << "Enter a bigint? ";
// cin >> n;
// ifstream fin("a.big");
// fin >> n;
// fin.close();
//--------------------------------------------------------------------------------------------------------------
istream& operator>>(istream& pStream, BigInt& pBigInt);

#endif
