/*

*/

#include "common_include.hpp"

class Solution {
private:
	vector<int> arr;
	unordered_map<int, int> idxmap;
public:
	bool add(int val) {
		if (idxmap.find(val) != idxmap.end()) return false;
		int size = arr.size();
		arr.push_back(val);
		idxmap[val] = size;
		return true;
	}
	bool del(int val) {
		if (idxmap.find(val) != idxmap.end()) return false;
		int idx = idxmap[val], tail = arr.size() - 1;
		swap(arr[idx], arr[tail]);
		arr.pop_back();
		idxmap.erase(val);
		idxmap[arr[idx]] = idx;
		return true;
	}
	int random_one() {
		int size = arr.size();
		if (size == 0 ) return 0;
		return arr[rand() % size];
	}
};

struct TestCase {
	vector<int> *pnums;
	int target;
};

TestCase g_test_cases[] = {
	TestCase{new vector<int>{1, 3, 4, 3, 9, 1}, 12},
	TestCase{new vector<int>{1, 3, 4, 3, 9, 1}, 8},
	TestCase{new vector<int>{1, 3, 4, 3, 9, 1}, 10},
};

int main() {
	srand(time(nullptr));

	Solution sol;
	/*
	int i = 0;
	for (const TestCase tc : g_test_cases) {
		vector<int> ans = sol.sub_array_sum(*tc.pnums, tc.target);
		cout << "case " << ++i << " [";
		print_ivec(*tc.pnums);
		cout << "]|" << tc.target << ": [";
		print_ivec(ans);
		cout << "]" << endl;
	}
	*/
	return 0;
}
