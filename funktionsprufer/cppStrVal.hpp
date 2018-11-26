#ifndef CPPSTRVAL_HPP
#define CPPSTRVAL_HPP

#include <string>
#include <memory>

#include "absVal.hpp"

class cppStrVal;

using spCppStrVal = std::shared_ptr<cppStrVal>;

template <class... Args>
spCppStrVal mkSpCppStrVal(Args... args)
{
	return std::make_shared<cppStrVal>(std::forward<Args>(args)...);
}

class cppStrVal : public absVal<std::string>
{
public:
	cppStrVal(std::string newVal = "", std::string newName = "");
	bool equalsSameType(spAbsVal<std::string> cmpVal);
	std::string valToString();
};

#endif
