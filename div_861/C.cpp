// NOT accepted
#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

bool st[20];

LL get(LL x){
    LL mi = 10, ma = -1;
    while(x){
        mi = min(mi, x % 10);
        ma = max(ma, x % 10);
        x /= 10;
    }
    return ma - mi;
}
void solve(){
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}