#include<iostream>
#include<vector>
using namespace std;
//vector<int> result;
vector<int> howsum(int target,vector<int> &v){
    if(target==0)
        return {};
    if(target<0)
        return {-1}; // return array conists of -1
    for(int i = 0;i<v.size();i++){
        int curr_sum = target - v[i];
        vector<int>result = howsum(curr_sum , v);
        int count = 0;
        if(result.size()==1 && result[0]==-1)
            count = 1;
        if(count==0){
            result.push_back(v[i]);
            return result;
        }
    }
    return {-1};
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n) ;
    int target;
    cin>>target;
    for(int i = 0;i<n;i++)
        cin >> v[i];
    vector<int> ans = howsum(target,v);
    for(int i =0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}