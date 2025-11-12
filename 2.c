#include<stdio.h>
#include<ctype.h>

#define size 50

char stack[size];
int top=-1;

void push(char elem)
{
    stack[++top]=elem;
}

char pop()
{
    return(stack[top--]);
}

int pt(char sym)
{
    if (sym == '^')
        return 3;
    else if (sym == '*' || sym == '/')
        return 3;
    else if (sym == '+' || sym == '-')
        return 1;
    else
        return 0;
}

void main()
{
    char infix,postfix[size],ch;

    scanf("%s",infix);
    printf("%s",infix);
}
