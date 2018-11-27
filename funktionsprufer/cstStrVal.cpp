#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>

#include "cstStrVal.hpp"

cstStrVal::cstStrVal(const char *newVal, std::string newName, bool newNeedToFree) : absVal<const char*>(newVal, newName)
{
	needToFree = newNeedToFree;
}

cstStrVal::~cstStrVal()
{
	if (needToFree)
	{
		delete[] getVal();
	}
}

bool cstStrVal::equalsSameType(spAbsVal<const char*> cmpVal)
{
	cstStrVal *ptrCmpVal = dynamic_cast<cstStrVal*>(cmpVal.get());

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

void cstStrVal::setVal(const char *newVal)
{
	if (needToFree && getVal() != nullptr && getVal() != newVal)
	{
		delete[] getVal();
	}
	absVal::setVal(newVal);
}

std::string cstStrVal::valToString()
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
