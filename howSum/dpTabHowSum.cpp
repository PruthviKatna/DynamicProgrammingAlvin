#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> howSum(vector<int>v ,int targetSum){
    unordered_map<int,vector<int>> dp;
    dp[0] = {};

    for(int i =0;i<=targetSum;i++){
        if(dp.find(i)!=dp.end()){
        for(int j =0;j<v.size();j++){
            if(i+v[j]<=targetSum){
                vector<int> temp = dp[i];
                temp.push_back(v[j]);
                dp[i+v[j]]=temp;
            }
            if(!dp[targetSum].empty()) // Just return if you find one way of solving it
                return dp[targetSum];
        }
        }
    }
    return dp[targetSum];
}
void printResult(vector<int> v){
    if(v.empty())
        cout<<"subset sum not found"<<endl;
    for(int i =0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main(){
    printResult( howSum({3,4,7},7));    
    printResult(howSum({7,14},300)); 
}