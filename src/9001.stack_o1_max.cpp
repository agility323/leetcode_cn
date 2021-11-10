/*
实现一个O(1)时间获取最大元素的Stack
*/

#include "common_include.hpp"

class Solution {
public:
	void push(int val) {
		int m = val;
		if (!st_data.empty()) {
			int last = st_max.back();
			if (last > m) m = last;
		}
		st_data.push_back(val);
		st_max.push_back(m);
	}

	void pop() {
		if (st_data.empty()) return;
		st_data.pop_back();
		st_max.pop_back();
		return;
	}

	int max() {
		if (st_data.empty()) return 0;
		return st_max.back();
	}

	void clear() {
		st_data.clear();
		st_max.clear();
	}

	void print() {
		cout << "\t[";
		print_ivec(st_data);
		cout << "] - " << max() << endl;
	}

private:
	vector<int> st_data;
	vector<int> st_max;
};

struct TestCase {
	vector<int> *pnums;
};

TestCase g_test_cases[] = {
	TestCase{new vector<int>{9, 2, 7, 11, 15}},
};

int main() {
	Solution sol;
	for (int i = 0; i < sizeof(g_test_cases) / sizeof(TestCase); ++i) {
		cout << "case " << i + 1 << " [";
		print_ivec(*g_test_cases[i].pnums);
		cout << "]:" << endl;
		for (const int val : *g_test_cases[i].pnums) {
			sol.push(val);
			sol.print();
		}
		for (size_t j = 0; j < g_test_cases[i].pnums->size(); ++j) {
			sol.pop();
			sol.print();
		}
		sol.clear();
	}
	return 0;
}
