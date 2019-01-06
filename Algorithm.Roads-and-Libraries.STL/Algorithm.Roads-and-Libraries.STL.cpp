/*
Roads and Libraries
https://www.hackerrank.com/challenges/torque-and-development

Input:
2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6

Output:
4
12
*/
#include <bits/stdc++.h>	
using namespace std;

vector<vector<int>> edges2matrix(vector<vector<int>> &edges, int N) {
	vector<vector<int>> result;
	for (size_t i = 0; i < N + 1; i++)
	{
		vector<int> vv(N + 1, 0);
		result.push_back(vv);
	}
	for (auto e : edges) {
		result[e[0]][e[1]] = 1;
		result[e[1]][e[0]] = 1; //if edges are bi-directional
	}
	return result;
}

void dfs(int n, int k, int index, vector<vector<int>> &matrix, vector<bool> &visited, map<int, long>& segments) {
	visited[k] = true;
	segments[index]++;
	for (size_t i = 1; i <= n; i++)
		if (matrix[k][i] == 1)
			if (!visited[i])
				dfs(n, i, index, matrix, visited, segments);
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
	if (!cities.size()) return c_lib * n;
	vector<vector<int>> matrix = edges2matrix(cities, n);
	vector<bool> visited(n + 1, false);
	map<int, long> segments;
	int count = 0;
	for (size_t i = 1; i <= n; i++)
		if (!visited[i])
		{
			count++;
			dfs(n, i, count, matrix, visited, segments);
		}
	long result = 0;
	for (auto seg : segments)
		result += min(
			(seg.second - 1) * c_road + c_lib, // connect all cities in a segment with roads + build one library
			seg.second * c_lib); // or build a library in every city / build no roads
	return result;
}

void check(int e[][2], int n, int m, int c_lib, int c_road, long expected) {
	vector<vector<int>> edges;
	for (size_t i = 0; i < m; i++)
	{ // converting int 2D array into 2D vector
		vector<int> vv(2);
		for (int j = 0; j < 2; j++)
			vv[j] = e[i][j];
		edges.push_back(vv);
	}
	long actual = roadsAndLibraries(n, c_lib, c_road, edges);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main() {
	int es1[3][2] = { 
		{1, 2}, 
		{3, 1}, 
		{2, 3} 
	};
	check(es1, 3, 3, 2, 1, 4);

	int es2[6][2] = {
		{1, 3},
		{3, 4},
		{2, 4},
		{1, 2},
		{2, 3},
		{5, 6} 
	};
	check(es2, 6, 6, 2, 5, 12);

	int es3[2][2] = {
		{8, 2},
		{2, 9}
	};
	check(es3, 9, 2, 91, 84, 805);

	int es4[1][2] = {
		{0, 0}
	};
	check(es4, 1, 0, 5, 3, 5);

	system("pause");
	return 0;
}
