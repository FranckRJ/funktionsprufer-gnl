#include <string>

#include "baseVal.hpp"

template <>
std::string baseVal<bool>::valToString()
{
	if (getVal())
	{
		return "true";
	}
	else
	{
		return "false";
	}
}

template <>
std::string baseVal<char>::valToString()
{
	return std::string(1, getVal());
}
