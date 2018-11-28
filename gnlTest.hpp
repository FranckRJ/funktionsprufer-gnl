#ifndef GNLTEST_HPP
#define GNLTEST_HPP

#include "funktionsprufer/absTest.hpp"
#include "funktionsprufer/baseVal.hpp"
#include "funktionsprufer/strVal.hpp"
#include "funktionsprufer/cstStrVal.hpp"

class gnlTest : public absTest
{
public:
	gnlTest();
protected:
	void setGnlToRightBufSize();
protected:
	int bufSizeToUse;
	long int baseFilePos;
	off_t testFilePos;
	int fdNumToUse;
	spStrVal baseLine;
	spStrVal testLine;
	std::function<int(const int, char**)> getNextLine;
	std::function<spBaseVal<int>(spCstStrVal, spStrVal)> baseFunction;
	std::function<spBaseVal<int>(spCstStrVal, spStrVal)> testFunction;
	std::function<bool(bool)> testValsFun;
	std::function<int(const int, char**)> gnl1;
	std::function<int(const int, char**)> gnl2;
	std::function<int(const int, char**)> gnl10;
	std::function<int(const int, char**)> gnl32;
	std::function<int(const int, char**)> gnl100;
	std::function<int(const int, char**)> gnl9999;
	std::function<int(const int, char**)> gnl10000000;
};

#endif
