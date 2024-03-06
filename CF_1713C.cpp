#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

int ans[N];

void recurse(int r){
    if (r < 0)
        return;
    int s =sqrt(2 * r); s *= s;
    int l = s - r; recurse(l - 1);
    for (; l <= r; l++, r--){
        ans[l] = r; ans[r] = l;
    }
}

void solve(){
    int n;
    scanf("%d", &n);  
    recurse(n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}