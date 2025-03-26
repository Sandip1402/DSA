#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s; // works based on hashing
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(7);
    for(auto it=s.begin(); it!=s.end(); it++) // s.end() point to space beyond end element
        cout<<*it<<" ";
    cout<<endl<<s.size()<<endl; // prints size of set(no. of elements)
    // s.clear(); // clears the set
    // cout<<s.size();
    if(s.find(15)==s.end()){ // find returns the iterator if element found
        cout<<"not found"<<endl;
    } else{
        cout<<"found"<<endl;
    }
    if(s.count(10)){ // same as find but returns 1 or 0 as there can't be duplicate element
        cout<<"found"<<endl;
    } else{
        cout<<"not found"<<endl;
    }
    s.erase(10); // removes an item from the set
    auto it=s.find(5);
    s.erase(it); // can pass address of element or element
    cout<<s.size()<<endl;
    s.erase(s.begin(),s.end());  // erase can be used to remove all elements
    cout<<s.size();
    return 0;
}