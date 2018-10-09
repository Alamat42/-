#include <stdio.h>
float atoi(char c);
float power(float base, int n);
int main()
{
    float answer;
    float num[50];
    int point=0;
    int j=0, k=0;
    char op[50];
    char c;
    for(int v=0;v<50;++v)
    {
        num[v]=0;
    }
    for(int i=0;(c=getchar())!='\n'; ++i)
    {
        if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0'||c=='.'||c==',')
        {
            if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0')
            {
                if(point>0)
                {
                    ++point;
                }
                num[j]=(num[j]*10+atoi(c))*power(0.1,point);
            }
            else
            {
                ++point;
            }
        }
        else 
        {
            if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
            {
                op[k]=c;
                ++j;
                ++k;
            }
        }
    }
    answer=num[0];
    for(int a=0;a<k;++a)
    {
        switch(op[a])
        {
            case '+':
            {
                answer=answer+num[a+1];
                break;
            }
            case '-':
            {
                answer=answer-num[a+1];
                break;
            }
            case '*':
            {
                answer=answer*num[a+1];
                break;
            }
            case '/':
            {
                answer=answer/num[a+1];
                break;
            }
            case '^':
            {
                answer=power(answer,num[a+1]);
                break;
            }
            default:
            {
                printf("Ошибочный оператор");
                break;
            }
        }
    }
    printf("=%g\n", answer);            
}




float atoi(char c)
{
    if(c<48||c>57)
    {
        return 0;
    }
    else
    {
    float p=c-48;
    return p;
    }
}

float power(float base, int n)
{
    float p=1;
    for(int i=0; i<n; ++i)
    {
        p=p*base;
    }
    return p;
}
