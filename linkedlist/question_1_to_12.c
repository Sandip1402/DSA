#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node *next;
};
struct node *create_node(int val, struct node *prev)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        printf("memory can't be allocated.\n");
    p->data = val;
    prev->next = p;
    p->next = NULL;
    return p;
}
struct node *reverse_list(struct node *head)
{
    struct node *prev, *curr;
    // converting first node at last
    if (head != NULL)
        prev = head;
    curr = head->next;
    head = head->next;
    prev->next = NULL;
    while (head != NULL)
    {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
        printf("DONE\n");
    }
    head = prev;
    return head;
}
void ll_traversal(struct node *head)
{
    struct node *i = head;
    while (i != NULL)
    {
        printf("NODE value : %d\n", i->data);
        i = i->next;
    }
}
int count_node(struct node *head)
{
    struct node *i = head;
    int count = 0;
    while (i != NULL)
    {
        count++;
        i = i->next;
    }
    return count;
}
struct node *insert_first(struct node *head, int val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->next = head;
    head = p;
    return head;
}
struct node *insert_end(struct node *head, int val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *i;
    i = head;
    while (i->next != NULL)
    {
        i = i->next;
    }
    p->data = val;
    i->next = p;
    p->next = NULL;
    return head;
}
struct node *insert_position(struct node *head, int val, int pos)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *i;
    i = head;
    while (pos > 2)
    {
        i = i->next;
        pos--;
    }
    p->data = val;
    p->next = i->next;
    i->next = p;
    return head;
}
struct node *delete_first(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}
struct node *delete_last(struct node *head)
{
    struct node *p = head;
    struct node *q;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
    return head;
}
struct node *delete_position(struct node *head, int pos)
{
    struct node *p = head;
    struct node *q;
    while (pos > 1)
    {
        q = p;
        p = p->next;
        pos--;
    }
    q->next = p->next;
    free(p);
    return head;
}
char *convert_list_string(struct node *head, int n)
{
    struct node *p = head;
    char *st = (char *)malloc(n * sizeof(char));
    int i = 0;
    while (p != NULL)
    {
        sprintf(st + i, "%d ", p->data);
        p = p->next;
        i += strlen(st + i);
    }
    return st;
}
int* convert_list_array(struct node *head, int n)
{
    struct node *p = head;
    int *a = (int *)malloc(n * sizeof(int));
    int i = 0;
    while (p != NULL)
    {
        a[i] = p->data;
        i++;
        p = p->next;
    }
    a[i] = 0;
    return a;
}
int main()
{
    int n, val, i = 1, pos;
    printf("enter number of nodes :\n");
    scanf("%d", &n);
    char *str = (char *)malloc(n * sizeof(char));
    int *a = (int *)malloc(n * sizeof(int));
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("enter the value of head :\n");
    scanf("%d", &head->data);
    head->next = NULL;
    struct node *prev, *next;
    prev = head;
    while (i < n)
    {
        printf("enter the value of node :\n");
        scanf("%d", &val);
        next = create_node(val, prev);
        prev = next;
        i++;
    }
    printf("Number of nodes : %d\n", count_node(head));
    ll_traversal(head);
    // printf("enter position to delete node :\n");
    // scanf("%d", &pos);
    // head = delete_last(head);
    // printf("Number of nodes : %d\n", count_node(head));
    // ll_traversal(head);
    a = convert_list_array(head, n);
    for(int i = 0; a[i] != 0; i++)
    printf("%d ", *(a+i));
    return 0;
}