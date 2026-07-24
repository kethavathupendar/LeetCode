
class Solution {
 public:
     vector<int> partitionLabels(string s) {

        // Store the last occurrence of each character
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {

            // Extend the current partition if needed
            end = max(end, last[s[i] - 'a']);

            // If we've reached the end of the current partition
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};
        