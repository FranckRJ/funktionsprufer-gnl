#include <functional>

#include "libft.h"
#include "gnlAdvancedTest.hpp"

gnlAdvancedTest::gnlAdvancedTest()
{
	funToTestExist = true;
}

int gnlAdvancedTest::launchTest(int newBufSizeToUse)
{
	gnlAdvancedTest test;

	test.bufSizeToUse = newBufSizeToUse;
	test.startTest(" -------- Test : advanced, BUFF_SIZE : " + std::to_string(test.bufSizeToUse) + ".", false);

	return test.errCount;
}

void gnlAdvancedTest::processTest()
{
	setGnlToRightBufSize();
	{
		fdNumToUse = 500;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		baseLine->setIsVoidVal(true);
		baseLine->setName("line");
		testLine->setVal(nullptr);
		testLine->setIsVoidVal(true);
		testLine->setName("line");
		testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal("", "fd"), baseLine);
		baseLine->setIsVoidVal(false);
		baseLine->setName("*line");
		testLine->setIsVoidVal(false);
		testLine->setName("*line");
	}
	{
		fdNumToUse = 501;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal("", "fd"), baseLine);
	}
	{
		char fileName[] = "/dev/random";
		fdNumToUse = 502;
		baseFilePos = 0;
		testFilePos = 0;
		for (int i = 0; i < 3; ++i)
		{
			baseLine->setVal(nullptr);
			testLine->setVal(nullptr);
			testThisFun(baseFunction, testFunction, mkSpCstStrVal(fileName, "fd"), baseLine);
		}
	}
	{
		char fileName[] = "/dev/null";
		fdNumToUse = 503;
		baseFilePos = 0;
		testFilePos = 0;
		for (int i = 0; i < 3; ++i)
		{
			baseLine->setVal(nullptr);
			testLine->setVal(nullptr);
			testThisFun(baseFunction, testFunction, mkSpCstStrVal(fileName, "fd"), baseLine);
		}
	}
}
