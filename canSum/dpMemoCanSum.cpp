        #include<iostream>
        #include<vector>
        using namespace std;
        bool canSum(int target , vector<int>&v , vector<int>&dp){
            if(dp[target]==0)
                return false;
            if(dp[target]==1)
                return true;
            if(target == 0)
                return true;
            if(target < 0)
                return false;
            
            for(int i = 0; i<v.size();i++){
            int curr_sum = target - v[i];
                if(canSum(curr_sum,v,dp)==true){
                    dp[target] = true;
                    return true;

                }
            }
            dp[target] = false;
            return false;
        }
        int main(){
        
            int n;
            cin>>n;
            vector<int> v(n) ,dp(1000,-1) ;
            int target;
            cin>>target;
            for(int i = 0;i<n;i++)
                cin >> v[i];
            cout<<canSum(target , v,dp);
        }