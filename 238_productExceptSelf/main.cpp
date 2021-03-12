#include "stdio.h"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "algorithm"
#include "string"
#include "queue"
#include "stack"


using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> result;
		result.resize(nums.size());

		if (nums.size() == 0) return vector<int>();
		if (nums.size() == 1) {
			result[0] = 0;
			return result;
		};


		unsigned int mul = 1;
		vector<int> prefix, tail;

		prefix.resize(nums.size());
		tail.resize(nums.size());

		for (int i = 0; i < nums.size(); i++) {
			mul *= nums[i];
			prefix[i] = (mul);
		}

		mul = 1;

		for (int i = nums.size() - 1; i >= 0; i--) {
			mul *= nums[i];
			tail[i] = (mul);
		}

		result.resize(nums.size());

		for (auto i = 0; i < nums.size(); i++) {

			if (i == 0) {
				result[i] = tail[i + 1];
			}
			else if (i == nums.size() - 1) {
				result[i] = prefix[i - 1];
			}
			else {
				result[i] = prefix[i - 1] * tail[i + 1];
			}
		}

		return result;
	}
};