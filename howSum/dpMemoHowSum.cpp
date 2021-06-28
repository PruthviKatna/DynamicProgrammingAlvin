#include<iostream>
#include<vector>
using namespace std;
bool howsum(int target,vector<int>&v,vector<int>&dp,vector<int>&result){
    if(target==0)
        return true;
    if(target<0)
        return false; 
    if(dp[target]==0)
        return false;
    if(dp[target]==1)
        return true;
 // return array conists of -1
    for(int i = 0;i<v.size();i++){
        int curr_sum = target - v[i];
        if(howsum(curr_sum,v,dp,result)==true){
            result.push_back(v[i]);
            dp[target]=1;
            return true;
        }
    }
    dp[target]=0;
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n) ;
    int target;
    cin>>target;
    for(int i = 0;i<n;i++)
        cin >> v[i];
    vector<int> dp(1000 ,-1);
    vector<int> result;
    howsum(target,v,dp,result);
    for(int i =0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
}