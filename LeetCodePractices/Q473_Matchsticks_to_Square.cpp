#include "Q473_Matchsticks_to_Square.h"
#include "common.h"

class Solution {
public:
	bool makesquare(const vector<int>& nums) {
		return false;
	}
};

static void test(const vector<int>& nums, bool expectedResult) {
	judge(Solution().makesquare(nums), expectedResult, [](bool b) { return string(b ? "true" : "false"); });
}

void Q473_Matchsticks_to_Square() {
	test({ 1, 1, 2, 2, 2 }, true);
	test({ 3, 3, 3, 3, 4 }, false);
}