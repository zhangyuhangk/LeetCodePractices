#include "Q436_Find_Right_Interval.h"
#include "common.h"

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

// class Solution {
// public:
// 	vector<int> findRightInterval(const vector<Interval>& intervals) {
// 		map<int, int> indexes; // <start, index>
// 		for (int i = 0; i < (int)intervals.size(); ++i) {
// 			indexes.insert(make_pair(intervals[i].start, i));
// 		}
// 
// 		vector<int> result;
// 		result.reserve(intervals.size());
// 		for (auto& interval : intervals) {
// 			auto itr = indexes.lower_bound(interval.end);
// 			auto index = (itr != indexes.end() ? itr->second : -1);
// 			result.push_back(index);
// 		}
// 		return result;
// 	}
// };

class Solution {
public:
	vector<int> findRightInterval(const vector<Interval>& intervals) {
		vector<int> indexes(intervals.size(), 0);
		for (size_t i = 0; i < intervals.size(); ++i) {
			indexes[i] = (int)i;
		}
		sort(indexes.begin(), indexes.end(), [&](int a, int b) { return intervals[a].start < intervals[b].start; });

		vector<int> result(indexes.size(), -1);
		for (size_t i = 0; i < indexes.size(); ++i) {
			auto start = i + 1;
			auto end = indexes.size() - 1;
			auto t = intervals[indexes[i]].end;
			while (start <= end) {
				auto mid = (start + end) / 2;
				auto v = intervals[indexes[mid]].start;
				if (v < t) {
					start = mid + 1;
				}
				else if (v > t) {
					end = mid - 1;
				}
				else { // v == t
					start = mid;
					break;
				}
			}

			if (start < indexes.size()) {
				result[indexes[i]] = indexes[start];
			}
		}
		return result;
	}
};

static void test(const vector<Interval>& intervals, const vector<int>& expectedResult) {
	judge(Solution().findRightInterval(intervals), expectedResult);
}

void Q436_Find_Right_Interval() {
	using I = Interval;
	test({ I(3, 4), I(2, 3), I(1, 2) }, { -1, 0, 1 });
	test({ I(1, 2) }, { -1 });
	test({ I(1, 4), I(2, 3), I(3, 4) }, { -1, 2, -1 });
}
