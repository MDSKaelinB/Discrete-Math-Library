#include "discretemaths.h"

// \brief Gets the absolute value of a number by making it positive.
// \param _kfX - The input float to check.
// \return The positive version of the number.
float Magnitude(const float _kfX)
{
	if (_kfX < 0.0f) //if negative
	{
		return _kfX * -1.0f; //make it positive and return it
	}
	//else already positive
	return _kfX;
}

// \brief Checks if a number is negative, positive, or zero.
// \param _kfX - The input float to check.
// \return -1.0f for negative, 1.0f for positive, 0.0f for zero.
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

// \brief Rounds a number down to the nearest whole integer.
// \param _kfX - The input float to round down.
// \return The rounded down whole number.
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

// \brief Rounds a number up to the nearest whole integer.
// \param _kfX - The input float to round up.
// \return The rounded up whole number.
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