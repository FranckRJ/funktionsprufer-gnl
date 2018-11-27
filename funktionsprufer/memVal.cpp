#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>

#include "memVal.hpp"

memVal::memVal(void *newVal, size_t newLen, std::string newName, bool newNeedToFree) : absVal<void*>(newVal, newName)
{
	len = newLen;
	needToFree = newNeedToFree;
}

memVal::~memVal()
{
	if (needToFree)
	{
		delete[] static_cast<char*>(getVal());
	}
}

bool memVal::equalsSameType(spAbsVal<void*> cmpVal)
{
	memVal *ptrCmpVal = dynamic_cast<memVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr)
	{
		return (len == ptrCmpVal->len && ((getVal() == nullptr && ptrCmpVal->getVal() == nullptr) ||
											((getVal() != nullptr && ptrCmpVal->getVal() != nullptr) &&
											 std::memcmp(getVal(), ptrCmpVal->getVal(), len) == 0)));
	}
	else
	{
		return false;
	}
}

size_t memVal::getLen()
{
	return len;
}

void memVal::setVal(void *newVal)
{
	if (needToFree && getVal() != nullptr && getVal() != newVal)
	{
		delete[] static_cast<char*>(getVal());
	}
	absVal::setVal(newVal);
}

void memVal::setLen(size_t newLen)
{
	len = newLen;
}

void memVal::setValAndLen(void *newVal, size_t newLen)
{
	setVal(newVal);
	setLen(newLen);
}

std::string memVal::valToString()
{
	if (getVal() != nullptr)
	{
		std::stringstream convert;
		std::string result;

		result += "{";
		for (size_t i = 0; i < len; ++i)
		{
			convert << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>((static_cast<unsigned char*>(getVal()))[i]);
			result += "0x" + convert.str();
			convert.str("");

			if (i < len - 1)
			{
				result += ", ";
			}
		}
		result += "}";

		return result;
	}
	else
	{
		return "NULL";
	}
}
