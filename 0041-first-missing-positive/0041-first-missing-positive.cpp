class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i=0;

        while(i<n){
            long long correct_idx = 1LL*nums[i]-1;
            if(nums[i]>0 && nums[i]<=n && nums[i] != nums[correct_idx]){
                swap(nums[i], nums[correct_idx]);

            }
            else{
                i++;
            }
        }
        for(int i =0; i<n; i++){
            if(nums[i] != i+1)
              return i+1;
        }
        return n+1;
        
    }
};