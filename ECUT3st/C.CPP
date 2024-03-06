#include <iostream>
#include <cstring>
#define N 200010

using namespace std;

long long arr[N];
void solve(){
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
    for (int i = 1; i <= n; i++){
        ans += 1;
        if (arr[i] == 1)
            continue;
        ans += i * (arr[i] - 1);
    } 
    cout << ans << endl;
}
int main(){
    int t;
        solve();
    return 0;
}