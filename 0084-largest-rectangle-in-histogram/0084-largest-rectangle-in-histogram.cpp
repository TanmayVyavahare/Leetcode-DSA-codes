class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int maxArea =0;
        int element,nse,pse;
        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                element = st.top(); 
                st.pop();
                nse =i;
                pse=st.empty()?-1:st.top();
                maxArea = max(maxArea,arr[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty()?-1:st.top();
            maxArea = max(maxArea,arr[element]*(nse-pse-1));
        }
        return maxArea;
    }
};