//**************************************************************************************************************
// CLASS: BigCalc
//
// DESCRIPTION
// The implementation of the BigCalc class declared in BigCalc.hpp.
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
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "BigCalc.hpp"
#include "BigInt.hpp"

//--------------------------------------------------------------------------------------------------------------
// BigCalc::BigCalc()
//--------------------------------------------------------------------------------------------------------------
BigCalc::BigCalc()
{
	Run();
}

//--------------------------------------------------------------------------------------------------------------
// BigCalc::GetBigInt(char const *)
//--------------------------------------------------------------------------------------------------------------
BigInt BigCalc::GetBigInt(char const *pPrompt) const
{
	cout << pPrompt;
	BigInt n; cin >> n;
	return n;
}

//--------------------------------------------------------------------------------------------------------------
// BigCalc::GetCommand(char const *)
//--------------------------------------------------------------------------------------------------------------
BigCalc::tCommand BigCalc::GetCommand(char const *pPrompt) const
{
	string strCmd;
	while (true) {
		cout << pPrompt; cin >> strCmd;
		if (strCmd == "+") return eAdd;
		else if (strCmd == "/") return eDiv;
		else if (strCmd == "%") return eMod;
		else if (strCmd == "*") return eMult;
		else if (strCmd == "-") return eSub;
		else if (strCmd == "quit") return eQuit;
		cout << "I don't understand '" << strCmd << "'." << endl;
		cout << "Valid commands are: +, -, *, /, %, or quit. Why don't you try one of those mate?" << endl;
	}
}

//--------------------------------------------------------------------------------------------------------------
// BigCalc::Run()
//--------------------------------------------------------------------------------------------------------------
void BigCalc::Run()
{
	tCommand cmd = GetCommand("(bigcalc) ");
	while (cmd != eQuit) {
		BigInt lhsOp = GetBigInt("Lefthand operand? ");
		BigInt rhsOp = GetBigInt("Righthand operand? ");
		BigInt result;
		switch (cmd) {
			case eAdd:  result = lhsOp + rhsOp; break;
			case eDiv:  result = lhsOp / rhsOp; break;
			case eMod:  result = lhsOp % rhsOp; break;
			case eMult: result = lhsOp * rhsOp; break;
			case eSub:  result = lhsOp - rhsOp; break;
			case eQuit: break;
		}
		cout << result << endl << endl;
		cmd = GetCommand("(bigcalc) ");
	}
}
