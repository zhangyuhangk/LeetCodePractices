#include "Q473_Matchsticks_to_Square.h"
#include "common.h"

class Solution {
public:
	bool makesquare(const vector<int>& nums) {
		int sum = 0;
		for (int i : nums) {
			sum += i;
		}
		if (sum % 4 != 0) {
			return false;
		}
		int average = sum / 4;
		auto x = nums;
		sort(x.begin(), x.end(), greater<int>());
		for (int i = 0; i < 4; ++i) {
			if (!pickNum(x, 0, average)) {
				return false;
			}
		}
		return true;
	}

	bool pickNum(vector<int>& x, int l, int t) {
		for (int i = l; i < (int)x.size(); ++i) {
			if (x[i] == 0 || x[i] > t) {
				continue;
			}
			if (x[i] == t || i < x.size() -1 && pickNum(x, i + 1, t - x[i])) {
				x[i] = 0;
				return true;
			}
		}
		return false;
	}
};

static void test(const vector<int>& nums, bool expectedResult) {
	judge<bool>(Solution().makesquare(nums), expectedResult, [](bool b) { return string(b ? "true" : "false"); });
}

void Q473_Matchsticks_to_Square() {
	test({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }, true);
	test({ 1, 1, 2, 2, 2 }, true);
	test({ 3, 3, 3, 3, 4 }, false);
	test({}, false);
	test({ 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3 }, true);
}