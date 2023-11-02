// https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 1)
            return {{1}};

        int row = 1;
        ans.push_back({1});
        while(row < numRows)
        {
            vector<int> temp(row+1);
            temp[0] = 1;
            temp[row] = 1;
            for(int i=1; i < row; i++)
            {
                temp[i] = ans[row-1][i-1] + ans[row-1][i];
            }

            ans.push_back(temp);
            row++;
        } 

        return ans;
    }
};

// Second Approach using resize keyword

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        for(int i=0; i<numRows; i++)
        {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;

            for(int j=1; j<=i-1; j++)
            {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }

        return res;
    }
};