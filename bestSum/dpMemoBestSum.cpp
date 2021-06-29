#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> bestSum(vector<int> &v ,int target , unordered_map<int,vector<int>> &dp){
    if(dp.find(target)!=dp.end())
        return dp[target];
     if(target == 0)
        return {};
    if(target < 0)
     return {INT_MIN};
    vector<int> bestSumArray = {INT_MIN};
    for(int i =0;i<v.size();i++){   
        int cur_sum = target - v[i];    
        vector<int>result = bestSum(v,cur_sum,dp);
        if(result != (vector<int>){INT_MIN}){
            result.push_back(v[i]);
            if(bestSumArray==(vector<int>){INT_MIN} || bestSumArray.size() > result.size()){
                           bestSumArray = result;
            }
        }
    }
    dp[target] = bestSumArray;
    return bestSumArray;
}
int main(){
    vector<int> v{3,2};
    int target = 5;
    unordered_map<int,vector<int>> m;
    vector<int> ans = bestSum(v,target,m);
    for(int i ;i<ans.size();i++)
        cout<<ans[i]<<" ";
}   