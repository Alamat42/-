#include <stdio.h>
int atoi(char c);
int power(int base, int n);
int main()
{
    int i, c, number1=0, number2=0, answer;
    int switch1=1; //1 - первое число, 2 - второе число
    char op;
    for(i=0;(c=getchar())!='\n'; ++i)
    {
        if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0')
        {
            if(switch1==1)
            {
                number1=(number1*10)+atoi(c);
            }
            else
            {
                number2=number2*10+atoi(c);
            }
        }
        else 
        {
            switch1=2;
            if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
            {
                op=c;
            }
        }
    }
    if(op=='+')
    {
        answer=number1+number2;
    }
    else if(op=='-')
    {
        answer=number1-number2;
    }
    else if(op=='*')
    {
        answer=number1*number2;
    }
    else if(op=='/')
    {
        answer=number1/number2;
    }
    else if(op=='^')
    {
        answer=power(number1,number2);
    }
        printf("%d%c%d=%d\n", number1, op, number2, answer);
}

int atoi(char c)
{
    if(c<48||c>57)
    {
        return 0;
    }
    else
    {
    int p=c-48;
    return p;
    }
}

int power(int base, int n)
{
    int p=1;
    for(int i=0; i<n; ++i)
    {
        p=p*base;
    }
    return p;
}
