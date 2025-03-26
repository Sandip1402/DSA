// program to serialize (tree to string/array) & deserialize (string/array to tree)
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
Node* createTree(string st){
    if(st.length()==0 || st[0]=='N')
        return NULL;
    queue<Node*>q;
    vector<string>nv;
    istringstream obj(st);
    for(string str; obj>>str; ){
        nv.push_back(str);
    }
    Node *root = new Node(stoi(nv[0]));
    q.push(root);
    int i=1;
    while(!nv.empty() && i<nv.size()){
        Node* curr = q.front();
        q.pop();
        string currval = nv[i];
        if(currval != "N"){
            curr->left = new Node(stoi(nv[i]));
            q.push(curr->left);
        }
        i++;
        if(i>=nv.size())
            break;
        currval = nv[i];
        if(currval != "N"){
            curr->right = new Node(stoi(nv[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
// here we pre-orderly serialize nodes into vector
// we assume there is no node with value -1
void serialize(Node*root, vector<int>&arr){
    if(root==NULL){
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    serialize(root->left, arr);
    serialize(root->right, arr);
}
Node* deserialize(vector<int>&arr, int &index){
    if(index==arr.size())
        return NULL;
    int val = arr[index];
    index++;
    if(val == -1)
        return NULL;
    Node *root = new Node(val);
    root->left = deserialize(arr, index);
    root->right = deserialize(arr, index);
    return root;
}
void inorder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
    string st;
    getline(cin, st);
    int index = 0;
    Node* root = createTree(st);
    cout<<"Inorder before serialization :"<<endl;
    inorder(root);
    cout<<endl;
    vector<int>arr;
    serialize(root, arr);
    cout<<"After serialization array is :"<<endl;
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"After deserialization array is :"<<endl;
    Node* root1 = deserialize(arr, index);
    cout<<"Inorder after deserialization :"<<endl;
    inorder(root1);
    return 0;
} 