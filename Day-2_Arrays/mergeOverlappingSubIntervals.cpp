// https://leetcode.com/problems/merge-intervals/solutions/ 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int j=0;
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++)
        {
            if(intervals[i][0] > ans[j][1])
            {
                ans.push_back(intervals[i]);
                j++;
            }
            else
                ans[j][1] = max(ans[j][1], intervals[i][1]);
        }

        return ans;
    }
};
