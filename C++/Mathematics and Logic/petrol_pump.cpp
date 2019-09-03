// CIRCULAR PETROL PUMP

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/

int tour(petrolPump p[],int n)
{
   int pos, r=0, a[n];
   for(int i=0; i<n; i++)
   {
       a[i] = p[i].petrol - p[i].distance;
       r = r + a[i];
   }
   if(r<0)  return -1;
   else
   {
       r=0;
       for(int i=0; i<n; i++)
       {
           queue <int> q;
           if(r+a[i] >= 0)
           {
               pos = i;
               for(int j=i; j<n; j++)  q.push(j);
               for(int j=0; j<i; j++)  q.push(j);
               for(int j=0; j<n; j++)
               {
                   r=r+a[q.front()];
                   if(r<0)  break;
                   q.push(q.front());
                   q.pop();
               }
               if(r>=0)  return pos;
           }
           r=0;
       }
   }
}
