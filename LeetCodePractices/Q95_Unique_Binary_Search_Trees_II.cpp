#include "Q95_Unique_Binary_Search_Trees_II.h"
#include "common.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n < 1) {
			return vector<TreeNode*>();
		}
		return buildTrees(1, n);
	}

	vector<TreeNode*> buildTrees(int l, int u) {
		vector<TreeNode*> v;
		if (l > u) {
			v.push_back(nullptr);
			return v;
		}
		v.reserve(u - l + 1);
		for (int i = l; i <= u; ++i) {
			auto leftNodes = buildTrees(l, i - 1);
			auto rightNodes = buildTrees(i + 1, u);
			for (auto left : leftNodes) {
				for (auto right : rightNodes) {
					auto node = new TreeNode(i);
					node->left = left;
					node->right = right;
					v.push_back(node);
				}
			}
		}
		return v;
	}

private:
	map<pair<int, int>, vector<TreeNode*>> cache;
};

static void printNode(TreeNode* node, const string& indent) {
	if (node == nullptr) {
		return;
	}
	cout << indent << node->val << endl;
	printNode(node->left, indent + "\t");
	printNode(node->right, indent + "\t");
}

static void deleteTree(TreeNode* node) {
	if (node == nullptr) {
		return;
	}
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

void Q95_Unique_Binary_Search_Trees_II() {
	int n = 0;
	Solution s;
	auto v = s.generateTrees(n);
	cout << n << " -> " << v.size() << " trees" << endl;

	for (auto node : v) {
		printNode(node, "");
		deleteTree(node);
	}
}
