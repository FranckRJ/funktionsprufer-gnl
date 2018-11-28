#include <iostream>

#include "colors.hpp"
#include "absTest.hpp"

bool absTest::isVerbose = false;
bool absTest::showOnlyErrors = false;
bool absTest::dontDoTestThatCrash = false;
bool absTest::dontDoUnclearTest = false;

void absTest::startTest(std::string funName, bool alignNames)
{
	msgTestBegin(funName, alignNames);
	processTest();
	msgTestEnd();

	if (!funToTestExist)
	{
		errCount = -1;
	}
}

void absTest::msgTestBegin(std::string funName, bool alignNames)
{
	if (alignNames)
	{
		int nbOfSpaces = 75 - funName.size();
		std::cout << " " << std::string((nbOfSpaces / 2) + (nbOfSpaces % 2), '-') << " ";
		std::cout << funName;
		std::cout << " " << std::string(nbOfSpaces / 2, '-') << std::endl;
	}
	else
	{
		std::cout << funName << std::endl;
	}
}

void absTest::msgTestEnd()
{
	if (!funToTestExist)
	{
		std::cout << "La fonction a tester n'existe pas." << std::endl;
	}
	else if (!isVerbose)
	{
		std::cout << "Tests passes : " << testCount - errCount << "/" << testCount;
		if (errCount > 0)
		{
			std::cout << colors::bold() + colors::red() << " <----------------- ERREUR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << colors::reset();
		}
		std::cout << std::endl;
	}
	else if (isVerbose && showOnlyErrors && errCount == 0)
	{
		std::cout << "Pas d'erreurs." << std::endl;
	}
	std::cout << std::endl;
}
