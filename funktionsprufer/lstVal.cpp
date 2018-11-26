#include <string>

#include "lstVal.hpp"

#ifdef TYPE_LST_EXIST
lstVal::lstVal(t_list *newVal, std::string newName, bool newNeedToFree) : absVal(newVal, newName)
{
	needToFree = newNeedToFree;
}

lstVal::~lstVal()
{
	if (needToFree)
	{
		deleteLst();
	}
}

bool lstVal::equalsSameType(spAbsVal<t_list*> cmpVal)
{
	lstVal *ptrCmpVal = dynamic_cast<lstVal*>(cmpVal.get());

	if (ptrCmpVal != nullptr && getIsVoidVal() == ptrCmpVal->getIsVoidVal())
	{
		t_list *lst = getVal();
		t_list *lstCmp = ptrCmpVal->getVal();

		while (lst != nullptr && lstCmp != nullptr)
		{
			if (!lstElemEqualAnother(lst, lstCmp))
			{
				return false;
			}
			lst = lst->next;
			lstCmp = lstCmp->next;
		}
		return (lst == lstCmp);
	}
	return false;
}

void lstVal::setVal(t_list *newVal)
{
	if (needToFree)
	{
		deleteLst();
	}
	absVal::setVal(newVal);
}

void lstVal::setValWithoutFree(t_list *newVal)
{
	absVal::setVal(newVal);
}

std::string lstVal::valToString()
{
	if (getIsVoidVal())
	{
		return "NULL";
	}
	else
	{
		std::string newStr;
		t_list *lst = getVal();

		newStr += "[";
		while (lst != nullptr)
		{
			if (lst->content == nullptr)
			{
				newStr += "NULL";
			}
			else
			{
				newStr += "\"" + std::string(((const char*)lst->content)) + "\"";
			}
			if (lst->next != nullptr)
			{
				newStr += ", ";
			}
			lst = lst->next;
		}
		newStr += "]";
		return newStr;
	}
}

bool lstVal::lstElemEqualAnother(t_list *e1, t_list *e2)
{
	if (e1->content_size != e2->content_size)
	{
		return false;
	}
	if (e1->content == nullptr || e2->content == nullptr)
	{
		return (e1->content == e2->content);
	}
	return (std::string((const char *)e1->content) == std::string((const char *)e2->content));
}

void lstVal::deleteLst()
{
	t_list *lst = getVal();

	while (lst != nullptr)
	{
		t_list *old_lst = lst;
		lst = lst->next;
		delete[] static_cast<const char*>(old_lst->content);
		delete old_lst;
	}
}
#endif
