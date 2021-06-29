#include<iostream>
#include<vector>
using namespace std;
int countConstruct(string target, vector<string> wordBank) {
    if(target=="")
        return 1;
    int count = 0;
    for(string s : wordBank){
        if(target.find(s)==0){
            string suffix = target.substr(s.size(),target.size()-s.size());
            count+=countConstruct(suffix,wordBank);    
        }
    }
    return count;
}

int main(){
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "ef", "abcd"}) << endl;                         
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;            
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;          
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}); 
}