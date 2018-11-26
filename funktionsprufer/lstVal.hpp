#ifndef LSTVAL_HPP
#define LSTVAL_HPP

#include <string>

#include "absVal.hpp"
#include "voidVal.hpp"
#include "libft.h"

#define TYPE_LST_EXIST

class lstVal;

using spLstVal = std::shared_ptr<lstVal>;

template <class... Args>
spLstVal mkSpLstVal(Args... args)
{
	return std::make_shared<lstVal>(std::forward<Args>(args)...);
}

#ifdef TYPE_LST_EXIST
class lstVal : public absVal<t_list*>
{
public:
	lstVal(t_list *newVal = nullptr, std::string newName = "", bool newNeedToFree = false);
	~lstVal();
	bool equalsSameType(spAbsVal<t_list*> cmpVal);
	void setVal(t_list *newVal);
	void setValWithoutFree(t_list *newVal);
	std::string valToString();
private:
	bool lstElemEqualAnother(t_list *e1, t_list *e2);
	void deleteLst();
private:
	bool needToFree;
};
#else
class lstVal : public voidVal {};
#endif

#endif
