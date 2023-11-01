// https://leetcode.com/problems/set-matrix-zeroes/description/

// Using vectors to store the index (i,j) containing 0
// Complextiy Analysis: O(N^2), O(N) 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> rows(n, -1);
        vector<int> cols(m, -1);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(rows[i] == 0 || cols[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

       // return matrix;
    }
};

// Using unordered_set to store index(i,j) containing 0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows; 
        unordered_set<int> cols;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m;j++)
            {
                if(rows.find(i) != rows.end() || cols.find(j) != cols.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }

       // return matrix;
    }
};


// Optimal Approach O(N^2), O(1)
// Using the 1st row and 1st column of the given matrix 
// to keep a track of the cells that need to be marked with 0

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};