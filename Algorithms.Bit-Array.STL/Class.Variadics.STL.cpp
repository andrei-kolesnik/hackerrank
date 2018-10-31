//https://www.hackerrank.com/challenges/bitset-1/problem
//Sample Input 1:
//3 1 1 1
//
//Sample Output 1:
//3
//Sample Input 2:
//10000000 658061970 695098531 1430548937
//Sample Output 2:
//10000000
//Sample Input 3:
//100000000 923092883 976061291 1205350525
//Sample Output 3:
//100000000

#include <cmath>
#include <cstdio>
#include <vector>
//#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int Map[(INT32_MAX/sizeof(int)+1)/8];

int countSetBits(int n)
{
	int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	unsigned int N, S, P, Q;
	cin >> N >> S >> P >> Q;
/*Verison 1: map (too slow)
	unordered_map<int, int> V;

	unsigned int a = S & 0b01111111111111111111111111111111;
	V[a] = 1;
	for (unsigned int i = 1; i <= N - 1; i++)
	{
		a = (a * P + Q) & 0b01111111111111111111111111111111;
		V[a] = 1;
	}

	cout << V.size() << endl;
*/

	unsigned int a = S & 0b01111111111111111111111111111111;
	int mod32      = a & 0b00000000000000000000000000011111; //a mod 32
	Map[a >> 5] |= (1 << mod32);
	for (unsigned int i = 1; i <= N - 1; i++)
	{
		a = (a * P + Q) & 0b01111111111111111111111111111111;
		mod32 = a & 0b00000000000000000000000000011111; //a mod 32
		Map[a >> 5] |= (1 << mod32);
	}

/*Version 2: count set bits using masks and shifts: too slow
	int result = 0;
	for (int i = 0; i < sizeof(Map) / sizeof(Map[0]); i++)
	{
		int bits = 0, mask = 1, num = Map[i];
		for (int k = 0; k < 32; k++)
		{
			if (num & mask) result++;
			mask <<= 1;
		}
	}
*/

	int result = 0, mapsize = sizeof(Map) / sizeof(Map[0]);
	for (int i = 0; i < mapsize; i++)
		result += countSetBits(Map[i]);
	cout << result << endl;

	getchar();
	getchar();
	return 0;
}