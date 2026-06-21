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
	std::cout << "Discrete Maths Tests:\n";
	runTests.RunAllTests(); //run all the tests
	std::cout << "\nPress Enter to exit...";
	std::cin.get();
	return 0;
}