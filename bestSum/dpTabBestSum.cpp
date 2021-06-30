#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> bestSum(vector<int>v ,int targetSum){
    unordered_map<int,vector<int>> dp;
    dp[0] = {};
    for(int i =0;i<=targetSum;i++){
        if(dp.find(i)!=dp.end()){
        for(int j =0;j<v.size();j++){
            if(i+v[j]<=targetSum){
                vector<int> temp = dp[i];
                temp.push_back(v[j]);
                if(dp[i+v[j]].empty() || dp[i+v[j]].size()>temp.size())
                    dp[i+v[j]]=temp;
            }
        }
        }
    }
    return dp[targetSum];
}
void printResult(vector<int> v){
    if(v.empty())
        cout<<"subset sum not found";
    for(int i =0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int main(){
    printResult( bestSum({5,3,7,4},7));    
    printResult(bestSum({7,14},300)); 
    printResult(bestSum( {2, 3, 5},8));
    printResult(bestSum( {5, 3, 4, 7},7));
    printResult(bestSum({1, 4, 5},8));
    printResult(bestSum( {1, 2, 5, 25},100));
    printResult(bestSum( {25, 1, 50, 2},100));
    printResult(bestSum({2, 8},17));
}