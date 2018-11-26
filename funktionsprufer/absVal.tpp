#include <typeinfo>

template <class T>
absVal<T>::absVal(T newVal, std::string newName)
{
	isVoidVal = false;
	isCrashVal = false;
	val = newVal;
	name = newName;
}

template <class T>
template <class P>
bool absVal<T>::equalsAnyType(P cmpVal)
{
	if (isCrashVal || cmpVal->getIsCrashVal())
	{
		return isCrashVal == cmpVal->getIsCrashVal();
	}
	if (typeid(val) == typeid(cmpVal->getVal()))
	{
		return equalsSameType(cmpVal);
	}
	else
	{
		return false;
	}
}

template <class T>
bool absVal<T>::equalsSameType(spAbsVal<T> cmpVal)
{
	return val == cmpVal->getVal();
}

template <class T>
T absVal<T>::getVal()
{
	return val;
}

template <class T>
std::string absVal<T>::getName()
{
	return name;
}

template <class T>
bool absVal<T>::getIsVoidVal()
{
	return isVoidVal;
}

template <class T>
bool absVal<T>::getIsCrashVal()
{
	return isCrashVal;
}

template <class T>
void absVal<T>::setVal(T newVal)
{
	val = newVal;
}

template <class T>
void absVal<T>::setName(std::string newName)
{
	name = newName;
}

template <class T>
void absVal<T>::setIsVoidVal(bool newVal)
{
	isVoidVal = newVal;
}

template <class T>
void absVal<T>::setIsCrashVal(bool newVal)
{
	isCrashVal = newVal;
}

template <class T>
std::string absVal<T>::valToStringOrCrash()
{
	if (isCrashVal)
	{
		return "CRASH";
	}
	else
	{
		return valToString();
	}
}
