class Solution {
public:
    string getHint(string secret, string guess) {
        int map[10] = {0};
        int a = 0, b = 0;
        for (int i = 0; i < guess.size(); ++i) {
            if (guess[i] == secret[i]) ++a;
            ++map[guess[i] - '0'];
        }
        for (int i = 0; i < secret.size(); ++i) {
            if (map[secret[i] - '0']-- > 0) ++b;
        }
        return to_string(a) + "A" + to_string(b - a) + "B";
    }
};