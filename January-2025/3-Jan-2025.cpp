//Leetcode 2270 : https://leetcode.com/problems/number-of-ways-to-split-array/
//T.C : O(n), S.C : O(n)

class Solution {
public:

    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), splits = 0;
        vector<long long>prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for(int i = 0; i < n-1; i++){
            long long leftSum = prefixSum[i];
            long long rightSum = prefixSum[n-1] - prefixSum[i];
            if(leftSum >= rightSum)
                splits++;
        }
        return splits;
    }
};