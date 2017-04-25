#include "common.h"

ostream& operator<<(ostream& s, const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		s << (i == 0 ? "" : ", ") << v[i];
	}
	return s;
}

int randomInt(int l, int u) {
	return rand() % (u - l + 1) + l;
}

vector<int> generateRandomNumbers(size_t count, int from, int to) {
	vector<int> numbers;
	numbers.reserve(count);
	for (size_t i = 0; i < count; ++i) {
		int n = (rand() % (to - from)) + from;
		numbers.push_back(n);
	}
	return numbers;
}

vector<int> generateRandomNumbers(size_t count) {
	return generateRandomNumbers(count, 1, (int)count);
}

vector<int> generateSequenceNumbers(size_t count, int base) {
	vector<int> numbers;
	numbers.reserve(count);
	for (size_t i = 0; i < count; ++i) {
		numbers.push_back(int(i + base));
	}
	return numbers;
}

vector<int> generateDescendingSequenceNumbers(size_t count) {
	return generateDescendingSequenceNumbers(count, (int)count - 1);
}

vector<int> generateDescendingSequenceNumbers(size_t count, int base) {
	vector<int> numbers;
	numbers.reserve(count);
	for (size_t i = 0; i < count; ++i) {
		numbers.push_back(base - int(i));
	}
	return numbers;
}

vector<int> stlSorted(const vector<int>& data) {
	auto result = data;
	sort(result.begin(), result.end());
	return result;
}

int ceilDivide(int a, int b) {
	return int(ceil(double(a) / b));
}
