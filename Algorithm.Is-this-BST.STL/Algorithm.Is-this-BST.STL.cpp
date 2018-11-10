/*
https://www.hackerrank.com/challenges/is-binary-search-tree/problem
Sample Input 0:
     3
  5    2
 1 4  6
Sample Output 0:
No
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
	Node(int d, Node* l, Node* r) {
		data = d;
		left = l;
		right = r;
	}
};

class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}

	void print(Node *root, string ident = "") {
		if (!root) return;
		cout << ident << root->data << endl;
		print(root->left, ident + "  L:");
		print(root->right, ident + "  R:");
	}


	// Write your code here...
	void BSTtoVec(Node* root, vector<int> &Vec)
	{
		if (!root) return;
		BSTtoVec(root->left, Vec);
		Vec.push_back(root->data);
		BSTtoVec(root->right, Vec);
	}

	bool checkBST(Node *root) {
		vector<int> Nodes;
		BSTtoVec(root, Nodes);
		int nmin = INT32_MIN;
		for (auto n : Nodes)
			if (n <= nmin)
				return false;
			else
				nmin = n;
		return true;
	}
	// End of your code
};

int main() {

	Solution myTree;
	Node* root = NULL;

	root = myTree.insert(root, 3);
	root->left = myTree.insert(root->left, 5);
	root->left->left = myTree.insert(root->left->left, 1);
	root->left->right = myTree.insert(root->left->right, 4);
	root->right = myTree.insert(root->right, 2);
	root->left = myTree.insert(root->left, 6);

	myTree.print(root);

	cout << boolalpha;
	cout << myTree.checkBST(root);

	system("pause");
	return 0;
}
