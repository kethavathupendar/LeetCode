class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;

        for(int i=0; i<nums.size(); i++){

            int first = nums[i];
            int complement = target - first;

            if(mp.find(complement) != mp.end())
               return {i, mp[complement]};


               mp[nums[i]] = i;
        }
        return {};
        
    }
};