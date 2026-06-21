/***********************************************************************
Bachelor of Software Engineering - Game Programming
Media Design School, Auckland, New Zealand
(c) 2026 Media Design School
Author      :   Kaelin Burt
Mail        :   Kaelin.Burt@mds.ac.nz
File Name   :	main.cpp
Description :	The main file for the project
**************************************************************************/

#include <iostream>
#include "test.h"

int main()
{
	test runTests; //test running object
	runTests.RunAllTests(); //run all the tests
	return 0;
}