#include<bits/stdc++.h>
using namespace std;
// returns floor of logn where base is 2
// for powerof 3 divide by 3
int poweroftwo(int n)
{
    if (n==1)
        return 0;
    else
        return 1+poweroftwo(n/2);
}
// conversion in binary
void convert_binary(int n)
{
    if(n==0)
        return;
    convert_binary(n/2);
    cout<<(n%2); //prints backwards
}
int main()
{
    cout<<poweroftwo(1024)<<endl;
    convert_binary(0);
    return 0;
}  