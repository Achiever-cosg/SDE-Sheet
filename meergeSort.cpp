// Sort an array

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid+1;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else   
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // re-assiging the values from temp to original array

    for(int i=low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void MergeSort(vector<int>& arr, int low, int high)
{
    // base condition
    if(low >= high)
        return;

    // split
    int mid = low + (high - low)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);

    // merge
    merge(arr, low, mid, high);
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    MergeSort(arr, 0, n-1);
    for(int x: arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

/* 
  Complexity Analysis: O(NlogN)              in all cases
  Splitting the array into half each time until number of elements becomes 1 takes O(logN) time.
  And, merging two sorted arrays take O(N) time.
  Therefore, in all cases, the time taken for merging is always O(NlogN).
*/
