/*

*/

#include "common_include.hpp"

class Solution {
public:
	int kth_partition(vector<int> nums, int k) {
		int size = nums.size();
		if (size == 0 || k >= size) return 0;
		int idx = rand() % size;
		swap(nums[0], nums[idx]);
		int head = 0, tail = size - 1;
		while (head < tail) {
			int i = partition(nums, head, tail);
			if (i == k) return nums[i];
			if (i > k) {
				tail = i;
			} else {
				head = i;
			}
		}
		return nums[tail];
	}
	int partition(vector<int> &nums, int head, int tail) {
		int i = head;
		while (head < tail) {
			for (; tail > i && nums[tail] >= nums[i]; tail--) {
			}
			if (tail > i) {
				swap(nums[i], nums[tail]);
				i = tail;
			}
			for (; head < i && nums[head] <= nums[i]; head++) {
			}
			if (head < i) {
				swap(nums[head], nums[i]);
				i = head;
			}
		}
		return i;
	}

	int kth_heap(vector<int> nums, int k) {
		return 0;
	}
};

struct TestCase {
	vector<int> *pnums;
	int k;
	int target;
};

TestCase g_test_cases[] = {
};

int main() {
	srand(time(nullptr));

	return 0;
}
