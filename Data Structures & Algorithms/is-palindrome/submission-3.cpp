class Solution {
    bool isAlphaNumeric(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }

public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !isAlphaNumeric(s[l])) {
                l++;
            }
            while (r > l && !isAlphaNumeric(s[r])) {
                r--;
            }

            if (tolower(s[l++]) != tolower(s[r--])) {
                return false;
            }
        }
        return true;
    }
};
