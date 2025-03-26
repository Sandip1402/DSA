// calculate diameter of a tree
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
// method - 1
// we simply calculate height of left and right subtree for every node and add 1 to get the diameter
// time complexity - O(n^2), space complexity - O(h)
int height(Node *root){
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int diameter(Node *root){
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(1+lh+rh, max(diameter(root->left),diameter(root->right)));
}
// method - 2
// we can pre-process height of every node in a unordered_map(Node*, int)
// time complexity - O(n), space complexity - O(n)
unordered_map<Node*, int> m;
int heightMap(Node *root){
    if(root == NULL)
        return 0;
    m[root] = max(heightMap(root->left), heightMap(root->right)) + 1;
}
int diameter1(Node *root){
    if(root==NULL)
        return 0;
    int lh = m[root->left];
    int rh = m[root->right];
    return max(lh+rh+1, max(diameter1(root->left), diameter1(root->right)));
}
// method - 3
// we can modify height function and use a global variable for max diameter
// or, we can pass the reference of the global variable
// this function won't return diameter but we will get the diameter from global variable
// time complexity - O(n), space complexity - O(h)
int diameter2(Node *root, int &dmtr){
    if(root==NULL)
        return 0;
    int lh = diameter2(root->left, dmtr);
    int rh = diameter2(root->right, dmtr);
    if(lh+rh+1 > dmtr)
        dmtr = lh+rh+1;
    return max(lh,rh)+1;
}
int main()
{
    string st;
    getline(cin, st);
    int dmtr = 0;
    Node *root = createTree(st);
    cout<<"Diameter of the tree is :"<<endl;
    cout<<"method 1 :"<<diameter(root)<<endl;
    heightMap(root);
    cout<<"method 2 :"<<diameter1(root)<<endl;
    diameter2(root, dmtr);
    cout<<"method 3 :"<<dmtr<<endl;
    return 0;
}