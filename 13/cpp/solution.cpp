#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && mp[s[i]] < mp[s[i + 1]]) {
                res -= mp[s[i]];
            } else {
                res += mp[s[i]];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "请输入罗马数字：";
    cin >> s;
    cout << "对应的整数是：" << sol.romanToInt(s) << endl;
    return 0;
}