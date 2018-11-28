#ifndef GNLBINARYTEST_HPP
#define GNLBINARYTEST_HPP

#include "gnlTest.hpp"

class gnlBinaryTest : public gnlTest
{
public:
	gnlBinaryTest();
	static int launchTest(int newBufSizeToUse);
protected:
	void processTest();
};

#endif
