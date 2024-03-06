#include <iostream>
#define int long long
#define N 200010 
using namespace std;
int max(int a, int b){
    return a < b ? b : a;
}
int arr[N], dp[N];
void solve(){
    int n;
    long long ans = INT64_MAX;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
    for (int i = 2; i < n; i++){
        int t = 0;
        if (arr[i] < max(arr[i - 1], arr[i + 1])  + 1)
            t = max(arr[i - 1], arr[i + 1]) + 1 - arr[i];
        if (i % 2 == 0){
               if (i - 2 < 1) 
                    dp[i] = t;
                else
                    dp[i] = dp[i - 2] + t;
        } 
        else{
            if (i - 3 < 1)
                dp[i] = t;
            else
                dp[i] = min(dp[i - 2], dp[i - 3]) + t; 
        }
        if (i  / 2 == (n - 1) / 2 && ans > dp[i])
            ans = dp[i];
    }
    cout << ans << endl;
}
signed main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}