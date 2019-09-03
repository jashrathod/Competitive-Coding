// Count Sort

void countSort(char arr[])
{
    int n=0;
    for(int i=0; arr[i]!='\0'; i++)
    {
        n++;
    }
    int v[26] = { 0 };
    for(int i=0; i<n; i++)
    {
        v[arr[i] - 'a']++;
    }
    for(int i=1; i<26; i++)
    {
        v[i] = v[i] + v[i-1];
    }
    char ans[n];
    for(int i=0; i<n; i++)
    {
        ans[v[arr[i] - 'a'] - 1] = arr[i];
        v[arr[i] - 'a']--;
    }
    for(int i=0; i<n; i++)
    { 
        arr[i] = ans[i];
    }
}