// https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return;

        int low = 0, mid = 0, high = n-1;
        while(mid <= high)
        {
            int x = nums[mid];
            switch(x)
            {
                case 0: swap(nums[low++], nums[mid++]);
                        break;
                case 1: mid++;
                        break;
                case 2: swap(nums[mid], nums[high--]);
                        break;
            }
        }
    }
};