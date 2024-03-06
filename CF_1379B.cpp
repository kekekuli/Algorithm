#include <iostream>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

LL ll, rr, m;
void solve(){
    scanf("%lld%lld%lld", &ll, &rr, &m);
    for (LL a = ll; a <= rr; a++){
        LL l = 0, r = (m + rr - ll)/ ll, mid = (l + r + 1) >> 1;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if (abs(m -  mid * a)> rr - ll)
                l = mid;
            else
                break;
        } 
        if (mid < 1)
            mid = 1;
        LL x = m - mid * a;
        if (abs(x) <= rr - ll){
            if (x >= 0)
                printf("%lld %lld %lld\n", a, rr, rr - x);
            else
                printf("%lld %lld %lld\n", a, ll, ll + abs(x));
            return;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}