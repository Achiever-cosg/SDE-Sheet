// 

//    Method-1: Using hashing {O(N), O(N)}

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int x: nums)
        {
            mpp[x]++;
        }
        for(auto it: mpp)
        {
            if(it.second > 1)
                return it.first;
        }
        return -1;
    }
};

// -------------------------------------------------------------------//

// Method-2: Using Linked List Cycle Method {O(N), O(N)}

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
