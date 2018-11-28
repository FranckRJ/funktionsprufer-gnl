#ifndef ABSTEST_HPP
#define ABSTEST_HPP

#include <string>
#include <functional>

class absTest
{
public:
	static bool isVerbose;
	static bool showOnlyErrors;
	static bool dontDoTestThatCrash;
	static bool dontDoUnclearTest;
	virtual ~absTest() = default;
protected:
	void startTest(std::string funName, bool alignNames = true);
	virtual void processTest() = 0;
	template <class Tret, class... Tpar>
	void crashTestTheseFun(std::function<Tret(Tpar...)> baseFunToTest,
						   std::function<Tret(Tpar...)> testFunToTest,
						   Tret *baseRetToSet,
						   Tret *testRetToSet,
						   Tpar... params);
	template <class Tret, class... Tpar>
	void testThisFun(std::function<Tret(Tpar...)> baseFun,
					 std::function<Tret(Tpar...)> testFun,
					 Tpar... params);
	template <class Tret, class... Tpar>
	void testThisFunAndVals(std::function<Tret(Tpar...)> baseFun,
							std::function<Tret(Tpar...)> testFun,
							std::function<bool(bool)> valsToTest,
							Tpar... params);
	template <class Tfstval, class... Tothval>
	bool compareVals(bool printRes, Tfstval fstVal, Tothval... othVals);
	template <class Tfstval>
	bool compareVals(bool printRes, Tfstval val);
private:
	template <class Tptr>
	std::shared_ptr<Tptr> buildPtrValOfPtr(std::shared_ptr<Tptr> thisPtr);
	template <class Tfstpar>
	std::string paramsToString(Tfstpar param);
	template <class Tfstpar, class... Tothpar>
	std::string paramsToString(Tfstpar fstParam, Tothpar... othParams);
	void msgTestBegin(std::string funName, bool alignNames);
	void msgTestEnd();
protected:
	bool funToTestExist = false;
	int testCount = 0;
	int errCount = 0;
};

#include "absTest.tpp"

#endif
