#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        ll result = x;
        while(--n){
            result = (result+1)|x;
        }
        return result;
    }
};