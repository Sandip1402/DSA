#include<bits/stdc++.h>
using namespace std;
// naive solution -- O(n)
int count_set_0(int n)
{
    int count=0;
    while(n!=0)
    {
        count = count + (n&1);
        n = n>>1;
    }
    return count;
}
// brian kernighan's algorithm -- O(no. of set bits)
int count_set_1(int n)
{
    int count = 0; 
    while(n!=0)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}
// O(1) time complexity method 
class count_set {
    private : 
    int tbl[256];
    public :
    void pre_process(int n)
    {
        tbl[0]=0;
        for(int i=1; i<256; i++)
        {
            tbl[i]=tbl[i&(i-1)]+1;
        }
        // for(int i=0; i<256; i++)
        //     cout<<tbl[i]<<endl;
    }
    int count_set_2(int n)
    {
        return tbl[(n&255)]+tbl[(n>>8)&255]+tbl[(n>>16)&255]+tbl[(n>>24)];
    }
};
int main()
{
    int n;
    count_set c1;
    cout<<"enter a number :";
    cin>>n;
    cout<<"Number of set bits are :"<<count_set_0(n)<<endl;
    cout<<"Number of set bits are :"<<count_set_1(n)<<endl;
    c1.pre_process(n);
    cout<<"Number of set bits are :"<<c1.count_set_2(n)<<endl;
    return 0;
}