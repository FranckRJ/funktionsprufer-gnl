#ifndef MEMVAL_HPP
#define MEMVAL_HPP

#include <string>
#include <memory>

#include "absVal.hpp"

class memVal;

using spMemVal = std::shared_ptr<memVal>;

template <class... Args>
spMemVal mkSpMemVal(Args... args)
{
	return std::make_shared<memVal>(std::forward<Args>(args)...);
}

class memVal : public absVal<void*>
{
public:
	memVal(void *newVal = nullptr, size_t newLen = 0, std::string newName = "", bool newNeedToFree = false);
	~memVal();
	bool equalsSameType(spAbsVal<void*> cmpVal);
	size_t getLen();
	void setVal(void *newVal);
	void setLen(size_t newLen);
	void setValAndLen(void *newVal, size_t newLen);
	std::string valToString();
private:
	bool needToFree;
	size_t len;
};

#endif
