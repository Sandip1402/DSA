// create tree and traverse inorder, postorder, preorderly
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
void printInorder(Node *root){
    if(root != NULL){
        printInorder(root->left);
        cout<< root->data <<" ";
        printInorder(root->right);
    }
}
void printPreorder(Node *root){
    if(root != NULL){
        cout<< root->data <<" ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}
void printPostorder(Node *root){
    if(root != NULL){
        printPostorder(root->left);
        printPostorder(root->right);
        cout<< root->data <<" ";
    }
}
vector<int> iterationPreorder(Node *root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    stack<Node*> s;
    s.push(root);
    Node *curr=NULL;
    while(!s.empty() || curr!=NULL){
        curr = s.top();
        s.pop();
        while(curr!=NULL){
            ans.push_back(curr->data);
            if(curr->right!=NULL)
                s.push(curr->right);
            curr=curr->left;
        }
    }
    return ans;
}
vector<int> iterationInorder(Node *root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    stack<Node*> s;
    Node *curr=root;
    while(!s.empty() || curr!=NULL){
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        ans.push_back(curr->data);
        curr=curr->right;
    }
    return ans;
}
// one stack & parent-tracking
vector<int> iterationPostorder(Node *root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    stack<pair<Node*, bool>> s;
    s.push({root,false});
    bool visited;
    Node*curr;
    while(!s.empty()){
        curr = s.top().first;
        visited = s.top().second;
        s.pop();
        if(curr!=NULL){
            if(visited){
                ans.push_back(curr->data);
            } else{
                s.push({curr,true});
                s.push({curr->right,false});
                s.push({curr->left,false});
            }
        }
    }
    return ans;
}
// one stack
vector<int> iterationPostorder2(Node* root) {
    vector<int> result;
    if (!root) return result;

    stack<Node*> stack;
    Node* prev = nullptr;

    do {
        while (root) {
            stack.push(root);
            root = root->left;
        }

        while (!stack.empty() && (!stack.top()->right || stack.top()->right == prev)) {
            prev = stack.top();
            result.push_back(prev->data);
            stack.pop();
        }

        if (!stack.empty()) {
            root = stack.top()->right;
        }
    } while (!stack.empty());

    return result;
}
// two stack
vector<int> iterationPostorder3(Node* root) {
    vector<int> result;
    if (!root) return result;

    stack<Node*> stack1;
    stack<Node*> stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        Node* node = stack1.top();
        stack1.pop();
        stack2.push(node);

        if (node->left) {
            stack1.push(node->left);
        }
        if (node->right) {
            stack1.push(node->right);
        }
    }

    while (!stack2.empty()) {
        result.push_back(stack2.top()->data);
        stack2.pop();
    }

    return result;
}
void printvector(vector<int> v){
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main()
{
    string st;
    cout<<"enter nodes :"<<endl;
    getline(cin, st);
    Node* root = createTree(st);
    vector<int> in,post,pre;
    cout<<"PREORDER : ";
        printPreorder(root);
    cout<<endl;
    cout<<"INORDER : ";
        printInorder(root);
    cout<<endl;
    cout<<"POSTORDER : ";
        printPostorder(root);
    cout<<endl;
    cout<<"ITERATIVE PREORDER : ";
        pre = iterationPreorder(root);
        printvector(pre);
    cout<<"ITERATIVE INORDER : ";
        in = iterationInorder(root);
        printvector(in);
    cout<<"ITERATIVE POSTORDER : ";
        post = iterationPostorder(root);
        printvector(post);
    return 0;
}