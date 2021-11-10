#include "common_include.hpp"

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> rec;
		for (int i = 0; i < nums.size(); ++i) {
			int complement = target - nums[i];
			if (rec.find(complement) != rec.end()) {
				return vector<int>{i, rec[complement]};
			}
			rec[nums[i]] = i;
		}
		return vector<int>{};
	}
};

struct TestCase {
	vector<int> *pnums;
	int target;
};

TestCase g_test_cases[] = {
	TestCase{new vector<int>{2, 7, 11, 15}, 9},
	TestCase{new vector<int>{2, 7, 11, 15}, 18},
};

int main() {
	Solution sol;
	for (int i = 0; i < sizeof(g_test_cases) / sizeof(TestCase); ++i) {
		vector<int> ans = sol.twoSum(*g_test_cases[i].pnums, g_test_cases[i].target);
		cout << "case " << i + 1 << " [";
		print_ivec(*g_test_cases[i].pnums);
		cout << "]|" << g_test_cases[i].target << ": [";
		print_ivec(ans);
		cout << "]" << endl;
	}
	return 0;
}
/*
case 1 [2,7,11,15,]|9: [1,0,]
case 2 [2,7,11,15,]|18: [2,1,]
*/
