/*
Quicksort 1 - Partition
https://www.hackerrank.com/challenges/quicksort1

Input:
4 5 3 7 2

Output:
3 2 4 5 7
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> quickSort(vector<int> arr) {
	vector<int> result;
	if (!arr.size()) return result;
	vector<int> left, right, equal;
	int pivot = arr[0];
	equal.push_back(pivot);
	for (size_t i = 1; i < arr.size(); i++)
		if (arr[i] < pivot) left.push_back(arr[i]);
		else if (arr[i] > pivot) right.push_back(arr[i]);
		else equal.push_back(arr[i]);
	for (auto a : quickSort(left))  result.push_back(a);
	for (auto a : equal) result.push_back(a);
	for (auto a : quickSort(right)) result.push_back(a);
	return result;
}

int main()
{
	int a[] = { 4, 5, 3, 7, 2 };
	vector<int> arr(a, a + sizeof(a) / sizeof(a[0]));

	vector<int> result = quickSort(arr);

	for (size_t i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << "\n";

	getchar();
	return 0;
}
