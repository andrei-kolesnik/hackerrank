//https://www.hackerrank.com/challenges/attending-workshops/problem
//Sample Input 1:
//6
//1 3 0 5 5 8
//1 1 6 2 4 1
//
//Sample Output 1:
//CalculateMaxWorkshops should return 4

//Sample Input 2:
//5
//1 2 3 4 5
//1 3 1 2 3
//Sample Output 2:
//CalculateMaxWorkshops should return 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
	int start_time;
	int duration;
	int end_time;
};

struct Available_Workshops {
	int n;
	Workshop* Workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
	Available_Workshops* AW;
	AW = (Available_Workshops*)malloc(sizeof(Available_Workshops));
	AW->n = n;
	AW->Workshops = new Workshop[n];
	for (int i = 0; i < n; i++)
	{
		AW->Workshops[i].start_time = start_time[i];
		AW->Workshops[i].duration = duration[i];
		AW->Workshops[i].end_time = start_time[i] + duration[i] - 1;
	}
	return AW;
}

bool CompareWorkshops(Workshop w1, Workshop w2)
{
	return w1.end_time < w2.end_time;
}
/* works, but too slow
int CalculateMaxWorkshops(Available_Workshops* ptr) {
	int result = 0;
	vector<Workshop> W;
	for (int i = 0; i < ptr->n; i++)
		W.push_back(ptr->Workshops[i]);
	sort(W.begin(), W.end(), CompareWorkshops);
	while (W.size() > 0)
	{
		int min_start = W[0].start_time, min_end = W[0].end_time;
		result++;
		W.erase(W.begin());
		for (vector<Workshop>::iterator it = W.begin(); it != W.end(); )
			if (!(it->start_time < min_start && it->end_time < min_start ||
				  it->start_time > min_end   && it->end_time > min_end))
				it = W.erase(it);
			else it++;
	}

	return result;
}
*/
int CalculateMaxWorkshops(Available_Workshops* ptr) {
	vector<Workshop> W;
	for (int i = 0; i < ptr->n; i++)
		W.push_back(ptr->Workshops[i]);
	sort(W.begin(), W.end(), CompareWorkshops);
	int result = 0, end_time = 0;
	for (vector<Workshop>::iterator it = W.begin(); it != W.end(); it++)
		if (it->start_time > end_time)
		{
			end_time = it->end_time;
			result++;
		}
	return result;
}

int main(int argc, char *argv[]) {
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;

	getchar();
	getchar();

	return 0;
}
