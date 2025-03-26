// LCA means lowest common ancestor
// we need to find LCA of given two node of a binary tree
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
// Method 1
// we are finding path to each given node and then finding nearest ancestor common to both
// time complexity - O(n), requires 3 times traversal of tree, space complexity - O(h) + vectors
bool findPath(Node* root, int n, vector<Node*>&p){
    if(root==NULL)
        return false;
    p.push_back(root); // first add then check descendents
    if(root->data == n) // found node
        return true;
    if(findPath(root->left, n, p) || findPath(root->right, n, p)) // if one of them returns true, means found the node
        return true;
    p.pop_back(); // if both of them returns false we pop last node
    return false;

}
Node* lca1(Node*root, int n1, int n2){
    vector<Node*> p1, p2;
    if(root==NULL)
        return NULL;
    if(findPath(root, n1, p1)==false || findPath(root, n2, p2)==false)
        return NULL;
    int s1,s2,i;
    s1 = p1.size();
    s2 = p2.size();
    s1 = s1<s2 ? s1 : s2;
    for(i=0; i<s1-1; i++){
        if(p1[i+1]!=p2[i+1])
            return p1[i];
    }
    if(p1[i]==p2[i])
        return p1[i];
    return NULL;
}
// Method 2
// we assume that tree must contain two nodes
// There are 4 possibilites :
// 1.got one node then we return that node as LCA
// 2.got one node at one of the side of a root, then we return current root as LCA
// 3.both node are on the same subtree of current root, then we return whatever that subtree returns
// 4.we didn't got any node then return NULL
Node* lca2(Node*root, int n1, int n2){
    if(root == NULL) // case 4
        return NULL;
    if(root->data == n1 || root->data == n2) // case 1
        return root;
    Node* lc1 = lca2(root->left, n1, n2);
    Node* lc2 = lca2(root->right, n1, n2);
    if(lc1!=NULL && lc2!=NULL) // case 3
        return root;
    else if(lc1!=NULL) // case 2
        return lc1;
    else // case 2
        return lc2;
}
int main()
{
    string st;
    int n1, n2;
    getline(cin, st);
    Node *root = createTree(st);
    cout<<"enter nodes to find LCA :"<<endl;
    cin>>n1>>n2;
    Node* l1 = lca1(root, n1, n2);
    Node* l2 = lca2(root, n1, n2);
    cout<<"LCA method 1 :"<<endl;
    if(l1==NULL)
        cout<<"Nodes not found";
    else
        cout<<l1->data;
    cout<<endl;
    cout<<"LCA method 2 :"<<endl;
    if(l2==NULL)
        cout<<"Nodes not found";
    else
        cout<<l2->data;
    return 0;
}