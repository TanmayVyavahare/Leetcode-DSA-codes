class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,-1);
        int n = s.length();
        int l = 0,r=0,maxlen = 0;
        while(r<n){
            if(freq[s[r]]!=-1){
                if(freq[s[r]]>=l) l = freq[s[r]]+1;
            }
            int len = r-l+1;
            maxlen = max(maxlen , len);
            freq[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};