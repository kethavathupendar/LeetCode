
class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        int n = s.size();
        int low = 0;
        int high = n;
        
        vector<int> ans;
        
        for (char c : s) {
            if (c == 'I') {
                ans.push_back(low);
                low++;
            }
            else { // c == 'D'
                ans.push_back(high);
                high--;
            }
        }
        
        // One number remains
        ans.push_back(low);
        
        return ans;
    }
};
