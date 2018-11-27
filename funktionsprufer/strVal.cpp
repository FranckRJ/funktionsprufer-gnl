#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>

#include "strVal.hpp"

strVal::strVal(char *newVal, std::string newName, bool newNeedToFree) : absVal<char*>(newVal, newName)
{
	needToFree = newNeedToFree;
}

strVal::~strVal()
{
	if (needToFree)
	{
		delete[] getVal();
	}
}

bool strVal::equalsSameType(spAbsVal<char*> cmpVal)
{
	strVal *ptrCmpVal = dynamic_cast<strVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr)
	{
		if (getVal() == nullptr || ptrCmpVal->getVal() == nullptr)
		{
			return (getVal() == ptrCmpVal->getVal());
		}
		else
		{
			return (std::string(getVal()) == std::string(ptrCmpVal->getVal()));
		}
	}
	else
	{
		return false;
	}
}

void strVal::setVal(char *newVal)
{
	if (needToFree && getVal() != nullptr && getVal() != newVal)
	{
		delete[] getVal();
	}
	absVal::setVal(newVal);
}

std::string strVal::valToString()
{
	if (getVal() != nullptr)
	{
		return std::string(getVal());
	}
	else
	{
		return "NULL";
	}
}
