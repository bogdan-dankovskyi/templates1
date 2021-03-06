// template_find.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename InputIterator, typename T>
InputIterator myFind(InputIterator itFirst, InputIterator itLast, const T& val)
{
	while (itFirst != itLast)
	{
		if (*itFirst == val)
			return itFirst;
		else
			itFirst++;
	}

	return itLast;

}

template <typename T, unsigned N>
void myPrint(T (&arr) [N])
{
	for (auto elem : arr)
		std::cout << elem << std::endl;

}

template <typename T, unsigned N = 0>
void myPrint1(T a)
{
	std::cout << "In myPrint1 " << a << std::endl;
	std::cout << "In myPrint1 " << N << std::endl;
}

template <typename T, unsigned N>
T* myBegin(T(&arr)[N])
{
	return &arr[0];
}

template <typename T, unsigned N>
T* myEnd(T(&arr)[N])
{
	return &arr[N];
}

template <typename T, unsigned N>
constexpr unsigned mySize(T(&arr)[N])
{
	return N;
}

int main()
{
	std::vector<int> a{ 0,1,2,3,4,5 };

	if (myFind(begin(a), end(a), 3) != end(a))
		std::cout << "found 3" << std::endl;
	else
		std::cout << "not found 3" << std::endl;


	if (myFind(begin(a), end(a), 5) != end(a))
		std::cout << "found 5" << std::endl;
	else
		std::cout << "not found 5" << std::endl;

	if (myFind(begin(a), end(a), 7) != end(a))
		std::cout << "found 7" << std::endl;
	else
		std::cout << "not found 7" << std::endl;

	std::list<std::string> b{ "a","b","c","d" };

	if (myFind(begin(b), end(b), "a") != end(b))
		std::cout << "found a" << std::endl;
	else
		std::cout << "not found a" << std::endl;

	if (myFind(begin(b), end(b), "d") != end(b))
		std::cout << "found d" << std::endl;
	else
		std::cout << "not found d" << std::endl;

	if (myFind(begin(b), end(b), "e") != end(b))
		std::cout << "found e" << std::endl;
	else
		std::cout << "not found e" << std::endl;

	std::cout << "=====================" << std::endl << std::endl;
	int d[3] = {1,3,4};
	myPrint(d);
	
	int e[1];
	myPrint(e);

	std::cout << "=====================" << std::endl << std::endl;

	if (myFind(myBegin(d), myEnd(d), 3) != myEnd(d))
		std::cout << "found 3" << std::endl;
	else
		std::cout << "not found 3" << std::endl;

	if (myFind(myBegin(d), myEnd(d), 5) != myEnd(d))
		std::cout << "found 5" << std::endl;
	else
		std::cout << "not found 5" << std::endl;

	std::cout << "=====================" << std::endl << std::endl;

	std::cout << "size of d = " << mySize(d) << std::endl;

	std::cout << "=====================" << std::endl << std::endl;

	int f = 5;
	myPrint1<int,6>(f);
	myPrint1<std::string>("A");


    std::cout << "end main\n";
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
