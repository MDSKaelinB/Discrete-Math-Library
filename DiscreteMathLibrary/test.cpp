#include "test.h"

//constructor
test::test()
{
	m_uiTestsRun = 0; //set total tests counter to 0
	m_uiTestsPassed = 0; //set passed tests counter to 0
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
	std::cout << "Tests Executed:" << m_uiTestsRun<< "\n"; //number of tests
	std::cout << "Total Tests Passed: " << m_uiTestsPassed << "\n"; //number of tests that passed
	std::cout<<"Score: " << m_uiTestsPassed << " / " << m_uiTestsRun << "\n"; //shows the score of how many tests passed
	//show whether everything passed or not
	if (m_uiTestsRun == m_uiTestsPassed) //if everthing passed
	{
		std::cout << "All tests passed successfully!!\n";
	}
	else //if at least one test failed
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
	AssertTest("Magnitude: |-5.0|", Magnitude(-5.0f) == 5.0f); //checks if absolute value makes negative numbers positive
	AssertTest("Magnitude: |10.0|", Magnitude(10.0f) == 10.0f); //checks if absolute value keeps positive numbers positive
	//signum
	AssertTest("Signum: sgn(-10.0)", Signum(-10.0f) == -1.0f); //checks if negative number returns negative sign indicator
	AssertTest("Signum: sgn(10.0)", Signum(10.0f) == 1.0f); //checks if positive number returns positive sign indicator
	AssertTest("Signum: sgn(0.0)", Signum(0.0f) == 0.0f); //checks if zero returns neutral indicator
	//floor
	//checks if floats round down
	AssertTest("Floor: positive float", Floor(5.9f) == 5.0f);
	AssertTest("Floor: negative float", Floor(-3.2f) == -4.0f);
	//ceiling
	 //checks if floats round up
	AssertTest("Ceiling: positive float", Ceiling(1.1f) == 2.0f);
	AssertTest("Ceiling: negative float", Ceiling(-5.5f) == -5.0f);
}
void test::TestCountingAndProbability()
{
	//factorial
	AssertTest("Factorial: 4!", Factorial(4) == 24ULL); //checks 4x3x2x1 loop
	AssertTest("Factorial: 0!", Factorial(0) == 1ULL); //checks that 0! equals 1
	//permutation
	AssertTest("Permutation: P(5, 2)", Permutation(5, 2) == 20ULL); //checks permutation order
	AssertTest("Permutation Error Case: P(2, 5)", Permutation(2, 5) == 0ULL); //returns 0 if tring to arrange more items than there are
	//combination
	AssertTest("Combination: C(5, 2)", Combination(5, 2) == 10ULL); //checks combinations where order doesnt matter
	AssertTest("Combination Error Case: C(2, 5)", Combination(2, 5) == 0ULL); //returns 0 if trying to choose more items than there arre
}
void test::TestSetRelationships()
{
	//Set A
	TSet setA;
	//adds elements to set a
	setA.AddElement(10);
	setA.AddElement(20);
	setA.AddElement(30);
	//Set B
	TSet setB;
	//adds elements to set b
	setB.AddElement(10);
	setB.AddElement(20);
	//Test C
	TSet setC;
	//adds elements to set c
	setC.AddElement(40);
	setC.AddElement(50);

	//cardinality
	AssertTest("Cardinality: |A|", Cardinality(setA) == 3); //checks if it counts the number of items in the set
	//power
	AssertTest("Power Set: P(A) Size", Power(setA) == 8ULL); //checks subset count
	//cartesian product
	AssertTest("Cartesian Product: A x B Size", CartesianProduct(setA, setB) == 6ULL); //checls total possible pairs count
	//subset
	AssertTest("Subset: B sub A", Subset(setB, setA) == true); //checks if all items in b are in a
	AssertTest("Subset: C sub A", Subset(setC, setA) == false); //chceks if different items fail subset test
	//superset
	AssertTest("Superset: A super B", Superset(setA, setB) == true); //checks if a has everything b has
	//equals
	AssertTest("Equality: A == B", Equals(setA, setB) == false); //checks if different sets are marked as not equal
	//disjoint
	AssertTest("Disjoint: A || C", Disjoint(setA, setC) == true); //checks if sets with zero overlapping return true
}
void test::TestSetOperations()
{
	//set A
	TSet setA;
	//setup set a
	setA.AddElement(10);
	setA.AddElement(20);
	setA.AddElement(30);

	//Set B
	TSet setB;
	//setup set b
	setB.AddElement(20);
	setB.AddElement(30);
	setB.AddElement(40);
	TSet result; //stores function results

	//union
	TSet unionTarget;
	unionTarget.AddElement(10); 
	unionTarget.AddElement(20); 
	unionTarget.AddElement(30); 
	unionTarget.AddElement(40);
	Union(setA, setB, result); //combine sets together
	AssertTest("Union: A U B", Equals(result, unionTarget) == true);

	//intersection
	result.SetClear(); //clear it before next test
	TSet intersectTarget;
	intersectTarget.AddElement(20); 
	intersectTarget.AddElement(30);
	Intersection(setA, setB, result); //find matching items in both sets
	AssertTest("Intersection: A n B", Equals(result, intersectTarget) == true);

	//set difference
	result.SetClear(); //clear it before next test
	TSet diffTarget;
	diffTarget.AddElement(10);
	SetDifference(setA, setB, result); //subtract set b from a
	AssertTest("Set Difference: A \\ B", Equals(result, diffTarget) == true);

	//symmetric difference
	result.SetClear(); //clear it before next test
	TSet symDiffTarget;
	symDiffTarget.AddElement(10); 
	symDiffTarget.AddElement(40);
	SymmetricDifference(setA, setB, result); //find items that are unique and are not overlapping
	AssertTest("Symmetric Difference: A symDiff B", Equals(result, symDiffTarget) == true);

	//compliment
	result.SetClear(); //clear it before next test
	TSet compTarget;
	compTarget.SetUniversal(); //fil set with numbers 1 to 100
	compTarget.RemoveElement(10);
	compTarget.RemoveElement(20); 
	compTarget.RemoveElement(30);
	Compliment(setA, result); //find everything outside of set a
	AssertTest("Compliment: A'", Equals(result, compTarget) == true);
}