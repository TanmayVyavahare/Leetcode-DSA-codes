class Solution {
public:
    int isPrefixOfWord(string sentence, string searchword) {
        vector<string> wordlist;
        string currentword;
        for(char character : sentence){
            if(character!= ' ') currentword+=character;
            else {
                if(!currentword.empty()){
                    wordlist.push_back(currentword);
                    currentword ="";
                }
            }
        }
        if (!currentword.empty()) {
            wordlist.push_back(currentword);
        }
        for(int i = 0;i<wordlist.size();i++){
            if(wordlist[i].size()>=searchword.size()){
                bool ismatch = true;
                for(int j =0;j<searchword.size();j++){
                    if(wordlist[i][j]!=searchword[j]){
                        ismatch = false;
                        break;
                    }
                }
                if(ismatch){
                    return i+1;
                }
            }

        }
        return -1;
    }
};