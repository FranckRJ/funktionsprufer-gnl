#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>

#include "strTabVal.hpp"

strTabVal::strTabVal(char **newVal, int newTabSize, std::string newName, bool newNeedToFree) : absVal<char**>(newVal, newName)
{
	tabSize = newTabSize;
	needToFree = newNeedToFree;
}

strTabVal::~strTabVal()
{
	if (needToFree)
	{
		deleteCurrentTab();
	}
}

bool strTabVal::equalsSameType(spAbsVal<char**> cmpVal)
{
	strTabVal *ptrCmpVal = dynamic_cast<strTabVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr)
	{
		if (getVal() == nullptr || ptrCmpVal->getVal() == nullptr)
		{
			return (getVal() == ptrCmpVal->getVal());
		}
		else
		{
			if (getCurrentSize() == ptrCmpVal->getCurrentSize())
			{
				for (int i = 0; i < getCurrentSize(); ++i)
				{
					if (std::string(getVal()[i]) != std::string(ptrCmpVal->getVal()[i]))
					{
						return false;
					}
				}
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

void strTabVal::setVal(char **newVal)
{
	if (needToFree)
	{
		deleteCurrentTab();
	}
	absVal::setVal(newVal);
}

std::string strTabVal::valToString()
{
	if (getVal() != nullptr)
	{
		std::string newStr;
		newStr += "[";
		for (int i = 0; i < getCurrentSize(); ++i)
		{
			newStr += "\"" + std::string(getVal()[i]) + "\"";
			if (i < (getCurrentSize() - 1))
			{
				newStr += ", ";
			}
		}
		newStr += "]";
		return newStr;
	}
	else
	{
		return "NULL";
	}
}

void strTabVal::deleteCurrentTab()
{
	if (getVal() != nullptr)
	{
		for (int i = 0; i < getCurrentSize(); ++i)
		{
			delete[] (getVal()[i]);
		}
		delete[] getVal();
	}
}

int strTabVal::getCurrentSize()
{
	if (getVal() == nullptr || tabSize >= 0)
	{
		return tabSize;
	}
	else
	{
		int i = 0;
		while (getVal()[i] != nullptr)
		{
			++i;
		}
		return i;
	}
}
