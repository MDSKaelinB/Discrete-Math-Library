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
//prints the test name checks if condition is true and updates the tracking counters
void test::AssertTest(const std::string& _kstrTestName, bool _bCondition)
{
	m_uiTestsRun++; //increase total number of tests
	std::cout << _kstrTestName << ": ";
	if (_bCondition) //if expected value
	{
		//test passed
		m_uiTestsPassed++; //increase succesful tests counter
		std::cout << "PASS\n";
	}
	else
	{
		//test failed
		std::cout << "FAIL\n";
	}
}
void test::RunAllTests()
{
	//test everything
	TestBasicMath();
	TestCountingAndProbability();
	TestSetRelationships();
	TestSetOperations();
	//show summary of tests
	std::cout << "------------------------\n";
	std::cout << "	Summary\n";
	std::cout << "------------------------\n";
	std::cout << "Tests Executed:" << m_uiTestsPassed << "\n";
	std::cout << "Total Tests Passed: " << m_uiTestsPassed << "\n";
	std::cout<<"Score: " << m_uiTestsPassed << " / " << m_uiTestsRun << "\n";
	//show whether everything passed or not
	if (m_uiTestsRun == m_uiTestsPassed)
	{
		std::cout << "All tests passed successfully!!\n";
	}
	else
	{
		//checks how many tests failed for correct grammar
		if ((m_uiTestsRun - m_uiTestsPassed) == 1)
		{
			//1 test failed
			std::cout << (m_uiTestsRun - m_uiTestsPassed) << " test failed\n";
		}
		else
		{
			//more than 1 test failed
			std::cout << (m_uiTestsRun - m_uiTestsPassed) << " tests failed\n";
		}
	}
}
//specific tests
void test::TestBasicMath()
{
	//magnitude
	AssertTest("Magnitude: |-5.0|", Magnitude(-5.0f) == 5.0f);
	AssertTest("Magnitude: |10.0|", Magnitude(10.0f) == 10.0f);
	//signum
	AssertTest("Signum: sgn(-10.0)", Signum(-10.0f) == -1.0f);
	AssertTest("Signum: sgn(10.0)", Signum(10.0f) == 1.0f);
	AssertTest("Signum: sgn(0.0)", Signum(0.0f) == 0.0f);
	//floor
	AssertTest("Floor: positive float", Floor(5.9f) == 5.0f);
	AssertTest("Floor: negative float", Floor(-3.2f) == -4.0f);
	//ceiling
	AssertTest("Ceiling: positive float", Ceiling(1.1f) == 2.0f);
	AssertTest("Ceiling: negative float", Ceiling(-5.5f) == -5.0f);
}
void test::TestCountingAndProbability()
{
	//factorial
	AssertTest("Factorial: 4!", Factorial(4) == 24ULL);
	AssertTest("Factorial: 0!", Factorial(0) == 1ULL);
	//permutation
	AssertTest("Permutation: P(5, 2)", Permutation(5, 2) == 20ULL);
	AssertTest("Permutation Error Case: P(2, 5)", Permutation(2, 5) == 0ULL);
	//combination
	AssertTest("Combination: C(5, 2)", Combination(5, 2) == 10ULL);
	AssertTest("Combination Error Case: C(2, 5)", Combination(2, 5) == 0ULL);
}
void test::TestSetRelationships()
{
	//Set A
	TSet setA;
	setA.AddElement(10);
	setA.AddElement(20);
	setA.AddElement(30);
	//Set B
	TSet setB;
	setB.AddElement(10);
	setB.AddElement(20);
	//Test C
	TSet setC;
	setC.AddElement(40);
	setC.AddElement(50);

	//cardinality
	AssertTest("Cardinality: |A|", Cardinality(setA) == 3);
	//power
	AssertTest("Power Set: P(A) Size", Power(setA) == 8ULL);
	//cartesian product
	AssertTest("Cartesian Product: A x B Size", CartesianProduct(setA, setB) == 6ULL);
	//subset
	AssertTest("Subset: B sub A", Subset(setB, setA) == true);
	AssertTest("Subset: C sub A", Subset(setC, setA) == false);
	//superset
	AssertTest("Superset: A super B", Superset(setA, setB) == true);
	//equals
	AssertTest("Equality: A == B", Equals(setA, setB) == false);
	//disjoint
	AssertTest("Disjoint: A || C", Disjoint(setA, setC) == true);
}
void test::TestSetOperations()
{
	//set A
	TSet setA;
	setA.AddElement(10);
	setA.AddElement(20);
	setA.AddElement(30);

	//Set B
	TSet setB;
	setB.AddElement(20);
	setB.AddElement(30);
	setB.AddElement(40);
	TSet result; //stores function results

	//union
	TSet unionTarget;
	unionTarget.AddElement(10); unionTarget.AddElement(20); unionTarget.AddElement(30); unionTarget.AddElement(40);
	Union(setA, setB, result);
	AssertTest("Union: A U B", Equals(result, unionTarget) == true);

	//intersection
	result.SetClear(); // Clear it out before the next test
	TSet intersectTarget;
	intersectTarget.AddElement(20); intersectTarget.AddElement(30);
	Intersection(setA, setB, result);
	AssertTest("Intersection: A n B", Equals(result, intersectTarget) == true);

	//set difference
	result.SetClear();
	TSet diffTarget;
	diffTarget.AddElement(10);
	SetDifference(setA, setB, result);
	AssertTest("Set Difference: A \\ B", Equals(result, diffTarget) == true);

	//symmetric difference
	result.SetClear();
	TSet symDiffTarget;
	symDiffTarget.AddElement(10); symDiffTarget.AddElement(40);
	SymmetricDifference(setA, setB, result);
	AssertTest("Symmetric Difference: A symDiff B", Equals(result, symDiffTarget) == true);

	//compliment
	result.SetClear();
	TSet compTarget;
	compTarget.SetUniversal();
	compTarget.RemoveElement(10); compTarget.RemoveElement(20); compTarget.RemoveElement(30); // Target is everything EXCEPT 10, 20, 30
	Compliment(setA, result);
	AssertTest("Compliment: A'", Equals(result, compTarget) == true);
}