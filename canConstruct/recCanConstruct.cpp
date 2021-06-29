#include<iostream>
#include<vector>
using namespace std;
bool canConstruct(string target, vector<string> wordBank) {
    if(target=="")
        return true;
    
    for(string s : wordBank){
        if(target.find(s)==0){
            string suffix = target.substr(s.size(),target.size()-s.size());
            if(canConstruct(suffix,wordBank)==true)
                return true; 
        }
    }
    return false;
}

int main(){
    cout << canConstruct("abcdef", {"ab", "abc", "cd", "ef", "abcd"}) << endl;                            // 1 (1 is true)
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;            // 0 (0 is false)
    cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;          // 1 
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}); // 0
}