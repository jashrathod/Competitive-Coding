// atoi - convert string to int 

int atoi(string str)
{
    int x = 0, y, j=0;
    if(str[0] == '-')  
    {
        y = -1;
        j=1;
    }
    else  y = 1;
    for(int i=j; str[i]!='\0'; i++)
    {
        if(str[i] - 48 > 9)
            return -1;
        else  x = 10*x + (str[i]-48);
    }
    return x*y;
}