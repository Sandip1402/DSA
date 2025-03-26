// problem is to print all nodes that are k distance away from root node
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
// Time complexity - O(n), space complexity - O(h), h - height
void kthNode(Node *root, int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    } else{
        kthNode(root->left, k-1);
        kthNode(root->right, k-1);
    }
}
int main()
{
    string st;
    int k;
    cout<<"enter nodes :"<<endl;
    getline(cin, st);
    cout<<"enter distance from root :"<<endl;
    cin>>k;
    Node *root = createTree(st);
    cout<<"Nodes "<<k<<" distance away from root are : ";
    kthNode(root, k);
    return 0;
}