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
    int n, k; 
    scanf("%d%d" ,&n, &k);
    int cnt0, cnt1;
    for (cnt0 = 0; cnt0 <= n; cnt0++){
        cnt1 = n - cnt0;
        int x = cnt0 * (cnt0 - 1) / 2 + cnt1 * (cnt1 - 1) / 2;
        if (x == k){
            cout << "YES\n";
            for (int i = 0; i < cnt0; i++)
                printf("1 ");
            for (int i = 0; i < cnt1; i++)
                printf("-1 ");
            printf("\n");
            return;
        }
    }
    printf("NO\n");
    return;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
