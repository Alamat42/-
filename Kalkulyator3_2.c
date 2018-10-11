#include <stdio.h> 
double atoi(char c);
double power(double base, int n);
double expr();
double add();
double mul();
char str[2000];
int ind=0;
int main()
{
    int i=0;
    while( (str[i]=getchar())!='\n')
    {
        ++i;
    }
    printf("=%g\n", expr());
}
double expr()
{
    double num=add();
    while(str[ind]=='+'||str[ind]=='-')
    {
        if(str[ind]=='+')
        {
            ind++;
            num=num+add();
        }
        if(str[ind]=='-')
        {
            ind++;
            num=num-add();
        }
    }
    if(str[ind]==')')
    {
        ++ind;
        return num;
    }
    return num;
}

double add()
{
    double num=mul();
    while(str[ind]=='*'||str[ind]=='/')
    {
        if(str[ind]=='*')
        {
            ++ind;
            num=num*mul();
        }
        if(str[ind]=='/')
        {
            ++ind;
            num=num/mul();
        }
        return num;
    }
}

double mul()
{
    int point=0;
    double num=0;
    while ((str[ind]>='0'&&str[ind]<='9')||str[ind]=='.'||str[ind]==',')
    {
        if(str[ind]>='0'&&str[ind]<='9')
        {
            if(point==0)
            {
                num=(num*10+atoi(str[ind]));
            }
            else if(point>0)
            {
                num=num+atoi(str[ind])*power(0.1,point);
                ++point;
            }
        }
        else
        {
            ++point;
        }
        ++ind;
    }
    if(str[ind]=='(')
    {
        ++ind;
        return expr();
    }
    if(str[ind]==')')
    {
        return num;
    }
    return num;
}

double atoi(char c)
{
    if(c<48||c>57)
    {
        return 0;
    }
    else
    {
    double p=c-48;
    return p;
    }
}

double power(double base, int n)
{
    double p=1;
    for(int i=0; i<n; ++i)
    {
        p=p*base;
    }
    return p;
}
        
        
        















