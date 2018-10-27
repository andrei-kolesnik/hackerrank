//https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
//Sample Input:
//3 1
//set 1 2
//get 1
//get 2
//
//Sample Output:
//2
//- 1

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {
protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};
/* Enter your code here. */
class LRUCache : virtual public Cache {
public:
	LRUCache(int k) { 
		cp = k; 
		head = tail = NULL;
	}
	virtual void set(int key, int value) {
		if (!mp.size()) //empty queue
		{
			head = tail = new Node(key, value);
			mp.insert(pair<int, Node*>(key, head));
			return;
		}
		Node* p;
		auto it = mp.find(key);
		if (it != mp.end()) // in the queue
		{
			p = it->second;
			p->value = value;
			if (p == head) return; // already #1, nothing else to do
			//let's move p to #1
			p->prev->next = p->next;
			if (p == tail) tail = p->prev;
			p->next = head;
			p->prev = NULL;
			head->prev = p;
			head = p;
			return;
		}
		// not in the queue, let's add to #1
		p = new Node(NULL, head, key, value);
		mp.insert(pair<int, Node*>(key, p));
		head->prev = p;
		head = p;
		if (mp.size() <= (size_t)cp)
			return; //still have room to grow
		//need to drop the tail
		p = tail;
		mp.erase(tail->key);
		if (tail->prev) tail->prev->next = NULL;
		tail = tail->prev;
		delete p;
	}
	virtual int get(int key) {
		auto it = mp.find(key);
		if (it != mp.end()) // in the queue
			return it->second->value;
		return -1;
	}
};
/* End of your code. */

int main() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
	return 0;
}
