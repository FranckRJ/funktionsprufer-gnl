#ifndef STRTABVAL_HPP
#define STRTABVAL_HPP

#include <string>
#include <memory>

#include "absVal.hpp"

class strTabVal;

using spStrTabVal = std::shared_ptr<strTabVal>;

template <class... Args>
spStrTabVal mkSpStrTabVal(Args... args)
{
	return std::make_shared<strTabVal>(std::forward<Args>(args)...);
}

class strTabVal : public absVal<char**>
{
public:
	strTabVal(char **newVal = nullptr, int newTabSize = -1, std::string newName = "", bool newNeedToFree = false);
	~strTabVal();
	bool equalsSameType(spAbsVal<char**> cmpVal);
	void setVal(char **newVal);
	std::string valToString();
private:
	void deleteCurrentTab();
	int getCurrentSize();
private:
	int tabSize;
	bool needToFree;
};

#endif
