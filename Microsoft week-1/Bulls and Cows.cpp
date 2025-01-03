class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp1,mp2;
        int bulls=0,cows=0;
        if(secret.size() != guess.size() || secret.empty()) return "0A0B";
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i] ) bulls++;
            else{
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for(auto it : mp1){
            if(mp2.find(it.first) != mp2.end()){
                cows += min(it.second, mp2[it.first]);
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B' ;
    }
};