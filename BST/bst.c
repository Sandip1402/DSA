#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *right,*left;
}bn;
bn *root=NULL;
bn *par;
void create(int item)
{
    bn *p,*s; 
    p=(bn*)malloc(sizeof(bn));
    p->data=item;
    p->left=p->right=NULL;
    s=root;
    if(root==NULL)  
        root=s=p;
    else
    {
        while(s!=NULL)
        {
            if(p->data<s->data)
            {
                if(s->left==NULL)
                {
                    s->left=p;
                    s=NULL;
                }
                else
                {
                    s=s->left;
                }
            }
            else
            {
                if(s->right==NULL)
                {
                    s->right=p;
                    s=NULL;
                }
                else
                {
                    s=s->right;
                }
            }
        }
    }     
}
void inorder(bn *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
void insert(bn*root,bn*newnode)
{
    if(root->data>newnode->data)
    {
        if(root->left==NULL)
        {
            root->left=newnode;
        }
        else
            insert(root->left,newnode);
    }
    else
    {
        if(root->right==NULL)
            root->right=newnode;
        else
            insert(root->right,newnode);    
    }
}
bn *search(int item)
{
    bn *loc,*parloc;
    loc=root;
    while((loc!=NULL)&&(loc->data!=item))
    {
        if(loc->data>item)
        {
            parloc=loc;
            loc=loc->left;
        }
        else
        {
            parloc=loc;
            loc=loc->right;
        }
    }
    par=parloc;
    return loc;
}
void delleaf(bn *loc)
{
    if(par->left==loc)
        par->left=NULL;
    else
        par->right=NULL;
    free(loc);    
}
void delonlyleft(bn *loc)
{
    if(par->left==loc)
        par->left=loc->left;
    else
        par->right=loc->right;
    free(loc);    
}
void delonlyright(bn *loc)
{
    if(par->left==loc)
        par->left=loc->right;
    else
        par->right=loc->right;
    free(loc);
}
void delete(int item)
{
    bn *loc;
    if(root==NULL)
        printf("emptyt tree");
    else
    {
        loc=search(item);
        if(loc==NULL)
        {
            printf("item not found");
        }
        else
        {
            if((loc->left==NULL)&&(loc->right==NULL))
            {
                delleaf(loc);
            }
            else if((loc->left!=NULL)&&(loc->right==NULL))
            {
                delonlyleft(loc);
            }
            else if((loc->left==NULL)&&(loc->right!=NULL))
            {
                delonlyright(loc);
            }
        }
    }
}
int main()
{
    int i,n,item,ch;
    bn *newnode;
    printf("enter no of node:\n");
    scanf("%d",&n);
    while(n--)
    {
        printf("enter the data:\n");
        scanf("%d",&item);
        create(item);
    }
    while(1)
    {
        printf("\n1.insert\n2.inorder\n3.search\n4.delete\n5.exit\n");
        printf("enter your choice :\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:newnode=(bn*)malloc(sizeof(bn));
                    printf("enter your data:\n");
                    scanf("%d",&newnode->data);
                    newnode->left=NULL;
                    newnode->right=NULL;
                    insert(root,newnode);
                    break;
            case 2: inorder(root);
                    break;
            case 3: printf("enter your data:\n");
                    scanf("%d",&item);
                    bn *loc=search(item);
                    if(loc!=NULL)
                    printf("data found");
                    else
                    {
                        printf("data not found");
                    }
                    break;
            case 4: printf("enter your data to delete:\n");
                    scanf("%d",&item);
                    delete(item);
                    break;
            case 5:exit(1);
                   break;
        }
    }
    return 0;
}