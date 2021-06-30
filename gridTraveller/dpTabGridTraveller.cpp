#include<iostream>
#include<vector>
using namespace std;

long long gridTraveller(int m, int n){
    vector<vector<long long>> v(m+1 , vector<long long>(n+1 ,0));
    v[1][1] = 1;
    for(int i =0;i<v.size();i++){
        for(int j = 0;j<v[0].size();j++){
                int curr = v[i][j];
                if(i+1<=m) v[i+1][j]+=curr;
                if(j+1<=n) v[i][j+1]+=curr;
        }
    }
    return v[m][n];


}
int main(){
    
    cout<<gridTraveller(18,18)<<endl;
    cout<<gridTraveller(25,25);

}