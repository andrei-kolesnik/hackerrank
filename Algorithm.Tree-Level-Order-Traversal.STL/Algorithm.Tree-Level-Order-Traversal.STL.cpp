/*
Tree: Level Order Traversal
https://www.hackerrank.com/challenges/tree-level-order-traversal

Input:
	 1
	  \
	   2
		\
		 5
		/  \
	   3    6
		\
		 4

Output:
1 2 5 3 6 4
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

	int height(Node* root) {
		if (!root) return 0;
		return max(height(root->left), height(root->right)) + 1;
	}

	void printLevel(Node* root, int level) {
		if (!root) return;
		if (level == 1)
			cout << root->data << " ";
		else {
			printLevel(root->left, level - 1);
			printLevel(root->right, level - 1);
		}
	}

	void levelOrder(Node* root) {
		for (int i = 1; i <= height(root); i++)
			printLevel(root, i);
	}

}; //End of Solution

void check(int nums[], int size) {
	Solution myTree;
	Node* root = NULL;
	for (int i = 0; i < size; i++)
		root = myTree.insert(root, nums[i]);
	myTree.levelOrder(root);
}

int main() {
	int arr1[] = { 1, 2, 5, 3, 4, 6 };
	check(arr1, 6);
	system("pause");
	return 0;
}
