class Solution {
public:
    string encode(vector<string>& strs) {
        string output;
        for (auto& str : strs) {
            output += to_string(str.length()) + "#" + str;
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;

        for (int i = 0; i < s.length();) {
            string lenStr;
            while (i < s.length() && s[i] != '#') {
                lenStr += s[i++];
            }
            int len = stoi(lenStr);
            string str = s.substr(++i, len);
            i += len;

            output.push_back(str);
        }
        return output;
    }
};
