class Solution {
public:
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                vector<double> next;

                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }

                double a = nums[i];
                double b = nums[j];

                vector<double> results = {
                    a + b,
                    a - b,
                    b - a,
                    a * b
                };

                if (abs(b) > 1e-6)
                    results.push_back(a / b);

                if (abs(a) > 1e-6)
                    results.push_back(b / a);

                for (double x : results) {
                    next.push_back(x);

                    if (solve(next))
                        return true;

                    next.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};