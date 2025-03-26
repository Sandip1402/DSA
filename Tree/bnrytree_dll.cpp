// program to convert binary tree to doubly linked list
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int x){
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
// time complexity - O(n), space complexity - O(h)
Node* bttodll(Node *root, Node *&prev){
    if(root == NULL)
        return NULL;
    Node* head = bttodll(root->left, prev);
    if(prev == NULL){
        head = root;
    } else{
        root->left = prev;
        prev->right = root;
    }
    prev=root;
    bttodll(root->right, prev);
    return head;
}
void lltraversal(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head -> right;
    }
}
int main()
{
    string st;
    getline(cin, st);
    Node *root = createTree(st);
    Node *prev = NULL;
    Node *head = bttodll(root, prev);
    cout<<"traversal of linked list : "<<endl;
    lltraversal(head);
    return 0;
}