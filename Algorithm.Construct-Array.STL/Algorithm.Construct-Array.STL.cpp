//https://www.hackerrank.com/challenges/construct-the-array/problem
//Sample Input
//n=4, k=3, x=2
//
//Sample Output
//3

//Sample Input 2
//n=5, k=2, x=2
//
//Sample Output 2
//0

//Sample Input 2
//761 99 1
//Sample Output 2
//236568308 //my:340560813

//Sample Input 5
//17048 14319 1
//Sample Output 5
//803254122

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 

using namespace std;

vector<string> split_string(string);

// Complete the countArray function below.
#define MODULO 1000000007
/*
long countArray(int n, int k, int x) {
	long** A = new long*[n];
	int i, j, l;

	for (i = 0; i < n; ++i)
		A[i] = new long[k];

	for (i = 0; i < n; i++)
		for (j = 0; j < k; j++)
			A[i][j] = 0;

	A[0][x-1] = 1;
	
	for (i = 1; i < n - 2; i++)
		for (j = 0; j < k; j++)
			for (l = 0; l < k; l++)
				if (j != l)
					A[i][l] = (A[i][l] + A[i-1][j]) % MODULO;

	for (j = 0; j < k; j++)
		for (l = 1; l < k; l++)
			if (j != l)
				A[n - 2][l] = (A[n-2][l] + A[n-3][j]) % MODULO;

	A[n-1][0] = 1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	long result = 0;
	for (j = 0; j < k; j++)
		result = (result + A[n-2][j]) % MODULO;

	return result;
}
*/

long countArray(int n, int k, int x) {
	long** A = new long*[2];
	int i, j, l;

	for (i = 0; i < 2; ++i)
		A[i] = new long[k];

	for (i = 0; i < 2; i++)
		for (j = 0; j < k; j++)
			A[i][j] = 0;

	A[0][x-1] = 1;

	for (i = 1; i < n - 2; i++)
	{
		for (j = 0; j < k; j++)
			for (l = 0; l < k; l++)
				if (j != l)
					A[1][l] = (A[1][l] + A[0][j]) % MODULO;
		for (j = 0; j < k; j++)
		{
			A[0][j] = A[1][j];
			A[1][j] = 0;
		}
	}

	for (j = 0; j < k; j++)
		for (l = 1; l < k; l++)
			if (j != l)
				A[1][l] = (A[1][l] + A[0][j]) % MODULO;

	long result = 0;
	for (j = 0; j < k; j++)
		result = (result + A[1][j]) % MODULO;

	return result;
}

int main()
{
/*
	ofstream fout(getenv("OUTPUT_PATH"));

	string nkx_temp;
	getline(cin, nkx_temp);

	vector<string> nkx = split_string(nkx_temp);

	int n = stoi(nkx[0]);
	int k = stoi(nkx[1]);
	int x = stoi(nkx[2]);

	long answer = countArray(n, k, x);
*/
	//long answer = countArray(4, 5, 5);
	//long answer = countArray(4, 3, 2);
	//long answer = countArray(761, 99, 1); //236568308
	long answer = countArray(17048, 14319, 1); //803254122

	cout << answer << "\n"; ///###fout
	getchar();
//	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
