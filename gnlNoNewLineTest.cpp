#include <functional>

#include "libft.h"
#include "gnlNoNewLineTest.hpp"

gnlNoNewLineTest::gnlNoNewLineTest()
{
	funToTestExist = true;
}

int gnlNoNewLineTest::launchTest(int newBufSizeToUse)
{
	gnlNoNewLineTest test;

	test.bufSizeToUse = newBufSizeToUse;
	test.startTest(" -------- Test : nonewline, BUFF_SIZE : " + std::to_string(test.bufSizeToUse) + ".", false);

	return test.errCount;
}

void gnlNoNewLineTest::processTest()
{
	setGnlToRightBufSize();
	{
		char fileName[] = "nonewline-01-test.txt";
		fdNumToUse = 201;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 5; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
	{
		char fileName[] = "nonewline-02-test.txt";
		fdNumToUse = 202;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 3; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
	{
		char fileName[] = "nonewline-03-test.txt";
		fdNumToUse = 203;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 3; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
	{
		char fileName[] = "nonewline-04-test.txt";
		fdNumToUse = 204;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 3; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
	{
		char fileName[] = "nonewline-05-test.txt";
		fdNumToUse = 205;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 3; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
	{
		char fileName[] = "nonewline-06-test.txt";
		fdNumToUse = 206;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 3; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
}
