#include <stdio.h>
#include "./include/Stack.h"
#include <ctype.h>

void teststack();
void middle2tail();

int main()
{
    // teststack();
    middle2tail();

    return 0;
}

void middle2tail()
{
    char equation[100] = {0};
    int n = read(STDIN_FILENO,equation,sizeof(equation));
    // equation[n-1] = '\0';

    Stack<char> stack;
    Stack<int> ansstack;

    // for(char c : equation)
    // {
    //     printf("c = %c\n",c);
    // }

    for(char c : equation)
    {
        // printf("c = %c\n",c);
        if(isdigit(c))
        {
            printf("%c",c);
        }
        else
        {
            switch (c)
            {
            case '*':
                if(stack.IsEmpty())
                {
                    stack.Push(c);
                }
                else                
                {
                    char temp = stack.Pop();
                    if(temp == '*' || temp == '/')
                    {
                        printf("%c",temp);
                        stack.Push(c);
                    }
                    else
                    {
                        stack.Push(temp);
                        stack.Push(c);
                    }
                }
                break;
            
            case '/':
                if(stack.IsEmpty())
                {
                    stack.Push(c);
                }
                else                
                {
                    char temp = stack.Pop();
                    if(temp == '*' || temp == '/')
                    {
                        printf("%c",temp);
                        stack.Push(c);
                    }
                    else
                    {
                        stack.Push(temp);
                        stack.Push(c);
                    }
                }
                break;

            case '+':
                if(stack.IsEmpty())
                {
                    stack.Push(c);
                }
                else                
                {
                    char temp = stack.Pop();
                    if(temp == '*' || temp == '/')
                    {
                        printf("%c",temp);
                        stack.Push(c);
                    }
                    else if(temp == '+' || temp == '-' || temp == '(')
                    {
                        stack.Push(temp);
                        stack.Push(c);
                    }
                }
                break;
            
            case '-':
                if(stack.IsEmpty())
                {
                    stack.Push(c);
                }
                else                
                {
                    char temp = stack.Pop();
                    if(temp == '*' || temp == '/')
                    {
                        printf("%c",temp);
                        stack.Push(c);
                    }
                    else if(temp == '+' || temp == '-' || temp == '(')
                    {
                        stack.Push(temp);
                        stack.Push(c);
                    }
                }
                break;

            case '(':
                // printf("aaaa\n");
                stack.Push(c);
                break;

            case ')':
                while (!stack.IsEmpty()) {
                    char temp = stack.Pop();
                    if (temp == '(') {
                        break;
                    }
                    printf("%c", temp);
                    // printf("pop:%c\n", temp);
                }
                break;

            default:
                break;
            }
        }
    }

    while(!stack.IsEmpty())
    {
        printf("%c",stack.Pop());
    }

    printf("\n");



}

void teststack()
{
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.Push(6);

    printf("len = %d\n",stack.len());
    int res = stack.Pop();
    printf("top = %d\n",res);

    res = stack.Pop();
    printf("top = %d\n",res);

    res = stack.Pop();
    printf("top = %d\n",res);

    res = stack.Pop();
    printf("top = %d\n",res);

    res = stack.Pop();
    printf("top = %d\n",res);

    res = stack.Pop();
    printf("top = %d\n",res);

    res = stack.Pop();
    printf("top = %d\n",res);

    res = stack.Pop();
    printf("top = %d\n",res);
    
    printf("len = %d\n",stack.len());
}