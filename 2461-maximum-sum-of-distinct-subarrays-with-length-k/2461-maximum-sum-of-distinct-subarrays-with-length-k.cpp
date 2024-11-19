class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res =0;
        unordered_map<int,int> mpp;
        long long sum =0;
        int l =0;
        for (int i =0;i<nums.size();i++){
            sum +=nums[i];
            mpp[nums[i]]++;
            if(i-l+1>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            if(mpp.size()==k && (i-l+1)==k){
                res = max(res,sum);
            }
        }
        return res;
      
    }
};