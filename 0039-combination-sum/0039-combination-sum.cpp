class Solution {
public:
       set<vector<int>> s;

    void helper(vector<int>& arr, vector<int> &combin, vector<vector<int>> &ans ,int i,int target ){
           int n = arr.size();
        if(i ==n || target <0)
            return;

        if(target == 0){
            if(s.find(combin)== s.end()){
                 ans.push_back(combin);
                 s.insert(combin);
            }
            return;
        }  

        combin.push_back(arr[i]);
        helper(arr, combin, ans, i+1, target - arr[i]); 
        helper(arr, combin, ans, i, target - arr[i]);  

        combin.pop_back();
        helper(arr, combin, ans, i+1, target ); 

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        vector<int> combin;
        vector<vector<int>> ans;

        helper(arr, combin, ans,0, target );
        return ans;


        
    }
};