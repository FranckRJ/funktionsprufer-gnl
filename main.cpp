#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <functional>

#include "funktionsprufer/colors.hpp"
#include "gnlBasicTest.hpp"

static std::string HELP_INFOS =
R"str(DESCRIPTION:
Execute les tests de gnl.

LISTE DES COMMANDES:
<nom_du_test>[-n]         Affiche le detail de ce test (mode verbeux).
                          Plusieurs tests peuvent etres appeles, seuls les tests appeles
                          seront testes.
                          Si -n est precise (ex : "basic-32") seul le test avec le buffer
                          de taille n sera appele.
-r<nom_du_test>[-n]       Desactive ce test en mode non-verbeux.
                          Si -n est precise (ex : "basic-32") seul le test avec le buffer
                          de taille n est desactive.
--erronly                 Affiche uniquement les tests echoues lors du mode verbeux.
--nocrashtest             N'effectue pas les tests qui doivent crasher.
--nouncleartest           N'effectue pas les tests dont le resultat n'est pas clair.
--nocolor                 Desactive l'affichage avec des couleurs.
--help                    Affiche cette page d'aide.)str";

int main(int argc, char **argv)
{
	int realArgc = argc - 1;
	int errCount = 0;
	int nbOfTestsWithError = 0;
	std::map<std::string, std::function<int()>> testList;
	std::list<std::string> removedTests;
	std::string curArg;

	std::cout << std::unitbuf;
	testList.emplace("basic-1", std::bind(gnlBasicTest::launchTest, 1));
	testList.emplace("basic-2", std::bind(gnlBasicTest::launchTest, 2));
	testList.emplace("basic-10", std::bind(gnlBasicTest::launchTest, 10));
	testList.emplace("basic-32", std::bind(gnlBasicTest::launchTest, 32));
	testList.emplace("basic-100", std::bind(gnlBasicTest::launchTest, 100));
	testList.emplace("basic-9999", std::bind(gnlBasicTest::launchTest, 9999));
	testList.emplace("basic-10000000", std::bind(gnlBasicTest::launchTest, 10000000));

	for (int i = 1; i < argc; ++i)
	{
		curArg = argv[i];
		if(curArg[0] == '-')
		{
			--realArgc;
			if (curArg.substr(0, 2) == "-r")
			{
				std::string funToRemove = curArg.substr(2);
				if (funToRemove.find('-') == std::string::npos)
				{
					removedTests.push_back(funToRemove + "-1");
					removedTests.push_back(funToRemove + "-2");
					removedTests.push_back(funToRemove + "-10");
					removedTests.push_back(funToRemove + "-32");
					removedTests.push_back(funToRemove + "-100");
					removedTests.push_back(funToRemove + "-9999");
					removedTests.push_back(funToRemove + "-10000000");
				}
				else
				{
					removedTests.push_back(funToRemove);
				}
			}
			else if (curArg == "--erronly")
			{
				absTest::showOnlyErrors = true;
			}
			else if (curArg == "--nocrashtest")
			{
				absTest::dontDoTestThatCrash = true;
			}
			else if (curArg == "--nouncleartest")
			{
				absTest::dontDoUnclearTest = true;
			}
			else if (curArg == "--nocolor")
			{
				colors::showColors = false;
			}
			else//if (curArg == "--help")
			{
				std::cout << HELP_INFOS << std::endl;
				return 0;
			}
		}
	}

	std::cout << " ---------------- get_next_line(const int fd, char **line) ----------------" << std::endl;

	if (realArgc < 1)
	{
		absTest::isVerbose = false;
		for (const std::pair<std::string, std::function<int()>>& thisFunc : testList)
		{
			if (std::find(removedTests.begin(), removedTests.end(), thisFunc.first) == removedTests.end())
			{
				int tmpResult = thisFunc.second();

				if (tmpResult > 0)
				{
					errCount += tmpResult;
					++nbOfTestsWithError;
				}
			}
		}
	}
	else
	{
		absTest::isVerbose = true;
		for (int i = 1; i < argc; ++i)
		{
			if (argv[i][0] != '-')
			{
				bool oneTestHasBeDone = false;
				std::string strToFind = argv[i];
				std::list<std::string> listOfFunToTests;

				if (strToFind.find('-') == std::string::npos)
				{
					listOfFunToTests.push_back(strToFind + "-1");
					listOfFunToTests.push_back(strToFind + "-2");
					listOfFunToTests.push_back(strToFind + "-10");
					listOfFunToTests.push_back(strToFind + "-32");
					listOfFunToTests.push_back(strToFind + "-100");
					listOfFunToTests.push_back(strToFind + "-9999");
					listOfFunToTests.push_back(strToFind + "-10000000");
				}
				else
				{
					listOfFunToTests.push_back(strToFind);
				}

				for (const std::string& thisStr : listOfFunToTests)
				{
					std::map<std::string, std::function<int()>>::iterator it = testList.find(thisStr);

					if (it != testList.end())
					{
						int tmpResult = it->second();
						oneTestHasBeDone = true;

						if (tmpResult > 0)
						{
							errCount += tmpResult;
							++nbOfTestsWithError;
						}
					}
				}

				if (!oneTestHasBeDone)
				{
					std::cout << "Erreur : pas de tests nomme " << strToFind << "." << std::endl << std::endl;
				}
			}
		}
	}

	std::cout << colors::bold();
	if (errCount == 0)
	{
		std::cout << colors::green();
		std::cout << "Erreurs : 0.";
	}
	else
	{
		std::cout << colors::red();
		std::cout << "Erreurs : " << errCount << ". Tests concernees : " << nbOfTestsWithError << ".";
	}
	std::cout << colors::reset() << std::endl;

	return 0;
}
