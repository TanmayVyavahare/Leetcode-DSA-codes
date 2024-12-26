class Solution {
public:
    int totalways = 0;
private:
    int fun(vector<int>nums,int currentidx,int currentsum,int target,vector<vector<int>>& memo){
        if(currentidx==nums.size()){
            if(currentsum == target) return 1;
            else {return 0;}
        }
        else {
            if(memo[currentidx][currentsum+totalways]!= numeric_limits<int>:: min()){
                return memo[currentidx][currentsum+totalways];
            }
            int add=fun(nums,currentidx+1,currentsum+nums[currentidx],target,memo);
            int subtract=fun(nums,currentidx+1,currentsum-nums[currentidx],target,memo);
            memo[currentidx][currentsum+totalways]= add+subtract;
            return memo[currentidx][currentsum+totalways];

        }
    };
    public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalways = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> memo(nums.size(),vector<int>(2*totalways+1,numeric_limits<int>::min()));

       
        return fun(nums,0,0,target,memo);
    }
};