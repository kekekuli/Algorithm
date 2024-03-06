#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int lengthOfLongestSubstring(string s) {
            int Hash[10000];
            memset(Hash, 0, sizeof(Hash));
            int i = 0, j = 0;
            int ans = INT_MIN;
            while(i < s.size()){
                Hash[s[i]]++;
                while(Hash[s[i]] == 2){
                    Hash[s[j]]--;
                    j++;
                }
                if(i - j + 1 > ans)
                    ans = i - j + 1;
                i++;
            }
        return ans;
    }

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}