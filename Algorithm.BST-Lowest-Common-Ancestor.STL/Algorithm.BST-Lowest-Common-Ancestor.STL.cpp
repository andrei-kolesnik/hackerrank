/*
https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
Sample Input 0:
6
4 2 3 1 7 6
1 7

Sample Output 0:
[reference to node 4]


Sample Input 2:
7
5 3 8 2 4 6 7
7 3

Sample Output 2:
[reference to node 5]
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

	Node *lca(Node *root, int v1, int v2) {
// Write your code here...
		int vmin = min(v1, v2);
		int vmax = max(v1, v2);
		if (root->data == vmin || root->data == vmax || (root->data > vmin && root->data < vmax))
			return root;
		if (root->data > vmin)
			return lca(root->left, vmin, vmax);
		else
			return lca(root->right, vmin, vmax);
// End of your code
	}
}; 

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	int v1, v2;
	std::cin >> v1 >> v2;

	myTree.print(root);
	Node *ans = myTree.lca(root, v1, v2);

	std::cout << ans->data;

	return 0;
}
