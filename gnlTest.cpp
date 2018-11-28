#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "gnl/get_next_line.h"
#include "gnlTest.hpp"

gnlTest::gnlTest()
{
	funToTestExist = true;

	baseFilePos = 0;
	testFilePos = 0;
	fdNumToUse = -1;
	baseLine = mkSpStrVal(nullptr, "*line", true);
	testLine = mkSpStrVal(nullptr, "*line", true);
	baseFunction =
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
	testFunction =
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
	testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spStrVal, spStrVal>(baseLine, testLine));};

	gnl1 = [](const int fd, char **line) {return get_next_line_1(fd, line);};
	gnl2 = [](const int fd, char **line) {return get_next_line_2(fd, line);};
	gnl10 = [](const int fd, char **line) {return get_next_line_10(fd, line);};
	gnl32 = [](const int fd, char **line) {return get_next_line_32(fd, line);};
	gnl100 = [](const int fd, char **line) {return get_next_line_100(fd, line);};
	gnl9999 = [](const int fd, char **line) {return get_next_line_9999(fd, line);};
	gnl10000000 = [](const int fd, char **line) {return get_next_line_10000000(fd, line);};
}

void gnlTest::setGnlToRightBufSize()
{
	switch (bufSizeToUse)
	{
		case 1:
		{
			getNextLine = gnl1;
			break;
		}
		case 2:
		{
			getNextLine = gnl2;
			break;
		}
		case 10:
		{
			getNextLine = gnl10;
			break;
		}
		case 32:
		{
			getNextLine = gnl32;
			break;
		}
		case 100:
		{
			getNextLine = gnl100;
			break;
		}
		case 9999:
		{
			getNextLine = gnl9999;
			break;
		}
		case 10000000:
		{
			getNextLine = gnl10000000;
			break;
		}
	}
}
