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
		char fileName[] = "basic-01-test.txt";
		fdNumToUse = 101;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 18; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
	{
		char fileName[] = "basic-02-test.txt";
		fdNumToUse = 102;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 5; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
	{
		char fileName[] = "basic-03-test.txt";
		fdNumToUse = 103;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 6; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
}
