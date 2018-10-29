//https://www.hackerrank.com/challenges/operator-overloading/problem
//Sample Input:
//1
//2 2
//2 2 2 2
//1 2 3 4
//
//Sample Output:
//3 4
//5 6
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Enter your code here
class Matrix {
public:
	vector<vector<int>> a;
	Matrix operator+(Matrix& b) {
		Matrix result;
		for (size_t i = 0; i < a.size(); i++) {
			vector<int> bv;
			for (size_t j = 0; j < a[i].size(); j++)
				bv.push_back(a[i][j] + b.a[i][j]);
			result.a.push_back(bv);
		}
		return result;
	}
};
//End of your code

int main() {
	int cases, k;
	cin >> cases;
	for (k = 0; k < cases; k++) {
		Matrix x;
		Matrix y;
		Matrix result;
		int n, m, i, j;
		cin >> n >> m;
		for (i = 0; i < n; i++) {
			vector<int> b;
			int num;
			for (j = 0; j < m; j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for (i = 0; i < n; i++) {
			vector<int> b;
			int num;
			for (j = 0; j < m; j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}
		result = x + y;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}

	getchar();
	getchar();

	return 0;
}
