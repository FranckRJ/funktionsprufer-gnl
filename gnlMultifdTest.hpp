#ifndef GNLMULTIFDTEST_HPP
#define GNLMULTIFDTEST_HPP

#include "gnlTest.hpp"

class gnlMultifdTest : public gnlTest
{
public:
	gnlMultifdTest();
	static int launchTest(int newBufSizeToUse);
protected:
	void processTest();
};

#endif
