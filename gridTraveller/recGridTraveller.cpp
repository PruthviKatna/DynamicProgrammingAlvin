
#include<iostream>
using namespace std;
long long gridTraveller(int m , int n){
    if(m==1 || n==1)
        return 1;
    return gridTraveller(m-1 ,n ) + gridTraveller(m,n-1);
}
int main(){
    int m , n;
    cin >> m >> n;
    cout<<gridTraveller(m,n);
}