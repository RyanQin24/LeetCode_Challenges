//https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> vect;
        bool start = false;
        string temp = "";
        for(int i = 0; i < s.length(); i++){
            if(!start && s[i] != ' '){
                temp += s[i];
                start = true;
            }else if(start && s[i] == ' '){
                vect.push_back(temp);
                temp = "";
                start = false;
            }else if(start){
                temp += s[i];
            }
            if(i == s.length()-1 && start){
                vect.push_back(temp);
            }
        }
        string result = "";
        for(int i = vect.size()-1; i >= 0; i--){
            result += vect[i];
            if(i != 0){
                result += " ";
            }
        }
        return result;
    }
};