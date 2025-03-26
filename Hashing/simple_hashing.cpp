#include<bits/stdc++.h>
using namespace std;
struct MyHash{
    int bucket;
    list<int>*table; // *table is array, the whole line defines array of doublylinkedlist
    MyHash(int b){
        bucket = b;
        table = new list<int> [b]; // allocates memory to the array
    }
    void insert(int key){
        int i = key%bucket;
        table[i].push_back(key);
    }
    bool search(int key){
        int i=key%bucket;
        for(auto x : table[i]){
            if(x==key)
            return true;
        }
        return false;
    }
    void remove(int key){
        int i=key%bucket;
        table[i].remove(key);
    }
};
int main()
{
    MyHash h(7);
    h.insert(70);
    h.insert(71);
    h.insert(56);
    h.insert(9);
    h.insert(72);
    cout<<h.search(10)<<endl;
    cout<<h.search(72)<<endl;
    h.remove(70);
    cout<<h.search(70)<<endl;
    return 0;
}