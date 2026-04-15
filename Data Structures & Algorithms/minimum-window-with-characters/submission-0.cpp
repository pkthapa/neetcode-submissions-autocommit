class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int counter = t.size();
        unordered_map<char, int> tCount;
        int minLen = INT_MAX;
        int minStartIdx = 0;
        string result;

        for (const auto& c : t) {
            tCount[c]++;
        }

        for (int r = 0; r < s.size(); r++) {
            if (tCount[s[r]] > 0) {
                counter--;
            }
            tCount[s[r]]--;

            while (counter == 0) { // All characters processed
                tCount[s[l]]++;

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStartIdx = l;
                }

                if (tCount[s[l]] > 0) {
                    counter++;
                }
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStartIdx, minLen);
    }
};
