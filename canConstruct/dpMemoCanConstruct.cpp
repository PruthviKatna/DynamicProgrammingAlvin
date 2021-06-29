    #include<iostream>
    #include<vector>
    #include<unordered_map>
    using namespace std;
    bool canConstruct(string target, vector<string> wordBank , unordered_map<string, bool>& dp) {
        if(target=="")
            return true;
        if(dp.find(target)!=dp.end())
            return dp[target];  
        for(string s : wordBank){
            if(target.find(s)==0){
                string suffix = target.substr(s.size(),target.size()-s.size());
                if(canConstruct(suffix,wordBank,dp)==true){
                    dp[target]=true;
                    return true; 
                }
            }
        }
        dp[target]=false;
        return false;
    }

    int main(){
        unordered_map<string,bool> m;
        cout << canConstruct("abcdef", {"ab", "abc", "cd", "ef", "abcd"},m) << endl;                            // 1 (1 is true)
        cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"},m) << endl;            // 0 (0 is false)
        cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"},m) << endl;          // 1 
        cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"},m); // 0
    }