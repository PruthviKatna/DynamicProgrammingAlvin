#include<iostream>
#include<vector>
using namespace std;

long long fib(int n , vector<long long> &v){
    if(n < 2)
        return 1;
    if(v[n] > 0)
        return v[n];
    else{
        v[n] = fib(n-1,v)+fib(n-2,v);
        return v[n];
    }
    
}
int main(){
    vector<long long> v(1000,0);
    int n;
    cin >> n;
    v[0] = 1 ;v[1] =1;
    cout<< fib(n,v);
}