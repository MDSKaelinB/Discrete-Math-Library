#include "discretemaths.h"

// \brief Gets the absolute value of a number by making it positive
// \param _kfX - The input float to check
// \return The positive version of the number
float Magnitude(const float _kfX)
{
	if (_kfX < 0.0f) //if negative
	{
		return _kfX * -1.0f; //make it positive and return it
	}
	//else already positive
	return _kfX;
}

// \brief Checks if a number is negative positive or zero
// \param _kfX - The input float to check
// \return -1.0f for negative, 1.0f for positive, 0.0f for zero
float Signum(const float _kfX)
{
	if (_kfX < 0.0f) //if negative
	{
		return -1.0f;
	}
	else if (_kfX > 0.0f) //if positive
	{
		return 1.0f;
	}
	//number must be 0
	return 0.0f;
}

// \brief Rounds a number down to the nearest whole integer
// \param _kfX - The input float to round down
// \return The rounded down whole number
float Floor(const float _kfX)
{
	//remove the decimal
	int iTruncated = (int)_kfX;

	//if its negative and had a decimal part
	if (_kfX < 0.0f && _kfX !=(float)iTruncated)
	{
		//minus 1 to account for negative rounding
		return(float)(iTruncated - 1);
	}
	//positive and whole numbers dont need changing
	return (float)iTruncated;
}

// \brief Rounds a number up to the nearest whole integer
// \param _kfX - The input float to round up
// \return The rounded up whole number
float Ceiling(const float _kfX)
{
	int iTruncated = (int)_kfX;
	//if positive and had a remainder
	if (_kfX > 0.0f && _kfX != (float)iTruncated)
	{
		return (float)(iTruncated + 1); //add one to account for positive rounding
	}
	//megative numbers and whole numbers dont need changing
	return (float)iTruncated;
}

// \brief Calculates factorial of a given unsigned integer
// \param _kdn - The input number used to calculate the factorial
// \return The final calculated factorial value
unsigned long long Factorial(const unsigned int _kdn)
{
	unsigned long long ullResult = 1; //set result tracker to 1
	for (unsigned int uiCount = 1; uiCount <= _kdn; uiCount++)
	{
		ullResult *= uiCount;
	}
	return ullResult;
}

// \brief Calculates the number of unique combinations (order doesnt matter)
// \param _kuin - The total number of items in the set (n)
// \param _kuir - The number of items to choose (r)
// \return The total number of unique combinations
unsigned long long Combination(const unsigned int _kuin, const unsigned int _kuir)
{
	//if trying to choose more items than exist, cant be mathematically possible
	if (_kuir > _kuin) 
	{
		return 0;
	}
	//calculate n
	unsigned long long ullNumerator = Factorial(_kuin);
	//calculate r * (n-r)
	unsigned long long ullDenomintor = Factorial(_kuir) * Factorial(_kuin - _kuir);
	//divide them to get final answer
	return ullNumerator / ullDenomintor;
}
// \brief Calculates the number of unique permutations (order matters)
// \param _kuin - The total number of items in the set (n)
// \param _kuir - The number of items to arrange (r)
// \return The total number of unique permutations
unsigned long long Permutation(const unsigned int  _kuin, const unsigned int _kuir)
{
	//if trying to arrange more items than exist, its not mathematically possible
	if (_kuir > _kuin)
	{
		return 0; //mathematically impossible
	}
	//calculate n
	unsigned long long ullNumerator = Factorial(_kuin);
	//calculate n-r
	unsigned long long ullDenominator = Factorial(_kuin - _kuir);
	//divide them to get final answer
	return ullNumerator / ullDenominator;
}

// \brief Counts the total number of unique elements inside a set
// \param _rSet - Refrence to the set being checked
// \return The total number of elements found
int Cardinality(TSet& _rSet)
{
	int iCount = 0;
	//loop through evert possible valid element in our set of 1 to 100
	for (int i = 0; i < SET_SIZE_MAX; i++)
	{
		//if set sontains current number then increase our counter by 1
		if (_rSet.ContainsElement(i))
		{
			iCount++;
		}
	}
	return iCount;
}
// \brief Calculates the total number of subsets in a sets power set
// \param _rSet - Reference to the set being evaluated
// \return The total count of subsets (2 to the power of cardinality)
unsigned long long Power(TSet& _rSet)
{
	//Get the total number of elements in the set
	int iElementsCount = Cardinality(_rSet);
	//Calculate 2^n using bitwise left shift
	unsigned long long ullSubsetsCount = 1ULL << iElementsCount; //1ULL is 1 Unsigned Long Long

	return ullSubsetsCount;
}
// \brief Finds all elements that exist in both Set A and Set B
// \param _rSetA - A referenec to the fisrt input set
// \param _rSetB - A reference to the second input set
// \return A new TSet containing the intersecting elements
TSet& Intersection(TSet& _rSetA, TSet& _rSetB, TSet& _rResultant)
{
	_rResultant.SetClear(); //creates an empty set to store the matches
	//loop through universal set range
	for (int i = 0; i < SET_SIZE_MAX; i++)
	{
		//if element is in both sets
		if (_rSetA.ContainsElement(i) && _rSetB.ContainsElement(i))
		{
			_rResultant.AddElement(i); //add to our result set
		}
	}
	return _rResultant;
}
// \brief Combines all unique elements from both Set A and Set B
// \param _rSetA - A reference to the first input set
// \param _rSetB - A reference to the second input set
// \return A new TSet containing the combined elements
TSet& Union(TSet& _rSetA, TSet& _rSetB, TSet& _rResultant)
{
	_rResultant.SetClear(); //empty set for combined elements
	for (int i = 0; i <= SET_SIZE_MAX; i++)
	{
		//if element is present in set A or B
		if (_rSetA.ContainsElement(i) || _rSetB.ContainsElement(i))
		{
			//Add it to result set
			_rResultant.AddElement(i);
		}
	}
	return _rResultant;
}
// \brief Finds all elements that exist in Set A but do not exist in Set B
// \param _rSetA - A reference to the base set (A)
// \param _rSetB - A reference to the set being subtracted (B)
// \return A new TSet containing the difference
TSet& SetDifference(TSet& _rSetA, TSet& _rSetB, TSet& _rResultant)
{
	_rResultant.SetClear(); //creates an empty set to store elements of set A
	//loop through set range 1 to 100
	for (int i = 1; i <= SET_SIZE_MAX; i++)
	{
		//if element is in Set A and not in set B
		if (_rSetA.ContainsElement(i) && !_rSetB.ContainsElement(i))
		{
			//add it to result set
			_rResultant.AddElement(i);
		}
	}
	return _rResultant;
}
// \brief Finds all elements in the universal set that do not exist in Set X
// \param _rSetX - A reference to the input set
// \return A new TSet containing the complement
TSet& Compliment(TSet& _rSetX, TSet& _rResultant)
{
	//Create an empty set to store remaining elemnts
	_rResultant.SetClear();

	//loop through set range
	for (int i = 0; i <= SET_SIZE_MAX; i++)
	{
		//if element isnt in set x
		if (!_rSetX.ContainsElement(i))
		{
			//add it to our result set
			_rResultant.AddElement(i);
		}
	}
	return _rResultant;
}