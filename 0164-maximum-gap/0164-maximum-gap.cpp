class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.size()==0 || nums.size()==1){
            return 0;
        }
       // map<int, int>mp;
        int max_sub=0;

        for(int i=1; i<nums.size(); i++){
           // mp[nums[i]]=i;
            int sub =nums[i]- nums[i-1];
            
            max_sub = max(max_sub , sub);
        }
        return max_sub;
        
    }
};