//https://www.hackerrank.com/challenges/attribute-parser
//Sample Input:
//4 3
//<tag1 value = "HelloWorld">
//<tag2 name = "Name1">
//< / tag2>
//< / tag1>
//tag1.tag2~name
//tag1~name
//tag1~value
//
//Sample Output:
//Name1
//Not Found!
//HelloWorld

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> GetWords(string str)
{
	vector<string> v;
	string::size_type found = str.find_first_of(" ");
	while (found != string::npos) 
	{
		v.push_back(str.substr(0, found));
		str = str.substr(found + 1);
		found = str.find_first_of(" ");
	}
	v.push_back(str);
	return v;
}

string GetFullTagName(vector<string> v)
{
	string fullname;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (i > 0) fullname += ".";
		fullname += v[i];
	}
	return fullname;
}

int main() {
	string line;
	int n, q;
	getline(cin, line);
	sscanf(line.c_str(), "%d %d", &n, &q);

	vector<string> tags;
	unordered_map<string, string> attrs;
	for (int i = 0; i < n; i++)
	{
		getline(cin, line);

		if (line[1] == '/') //end tag
			tags.pop_back();
		else //start tag
		{
			line = line.substr(1, line.size() - 2);
			vector<string> words = GetWords(line);
			tags.push_back(words.front()); //tag name
			words.erase(words.begin());
			string fullname = GetFullTagName(tags);
			while (!words.empty())
			{
				string name = words.front(); //attribute name
				words.erase(words.begin());
				string equal = words.front(); //=
				words.erase(words.begin());
				string value = words.front(); //attribute "value"
				words.erase(words.begin());
				value = value.substr(1, value.size() - 2);
				name = fullname + "~" + name;
				attrs[name] = value;
			}
		}
	}

	for (int i = 0; i < q; i++)
	{
		getline(cin, line);
		unordered_map<string, string>::iterator found = attrs.find(line);
		if (found == attrs.end())
			cout << "Not Found!" << endl;
		else
			cout << found->second.c_str() << endl;
	}

	return 0;
}
