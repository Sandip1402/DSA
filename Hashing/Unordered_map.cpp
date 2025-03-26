#include<bits/stdc++.h>
// #include<unordered_map> // for unordered map
using namespace std;

int main()
{
    unordered_map<string,int> m;
    m["gfg"]=20; 
    /* [] used to get reference of key if present or 
        returns reference to new key if not present */ 
    m["ide"]=30;
    m.insert({"courses",153});
    for(auto x : m)
    cout<<x.first<<" "<<x.second<<endl; // x.first for key & second for value
    // find operation
    if(m.find("gfg")!=m.end()){
        cout<<"found"<<endl;
    } else{
        cout <<"not found"<<endl;
    }
    /*or,
        auto it = m.find("gfg");
        if(it!=m.end()){
            cout<<(it->second);
        }*/
    // at function
    m.at("gfg")=50; // updating value
    m["pts"]; // if nothing is assigned then 0 is assigned as default
    for(auto it=m.begin(); it!=m.end(); it++)
    cout<<it->first<<"-"<<it->second<<" "; // arrow operator as it is a pointer
    /*begin returns reference to first key & 
      end returns iterator to element beyond end(undefined location)*/
    // count function
    if(m.count("gfg")>0){ // count returns 0 or 1. it's return type is size_t not boolean
        cout<<"found"<<endl;
    } else{
        cout<<"not found"<<endl;
    }
    // size & erase
    cout<<m.size()<<endl;
    m.erase("gfg");
    m.erase(m.begin());
    m.erase(m.begin(),m.end()); // erases all excluding m.end()
    cout<<m.size()<<endl;
    // empty function
    if(m.empty())
    cout<<"empty"<<endl;
    return 0;
}