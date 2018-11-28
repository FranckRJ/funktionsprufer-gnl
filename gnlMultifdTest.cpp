#include <functional>

#include "libft.h"
#include "gnlMultifdTest.hpp"

gnlMultifdTest::gnlMultifdTest()
{
	funToTestExist = true;
}

int gnlMultifdTest::launchTest(int newBufSizeToUse)
{
	gnlMultifdTest test;

	test.bufSizeToUse = newBufSizeToUse;
	test.startTest(" -------- Test : multifd, BUFF_SIZE : " + std::to_string(test.bufSizeToUse) + ".", false);

	return test.errCount;
}

void gnlMultifdTest::processTest()
{
	setGnlToRightBufSize();
	{
		char fileNameTab[5][20] = { "multifd-01-test.txt", "multifd-02-test.txt", "multifd-03-test.txt", "multifd-04-test.txt", "multifd-05-test.txt"};
		int fdNumToUseTab[] = { 401, 402, 403, 404, 405 };
		int baseFilePosTab[] = { 0, 0, 0, 0, 0 };
		int testFilePosTab[] = { 0, 0, 0, 0, 0 };
		int readFilesOrder[] = { 0, 1, 3, 2, 1, 3, 0, 0, 0, 3, 2, 4, 3, 2, 1, 0, 0, 3, 2, 0, 1, 4, 2, 3, 1, 0, 2, 4, 4, 3 };

		baseLine->setVal(nullptr);
		testLine->setVal(nullptr);
		for (size_t i = 0; i < (sizeof(readFilesOrder) / sizeof(int)); ++i)
		{
			fdNumToUse = fdNumToUseTab[readFilesOrder[i]];
			baseFilePos = baseFilePosTab[readFilesOrder[i]];
			testFilePos = testFilePosTab[readFilesOrder[i]];
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileNameTab[readFilesOrder[i]], "fd"), baseLine);
			baseFilePosTab[readFilesOrder[i]] = baseFilePos;
			testFilePosTab[readFilesOrder[i]] = testFilePos;
		}
	}
}
