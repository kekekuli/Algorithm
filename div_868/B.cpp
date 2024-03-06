#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define N 200010
#define LL long long
using namespace std;


void solve(){
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        if (a % k != i % k)
            cnt++;
    }
    if (cnt == 0)
        printf("0\n");
    else if (cnt == 2)
        printf("1\n");
    else
        printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
