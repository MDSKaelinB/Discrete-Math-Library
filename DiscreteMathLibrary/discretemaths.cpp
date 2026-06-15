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