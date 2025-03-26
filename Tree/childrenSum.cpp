// problem to find if tree supports children sum property
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
bool CSproperty(Node *root){
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if(root->left != NULL) 
        sum+=(root->left)->data;
    if(root->right != NULL) 
        sum+=(root->right)->data;
    return (root->data == sum && CSproperty(root->left) && CSproperty(root->right));
}
int main()
{
    string st;
    getline(cin, st);
    Node *root = createTree(st);
    if(CSproperty(root))
        cout<<"Tree follows child-sum property."<<endl;
    else
        cout<<"Tree doesn't follow child-sum property."<<endl;
    return 0;
}