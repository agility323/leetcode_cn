/*
给定1个正整数数组array和1个正整数n，从array中寻找和值大于等于n的最短子数组。
如果存在，则返回最短子数组长度；如果不存在返回0。
例如：array = 1, 3, 4, 3, 9, 1, n = 12,
那么子数组3, 9满足条件且长度最短为2
*/

#include "common_include.hpp"

class Solution {
public:
	vector<int> sub_array_sum(const vector<int> &nums, int target) {
		int i = 0, j = 0;
		int size = nums.size();
		int indice[2] = {0, size};
		int s = nums[0];
		while (true) {
			if (s >= target) {
				if (i + 1 > j) return vector<int>(nums.begin() + i, nums.begin() + j + 1);
				if (j - i < indice[1] - indice[0]) {
					indice[0] = i;
					indice[1] = j;
				}
				s -= nums[i++];
			} else {
				if (++j >= size) break;
				s += nums[j];
			}
		}
		return vector<int>(nums.begin() + indice[0], nums.begin() + indice[1] + 1);
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
	Solution sol;
	int i = 0;
	for (const TestCase tc : g_test_cases) {
		vector<int> ans = sol.sub_array_sum(*tc.pnums, tc.target);
		cout << "case " << ++i << " [";
		print_ivec(*tc.pnums);
		cout << "]|" << tc.target << ": [";
		print_ivec(ans);
		cout << "]" << endl;
	}
	return 0;
}
