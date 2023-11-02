// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int maxi = INT_MIN;
        int curr_sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            curr_sum += nums[i];
            curr_sum = max(curr_sum, nums[i]);

            maxi = max(maxi, curr_sum);
        }

        return maxi;
    }
};