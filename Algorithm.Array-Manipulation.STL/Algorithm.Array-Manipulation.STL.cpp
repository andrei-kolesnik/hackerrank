//https://www.hackerrank.com/challenges/crush/problem
//Sample Input:
//5 3
//1 2 100
//2 5 100
//3 4 100
//
//Sample Output:
//200

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
/* Version 1: works fine, but too slow
// Complete the arrayManipulation function below.
typedef pair<int, int> Range;

struct RangeValue {
	Range range;
	long long value;
};

long long arrayManipulation(int n, vector<vector<int>> queries) {
	vector<RangeValue> Rs;
	for (size_t i = 0; i < queries.size(); i++)
	{
		int old_size = queries.size();///###
		Range New(queries[i][0], queries[i][1]);
		int k = queries[i][2];
		bool found = false;
		for (auto& Old : Rs)
		{
			if (Old.range.first == New.first && Old.range.second == New.second) //total match
			{
				Old.value += k;
				found = true;
				break;
			}
			
			if (Old.range.first == New.first && Old.range.second > New.second) //same start, old is longer
			{
				vector<int> Extra(3);
				Extra[0] = New.second + 1;
				Extra[1] = Old.range.second;
				Extra[2] = Old.value;
				queries.push_back(Extra);
				Old.range.second = New.second;
				Old.value += k;
				found = true;
				break;
			}
			if (Old.range.first == New.first && Old.range.second < New.second) //same start, new is longer
			{
				vector<int> Extra(3);
				Extra[0] = Old.range.second + 1;
				Extra[1] = New.second;
				Extra[2] = k;
				queries.push_back(Extra);
				Old.value += k;
				found = true;
				break;
			}
			if (Old.range.first < New.first && Old.range.second == New.second) //same end, old is longer
			{
				vector<int> Extra(3);
				Extra[0] = Old.range.first;
				Extra[1] = New.first - 1;
				Extra[2] = Old.value;
				queries.push_back(Extra);
				Old.range.first = New.first;
				Old.value += k;
				found = true;
				break;
			}
			if (Old.range.first > New.first && Old.range.second == New.second) //same end, new is longer
			{
				vector<int> Extra(3);
				Extra[0] = New.first;
				Extra[1] = Old.range.first - 1;
				Extra[2] = k;
				queries.push_back(Extra);
				Old.value += k;
				found = true;
				break;
			}
			if (Old.range.first < New.first && Old.range.second > New.second) //new is within old
			{
				vector<int> Extra(3);
				Extra[0] = Old.range.first;
				Extra[1] = New.first - 1;
				Extra[2] = Old.value;
				queries.push_back(Extra);
				vector<int> Extra2(3);
				Extra2[0] = New.second + 1;
				Extra2[1] = Old.range.second;
				Extra2[2] = Old.value;
				queries.push_back(Extra2);
				Old.range.first = New.first;
				Old.range.second = New.second;
				Old.value += k;
				found = true;
				break;
			}
			if (Old.range.first > New.first && Old.range.second < New.second) //old is within new
			{
				vector<int> Extra(3);
				Extra[0] = New.first;
				Extra[1] = Old.range.first - 1;
				Extra[2] = k;
				queries.push_back(Extra);
				vector<int> Extra2(3);
				Extra2[0] = Old.range.second + 1;
				Extra2[1] = New.second;
				Extra2[2] = k;
				queries.push_back(Extra2);
				Old.value += k;
				found = true;
				break;
			}
			if (Old.range.first < New.first && Old.range.second >= New.first) //overlap, old is earlier
			{
				vector<int> Extra(3);
				Extra[0] = Old.range.first;
				Extra[1] = New.first - 1;
				Extra[2] = Old.value;
				queries.push_back(Extra);
				vector<int> Extra2(3);
				Extra2[0] = Old.range.second + 1;
				Extra2[1] = New.second;
				Extra2[2] = k;
				queries.push_back(Extra2);
				Old.range.first = New.first;
				Old.value += k;
				found = true;
				break;
			}
			if (Old.range.first > New.first && Old.range.first <= New.second) //overlap, new is earlier
			{
				vector<int> Extra(3);
				Extra[0] = New.first;
				Extra[1] = Old.range.first - 1;
				Extra[2] = k;
				queries.push_back(Extra);
				vector<int> Extra2(3);
				Extra2[0] = New.second + 1;
				Extra2[1] = Old.range.second;
				Extra2[2] = Old.value;
				queries.push_back(Extra2);
				Old.range.second = New.second;
				Old.value += k;
				found = true;
				break;
			}
			//else no overlap at all with this range
		}
		if (!found)
		{
			RangeValue NewR;
			NewR.range.first = New.first;
			NewR.range.second = New.second;
			NewR.value = k;
			Rs.push_back(NewR);
		}

	}

	long long max = 0;
	for (auto R : Rs)
		if (R.value > max) max = R.value;
	return max;
}
*/
// Version 2: Difference Array | Range update query in O(1) 
//https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
// Complete the arrayManipulation function below.
long long arrayManipulation(int n, vector<vector<int>> queries) {
	map<int, long> M;
	for (auto q : queries)
	{
		M[q[0]] += q[2];
		M[q[1] + 1] -= q[2];
	}

	long long result = 0, sum = 0;
	for (auto m : M)
	{
		sum += m.second;
		if (sum > result)
			result = sum;
	}
	return result;
}

int main()
{
	ifstream fin("in-arr-manip.txt");
	ofstream fout("out-arr-manip.txt");

	string nm_temp;
	getline(fin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	vector<vector<int>> queries(m);
	for (int i = 0; i < m; i++) {
		queries[i].resize(3);

		for (int j = 0; j < 3; j++) {
			fin >> queries[i][j];
		}

		fin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	long long result = arrayManipulation(n, queries);

	fout << result << "\n";

	fout.close();

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
