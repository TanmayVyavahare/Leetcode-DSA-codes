class Solution {
public:
    bool isvowel(char c){
        if(c=='a' ||c=='e' || c=='i'|| c=='o'|| c=='u'){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N= words.size();
        vector<int>pf(N,0);
        vector<int>v;
        int sum=0;
        for(int i=0; i<words.size(); i++){
            int n=words[i].length();
            if(isvowel(words[i][0]) && isvowel(words[i][n-1])){
                sum++;
            }
            pf[i]=sum;
        }
        for(auto i: queries){
            int x= pf[i[1]] - (i[0]==0 ? 0: pf[i[0]-1]);
            v.push_back(x);
        }
        return v;
    }
};