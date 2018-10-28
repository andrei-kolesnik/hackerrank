//https://www.hackerrank.com/challenges/deque-stl/problem
//Sample Input:
//2
//5 2
//3 4 6 3 4
//7 4
//3 4 5 8 1 4 10
//Sample Output:
//4 6 6 4
//8 8 8 10
#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k) {
	//Write your code here.
	deque<int> deq;
	int max = 0;
	for (int i = 0; i < k; i++)
	{
		deq.push_back(arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}
	int m = k;
	while (m <= n)
	{
		cout << max << " ";
		if (deq.front() == max)
		{
			max = 0;
			for (int i = 1; i < k; i++)
				if (deq[i] > max)
					max = deq[i];
		}
		deq.pop_front();
		deq.push_back(arr[m]);
		if (arr[m] > max)
			max = arr[m];
		m++;
	}
	cout << endl;
	//End of your code
}

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		int n, k;
		cin >> n >> k;
		int i;
		int arr[10000]; //submitted as: arr[n]
		for (i = 0; i < n; i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}
