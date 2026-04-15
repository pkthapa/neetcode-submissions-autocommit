class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> m; // <letter, occurrence-count>

        for (const auto &c : s) {
            m[c]++;
        }

        for (const auto &c : t) {
            if (m[c] > 0) {
                m[c]--;
                if (m[c] == 0) {
                    m.erase(c);
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};
