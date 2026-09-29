class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int count =0;
        for(int i =0; i<n; i++){
            if(isupper(word[i]))
               count++;
        }

        return count == word.length()
               || count ==0
               || (count ==1 && isupper(word[0]));
        
    }
};