// https://www.interviewbit.com/problems/repeat-and-missing-number-array/discussion/p/easy-c-code-tc-o-n/433628/491/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int temp[n+1] = {0};
    
    for(int i=0; i<n; i++)
    {
        temp[A[i]]++;
    }
    
    int missing = -1, duplicate = -1;
    for(int i=1; i<=n; i++)
    {
        if(temp[i] == 0)
            missing = i;
        else if(temp[i] == 2)
            duplicate = i;
    }
    
    return {duplicate, missing};
}
