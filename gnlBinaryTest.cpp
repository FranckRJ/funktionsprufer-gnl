#include <functional>

#include "libft.h"
#include "funktionsprufer/memVal.hpp"
#include "gnlBinaryTest.hpp"

gnlBinaryTest::gnlBinaryTest()
{
	funToTestExist = true;
}

int gnlBinaryTest::launchTest(int newBufSizeToUse)
{
	gnlBinaryTest test;

	test.bufSizeToUse = newBufSizeToUse;
	test.startTest(" -------- Test : binary, BUFF_SIZE : " + std::to_string(test.bufSizeToUse) + ".", false);

	return test.errCount;
}

void gnlBinaryTest::processTest()
{
	auto testValsBinaryFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spMemVal, spMemVal>(
					mkSpMemVal(baseLine->getVal(), 10, "*line"),
					mkSpMemVal(testLine->getVal(), 10, "*line")));};

	setGnlToRightBufSize();
	{
		char fileName[] = "binary-01-test.txt";
		fdNumToUse = 301;
		baseFilePos = 0;
		testFilePos = 0;
		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (int i = 0; i < 3; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsBinaryFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
}
