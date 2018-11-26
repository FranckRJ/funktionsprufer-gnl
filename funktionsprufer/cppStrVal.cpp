#include <string>
#include <iomanip>
#include <sstream>

#include "cppStrVal.hpp"

cppStrVal::cppStrVal(std::string newVal, std::string newName) : absVal<std::string>(newVal, newName)
{
	//rien
}

bool cppStrVal::equalsSameType(spAbsVal<std::string> cmpVal)
{
	cppStrVal *ptrCmpVal = dynamic_cast<cppStrVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr)
	{
		return (getVal() == ptrCmpVal->getVal());
	}
	else
	{
		return false;
	}
}

std::string cppStrVal::valToString()
{
	return getVal();
}
