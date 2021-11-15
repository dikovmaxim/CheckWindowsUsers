// HelloParameter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main(int argc, char const* argv[])
{
	std::cout << "Hello Parameter!\n";

	for (int i = 0; i <= argc; i++)
	{
		printf("Argument %d/%d: %s\n", i, argc, argv[i]);
	}
	return 0;
}