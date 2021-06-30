    #include<iostream>
    #include<vector>
    #include<unordered_map>
    using namespace std;
    vector<vector<string>> allConstruct(string target, vector<string> wordBank) {
      //  vector<int> dp(target.size()+1 , 0);
        unordered_map<int,vector<vector<string>>> dp;
        dp[0] = {{}}; //initialize dp[0] as true
        for(int i =0;i<=target.size();i++){
            if(dp.find(i)!=dp.end()){
                for(string word : wordBank){
                    if(word == target.substr(i,word.size()) && i+word.size()<=target.size()){
                        for(int j =0;j<dp[i].size();j++){
                            vector<string> temp = dp[i][j];
                            temp.push_back(word);
                            dp[i+word.size()].push_back(temp);
                        }
                    }
                }
            }
        }
        return dp[target.size()];
    }
void printResult(vector<vector<string>> v){
    if(v.empty())
        cout<<"construct strings not found in word bank";
    else {
    for(int i =0;i<v.size();i++){
        for(int j =0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    }
    cout<<endl;
}
    int main(){
        // printResult(allConstruct("purple", {"purp", "p", "ur", "le", "purpl"})) ;                           // 2
        // printResult(allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"})) ;                            // 1 
        // printResult(allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"})) ;           // 0
        // printResult(allConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}));          // 4 
         printResult(allConstruct("eeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"})); // 0   
    }