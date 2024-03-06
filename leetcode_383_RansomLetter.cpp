class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int num[26] = {0};
        for(int i = 0; i < magazine.size(); i++)
            num[magazine[i] - 'a']++;
        for(int i = 0; i < ransomNote.size(); i++){
            num[ransomNote[i] - 'a']--;
            if(num[ransomNote[i] - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};