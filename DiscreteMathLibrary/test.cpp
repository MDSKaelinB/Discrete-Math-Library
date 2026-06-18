#include "test.h"
//constructor
test::test()
{
	m_uiTestsRun = 0;
	m_uiTestsPassed = 0;
}
//destructor
test::~test()
{

}
void test::RunAllTests()
{
	TestBasicMath();
	TestCountingAndProbability();
	TestSetRelationships();
	TestSetOperations();
}
//specific tests
void test::TestBasicMath()
{
	//magnitude
	AssertTest("Magnitude negative input", Magnitude(-5.0f) == 5.0f);
	AssertTest("Magnitude positive input", Magnitude(10.0f) == 10.0f);
	//signum
	AssertTest("Signum negative input", Signum(-10.0f) == -1.0f);
	AssertTest("Signum positive input", Signum(10.0f) == 1.0f);
	AssertTest("Signum zero input", Signum(0.0f) == 0.0f);
	//floor
	AssertTest("Floor positive float", Floor(5.9f) == 5.0f);
	AssertTest("Floor negative float", Floor(-3.2f) == -4.0f);
	//ceiling
	AssertTest("Ceiling positive float", Ceiling(1.1f) == 2.0f);
	AssertTest("Ceiling negative float", Ceiling(-5.5f) == -4.0f);
}
void test::TestCountingAndProbability()
{

}
void test::TestSetRelationships()
{

}
void test::TestSetOperations()
{

}