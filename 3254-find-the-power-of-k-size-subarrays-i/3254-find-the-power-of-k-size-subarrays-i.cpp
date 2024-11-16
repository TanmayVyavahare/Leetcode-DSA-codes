class Solution {
public:
    void helper(vector<int>& nums,int k ,int idx,vector<int>& v){
        if (idx > nums.size() - k) return;
        bool flag = true;
        for (int i = idx; i < idx + k - 1; i++) {
            if (nums[i] + 1 != nums[i + 1]) {
                flag = false;
                break;
            }
        }

        if (flag) 
        {
            int maxElement = nums[idx + k - 1];
            v.push_back(maxElement);
        } 
        else 
        {
            v.push_back(-1);
        }
        helper(nums, k, idx + 1, v);

        
}
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> v;
        helper(nums,k,0,v);
        return v;
    }
    
};