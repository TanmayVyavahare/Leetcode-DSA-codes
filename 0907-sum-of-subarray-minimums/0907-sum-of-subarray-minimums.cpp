class Solution {
    private:
    vector<int> findnge(vector<int>& arr){
        int n= arr.size();
        vector<int>nge(n);
        stack<int> st;
        for(int i = n-1;i>=0;i-- ){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nge[i] = st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    private:
    vector<int> findpsee(vector<int>& arr){
        int n= arr.size();
        vector<int>psee(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            psee[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod =(int) 1e9+7;
        vector<int>nge =findnge(arr);
        vector<int>psee =findpsee(arr);
        long total = 0;
        for(int i =0;i<n;i++){
            int left = i-psee[i];
            int right = nge[i]-i;
            total = (total +(left*right*1LL*arr[i])%mod)%mod;
        }
        return total ;
    }
};