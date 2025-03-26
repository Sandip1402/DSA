#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int top;
    int size;
    int *a;
} stack;
int isfull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    return 0;
}
int isempty(stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}
void push(stack *s, int n)
{
    if (!isfull(s))
    {
        s->top++;
        s->a[s->top] = n;
    }
    else
        printf("stack is full\n");
}
int pop(stack *s)
{
    int a;
    if (!isempty(s))
    {
        a = s->a[s->top];
        s->top--;
        return a;
    }
    else
        printf("stack is empty!\n");
}
void display(stack *s)
{
    while (!isempty(s))
    {
        printf("%d ", pop(s));
    }
    printf("\n");
}
void convert_binary(stack *s, int n)
{
    if (n == 0)
        push(s, n);
    else
    {
        while (n != 0)
        {
            push(s, n % 2);
            n = n / 2;
        }
    }
}
int main()
{
    int n;
    stack *s = (stack *)malloc(sizeof(stack));
    printf("size of stack :\n");
    scanf("%d", &s->size);
    s->top = -1;
    s->a = (int *)malloc(s->size * sizeof(int));
    printf("enter a number to convert in binary :\n");
    scanf("%d", &n);
    convert_binary(s, n);
    printf("after convertion :\n");
    display(s);
    return 0;
}