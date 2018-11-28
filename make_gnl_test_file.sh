read -r -d '' VAR << EOM
#ifndef $(echo "$1"|awk '{print toupper($0)}')TEST_HPP
#define $(echo "$1"|awk '{print toupper($0)}')TEST_HPP

#include "gnlTest.hpp"

class ${1}Test : public gnlTest
{
public:
	${1}Test();
	static int launchTest(int newBufSizeToUse);
protected:
	void processTest();
};

#endif
EOM

read -r -d '' WAR << EOM
#include <functional>

#include "libft.h"
#include "${1}Test.hpp"

${1}Test::${1}Test()
{
	funToTestExist = true;
}

int ${1}Test::launchTest()
{
	gnlBasicTest test;

	test.bufSizeToUse = newBufSizeToUse;
	test.startTest(" -------- Test : _PLACEHOLDER_, BUFF_SIZE : " + std::to_string(test.bufSizeToUse) + ".", false);

	return test.errCount;
}

void ${1}Test::processTest()
{
	setGnlToRightBufSize();
	{
		fdNumToUse = 0;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal("NULL", "fd"), baseLine);
	}
	{
		char fileName[] = "01-test.txt";
		fdNumToUse = 1;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 10; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
}
EOM

echo "$VAR" > ${1}Test.hpp
echo "$WAR" > ${1}Test.cpp
