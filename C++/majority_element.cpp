// MAJORITY ELEMENT (more than n/2 times)

#include <iostream>
using namespace std;

int main() {
	int t, n, c;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
	    scanf("%d", &n);
	    int a[n], m=0, pos;
	    for(int j=0; j<n; j++)
	        scanf("%d", &a[j]);
	    for(int j=0; j<n; j++)
	    {
	        int count=0;
	        for(int k=0; k<n; k++)
	        {
	            if(a[j] == a[k])
	                count++;
	            if(count>n/2)  break;
	        }
	        if(m<count)
	        {
	            m=count;
	            pos=j;
	            if(m>n/2)  break;
	        }
	    }
	    if(m>n/2) printf("%d", a[pos]);
	    else printf("%d", -1);
	    printf("\n");
	}
	return 0;
}
