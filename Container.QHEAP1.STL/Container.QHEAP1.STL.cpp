/*
https://www.hackerrank.com/challenges/qheap1

Sample Input:

5
1 4
1 9
3
2 4
3

Sample Output:
4
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int Q;
	cin >> Q;
	vector<int> v;
	while (Q)
	{
		int command, argument;
		cin >> command;
		if (command == 1 || command == 2) cin >> argument;
		switch (command)
		{
		case 1: 
			v.push_back(argument); 
			push_heap(v.begin(), v.end(), greater<int>()); 
			break;
		case 2: 
			v.erase(find(v.begin(), v.end(), argument)); 
			make_heap(v.begin(), v.end(), greater<int>());
			break;
		case 3: 
			cout << v.front() << endl; 
			break;
		}
		Q--;
	}
	system("pause");
	return 0;
}