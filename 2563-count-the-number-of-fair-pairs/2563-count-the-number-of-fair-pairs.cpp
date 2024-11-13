class Solution {
public:
     long long lb(vector<int>&nums, int l, int h, int e){
        while(l<=h){
            int mid= l+((h-l)/2);
            if(nums[mid]>=e){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return l;
    }


    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            long long low =  lb(nums,i+1,nums.size()-1, lower - nums[i]);
            long long high = lb(nums,i+1,nums.size()-1, upper-nums[i]+1);
            ans+=high-low;
        }
        return ans;
    }
};