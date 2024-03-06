#include <iostream>
#include <cstring>
#define N 200010

using namespace std;
void solve(){
    int ans = 0;
    int n, now = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        now += b - a;
        ans = max(ans, now);
    }
    cout << ans << endl;
}
int main(){
        solve();
    return 0;
}