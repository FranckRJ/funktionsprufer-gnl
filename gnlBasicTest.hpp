#ifndef GNLBASICTEST_HPP
#define GNLBASICTEST_HPP

#include "gnlTest.hpp"

class gnlBasicTest : public gnlTest
{
public:
	gnlBasicTest();
	static int launchTest(int newBufSizeToUse);
protected:
	void processTest();
};

#endif
