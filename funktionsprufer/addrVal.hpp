#ifndef ADDRVAL_HPP
#define ADDRVAL_HPP

#include <string>
#include <memory>

#include "absVal.hpp"

class addrVal;

using spAddrVal = std::shared_ptr<addrVal>;

template <class... Args>
spAddrVal mkSpAddrVal(Args... args)
{
	return std::make_shared<addrVal>(std::forward<Args>(args)...);
}

class addrVal : public absVal<void*>
{
public:
	addrVal(void *newVal = nullptr, void *newBaseVal = nullptr, std::string newName = "", bool newNeedToFree = false);
	~addrVal();
	bool equalsSameType(spAbsVal<void*> cmpVal);
	void setVal(void *newVal);
	std::string valToString();
private:
	bool needToFree;
	void *baseVal;
};

#endif
