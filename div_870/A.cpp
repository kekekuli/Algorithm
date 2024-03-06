#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 210
#define LL long long
using namespace std;

int arr[N], cnt[N];

void solve(){
    for (int i = 0; i <= 200; i++)
        cnt[i] = 0;

    int n, ans = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    int flag = 0;
    int s = 0;
    for (int i = 0; !flag && i <= n; i++){
        if (!cnt[i])
            continue;
        int t = s + cnt[i], f = n - t;
        if (f >= i){
            cout << f << endl;
            return;
        }
        else flag = 1;
        s += cnt[i];
    }

    cout << -1 << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}