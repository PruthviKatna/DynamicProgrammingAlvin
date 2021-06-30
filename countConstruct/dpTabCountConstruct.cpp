    #include<iostream>
    #include<vector>
    #include<unordered_map>
    using namespace std;
    int countConstruct(string target, vector<string> wordBank) {
        vector<int> dp(target.size()+1 , 0);
        dp[0] = 1; //initialize dp[0] as true
        for(int i =0;i<=target.size();i++){
            if(dp[i]>0){
                for(string word : wordBank){
                    if(word == target.substr(i,word.size()) && i+word.size()<=target.size()){
                        dp[i+word.size()]+=dp[i];
                    }
                }
            }
        }
        return dp[target.size()];
    }

    int main(){

       cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << endl;                           // 2
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;                            // 1 
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;            // 0
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"})<< endl;          // 4 
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}); // 0   
    }