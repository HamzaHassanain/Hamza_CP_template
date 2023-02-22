// C++ program to find out execution time of
// of functions
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

// For demonstration purpose, we will fill up
// a vector with random integers and then sort
// them using sort function. We fill record
// and print the time required by sort function
int main()
{

	auto start = high_resolution_clock::now();
	long long counter = 0;
	for (int i = 0; i < 2; i++)
	{
	}

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		 << duration.count() << "ms" << endl;

	return 0;
}