// LRU CACHE

/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */

// Code 1

int n;
unordered_map<int, int> m;
queue <int> q;

LRUCache::LRUCache(int N)
{
    n = N;     
}

void LRUCache::set(int x, int y) 
{
    int f=0;
    if(m[x] != NULL)
    {
        for(int i=0; i<n; i++)
        {
            if(q.front() == x && f == 0)  
            {
                q.pop();
                f=1; 
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        if(f == 1)  q.push(x);
    }
    else
    {
        if(q.size() == n)  q.pop();
        q.push(x);
    }
    m[x] = y;
}

int LRUCache::get(int x)
{
    for(int i=0; i<n; i++)
    {
        if(q.front() == x)  
        {
            q.pop();
            q.push(x);
            return m[x];
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return -1;
}


// Code 2

int n, l;
queue<int> q;
unordered_map<int, int> m;

LRUCache::LRUCache(int N)
{
    n = N;
    l = 0;
}

void LRUCache::set(int x, int y) 
{
    int f = 0;
    if(m[x] != NULL)
    {
        for(int i=0; i<l; i++)
        {
            if(x == q.front())
            {
                m[x] = y;
                q.pop();
                f = 1;
            }
            else
            {
                int t = q.front();
                q.pop();
                q.push(t);
            }
        }
        if(f == 1)  q.push(x);
    }
    else
    {
        if(l < n)
        {
            q.push(x);
            l++;
            m[x] = y;
        }
        else
        {
            m.erase(q.front());
            // cout<<"m: "<<m[q.front()]<<"  ";
            q.pop();
            q.push(x);
            m[x] = y;
        }
    }
}

int LRUCache::get(int x)
{
    if(m[x] != NULL)
    {
        for(int i=0; i<l; i++)
        {
            if(x != q.front())
            {
                q.push(q.front());
            }
            q.pop();
        }
        q.push(x);
        return m[x];
    }
    else
    {
        return -1;
    }
}
