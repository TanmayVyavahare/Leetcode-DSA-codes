class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(k>n) return false;
        else if(k==n) return true;
            vector<int> vec(26,0);
            for(char & ch : s){
                vec[ch-'a']++;
            }
            int oddfreqchar =0;
            for(int i =0;i<vec.size();i++){
                if(vec[i]%2!=0) oddfreqchar++;
            }
        return oddfreqchar<=k;
    }
};