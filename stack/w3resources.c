#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int size;
    int top;
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
// question 1,3
void push(stack *s)
{
    if (!isfull(s))
    {
        s->top++;
        printf("enter value to push :\n");
        scanf("%d", &s->a[s->top]);
    }
    else
    {
        printf("stack is full\n");
        return;
    }
}
void pop(stack *s)
{
    if (!isempty(s))
    {
        int a = s->a[s->top];
        s->top--;
    }
    else
    {
        printf("stack is empty!\n");
        return;
    }
}
// question 15
// remove smallest element from stack
void remove_smallest(stack *s)
{
    int m, min;
    m = min = s->top;
    while (m >= 0)
    {
        if (s->a[m] <= s->a[min])
            min = m;
        m--;
    }
    printf("minimum is %d.\n", s->a[min]);
    if (min == s->top)
    {
        pop(s);
    }
    else
    {
        m = min;
        while (m < s->top)
        {
            s->a[m] = s->a[m + 1];
            m++;
        }
        pop(s);
    }
}
void display(stack *s)
{
    int i = 0;
    while (i <= s->top)
    {
        printf("%d ", s->a[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    int n;
    stack *s = (stack *)malloc(sizeof(stack));
    printf("size of stack :\n");
    scanf("%d", s->size);
    s->top = -1;
    s->a = (int *)malloc(s->size * sizeof(int));
    printf("enter no. of elements :\n");
    scanf("%d", &n);
    while(n--)
    {
        push(s);
    }
    display(s);
    remove_smallest(s);
    display(s);
    free(s);
}