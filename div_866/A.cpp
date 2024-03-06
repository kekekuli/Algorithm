#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

void solve(){
    string s;
    int ans = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '_'){
            if (i - 1 < 0 || s[i - 1] != '^'){
                s = s.substr(0, i) + '^' + s.substr(i, s.size() - i);
                ans++;
                i++;
            }
            if (i + 1 >= s.size() || s[i + 1] != '^'){
                s = s.substr(0, i + 1) + "^" + s.substr(i + 1, s.size() - (i + 1));
                ans++;
            }
        }
        else{
            if (!(i - 2 >= 0 && s[i - 2] == '^') && !(i + 2 < s.size() && s[i + 2] == '^') && !(i - 1 >= 0 && s[i - 1] == '^') && !(i + 1 < s.size() && s[i + 1] == '^')){
                if (i + 1 < s.size() && s[i + 1] == '_'){
                    s = s.substr(0, i + 2) + '^' + s.substr(i + 2, s.size() - (i + 2));
                    ans++;
                }
                else{
                    s = s.substr(0, i + 1) + "^" + s.substr(i + 1, s.size() - (i + 1));
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}