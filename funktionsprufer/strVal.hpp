#ifndef STRVAL_HPP
#define STRVAL_HPP

#include <string>
#include <memory>

#include "absVal.hpp"

class strVal;

using spStrVal = std::shared_ptr<strVal>;

template <class... Args>
spStrVal mkSpStrVal(Args... args)
{
	return std::make_shared<strVal>(std::forward<Args>(args)...);
}

class strVal : public absVal<char*>
{
public:
	strVal(char *newVal = nullptr, std::string newName = "", bool newNeedToFree = false);
	~strVal();
	bool equalsSameType(spAbsVal<char*> cmpVal);
	void setVal(char *newVal);
	std::string valToString();
private:
	bool needToFree;
};

#endif
