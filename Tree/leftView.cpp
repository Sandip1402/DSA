// print the left view of a binary tree
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
// recursive solution
int maxlevel = 0;
void leftview(Node *root, int level){
    if(root==NULL)
        return;
    else{
        if(maxlevel < level){
            cout<<root->data<<" ";
            maxlevel = level;
        }
        leftview(root->left, level+1);
        leftview(root->right, level+1);
    }
}
// iterative solution
void leftview1(Node* root){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        // as it is a level order traversal after one iteration 
        // queue will contain only nodes of same level
        int count = q.size(); 
        for(int i=0; i<count; i++){
            Node *curr = q.front();
            q.pop();
            if(i==0)
                cout<<curr->data<<" ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
}
int main()
{
    string st;
    getline(cin, st);
    Node *root = createTree(st);
    cout<<"left view of binary tree : "<<endl;
    leftview(root, 1);
    cout<<endl;
    cout<<"left view of binary tree : "<<endl;
    leftview1(root);
    return 0;
}