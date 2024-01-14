#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <math.h>
#include <time.h>

using namespace std;

void print_ivec(const vector<int> &v) {
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
//	for(const auto &i : v) { cout << i << ","; }
}

