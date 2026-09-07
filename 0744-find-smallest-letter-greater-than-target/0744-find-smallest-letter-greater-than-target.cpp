class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st =0;
        int end= letters.size()-1;

        while(st<=end){
            int mid = st + (end - st)/2;

            if(target < letters[mid]){
                end = mid -1;

            }
            else {
                st = mid +1;
            }
        }
        return letters[st % letters.size()];
        
    }
};