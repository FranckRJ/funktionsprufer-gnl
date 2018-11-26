#ifndef VOIDVAL_HPP
#define VOIDVAL_HPP

#include <string>

#include "absVal.hpp"

class voidVal;

using spVoidVal = std::shared_ptr<voidVal>;

spVoidVal mkSpVoidVal();

class voidVal : public absVal<void*>
{
public:
	voidVal();
	std::string valToString();
};

#endif
