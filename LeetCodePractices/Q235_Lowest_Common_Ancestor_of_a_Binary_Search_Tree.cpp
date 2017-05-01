#include "Q235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree.h"
#include "common.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while ((root->val - p->val) * (root->val - q->val) > 0) { // p and q are at the same side
			root = (p->val < root->val ? root->left : root->right);
		}
		return root;
	}
};

static void setChildren(TreeNode* node, int leftValue, int rightValue) {
	node->left = new TreeNode(leftValue);
	node->right = new TreeNode(rightValue);
}

/*
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
*/

static TreeNode* buildTree() {
	auto root = new TreeNode(6);
	setChildren(root, 2, 8);
	setChildren(root->left, 0, 4);
	setChildren(root->right, 7, 9);
	setChildren(root->left->right, 3, 5);
	return root;
}

static void deleteTree(TreeNode* node) {
	if (node == nullptr) {
		return;
	}
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

static TreeNode* findNode(TreeNode* root, int value) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->val == value) {
		return root;
	}
	auto r = findNode(root->left, value);
	if (r != nullptr) {
		return r;
	}
	return findNode(root->right, value);
}

static void test(TreeNode* root, int a, int b, int expectedResult) {
	auto p = findNode(root, a);
	auto q = findNode(root, b);
	_ASSERT(p != nullptr && q != nullptr);

	Solution solution;
	auto node = solution.lowestCommonAncestor(root, p, q);
	if (node == nullptr) {
		cout << "Failed: null result" << endl;
		return;
	}
	if (node->val != expectedResult) {
		cout << "Failed: wrong result " << node->val << ", expected " << expectedResult << endl;
		return;
	}
	cout << "OK" << endl;
}

void Q235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree() {
	auto tree = buildTree();
	test(tree, 2, 8, 6);
	test(tree, 2, 4, 2);
	test(tree, 5, 7, 6);
	deleteTree(tree);
}