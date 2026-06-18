#pragma once
#include "discretemaths.h"
class test
{
public:
	test(); //constructor
	~test(); //destructor

	//calls all different tests one at a time
	void RunAllTests();
private:
	//tracks total number of tests cases
	unsigned int m_uiTestsRun;
	//tracks total number of cases successfully passed
	unsigned int m_uiTestsPassed;
	//prints the test name checks if condition is true and automatically updates the tracking countersa
	void AssertTest(const std::string& _kstrTestName, bool _bCondition);
	//tests
	void TestBasicMath(); //absolute values signing floors and ceiling
	void TestCountingAndProbability(); //factorials permutations and combinations
	void TestSetRelationships(); //cardinalit subsets supersets and equality
	void TestSetOperations(); //union intesection difference compliment
};