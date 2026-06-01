//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()){
            return -1;
        }
        for(int i = 0; i < haystack.size() - needle.size() + 1; i++){
            if(needle == haystack.substr(i,needle.size())){
                return i;
            }
        }
        return -1;
    }
};