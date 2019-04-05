#include<iostream>
#include<math.h>
using namespace std;

/*
int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int p1, p2, k, s;
		cin>>p1>>p2>>k;
		s=(p1+p2)/k;
		if(s%2==0)
			cout<<"CHEF";
		else
			cout<<"COOK";
		cout<<endl;
	}
	return 0;
}
*/

int main() {
	long long int t, n; 
	cin>>t;
	for(long long int k=0; k<t; k++)
	{
	   cin>>n;
	   long long int i=2, bi=1, ni=0, by=0;
	   for(long long int j=2; j<n; j+=i)
	   {
	       if(i==2)
	       {
	           i=8; 
	           ni=bi; 
	           bi=by=0;
	       }
	       else if(i==8)
	       { 
	           i=16; 
	           by=ni; 
	           ni=bi=0;
	       }
	       else
	       {
	           i=2; 
	           bi=2*by; 
	           by=ni=0;
	       }
	   }
	   cout<<bi<<" "<<ni<<" "<<by<<endl;
	}
	return 0;
}

/*
int main() {

    int n;
    cin>>n;
    for(int i= 0 ; i<n;i++)
    {
        long time;
        cin>>time;
        long stage = time/26;
        long interStage = time%26;
        if(interStage==0)
        {
            cout<<0<<" "<<0<<" "<<pow(2,stage-1)<<endl;
        }
        else
        {
            if(interStage<=2)
            	cout<<pow(2,stage)<<" "<<0<<" "<<0<<endl;
            else if(interStage<=10)
            	cout<<0<<" "<<pow(2,stage)<<" "<<0<<endl;
            else if(interStage<=25)
            	cout<<0<<" "<<0<<" "<<pow(2,stage)<<endl;
        
        }
    }
	return 0;
}
*/