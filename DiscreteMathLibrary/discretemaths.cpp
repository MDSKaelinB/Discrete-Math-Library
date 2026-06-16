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