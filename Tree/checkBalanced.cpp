// problem is to check whether the tree is balanced or not
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node (int x){
        data = x;
        left = right = NULL;
    }
};
Node* createTree(string ar){ // 12 3 4 56 N N N N
    if(ar.length() == 0 || ar[0] == 'N')
        return NULL;
    vector <string> nv;
    istringstream obj(ar); // detects space and split the strings 
    for(string st; obj >> st; ){ // enters the string into vector until obj becomes empty
        nv.push_back(st);
    }
    // creating root
    Node* root = new Node(stoi(nv[0])); 
    // creating queue to connect node
    queue <Node*> q;
    // pushing root in queue
    q.push(root);
    int i=1;
    while(!nv.empty() && i<nv.size()){
        Node* currnode = q.front();
        q.pop();
        string currval = nv[i];
        // connecting left node
        if(currval != "N"){
            currnode -> left = new Node(stoi(currval));
            q.push(currnode->left);
        }
        i++;
        if(i >= nv.size())
            break;
        currval = nv[i];
        // connecting right node
        if(currval != "N"){
            currnode -> right = new Node(stoi(currval));
            q.push(currnode -> right);
        }
        i++;
    }
    return root;
}
// method - 1, time complexity O(n^2)
// calculating height of left and right subtree
int height(Node*root){
    if(root==NULL)
        return 0;
    else
        return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(Node *root){
    if(root == NULL) 
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}
// method - 2, time complexity O(n)
// we return one value recursively, if tree is balanced the value we
// return is it's height, else return -1
int isBalanced1(Node *root){
    if(root == NULL)
        return 0;
    int lh = isBalanced1(root->left);
    if(lh==-1)
        return -1;
    int rh = isBalanced1(root->right);
    if(rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;
    else
        return max(lh,rh)+1;
}
int main()
{
    string st;
    getline(cin,st);
    Node*root = createTree(st);
    if(isBalanced(root))
        cout<< "Tree is balanced."<<endl;
    else
        cout<<"Tree not balanced."<<endl;
    if(isBalanced1(root)!=-1)
        cout<< "Tree is balanced."<<endl;
    else
        cout<<"Tree not balanced."<<endl;
    return 0;
}