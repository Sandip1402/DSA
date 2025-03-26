#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_node()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        printf("memory can't be allocated.\n");
    else
    {
        printf("enter value of new node :\n");
        scanf("%d",&p->data);
        p->next = NULL;
        return p;
    }
}
void display(struct node *h)
{
    struct node *i = h;
    printf("elements are :\n");
    while(i != NULL)
    {
        printf("%d ", i->data);
        i = i->next;
    }
    printf("\n");
}
struct node* getMiddle(struct node *head)
{
    struct node *p, *mid;
    int count = -1;
    p = mid = head;
    if (p == NULL)
        return NULL;
    else
    {
        while (p!= NULL)
        {
            if(count % 2 == 0)
            {mid = mid->next;}
            count++;
            p = p->next;
            printf("ok\n");
        }
    }
    printf("middle element is %d", mid->data);
}
int main()
{
    int n;
    struct node *prev, *next, *head = NULL;
    printf("enter number of nodes :\n");
    scanf("%d", &n);
    while (n!=0)
    {
        if(head == NULL)
            prev = head = create_node();
        else
        {
            next = create_node();
            prev->next = next;
            prev = prev->next;
        }
        n--;
    }
    display(head);
    getMiddle(head);
    return 0;
}