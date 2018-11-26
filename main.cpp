#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <functional>

#include "funktionsprufer/colors.hpp"
#include "gnlTest.hpp"

static std::string HELP_INFOS =
R"str(DESCRIPTION:
Execute les tests de gnl.

LISTE DES COMMANDES:
--erronly                 Affiche uniquement les tests echoues.
--nocrashtest             N'effectue pas les tests qui doivent crasher.
--nouncleartest           N'effectue pas les tests dont le resultat n'est pas clair.
--nocolor                 Desactive l'affichage avec des couleurs.
--help                    Affiche cette page d'aide.)str";

int main(int argc, char **argv)
{
	int realArgc = argc - 1;
	int errCount = 0;
	std::string curArg;

	std::cout << std::unitbuf;

	for (int i = 1; i < argc; ++i)
	{
		curArg = argv[i];
		if(curArg[0] == '-')
		{
			--realArgc;
			if (curArg == "--erronly")
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

	absTest::isVerbose = true;
	errCount = gnlTest::launchTest();

	std::cout << colors::bold();
	if (errCount == 0)
	{
		std::cout << colors::green();
	}
	else
	{
		std::cout << colors::red();
	}
	std::cout << "Erreurs : " << errCount << "." << colors::reset() << std::endl;

	return 0;
}
