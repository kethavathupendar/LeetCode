class Solution {
public:
    int minimumSwaps(vector<int>& nums) {

        int st =0; 
         int end =nums.size()-1;
         int count =0;

     while (st < end) {

            // Find the first misplaced 0 from the left
            while (st < end && nums[st] != 0)
                st++;

            // Find the first misplaced non-zero from the right
            while (st < end && nums[end] == 0)
                end--;

            // Swap them
            if (st < end) {
                swap(nums[st], nums[end]);
                count++;
                st++;
                end--;
            }
        }

        return count;
        
    }
};