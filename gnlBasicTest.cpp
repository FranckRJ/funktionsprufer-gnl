#include <functional>

#include "libft.h"
#include "gnlBasicTest.hpp"

gnlBasicTest::gnlBasicTest()
{
	funToTestExist = true;
}

int gnlBasicTest::launchTest(int newBufSizeToUse)
{
	gnlBasicTest test;

	test.bufSizeToUse = newBufSizeToUse;
	test.startTest(" -------- Test : basic, BUFF_SIZE : " + std::to_string(test.bufSizeToUse) + ".", false);

	return test.errCount;
}

void gnlBasicTest::processTest()
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
