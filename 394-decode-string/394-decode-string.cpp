class Solution {
public:
    unordered_map<int, int> closePos;
    string decodeString(const string& s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[')
                st.push(i);
            else if (s[i] == ']') {
                closePos[st.top()] = i;
                st.pop();
            }
        }
        return solve(s, 0, s.size() - 1);
    }
    string solve(const string& s, int l, int r) {
        string ans = "";
        int num = 0;
        while (l <= r) {
            char c = s[l];
            if (isdigit(c))
                num = num * 10 + c - '0';
            else if (c == '[') {
                string sub = solve(s, l + 1, closePos[l] - 1);
                for (int i = 0; i < num; ++i) ans += sub;
                num = 0;
                l = closePos[l];
            } else {
                ans += c;
            }
            l += 1;
        }
        return ans;
    }
};