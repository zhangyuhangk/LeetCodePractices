#include "Q241_Different_Ways_to_Add_Parentheses.h"
#include "common.h"

class Solution {
public:
	vector<int> diffWaysToCompute(const string& input) {
		vector<int> numbers;
		vector<char> operators;
		parseInput(input, numbers, operators);
		return calculate(numbers, 0, (int)numbers.size() - 1, operators, 0, (int)operators.size() - 1);
	}

	vector<int> calculate(const vector<int>& numbers, int nL, int nU, const vector<char>& operators, int oL, int oU) {
		vector<int> result;
		if (nL > nU) {
			return result;
		}
		if (nL == nU) {
			result.push_back(numbers[nL]);
			return result;
		}
		for (int i = oL; i <= oU; ++i) {
			auto v1 = calculate(numbers, nL, i, operators, oL, i - 1);
			auto v2 = calculate(numbers, i + 1, nU, operators, i + 1, oU);
			auto v = calculate(v1, operators[i], v2);
			result.insert(result.end(), v.begin(), v.end());
		}
		return result;
	}

	vector<int> calculate(const vector<int>& v1, char op, const vector<int>& v2) {
		vector<int> results;
		results.reserve(v1.size() * v2.size());
		for (int a : v1) {
			for (int b : v2) {
				results.push_back(calculate(a, op, b));
			}
		}
		return results;
	}

	int calculate(int a, char op, int b) {
		switch (op) {
		case '+':	return a + b;
		case '-':	return a - b;
		case '*':	return a * b;
		default:
			_ASSERT(false);
			return 0;
		}
	}

	void parseInput(const string& input, vector<int>& numbers, vector<char>& operators) {
		istringstream ss(input);
		int n = 0;
		char op = ' ';
		while (ss >> n) {
			numbers.push_back(n);
			if (!(ss >> op)) {
				break;
			}
			if (!isValidOperator(op)) {
				throw new exception((string("invalid operator: ") + op).c_str());
			}
			operators.push_back(op);
		}
		_ASSERT(numbers.size() == operators.size() + 1);
	}

	bool isValidOperator(char op) {
		return op == '+' || op == '-' || op == '*';
	}
};


void Q241_Different_Ways_to_Add_Parentheses() {
	string s;
	while (getline(cin, s)) {
		if (s.empty()) {
			break;
		}
		Solution solution;
		auto v = solution.diffWaysToCompute(s);
		for (auto i : v) {
			cout << i << endl;
		}
	}
}
