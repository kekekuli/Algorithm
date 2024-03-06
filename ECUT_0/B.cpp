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
    int cnt = 0;
    string s, ans = "";
    cin >> s;
    int i = 0;
    while(i < s.size()){
        while(i < s.size() && s[i] != '0'){
            cnt += s[i] - '0';
            i++;
        }
        if (s[i] == '0')
            i++;
        ans += 'a' + cnt - 1;
        cnt = 0;
    }
    cout <<  ans << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
