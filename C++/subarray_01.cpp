// Largest subarray of 0's and 1's

// Recursive 

int fn(int arr[], int i, int j)
{
    if(i == j)  return 0;
    int z=0, o=0;
    for(int k=i; k<=j; k++)
    {
        if(arr[k] == 0)  z++;
        else  o++;
    }
    if(z == o)  return z+o;
    else if(z== 0 || o == 0)  return 0;
    else  return max(fn(arr, i+1, j), fn(arr, i, j-1));
}

int maxLen(int arr[], int n)
{
    return fn(arr, 0, n-1);
}

// Efficient (Similar to Kadane's Algorithm)

int maxLen(int arr[], int n)
{
    unordered_map<int,int> m;
    int sum = 0, ans = INT_MIN;
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == 0)  arr[i] = -1;
    }
            
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        if(sum == 0)  ans = max(ans,i+1);
        if(m.find(sum) != m.end())  ans = max(ans,i-m[sum]);
        else  m[sum] = i;
    }
    if(ans == INT_MIN)  return 0;
    return ans; 
}
