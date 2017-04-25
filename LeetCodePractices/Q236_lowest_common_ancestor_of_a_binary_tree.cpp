#include "Q236_lowest_common_ancestor_of_a_binary_tree.h"
#include "common.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		list<TreeNode*> chainP;
		list<TreeNode*> chainQ;
		track(root, p, chainP);
		track(root, q, chainQ);
		auto itrP = chainP.begin();
		auto itrQ = chainQ.begin();
		auto result = root;
		while (itrP != chainP.end() && itrQ != chainQ.end() && *itrP == *itrQ) {
			result = *itrP;
			++itrP;
			++itrQ;
		}
		return result;
	}

	bool track(TreeNode* root, TreeNode* t, list<TreeNode*>& chain) {
		if (root == nullptr) {
			return false;
		}
		chain.push_back(root);
		if (root == t) {
			return true;
		}
		if (track(root->left, t, chain) || track(root->right, t, chain)) {
			return true;
		}
		chain.pop_back();
		return false;
	}
};

static void setChildren(TreeNode* node, int leftValue, int rightValue) {
	node->left = new TreeNode(leftValue);
	node->right = new TreeNode(rightValue);
}

/*
         _______3______
        /              \
    ___5__           ___1__
   /      \         /      \
   6       2        0       8
          /  \
         7    4
*/

static TreeNode* buildTree() {
	auto root = new TreeNode(3);
	setChildren(root, 5, 1);
	setChildren(root->left, 6, 2);
	setChildren(root->right, 0, 8);
	setChildren(root->left->right, 7, 4);
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

void Q236_lowest_common_ancestor_of_a_binary_tree() {
	auto tree = buildTree();
	test(tree, 6, 4, 5);
	test(tree, 5, 4, 5);
	test(tree, 7, 8, 3);
	deleteTree(tree);
}
