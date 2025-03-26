#include<bits/stdc++.h>
using namespace std;
struct MyHash{
    int *arr;
    int cap,prsnt; // cap -> capacity of table, prsnt -> no. of element present
    MyHash(int n){ // constructor
        cap=n;
        prsnt=0;
        arr = new int(n);
        for(int i=0; i<n; i++)
        arr[i]=-1;
    }
    int hash(int key){
        return key%cap;
    }
    void print_table(){
        for(int i=0; i<cap; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    bool search(int key){
        int idx,act_idx;
        idx=act_idx=hash(key);
        do{
            if(arr[idx]==key)
            return true;
            else
            idx=(idx+1)%cap;
        }while((idx!=act_idx)||(arr[idx]==-1));
        return false;
    }
    bool insert(int key){
        int idx,act_idx;
        idx=act_idx=hash(key);
        do{
            if(arr[idx]==key)
                return false;
            else if(arr[idx]==-1||arr[idx]==-2){
                arr[idx]=key;
                prsnt++;
                return true;
            }
            else
            idx=(idx+1)%cap;
        }while(idx!=act_idx);
        return false;
    }
    bool insert_gfg(int key){
        if(cap==prsnt)
        return false;
        int idx=hash(key);
        while(arr[idx]!=-1&&arr[idx]!=-2&&arr[idx]!=key)
            idx=(idx+1)%cap;
        if(arr[idx]==key)
            return false;
        else
        {
            arr[idx]=key;
            prsnt++;
            return true;
        }    
    }
    bool remove(int key){
        int idx,act_idx;
        idx=act_idx=hash(key);
        do{
            if(arr[idx]==key){
                arr[idx]=-2;
                prsnt--;
                return true;
            }
            else
            idx=(idx+1)%cap;
        }while(idx!=act_idx);
        return false;
    }
};
int main()
{
    MyHash table(7);
    table.insert(49);
    table.insert(50);
    table.insert(51);
    table.insert(63);
    table.insert(69);
    cout<<table.insert_gfg(63)<<endl;
    table.insert(77);
    table.print_table();
    // cout<<table.search(63)<<endl;
    // cout<<table.search(64)<<endl;
    cout<<table.remove(70)<<endl;
    table.print_table();
    // cout<<table.search(63)<<endl;
    return 0;
}