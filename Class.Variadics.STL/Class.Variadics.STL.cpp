//https://www.hackerrank.com/challenges/cpp-variadics/problem
//
//Sample Input:
//2
//65 1
//10 0
//
//Sample Output:
//0100000000000000000000000000000000000000000000000000000000000000
//0000000000100000000000000000000000000000000000000000000000000000

#include <iostream>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()
template <bool digit>
int reversed_binary_value()
{
	return digit;
}

template <bool digit1, bool digit2, bool...digits>
int reversed_binary_value()
{
	return reversed_binary_value<digit2, digits...>() * 2 + digit1;
}
//...end of your code

template <int n, bool...digits>
struct CheckValues {
	static void check(int x, int y)
	{
		CheckValues<n - 1, 0, digits...>::check(x, y);
		CheckValues<n - 1, 1, digits...>::check(x, y);
	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
	static void check(int x, int y)
	{
		int z = reversed_binary_value<digits...>();
		std::cout << (z + 64 * y == x);
	}
};

int main()
{
	int t; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int x, y;
		cin >> x >> y;
		CheckValues<6>::check(x, y);
		cout << "\n";
	}
}
