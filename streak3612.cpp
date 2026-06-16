#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result;

        for (char ch : s) {
            if (islower(ch)) {
                result.push_back(ch);
            }
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else if (ch == '#') {
                result += result;
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s1 = "a#b%*";
    cout << sol.processStr(s1) << endl;  // Output: ba

    string s2 = "z*#";
    cout << sol.processStr(s2) << endl;  // Output: ""

    return 0;
}