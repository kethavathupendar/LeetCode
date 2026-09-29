class Solution {
public:
    long long helper(int x) {

        long long y = 0;

        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return y;
    }

    int reverse(int x) {

        // Special case because -INT_MIN overflows
        if (x == INT_MIN)
            return 0;

        if (x < 0) {

            long long rev = helper(-x);

            if (rev > INT_MAX)
                return 0;

            return -rev;
        }

        long long rev = helper(x);

        if (rev > INT_MAX)
            return 0;

        return rev;
    }
};