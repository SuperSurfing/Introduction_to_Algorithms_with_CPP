// MaxSubarray_Stock.cpp
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int maxAccross(vector<int>& A, int lo, int mi, int hi) {
		int maxLeft = A[mi];
		int sum = A[mi];
		for (int i = mi - 1; i >= lo; --i) {
			sum += A[i];
			if (sum > maxLeft)
				maxLeft = sum;
		}

		int maxRight = A[mi];
		sum = A[mi];
		for (int j = mi + 1; j <= hi; ++j) {
			sum += A[j];
			if (sum > maxRight)
				maxRight = sum;
		}

		return maxLeft + maxRight - A[mi];
	}

	int maxSubArrayCore(vector<int>& A, int lo, int hi) {
		int len = hi - lo + 1;

		if (len < 2) // base case
			return A[lo];

		// Divide 
		int mi = (hi + lo) >> 1;
		int maxLeft = maxSubArrayCore(A, lo, mi);
		int maxRight = maxSubArrayCore(A, mi + 1, hi);
		int maxMiddle = maxAccross(A, lo, mi, hi);

		// Merge
		return max(max(maxLeft, maxRight), maxMiddle);
	}

	int maxSubArray(vector<int>& nums) {
		int len = nums.size();

		if (len < 2) // base case
			return nums[0];

		return maxSubArrayCore(nums, 0, len-1);
	}
};

void printArray(vector<int>& nums)
{
	cout << "The array is:" << endl;
	for (auto n : nums)
		cout << n << '\n';

	cout << endl;
}

// Advanced Solution with DP
class SolutionDP {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            throw "input array is empty";
        
        int n = nums.size();
        int nCurrSum = nums[0];
        int max = nCurrSum;
        
        for (int i = 1; i < n; ++i) {
            nCurrSum = nCurrSum > 0 ? nCurrSum + nums[i] : nums[i];
            
            if (nCurrSum > max)
                max = nCurrSum;
        }
        
        return max;
    }
};


int main()
{
	Solution s;
	vector<int> A = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	cout << s.maxSubArray(A) << endl;
	//int mi = (4 + 0) >> 1;
	//cout << mi << endl;
    std::cout << "Hello World!\n"; 
}
