class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
                continue;
            }

            if (stk.empty()) {
                return false;
            }
            
            char topChar = stk.top();
            stk.pop();

            if ((topChar == '(' && c != ')') || 
                (topChar == '[' && c != ']') ||
                (topChar == '{' && c != '}')) {
                return false;
            }
        }
        // Stack must be empty if all given parentheses were valid
        return stk.empty();
    }
};
