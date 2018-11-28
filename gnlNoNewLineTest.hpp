#ifndef GNLNONEWLINETEST_HPP
#define GNLNONEWLINETEST_HPP

#include "gnlTest.hpp"

class gnlNoNewLineTest : public gnlTest
{
public:
	gnlNoNewLineTest();
	static int launchTest(int newBufSizeToUse);
protected:
	void processTest();
};

#endif
