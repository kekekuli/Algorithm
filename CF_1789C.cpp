#include <iostream>
#define LL long long

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}
LL lcm(LL a, LL b){
    return a / gcd(a, b) * b;
}

void solve(){
    LL n, cnt = 0, gd = 0, lm = 1;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        LL a, b;
        scanf("%lld%lld", &a, &b);
        gd = gcd(gd, a * b), lm = lcm(lm, b);
        if (gd % lm != 0){
            cnt++;
            gd = a * b;
            lm = b;
        }
    }
    printf("%lld\n", cnt + 1);
}

int main(){
    int t;
    scanf("%d", &t); 
    while(t--)
        solve();
    return 0;
}