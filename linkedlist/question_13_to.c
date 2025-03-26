#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_node(int n)
{
    struct node *h, *prev, *current;
    int i = 1;
    h = (struct node *)malloc(sizeof(struct node));
    if (h == NULL)
        printf("memeory can't be allocated\n");
    while (i <= n)
    {
        if (i == 1)
        {
            printf("enter value for node %d-\n", i);
            scanf("%d", &h->data);
            h->next = NULL;
            prev = h;
        }
        else
        {
            current = (struct node *)malloc(sizeof(struct node));
            printf("enter value for node %d-\n", i);
            scanf("%d", &current->data);
            current->next = NULL;
            prev->next = current;
            prev = current;
        }
        i++;
    }
    return h;
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
struct node* merge_list(struct node *h1, struct node *h2)
{
    struct node* p;
    struct node* p1 = h1;
    struct node* p2 = h2;
    struct node* start = p;
    while((p1 != NULL) || (p2 != NULL))
    {
        if(p1->data < p2->data)
        {printf("1\n");
            p->next = p1;
            p1 = p1->next;}    
        else if(p2->data < p1->data)
        {printf("2\n");
            p->next = p2;
            p2 = p2->next;}
        else if(h1 == NULL)
        {printf("3\n");
            p->next = p2;
            p2 = p2->next;
        }
        else if(p2 == NULL)
        {printf("4\n");
            p->next = p1;
            p1 = p1->next;
        }        
        p = p->next;
    }
    printf("5\n");
    return start;
}
int main()
{
    struct node *h1, *h2, *h3;
    int n1, n2;
    printf("enter a sorted list :\n");
    printf("enter no. of nodes :\n");
    scanf("%d", &n1);
    h1 = create_node(n1);
    printf("enter another sorted list :\n");
    printf("enter no. of nodes :\n");
    scanf("%d", &n2);
    h2 = create_node(n2);
    h3 = merge_list(h1,h2);
    display(h1);
    display(h2);
    display(h3);
    return 0;
}