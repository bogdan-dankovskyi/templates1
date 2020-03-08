// Template_functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <functional>
#include <iostream>

//working good with pointers as less 
template<typename T>
const T& compare(const T &a, const T &b) 
{
	if (std::less<T>()(a, b))
		return a;
	else
		return b;

}

// seems to work in the same way
// inline and constexpr shall be specified before the function
template<typename T>
inline constexpr const T& compare1(const T& a, const T& b)
{
	if (a<b)
		return a;
	else
		return b;

}


int main()
{
	int c=1, d=2;
	int* a = &c;
	int* b = &d;
	
	std::cout << compare1(5, 6) << "\n";
	std::cout << compare1(5.5, 6.2) << "\n";
	std::cout << compare1("5", "6") << "\n";
	
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";

	std::cout << compare1(a, b) << "\n";
	std::cout << compare1(*a, *b) << "\n";

    std::cout << "main end\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
