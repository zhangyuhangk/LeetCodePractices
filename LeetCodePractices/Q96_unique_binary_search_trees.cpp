#include "Q96_unique_binary_search_trees.h"
#include "common.h"

class Solution {
public:
	int numTrees(int n) {
		auto x = new int[n + 1];
		memset(x, 0, (n + 1) * sizeof(int));
		x[0] = x[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int k = 1; k <= i; ++k) {
				x[i] += x[k - 1] * x[i - k];
			}
		}
		int r = x[n];
		delete[] x;
		return r;
	}
};

static void test(int n, int expectedResult) {
	Solution s;
	int result = s.numTrees(n);
	if (result != expectedResult) {
		cout << "Failed: " << result << ", expected " << expectedResult << endl;
		return;
	}
	cout << "OK" << endl;
}

void Q96_unique_binary_search_trees() {
	test(3, 5);
}
