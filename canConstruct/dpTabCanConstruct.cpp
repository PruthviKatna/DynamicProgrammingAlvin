    #include<iostream>
    #include<vector>
    #include<unordered_map>
    using namespace std;
    bool canConstruct(string target, vector<string> wordBank) {
        vector<bool> dp(target.size()+1 , false);
        dp[0] =true; //initialize dp[0] as true
        for(int i =0;i<=target.size();i++){
            if(dp[i]==true){
                for(string word : wordBank){
                    if(word == target.substr(i,word.size()) && i+word.size()<=target.size()){
                        dp[i+word.size()] = true;
                    }
                }
            }
        }
        return dp[target.size()];
    }

    int main(){
        unordered_map<string,bool> m;
        cout << canConstruct("abcdef", {"ab", "abc", "cd", "ef", "abcd"}) << endl;                            // 1 (1 is true)
        cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;            // 0 (0 is false)
        cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;          // 1 
        cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}); // 0
    }