class Solution {
public:
    bool canJump(vector<int>& nums) {

        int i = nums.size()-2;
        int pos = nums.size()-1;

        while(i>=0){
            
            if(nums[i]+i>= pos){
                pos = i;
            }
            i--;
        }

        if(pos == 0)
           return true;
        else 
           return false;   
        
    }
};