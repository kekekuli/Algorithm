#include <iostream>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;
vector<LL> arr[300010];

void solve(){
    int n, m;
    LL ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        arr[i].clear();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            LL a;
            scanf("%lld", &a);
            arr[j].push_back(a);
        }
    }
    for (int i = 1; i <= m; i++){
        sort(arr[i].begin(), arr[i].end());
        for (int j = 0; j < n - 1; j++){
            LL x = arr[i][j + 1] - arr[i][j]; 
            ans += (LL)(j + 1) * (n - j - 1) * x;
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