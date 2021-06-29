    #include<iostream>
    #include<vector>
    #include<unordered_map>
    using namespace std;
    int countConstruct(string target, vector<string> wordBank , unordered_map<string, int>& dp) {
        if(dp.find(target) != dp.end())
            return dp[target];
        if(target == "")
            return 1;
 
        int count = 0;
        for(string s : wordBank){
            if(target.find(s) == 0){
                string suffix = target.substr(s.size(),target.size()-s.size());
                count += countConstruct(suffix,wordBank,dp);    
            }
        }
        dp[target] = count;
        return count;
    }

    int main(){
        unordered_map<string,int> m;
    cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"},m) << endl;                           // 2
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"},m) << endl;                            // 1 
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"},m) << endl;            // 0
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"},m) << endl;          // 4 
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"},m); // 0   
    }