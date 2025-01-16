class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        unordered_map<int, long> freq;
        
        for (int num : nums1) {
            freq[num] += len2;
        }
        
        for (int num : nums2) {
            freq[num] += len1;
        }
       
        int result = 0;
        
        for(auto &it : freq){
            int number = it.first;
            int frequency = it.second;
            if(frequency%2!=0) result^=number ;
        }
        return result;
    }
};