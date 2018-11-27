#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>

#include "addrVal.hpp"

addrVal::addrVal(void *newVal, void *newBaseVal, std::string newName, bool newNeedToFree) : absVal<void*>(newVal, newName)
{
	baseVal = newBaseVal;
	needToFree = newNeedToFree;
}

addrVal::~addrVal()
{
	if (needToFree)
	{
		delete[] static_cast<char*>(getVal());
	}
}

bool addrVal::equalsSameType(spAbsVal<void*> cmpVal)
{
	addrVal *ptrCmpVal = dynamic_cast<addrVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr)
	{
		return ((getVal() == nullptr && ptrCmpVal->getVal() == nullptr) ||
				((char*)getVal() - (char*)baseVal) == ((char*)ptrCmpVal->getVal() - (char*)ptrCmpVal->baseVal));
	}
	else
	{
		return false;
	}
}

void addrVal::setVal(void *newVal)
{
	if (needToFree && getVal() != nullptr && getVal() != newVal)
	{
		delete[] static_cast<char*>(getVal());
	}
	absVal::setVal(newVal);
}

std::string addrVal::valToString()
{
	if (getVal() == nullptr)
	{
		return "addrdif : NULL";
	}
	else
	{
		return "addrdif : " + std::to_string((char*)getVal() - (char*)baseVal);
	}
}
