class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashSet;
        int l = 0;
        int result = 0;

        for (int r = 0; r < s.size(); r++) {
            while (hashSet.find(s[r]) != hashSet.end()) {
                hashSet.erase(s[l++]);
            }
            hashSet.insert(s[r]);
            result = max(result, r - l + 1);
        }
        return result;
    }
};
