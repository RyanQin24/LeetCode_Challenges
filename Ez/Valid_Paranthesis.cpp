// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int N = s.length();
        for(int i = 0; i < N; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else if(!st.empty() && ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}'))){
                st.pop();
            }else if (!st.empty() && ((st.top() != '(' && s[i] == ')') || (st.top() != '[' && s[i] == ']') || (st.top() != '{' && s[i] == '}'))){
                return false;
            }else if (st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                return false;
            }
        }
        return st.empty();
    }
};