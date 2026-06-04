class Solution {
public:
    int totalWaviness(int num1, int num2) {
        long long total = 0;
  for (int num = num1; num <= num2; num++) {
            string s = to_string(num);
            int waviness = 0;
            for (int i = 1; i < s.size() - 1; i++) {
                if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                    (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                    waviness++;
                }
            }
            total += waviness;
        }return total;
    }
};