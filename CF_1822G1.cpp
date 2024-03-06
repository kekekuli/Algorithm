#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#define N 200010
#define M 1000010
#define LL long long
using namespace std;

int arr[N];
int mm[M];

void solve(){

    int n;
    LL ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        mm[arr[i]]++;
    }
    for (int b = 1; b <= M / b; b++)
        for (int i = 1; i <= n; i++){
            if (b == 1){
                int c = mm[arr[i]];
                if (c > 2)
                    ans += (LL)(c - 1) * (c - 2); 
                continue;
            }
            if ((LL)arr[i] * b * b >= M)
                continue;
            ans += (LL)mm[arr[i] * b] * mm[arr[i] * b * b];
        }
    printf("%lld\n", ans);
    for(int i = 1; i <= n; i++)
        mm[arr[i]] = 0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}