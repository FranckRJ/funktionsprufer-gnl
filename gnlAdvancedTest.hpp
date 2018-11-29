#ifndef GNLADVANCEDTEST_HPP
#define GNLADVANCEDTEST_HPP

#include "gnlTest.hpp"

class gnlAdvancedTest : public gnlTest
{
public:
	gnlAdvancedTest();
	static int launchTest(int newBufSizeToUse);
protected:
	void processTest();
};

#endif
