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
	AssertTest("|A|", Cardinality(setA) == 3);
	//power
	AssertTest("P(A) Size", Power(setA) == 8ULL);
	//cartesian product
	AssertTest("A x B Size", CartesianProduct(setA, setB) == 6ULL);
	//subset
	AssertTest("B sub A", Subset(setB, setA) == true);
	AssertTest("C sub A", Subset(setC, setA) == false);
	//superset
	AssertTest("A super B", Superset(setA, setB) == true);
	//equals
	AssertTest("A == B", Equals(setA, setB) == false);
	//disjoint
	AssertTest("A || C", Disjoint(setA, setC) == true);
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
	AssertTest("A U B", Equals(result, unionTarget) == true);

	//intersection
	result.SetClear(); // Clear it out before the next test
	TSet intersectTarget;
	intersectTarget.AddElement(20); intersectTarget.AddElement(30);
	Intersection(setA, setB, result);
	AssertTest("A n B", Equals(result, intersectTarget) == true);

	//set difference
	result.SetClear();
	TSet diffTarget;
	diffTarget.AddElement(10);
	SetDifference(setA, setB, result);
	AssertTest("A \\ B", Equals(result, diffTarget) == true);

	//symmetric difference
	result.SetClear();
	TSet symDiffTarget;
	symDiffTarget.AddElement(10); symDiffTarget.AddElement(40);
	SymmetricDifference(setA, setB, result);
	AssertTest("A symDiff B", Equals(result, symDiffTarget) == true);

	//compliment8
	result.SetClear();
	TSet compTarget;
	compTarget.SetUniversal();
	compTarget.RemoveElement(10); compTarget.RemoveElement(20); compTarget.RemoveElement(30); // Target is everything EXCEPT 10, 20, 30
	Compliment(setA, result);
	AssertTest("A'", Equals(result, compTarget) == true);
}