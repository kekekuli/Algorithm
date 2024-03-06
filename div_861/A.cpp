#include <iostream>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;
int get(int x){
    int mi = 10, ma = -1;
    while(x){
        mi = min(mi, x % 10);
        ma = max(ma, x % 10);
        x /= 10;
    }
    return ma - mi;
}

void solve(){
    int l, r, cnt = 0, ans = 0 ,p;
    scanf("%d%d", &l, &r);
    p = l;
    for (; cnt <= 100 && l <= r; l++, cnt++){
        int c = get(l);
        if (c > ans){
            ans = c;
            p = l;
        }
    }
    cout << p << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}