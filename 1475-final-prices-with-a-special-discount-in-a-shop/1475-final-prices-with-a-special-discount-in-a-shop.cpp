class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();

        for(int i= n-1; i>=0; i--){

            while(s.size()>0 && s.top()> prices[i]){
                s.pop();
            }

            int curr = prices[i];

            if(!s.empty()){
                prices[i]= prices[i]- s.top();

            }
            else{
                prices[i]= prices[i];
            }
            s.push(curr);
        }
        return prices;
        
    }
};