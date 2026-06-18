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
	AssertTest("Magnitude negative input", Magnitude(-5.0f) == 5.0f);
	AssertTest("Magnitude positive input", Magnitude(10.0f) == 10.0f);
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