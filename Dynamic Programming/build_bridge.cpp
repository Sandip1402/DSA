/* Program to build bridge between cities. Bridges are given as
    pairs of city number. (2,6) means bridge between 2 to 6th city.
    Condition is no bridge should cross each other. Find maximum bridges
    that can be constructed from the given pairs. */
#include<bits/stdc++.h>
using namespace std;
/* the idea to solve the problem is to sort the given pairs
    according to the first value. Then find the LIS from the second value of pair. */
void sort_pair(vector<pair<int,int>>&,int,int);
void merge(vector<pair<int,int>>&,int,int,int);
int build_bridge(vector<pair<int,int>>&pairs){

}
void sort_pair(vector<pair<int,int>>&pairs,int low, int high){
    int mid = (low+high)/2; // to handle overflow
    while(low<high){
        cout<<"ok"<<endl;
        sort_pair(pairs,low,mid);
        sort_pair(pairs,mid+1,high);
        merge(pairs,low,mid,high);
    }
}
void merge(vector<pair<int,int>>&pairs, int l, int m, int h){
    int left = m-l+1, right = h-m, i=0,j=0,k=0;
    vector<pair<int,int>> arL, arR;
    for(int n=0; n<left; n++){
        arL.push_back(pairs[l+n]);
    }
    for(int n=0; n<right; n++){
        arR.push_back(pairs[m+n+1]);
    }
    while(i<left && j<right){
        if(arL[i].first>=arR[j].first){
            pairs[l+k]=arL[i];
            i++;k++;
        }else{
            pairs[l+k]=arR[j];
            j++;k++;
        }
    }
    while(i<left){
        pairs[l+k]=arL[i];
        i++;k++;
    }
    while(j<right){
        pairs[l+k]=arR[j];
        j++;k++;
    }
}
int main()
{
    vector<pair<int,int>> pairs;
    pair<int,int>t;
    int n,a;
    cout<<"enter no. of pairs : ";
    cin>>n;
    cout<<"enter pairs :"<<endl;
    while(n--){
        cin>>t.first;
        cin>>t.second;
        pairs.push_back(t);
    }
    a=pairs.size()-1;
    sort_pair(pairs,0,a);
    for(auto it=pairs.begin(); it!=pairs.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    return 0;
}