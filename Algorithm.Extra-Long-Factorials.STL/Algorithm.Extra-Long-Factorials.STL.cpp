/*
https://www.hackerrank.com/challenges/extra-long-factorials/problem
Sample Input
25

Sample Output
15511210043330985984000000
*/
#include <bits/stdc++.h>

using namespace std;

void extraLongFactorials(int n) {
	vector<int> result; 
	result.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		for (auto &digit : result)
			digit = digit * i;
		int carry = 0;
		for (auto &digit : result)
		{
			digit += carry;
			if (digit > 9)
			{
				int new_digit = digit % 10;
				carry = digit / 10;
				digit = new_digit;
			}
			else carry = 0;
		}
		while (carry)
		{
			result.push_back(carry % 10);
			carry /= 10;
		}
	}
	for (vector<int>::reverse_iterator rit = result.rbegin(); rit != result.rend(); rit++)
		cout << *rit;
	cout << endl;
}

int main()
{
	extraLongFactorials(0); //1
	extraLongFactorials(1); //1
	extraLongFactorials(2); //2
	extraLongFactorials(4); //24
	extraLongFactorials(5); //120
	extraLongFactorials(6); //720
	extraLongFactorials(25); //15511210043330985984000000
	extraLongFactorials(100); //93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
	system("pause");
	return 0;
}
