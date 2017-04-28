#pragma once

#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <iostream>
#include <functional>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>

#undef max
#undef min

using namespace std;

static const int maxInt = numeric_limits<int>::max();
static const int minInt = numeric_limits<int>::min();

ostream& operator << (ostream& s, const vector<int>& v);

int randomInt(int l, int u);
vector<int> generateRandomNumbers(size_t count, int from, int to);
vector<int> generateRandomNumbers(size_t count);
vector<int> generateSequenceNumbers(size_t count, int base = 0);
vector<int> generateDescendingSequenceNumbers(size_t count);
vector<int> generateDescendingSequenceNumbers(size_t count, int base);
vector<int> stlSorted(const vector<int>& data);
int ceilDivide(int a, int b);

template<typename T>
static void judge(T result, T expectedResult, function<string(T v)> convert = nullptr) {
	if (result != expectedResult) {
		cout << "Failed" << endl;
		cout << "\tresult: ";
		if (convert != nullptr) {
			cout << convert(result) << endl;
		}
		else {
			cout << result << endl;
		}
		cout << "\texpect: ";
		if (convert != nullptr) {
			cout << convert(expectedResult) << endl;
		}
		else {
			cout << expectedResult << endl;
		}
		return;
	}
	cout << "OK" << endl;
}

// static void judge(bool result, bool expectedResult) {
// 	judge(result ? 1 : 0, expectedResult ? 1 : 0, [](int v) { return string(v == 1 ? "true" : "false"); });
// }