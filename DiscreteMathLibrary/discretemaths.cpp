#include "discretemaths.h"
float Magnitude(const float _kfX)
{
	if (_kfX < 0.0f) //if negative
	{
		return _kfX * -1.0f; //make it positive and return it
	}
	//else already positive
	return _kfX;
}

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