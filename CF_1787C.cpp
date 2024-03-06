#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

LL xs[N], ans[N][2], arr[N];

LL min(LL a , LL b){
    return a < b ? a : b;
}

LL max(LL a, LL b){
    return a > b ? a : b;
}

LL tryBig(LL a, LL s){
    if(a < s)
        return a;
    else if (a < 2 * s)
        return s;
    else
        return a - s;
}

LL trySmall(LL a, LL s){
    if (a < s)
        return 0;
    else if (a < 2 * s)
        return a - s;
    else
        return s;
}

void solve(){
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &arr[i]);
        if (i == 1 || i == 2)
            continue;
        if (i == 3){
            if (arr[1] < arr[3])
                xs[2] = tryBig(arr[2], s);
            else
                xs[2] = trySmall(arr[2], s);
            continue;
        }
        LL a = arr[i - 2] - xs[i - 2];
        if (a < arr[i])
            xs[i - 1] = tryBig(arr[i - 1], s);
        else
            xs[i - 1] = trySmall(arr[i - 1], s);
    } 
    ans[2][0] = arr[1] * min(xs[2], arr[2] - xs[2]);
    ans[2][1] = arr[1] * max(xs[2], arr[2] - xs[2]);
    for (int i = 3; i < n; i++){
        LL lx = xs[i - 1], ly = arr[i - 1] - lx;
        LL x = xs[i], y = arr[i] - x;

        ans[i][0] = min(ans[i - 1][0] + max(lx, ly) * min(x, y), ans[i - 1][1] + min(lx, ly) * min(x, y));
        ans[i][1] = min(ans[i - 1][0] + max(lx, ly) * max(x, y), ans[i - 1][1] + min(lx, ly) * max(x, y));
    }
    LL x = xs[n - 1], y = arr[n- 1] - x;
    cout << min(ans[n - 1][0] + max(x, y) * arr[n], ans[n - 1][1] + min(x, y) * arr[n]) << endl;
//    printf("%lld\n", ans[n] + (arr[n - 1] - xs[n - 1]) * arr[n]);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}