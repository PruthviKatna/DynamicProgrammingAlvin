#include<iostream>
#include<vector>
using namespace std;
vector<int> bestSum(vector<int> &v ,int target){
    if(target == 0)
        return {};
    if(target < 0)
     return {INT_MIN};
    vector<int> bestSumArray = {INT_MIN};
    for(int i =0;i<v.size();i++){   
        int cur_sum = target - v[i];    
        vector<int>result = bestSum(v,cur_sum);
        if(result != (vector<int>){INT_MIN}){
            result.push_back(v[i]);
            if(bestSumArray==(vector<int>){INT_MIN} || bestSumArray.size() > result.size()){
                           bestSumArray = result;
            }
        }
    }
    return bestSumArray;
}
int main(){
    vector<int> v{3};
    int target = 6;
    vector<int> ans = bestSum(v,target);
    for(int i ;i<ans.size();i++)
        cout<<ans[i]<<" ";
}   