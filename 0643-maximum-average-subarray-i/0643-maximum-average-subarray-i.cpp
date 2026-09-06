class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        int total = 0;

        // First window
        for (int i = 0; i < k; i++) {
            total += nums[i];
        }

        double max_avg = (double)total / k;

        int st = 0;
        int end = k - 1;

        // Slide the window
        for (int i = 0; i < n - k; i++) {

            total = total - nums[st] + nums[end + 1];

            st++;
            end++;

            max_avg = max(max_avg, (double)total / k);
        }

        return max_avg;
    }
};