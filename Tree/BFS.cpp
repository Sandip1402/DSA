// LOT(level order traversal) or BFS(breadth first search) of tree
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
// time complexity - O(n), space complexity - O(n), width of tree(w) = no. of nodes at last level at worst case for
// perfect binary tree = (n+1)/2;
void levelorder(Node *root)
{
    if(root == NULL) {return;}
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr_key = q.front();
        q.pop();
        cout<<curr_key->data<<" ";
        if(curr_key->left != NULL)
            q.push(curr_key->left);
        if(curr_key->right != NULL)
            q.push(curr_key->right);
    }
}
void levelorderByLine(Node *root){
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->data<<" ";
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);
    }
}
void levelorderByLine1(Node *root){
    if(root == NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        for(int i=0; i<count; i++){
            Node* curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        cout<<endl;
    }
}
int main()
{
    string st;
    getline(cin, st);
    Node *root = createTree(st);
    cout<<"Level order traversal : ";
    levelorder(root);
    cout<<endl;
    cout<<"Level order traversal by lines : "<<endl;
    levelorderByLine(root);
    cout<<endl;
    cout<<"Level order traversal by lines(method 2) : "<<endl;
    levelorderByLine1(root);
    return 0;
}