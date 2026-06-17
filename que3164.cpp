class Solution {
public:
    char kthCharacter(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        // Calculate length after each operation
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                len[i + 1] = len[i] + 1;
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                len[i + 1] = len[i] * 2;
            }
            else if (ch == '%') {
                len[i + 1] = len[i];
            }
        }

        // k is out of bounds
        if (k >= len[n]) {
            return '.';
        }

        // Trace back from the end
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                if (k == len[i]) {
                    return ch;
                }
            }
            else if (ch == '*') {
                long long before = len[i];
                long long after = len[i + 1];

                // Deleted character position
                if (before > after && k == after) {
                    return '.';
                }
            }
            else if (ch == '#') {
                long long half = len[i];
                if (half > 0) {
                    k %= half;
                }
            }
            else if (ch == '%') {
                long long currLen = len[i];
                k = currLen - 1 - k;
            }
        }

        return '.';
    }
};