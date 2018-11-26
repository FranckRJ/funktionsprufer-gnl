#ifndef ABSVAL_HPP
#define ABSVAL_HPP

#include <string>
#include <memory>

template <class T>
class absVal;

template <class T>
using spAbsVal = std::shared_ptr<absVal<T>>;

template <class T>
class absVal
{
public:
	absVal(T newVal, std::string newName = "");
	virtual ~absVal() = default;
	template <class P>
	bool equalsAnyType(P cmpVal);
	virtual bool equalsSameType(spAbsVal<T> cmpVal);
	virtual T getVal();
	virtual std::string getName();
	bool getIsVoidVal();
	bool getIsCrashVal();
	virtual void setVal(T newVal);
	void setName(std::string newName);
	void setIsVoidVal(bool newVal);
	void setIsCrashVal(bool newVal);
	std::string valToStringOrCrash();
	virtual std::string valToString() = 0;
private:
	T val;
	std::string name;
	bool isVoidVal;
	bool isCrashVal;
};

#include "absVal.tpp"

#endif
