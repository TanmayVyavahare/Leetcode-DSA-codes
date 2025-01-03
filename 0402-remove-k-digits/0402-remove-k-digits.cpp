class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        // Remove remaining characters if k > 0
        while (k > 0) {
            st.pop();
            k--;
        }
        
        // If the stack is empty, return "0"
        if (st.empty()) return "0";
        
        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        
        // Remove leading zeros
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }
        
        // Reverse the string to get the correct order
        reverse(res.begin(), res.end());
        
        // If the result is empty, return "0"
        if (res.empty()) return "0";
        
        return res;
    }
};