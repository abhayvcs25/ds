#include<stdio.h>
#include<ctype.h>

#define size 20

char stack[size];
int top = -1;

void push(char elem)
{
    stack[++top]= elem;
}

int pop()
{
    return (stack[top--]);
}

int pr(char ch)
{
    if (ch == '^')
        return 3;
    else if ( ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void main()
{
    char infix[size],postfix[size],ch,elem;
    int i=0 ,k =0;

    printf("Enter expression = ");
    gets(infix);
    push('#');

    while((ch=infix[i++]) != '\0')
    {
        if (ch == '(') push(ch);
        else
        {
            if (isalnum(ch))
                postfix[k++]=ch;
            else
            {
                if(ch == ')')
                {
                    while (stack[top] != '(')
                        postfix[k++] = pop();
                    elem=pop();
                }
                else
                {
                    while(pr(stack[top])>=pr(ch))
                        postfix[k++] = pop();
                    push(ch);
                }
            }
        }
    }

    while(stack[top] != '#')
        postfix[k++] = pop();

    printf("The expression is = %s",postfix);
}
