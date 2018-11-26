#ifndef GNLTEST_HPP
#define GNLTEST_HPP

#include "funktionsprufer/absTest.hpp"

class gnlTest : absTest
{
public:
	gnlTest();
	static int launchTest();
protected:
	void processTest();
};

#endif
