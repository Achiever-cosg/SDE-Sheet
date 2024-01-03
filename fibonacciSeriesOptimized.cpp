
#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 20

int arr[MAX_SIZE];

int fibo(int n, int arr[], int& cnt)
{
    if(n == 0 || n == 1)
        return n;
    
    if(arr[n] != -1)
    {
        cnt++;
        return arr[n];
    }
    
    return arr[n] = fibo(n-1, arr, cnt) + fibo(n-2, arr, cnt);
}

int main()
{
    int n;
    cin>>n;
    arr[0] = 0; 
    arr[1] = 1;
    int cnt = 0;
    for(int i=2; i<MAX_SIZE; i++)
    {
        arr[i] = -1;
    }
    
    int ans = fibo(n, arr, cnt);
    cout<<ans<<endl;
    cout<<"The count is: "<<cnt<<endl;
    cout<<"Contents of the array are: "<<endl;
    for(int i=0; i<=n; i++)
        cout<<arr[i]<<" ";
        
    return 0;
}

// count represents the number of skippeed function calls
