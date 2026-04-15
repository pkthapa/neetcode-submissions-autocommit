class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0); // Keep count of each alphabet
        int maxFreq = 0;
        int l = 0; // window start offset
        int maxWindowLen = 0;

        for (int r = 0; r < s.size(); r++) { // r = window end offset
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            int currWinLen = r - l + 1;
            if (currWinLen - maxFreq <= k) {
                maxWindowLen = max(maxWindowLen, currWinLen);
            }
            else {
                freq[s[l] - 'A']--;
                l++;
            }
        }
        return maxWindowLen;
    }
};
