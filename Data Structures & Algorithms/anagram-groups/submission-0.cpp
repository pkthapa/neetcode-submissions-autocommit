class Solution {
    string getFrequencyString(string& str) {
        vector<int> freq(26, 0); // a ... z

        for (auto &c : str) {
            freq[c - 'a']++;
        }

        string res;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                res += char(i + 'a') + to_string(freq[i]);
            }
        }
        return res;
    }

public:
    // Refer https://leetcode.com/problems/group-anagrams/submissions/1898991807/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqMap;

        for (auto &str : strs) {
            string freqStr = getFrequencyString(str);
            freqMap[freqStr].push_back(str);
        }

        vector<vector<string>> result;
        for (auto &m : freqMap) {
            result.push_back(m.second);
        }
        return result;
    }
};
