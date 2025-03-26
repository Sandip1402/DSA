// problem is to create tree from given inorder & preorder traversal of tree
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// time complexity - O(n^2)
Node *iptotree(int pre[], int in[], int is, int ie, int &preindex){
    if(is>ie)
        return NULL;
    Node *root = new Node(pre[preindex++]);
    int inindex;
    for(int i=is; i<=ie; i++){
        if(in[i] == root->data){
            inindex = i;
            break;
        }
    }
    root->left = iptotree(pre, in, is, inindex-1, preindex);
    root->right = iptotree(pre, in, inindex+1, ie, preindex);
    return root;
}
// we can improve the solution by preprocessing a unordered table, where keys are inorder, index are values
// time complexity will be - O(n)
// doesn't work if nodes has same value
int preidx = 0;
Node *iptotree1(int pre[], unordered_map<int, int>m, int is, int ie){
    if(is>ie)
        return NULL;
    Node *root = new Node(pre[preidx++]);
    int inindex = m[root->data];
    root->left = iptotree1(pre, m, is, inindex-1);
    root->right = iptotree1(pre, m, inindex+1, ie);
    return root;
}
void Inorder(Node *root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}
int main()
{
    int node, preindex=0;
    cout<<"Enter no. of nodes :";
    cin>>node;
    int pre[node], in[node];
    unordered_map<int, int>m;
    cout<<"Enter pre-order traversal of tree :"<<endl;
    for(int i=0; i<node; i++)
        cin>>pre[i];
    cout<<"Enter in-order traversal of tree :"<<endl;
    for(int i=0; i<node; i++)
        cin>>in[i];
    Node *root1 = iptotree(pre, in, 0, node-1, preindex);
    for(int i=0; i<node; i++)
        m[in[i]] = i;
    Node *root2 = iptotree1(pre, m, 0, node-1);
    cout<<"Inorder traversal for method 1 :";
    Inorder(root1);
    cout<<endl;
    cout<<"Inorder traversal for method 2 :";
    Inorder(root2);    
    return 0;
}