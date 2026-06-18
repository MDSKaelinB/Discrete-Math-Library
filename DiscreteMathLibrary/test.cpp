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
	AssertTest("|-5.0|", Magnitude(-5.0f) == 5.0f);
	AssertTest("|5.0|", Magnitude(10.0f) == 10.0f);
	//signum
	AssertTest("sgn(-10.0)", Signum(-10.0f) == -1.0f);
	AssertTest("sgn(10.0)", Signum(10.0f) == 1.0f);
	AssertTest("sgn(0.0)", Signum(0.0f) == 0.0f);
	//floor
	AssertTest("Floor (positive float)", Floor(5.9f) == 5.0f);
	AssertTest("Floor (negative float)", Floor(-3.2f) == -4.0f);
	//ceiling
	AssertTest("Ceiling (positive float)", Ceiling(1.1f) == 2.0f);
	AssertTest("Ceiling (negative float)", Ceiling(-5.5f) == -5.0f);
}
void test::TestCountingAndProbability()
{
	//factorial
	AssertTest("4!", Factorial(4) == 24ULL);
	AssertTest("0!", Factorial(0) == 1ULL);
	//permutation
	AssertTest("P(5, 2)", Permutation(5, 2) == 20ULL);
	AssertTest("P(2, 5) Error Case", Permutation(2, 5) == 0ULL);
	//combination
	AssertTest("C(5, 2)", Combination(5, 2) == 10ULL);
	AssertTest("C(2, 5) Error Case", Combination(2, 5) == 0ULL);
}
void test::TestSetRelationships()
{

}
void test::TestSetOperations()
{

}