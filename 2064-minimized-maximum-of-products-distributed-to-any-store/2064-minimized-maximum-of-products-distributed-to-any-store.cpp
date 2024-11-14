class Solution{
private:
    int getCnt(vector<int>&nums,int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=(nums[i]+mid-1)/mid;
        }
        return cnt;
    }
public:
    int minimizedMaximum(int n,vector<int>&nums){
        int high=0;
        for(int num:nums){
            high=max(high,num);
        }
        int res=high;
        int low=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=getCnt(nums,mid);
            if(cnt<=n){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return res;
    }

};
