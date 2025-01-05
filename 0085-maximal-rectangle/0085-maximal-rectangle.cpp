class Solution {
public:
    int lhist(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;
        int element, nse, pse;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                element = st.top(); 
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, arr[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, arr[element] * (nse - pse - 1));
        }
        
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty()) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        int maxArea = 0;
        
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == '1') {
                    sum += 1;
                } else {
                    sum = 0;
                }
                prefix[i][j] = sum;
            }
        }
        
        // Calculate the maximal area of rectangle in each row's histogram
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, lhist(prefix[i]));
        }
        
        return maxArea;
    }
};
