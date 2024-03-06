#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;
bool st[N];
string s;

LL dfs(int i){
    if (i < 0)
        i += s.size();
    if (i >= s.size())
        i = i - s.size();
    if (st[i] || s[i] == '0')
        return 0;
    st[i] = true;
    return 1 + dfs(i + 1) + dfs(i - 1);
}

void solve(){
    cin >> s;
    memset(st, false, sizeof(bool) * (s.size() + 10));
    LL cnt = 0;
    for (int i = 0; i < s.size(); i++)
        cnt = max(cnt, dfs(i));
    if (cnt == s.size()){
        cout << cnt * cnt << endl;
        return;
    }
    LL ans = cnt;    
    for (LL i = 0; i < cnt; i++)
        ans = max(ans, (i + 1) * (cnt - i));
    cout << ans << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
