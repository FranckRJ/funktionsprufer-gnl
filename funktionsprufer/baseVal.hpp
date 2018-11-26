#ifndef BASEVAL_HPP
#define BASEVAL_HPP

#include <string>
#include <memory>

#include "absVal.hpp"

template <class T>
class baseVal;

template <class T>
using spBaseVal = std::shared_ptr<baseVal<T>>;

template <class T, class... Args>
spBaseVal<T> mkSpBaseVal(Args... args)
{
	return std::make_shared<baseVal<T>>(std::forward<Args>(args)...);
}

template <class T>
class baseVal : public absVal<T>
{
public:
	baseVal(T newVal = 0, std::string newName = "");
	std::string valToString();
};

#include "baseVal.tpp"

#endif
