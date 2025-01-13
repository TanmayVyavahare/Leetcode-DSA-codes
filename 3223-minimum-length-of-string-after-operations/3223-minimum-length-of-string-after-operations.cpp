class Solution {
public:
    int minimumLength(string s) {
        map<char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        int count =0;
        for(auto &pair: freq){
            int frequency = pair.second;
            if(frequency%2==1) count+=frequency-1;
            else count+=frequency-2;
        }
        return s.length()-count;
    }
};