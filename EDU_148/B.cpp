#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;
LL arr[N], be[N];

void solve(){
    LL n, k, sum = 0, ans = -1;
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++)
        be[i] = be[i - 1] + arr[i];
    for (int i = 0; i <= k; i++){
        int j = k - i;
        int l = 2 * i + 1, r = n - j;
        if (ans == -1 || ans < be[r] - be[l - 1])
            ans = be[r] - be[l - 1];
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
