#include <iostream>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

void solve(){
    LL k, n;
    scanf("%lld%lld", &n, &k);
    while(n > 0 && n % 2)
        n -= k;
    if (n < 0)
        printf("NO\n");
    else
        printf("YES\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}