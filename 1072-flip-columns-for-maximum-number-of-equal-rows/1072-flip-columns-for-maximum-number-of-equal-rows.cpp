class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxrow = 0;
        for(auto&currow : matrix){
            vector<int> inverted(n);
            for(int i = 0;i<n;i++){
                inverted[i]=currow[i]==0 ? 1:0;
            }
        int count =0;
        for(auto&row : matrix){
            if(row == inverted || row == currow ) count ++;
        }
        maxrow = max(maxrow,count);
        }
        return maxrow;
    }
};