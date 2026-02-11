class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') ++i;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            ++i;
        }

        // 3. Convert digits
        int result = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // 4. Overflow check
            if (result > INT_MAX / 10 || 
               (result == INT_MAX / 10 && digit > 7))
                return sign == 1 ? INT_MAX : INT_MIN;

            result = result * 10 + digit;
            ++i;
        }

        return result * sign;
    }
};
