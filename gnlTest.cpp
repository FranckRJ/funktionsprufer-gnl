#include <functional>

#include "gnl/get_next_line.h"
#include "funktionsprufer/baseVal.hpp"
#include "funktionsprufer/strVal.hpp"
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
	spStrVal baseLine = mkSpStrVal(nullptr, "line", true);
	spStrVal testLine = mkSpStrVal(nullptr, "line", true);
	std::function<spBaseVal<int>(spBaseVal<int>, spStrVal)> baseFunction =
		[&](spBaseVal<int> fd, spStrVal line)
		{
			(void)line;
			if (baseLine->getIsVoidVal())
			{
				return mkSpBaseVal<int>(-1);
			}
			else
			{
				(void)fd;
				/*char *newLine = line->getVal();
				int gnlRet = get_next_line(fd->getVal(), nullptr);
				line->setVal(newLine);*/
				return mkSpBaseVal<int>(1);
			}
		};
	std::function<spBaseVal<int>(spBaseVal<int>, spStrVal)> testFunction =
		[&](spBaseVal<int> fd, spStrVal line)
		{
			(void)line;
			if (testLine->getIsVoidVal())
			{
				return mkSpBaseVal<int>(get_next_line(fd->getVal(), nullptr));
			}
			else
			{
				char *newLine = testLine->getVal();
				int gnlRet = get_next_line(fd->getVal(), nullptr);
				testLine->setVal(newLine);
				return mkSpBaseVal<int>(gnlRet);
			}
		};
	auto testValsFun =
		[&](bool printRes) {return compareVals(printRes, std::pair<spStrVal, spStrVal>(baseLine, testLine));};

	{
		testThisFunAndVals(baseFunction, testFunction, testValsFun, mkSpBaseVal<int>(-1, "fd"), baseLine);
	}
}
