#include <iostream>
#include <algorithm>
#define N 110
using namespace std;

int arr[N];
void solve(){
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n - 2 * k; i++)
        ans += arr[i];
    for (int i = 1; i <= k; i++)
        ans += arr[n - 2 * k + i] / arr[n - k + i];
    cout << ans << endl;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}