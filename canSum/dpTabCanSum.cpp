#include<iostream>
#include<vector>
using namespace std;
bool canSum(vector<int>v ,int targetSum){
    vector<bool>dp(targetSum+1,false);
    dp[0] = true;
    for(int i =0;i<=targetSum;i++){
        if(dp[i] == true){
        for(int j =0;j<v.size();j++){
            if(i+v[j]<=targetSum)
                dp[i+v[j]]=true;
        }
        }
    }
    return dp[targetSum];
}

int main(){
    cout<<canSum({5,3,4,7},7)<<endl;   //1 (true) 
    cout<<canSum({7,14},300)<<endl; //0(false)
}