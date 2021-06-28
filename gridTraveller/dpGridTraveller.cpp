#include<iostream>
#include<vector>
using namespace std;
long long dpGridTraveller(int m ,int n , vector<vector<long long>>&v){
    if(m==1 || n==1)
        return 1;
    if(v[m][n]>0)
        return v[m][n];
    else{
        v[m][n] = dpGridTraveller(m-1,n,v)+dpGridTraveller(m,n-1,v);
        return v[m][n];
    }
}
int main(){
    int m ,n;
    cin>>m>>n;
    vector<vector<long long>> v( n+1 , vector<long long> (m+1, 0));
    cout<<dpGridTraveller(m,n,v);
}