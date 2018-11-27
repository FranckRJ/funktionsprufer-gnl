#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "gnl/get_next_line.h"
#include "funktionsprufer/baseVal.hpp"
#include "funktionsprufer/strVal.hpp"
#include "funktionsprufer/cstStrVal.hpp"
#include "gnlTest.hpp"

gnlTest::gnlTest()
{
	funToTestExist = true;
}

int gnlTest::launchTest()
{
	gnlTest test;

	test.startTest("get_next_line(const int fd, char **line)");

	return test.errCount;
}

void gnlTest::processTest()
{
	long int baseFilePos = 0;
	off_t testFilePos = 0;
	int fdNumToUse = -1;
	spStrVal baseLine = mkSpStrVal(nullptr, "*line", true);
	spStrVal testLine = mkSpStrVal(nullptr, "*line", true);
	std::function<int(const int, char**)> getNextLine;
	std::function<spBaseVal<int>(spCstStrVal, spStrVal)> baseFunction =
		[&](spCstStrVal fn, spStrVal line)
		{
			(void)line;
			if (baseLine->getIsVoidVal())
			{
				return mkSpBaseVal<int>(-1);
			}
			else
			{
				int getLineRet = -1;
				FILE *fileToUse = fopen(fn->getVal(), "r");
				if (fileToUse != nullptr)
				{
					char *newLine = nullptr;
					size_t lineLen = 0;
					fseek(fileToUse, baseFilePos, SEEK_SET);
					getLineRet = getline(&newLine, &lineLen, fileToUse);
					if (getLineRet == -1)
					{
						if (feof(fileToUse) != 0)
						{
							getLineRet = 0;
						}
					}
					baseFilePos = ftell(fileToUse);
					fclose(fileToUse);
					if (getLineRet > 0)
					{
						if (newLine[getLineRet - 1] == '\n')
						{
							newLine[getLineRet - 1] = '\0';
						}
						baseLine->setVal(newLine);
					}
				}
				return mkSpBaseVal<int>(getLineRet > 0 ? 1 : getLineRet);
			}
		};
	std::function<spBaseVal<int>(spCstStrVal, spStrVal)> testFunction =
		[&](spCstStrVal fn, spStrVal line)
		{
			(void)line;
			if (testLine->getIsVoidVal())
			{
				int dummyFd = open(fn->getVal(), O_RDONLY);
				int fdToUse = dup2(dummyFd, 101);
				lseek(fdToUse, testFilePos, SEEK_SET);
				int gnlRet = getNextLine(fdToUse, nullptr);
				testFilePos = lseek(fdToUse, 0, SEEK_CUR);
				close(fdToUse);
				close(dummyFd);
				return mkSpBaseVal<int>(gnlRet);
			}
			else
			{
				int dummyFd = open(fn->getVal(), O_RDONLY);
				int fdToUse = dup2(dummyFd, 100 + fdNumToUse);
				lseek(fdToUse, testFilePos, SEEK_SET);
				char *newLine = testLine->getVal();
				int gnlRet = getNextLine(fdToUse, &newLine);
				testLine->setVal(newLine);
				testFilePos = lseek(fdToUse, 0, SEEK_CUR);
				close(fdToUse);
				close(dummyFd);
				return mkSpBaseVal<int>(gnlRet);
			}
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spStrVal, spStrVal>(baseLine, testLine));};

	auto gnl1 = [](const int fd, char **line) {return get_next_line_1(fd, line);};
	auto gnl2 = [](const int fd, char **line) {return get_next_line_2(fd, line);};
	auto gnl10 = [](const int fd, char **line) {return get_next_line_10(fd, line);};
	auto gnl32 = [](const int fd, char **line) {return get_next_line_32(fd, line);};
	auto gnl100 = [](const int fd, char **line) {return get_next_line_100(fd, line);};
	auto gnl9999 = [](const int fd, char **line) {return get_next_line_9999(fd, line);};
	auto gnl10000000 = [](const int fd, char **line) {return get_next_line_10000000(fd, line);};

	{
		getNextLine = gnl1;
		testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal("NULL", "fd"), baseLine);
	}
	{
		char fileName[] = "01-test.txt";
		fdNumToUse = 1;
		getNextLine = gnl1;
		for (int i = 0; i < 10; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
		fdNumToUse = 2;
		baseFilePos = 0;
		testFilePos = 0;
		getNextLine = gnl2;
		for (int i = 0; i < 10; ++i)
			testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpCstStrVal(fileName, "fd"), baseLine);
	}
}
