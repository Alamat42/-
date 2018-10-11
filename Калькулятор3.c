#include <stdio.h> 
double atoi(char c);
double power(double base, int n);
double func(double m);
double add();
double factor();
char input[2000];
int j=0, k=0;
char op1='+';
int main()
{
    extern int k;
    extern char input[2000], op1;
    char c;
    for(int i=0; i<2000&&(c=getchar())!='\n';++i)
    {
       input[j]=c;
       ++j;
    }
    input[j]='X';
    printf("=%g\nop=%c\n", func(0), op1);
}
double func(double num1)
{
    extern char op1;
    switch (op1)
    {
        case '+':
        {
            num1=num1+add();
            if(op1=='+'||op1=='-')
            {
                return func(num1);
            }
            if(op1=='X')
            {
                return num1;
            }
            break;
        }
        case '-':
        {
            num1=num1-add();
            if(op1=='+'||op1=='-')
            {
                return func(num1);
            }
            if(op1=='X')
            {
                return num1;
            }
            break;
        }
        case 'X':
        {
            return num1;
            break;
        }
        default:
        {
            printf("Ошибочный оператор; num1=%d\n",num1);
        }
    }
    return num1;
}

double add()
{
    extern int k;
    extern char input[2000];
    extern char op1;
    double addendum=factor();
    switch (op1)
    {
        case '+' :
        {
            return addendum;
            break;
        }
        case '-' :
        {
            return addendum;
            break;
        }
        case 'X':
        {
            return addendum;
            break;
        }
        case '*':
        {
            addendum=addendum*factor();
            return addendum;
            break;
        }
        case '/':
        {
            addendum=addendum/factor();
            return addendum;
            break;
        }
        default:
        {
            printf("Ошибочный оператор\n");
            return 0;
            break;
        }
    }
}

double factor()
{
    double number=0;
    int point=0;
    extern int k;
    extern char input[2000];
    extern char op1;
    while (input[k]=='0'||input[k]<='1'||input[k]<='2'||input[k]<='3'||input[k]<='4'||input[k]<='5'||input[k]<='6'||input[k]<='7'||input[k]<='8'||input[k]<='9'||input[k]=='.'||input[k]==',')
    {
        if(input[k]=='0'||input[k]<='1'||input[k]<='2'||input[k]<='3'||input[k]<='4'||input[k]<='5'||input[k]<='6'||input[k]<='7'||input[k]<='8'||input[k]<='9')
        {
            if(point==0)
            {
                number=(number*10+atoi(input[k]));
            }
            else if(point>0)
            {
                number=number+atoi(input[k])*power(0.1,point);
                ++point;
            }
        }
        else
        {
            ++point;
        }
        ++k;
    }
    if (input[k]=='+'||input[k]=='-'||input[k]=='*'||input[k]=='/')
    {
        op1=input[k];
        ++k;
        return number;
    }
    else if (input[k]=='(')
    {
        ++k;
        return func(0);
    }
    else if (input[k]==')')
    {
        ++k;
        return number;
    }
    else if (input[k]=='X')
    {
        op1='X';
        return number;
    }
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
    
    
            
            
    
    
    
    
    
    
            
