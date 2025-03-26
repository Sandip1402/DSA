#include<bits/stdc++.h>
using namespace std;
// printing all subsets --O(2^n * n)
void power_set(string s)
{
    int n=s.length();
    int psize=(1<<n);
    for(int i=0; i<psize; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((i&(1<<j))!=0)
            cout<<s[j];
        }
        cout<<endl;
    }
}
int main()
{
    string s;
    cout<<"enter a string :"<<endl;
    cin>>s;
    // cout<<s;
    power_set(s);
    return 0;
}