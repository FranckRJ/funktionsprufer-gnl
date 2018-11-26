#include "voidVal.hpp"

spVoidVal mkSpVoidVal()
{
	return std::make_shared<voidVal>();
}

voidVal::voidVal() : absVal<void *>(nullptr, "")
{
	setIsVoidVal(true);
}

std::string voidVal::valToString()
{
	return "VOID";
}
